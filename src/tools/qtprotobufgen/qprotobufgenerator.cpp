// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#include "qprotobufgenerator.h"
#include "enumdeclarationprinter.h"
#include "enumdefinitionprinter.h"
#include "messagedeclarationprinter.h"
#include "messagedefinitionprinter.h"

#include "commontemplates.h"
#include "utils.h"
#include "options.h"

#include <cassert>
#include <array>
#include <numeric>
#include <set>
#include <unordered_set>
#include <google/protobuf/stubs/logging.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/descriptor.h>

using namespace ::QtProtobuf;
using namespace ::qtprotoccommon;
using namespace ::google::protobuf;
using namespace ::google::protobuf::io;
using namespace ::google::protobuf::compiler;

QProtobufGenerator::QProtobufGenerator() : GeneratorBase()
{}

QProtobufGenerator::~QProtobufGenerator() = default;

bool QProtobufGenerator::Generate(const FileDescriptor *file,
                                  [[maybe_unused]] const std::string &parameter,
                                  GeneratorContext *generatorContext,
                                  std::string *error) const
{
    assert(file != nullptr && generatorContext != nullptr);

    if (file->syntax() != FileDescriptor::SYNTAX_PROTO3) {
        *error = "Invalid proto used. qtprotobufgen only supports 'proto3' syntax";
        return false;
    }

    return GenerateMessages(file, generatorContext);
}

void QProtobufGenerator::GenerateSources(const FileDescriptor *file,
                                         GeneratorContext *generatorContext) const
{
    assert(file != nullptr && generatorContext != nullptr);

    std::string filename = utils::extractFileBasename(file->name());
    std::string basename = generateBaseName(file, filename);
    std::unique_ptr<io::ZeroCopyOutputStream> sourceStream(
                generatorContext->Open(basename + CommonTemplates::ProtoFileSuffix() + ".cpp"));
    std::unique_ptr<io::ZeroCopyOutputStream> registrationStream(
                generatorContext->Open(basename + "_protobuftyperegistrations.cpp"));

    std::shared_ptr<Printer> sourcePrinter(new Printer(sourceStream.get(), '$'));
    std::shared_ptr<Printer> registrationPrinter(new Printer(registrationStream.get(), '$'));

    printDisclaimer(sourcePrinter.get());
    sourcePrinter->Print({{"include", basename + CommonTemplates::ProtoFileSuffix()}},
                         CommonTemplates::InternalIncludeTemplate());

    registrationPrinter->Print({{"include", "QtProtobuf/qprotobufserializer.h"}},
                               CommonTemplates::ExternalIncludeTemplate());

    registrationPrinter->Print({{"include", basename + CommonTemplates::ProtoFileSuffix()}},
                               CommonTemplates::InternalIncludeTemplate());

    sourcePrinter->Print({{"include", "QtProtobuf/qprotobufserializer.h"}},
                         CommonTemplates::ExternalIncludeTemplate());
    if (Options::instance().hasQml()) {
        sourcePrinter->Print({{"include", "QQmlEngine"}},
                             CommonTemplates::ExternalIncludeTemplate());
    }

    OpenFileNamespaces(file, sourcePrinter.get());
    OpenFileNamespaces(file, registrationPrinter.get());

    for (int i = 0; i < file->enum_type_count(); ++i) {
        EnumDefinitionPrinter enumSourceDef(file->enum_type(i), sourcePrinter);
        enumSourceDef.run();
    }

    common::iterateMessages(
                file,
                [&sourcePrinter, &registrationPrinter](const Descriptor *message) {
        MessageDefinitionPrinter messageDef(message, sourcePrinter);
        messageDef.printClassDefinition();
        messageDef.printClassRegistration(registrationPrinter.get());
    });

    CloseFileNamespaces(file, registrationPrinter.get());
    CloseFileNamespaces(file, sourcePrinter.get());

    // Include the moc file:
    sourcePrinter->Print({{"source_file", filename + CommonTemplates::ProtoFileSuffix()}},
                         "#include \"moc_$source_file$.cpp\"\n");

}

void QProtobufGenerator::GenerateHeader(const FileDescriptor *file,
                                        GeneratorContext *generatorContext) const
{
    assert(file != nullptr && generatorContext != nullptr);

    std::string filename = utils::extractFileBasename(file->name());
    std::string basename = generateBaseName(file, filename);
    std::set<std::string> internalIncludes;
    std::set<std::string> externalIncludes;

    std::unique_ptr<io::ZeroCopyOutputStream> headerStream(
                generatorContext->Open(basename
                                       + CommonTemplates::ProtoFileSuffix() + ".h"));
    std::shared_ptr<Printer> headerPrinter(new Printer(headerStream.get(), '$'));

    printDisclaimer(headerPrinter.get());

    std::string fileNameToUpper = filename;
    std::transform(fileNameToUpper.begin(), fileNameToUpper.end(),
                   fileNameToUpper.begin(), utils::toAsciiUpper);

    headerPrinter->Print({{"filename", fileNameToUpper}}, CommonTemplates::PreambleTemplate());

    headerPrinter->Print(CommonTemplates::DefaultProtobufIncludesTemplate());
    if (Options::instance().hasQml()) {
        headerPrinter->Print(CommonTemplates::QmlProtobufIncludesTemplate());
    }

    bool hasOneofFields = false;
    std::unordered_set<std::string> qtTypesSet;
    common::iterateMessages(
            file, [&](const Descriptor *message) {
                if (message->oneof_decl_count() > 0)
                    hasOneofFields = true;

                if (message->full_name() == "google.protobuf.Timestamp") {
                    externalIncludes.insert("QtCore/QDateTime");
                }
                if (message->full_name() == "google.protobuf.Any")
                    externalIncludes.insert("QtProtobufWellKnownTypes/qprotobufanysupport.h");

                for (int i = 0; i < message->field_count(); ++i) {
                    const auto *field = message->field(i);
                    if (field->type() == FieldDescriptor::TYPE_MESSAGE && !field->is_map()
                        && !field->is_repeated() && common::isQtType(field)) {
                        externalIncludes.insert(field->message_type()->file()->package()
                                                + "/" + field->message_type()->name());
                        qtTypesSet.insert(field->message_type()->file()->package());
                    }
                }
            });

    if (hasOneofFields)
        externalIncludes.insert("QtProtobuf/qprotobufoneof.h");

    for (const auto &qtTypeInclude: qtTypesSet) {
        std::string qtTypeLower = qtTypeInclude;
        std::transform(qtTypeLower.begin(), qtTypeLower.end(),
                       qtTypeLower.begin(), utils::toAsciiLower);
        externalIncludes.insert("QtProtobuf" + qtTypeInclude
                                + "Types/qtprotobuf" + qtTypeLower + "types.h");
    }

    for (int i = 0; i < file->dependency_count(); ++i) {
        if (file->dependency(i)->name() == "QtCore/QtCore.proto"
                || file->dependency(i)->name() == "QtGui/QtGui.proto") {
            continue;
        }
        // Override the any.proto include with our own specific support
        if (file->dependency(i)->name() == "google/protobuf/any.proto") {
            externalIncludes.insert("QtProtobufWellKnownTypes/qprotobufanysupport.h");
            continue;
        }
        internalIncludes.insert(utils::removeFileSuffix(file->dependency(i)->name())
                                + CommonTemplates::ProtoFileSuffix());
    }

    externalIncludes.insert("QtCore/qbytearray.h");
    externalIncludes.insert("QtCore/qstring.h");

    for (const auto &include : externalIncludes) {
        headerPrinter->Print({{"include", include}}, CommonTemplates::ExternalIncludeTemplate());
    }

    for (const auto &include : internalIncludes) {
        headerPrinter->Print({{"include", include}}, CommonTemplates::InternalIncludeTemplate());
    }

    headerPrinter->Print(CommonTemplates::DefaultQtIncludesTemplate());
    headerPrinter->Print(CommonTemplates::DefaultSystemIncludesTemplate());

    headerPrinter->PrintRaw("\n");
    if (!Options::instance().exportMacro().empty()) {
        headerPrinter->Print({ { "export_macro", Options::instance().exportMacro() } },
                             CommonTemplates::ExportMacroTemplate());
    }
    OpenFileNamespaces(file, headerPrinter.get());

    for (int i = 0; i < file->enum_type_count(); ++i) {
        EnumDeclarationPrinter enumDecl(file->enum_type(i), headerPrinter);
        enumDecl.run();
    }

    common::iterateMessages(file, [&headerPrinter](const Descriptor *message) {
        MessageDeclarationPrinter messageDecl(message, headerPrinter);
        messageDecl.printClassForwardDeclaration();
    });

    common::iterateMessages(
                file,
                [&headerPrinter](const Descriptor *message) {
        MessageDeclarationPrinter messageDecl(message, headerPrinter);
        messageDecl.printClassDeclaration();
    });

    CloseFileNamespaces(file, headerPrinter.get());

    common::iterateMessages(file, [&headerPrinter](const Descriptor *message) {
        MessageDeclarationPrinter messageDef(message, headerPrinter);
        messageDef.printMetaTypesDeclaration();
    });

    headerPrinter->Print({{"filename", fileNameToUpper}}, CommonTemplates::FooterTemplate());
}

bool QProtobufGenerator::GenerateMessages(const FileDescriptor *file,
                                          GeneratorContext *generatorContext) const
{
    assert(file != nullptr && generatorContext != nullptr);

    if (file->message_type_count() <= 0 && file->enum_type_count() <= 0) {
        return false;
    }
    GenerateHeader(file, generatorContext);
    GenerateSources(file, generatorContext);
    return true;
}
