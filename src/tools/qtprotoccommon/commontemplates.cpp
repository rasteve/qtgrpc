// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>, Tatyana Borisova <tanusshhka@mail.ru>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#include "commontemplates.h"

// CommonTemplates navigation map:
// All template functions are named as following(with some exceptions):
//     <CommonTemplateType>[TemplateSubject][Declaration|Definition]Template
//
// CommonTemplateType usually describes what template implements e.g. Constructor, Member,
// Property etc.
//
// TemplateSubject is the type that the template is applicable for. The following naming is used for
// the common types:
// ''(empty) - for integral types like int32, fixed32, bool, etc.
// Map       - any map types.
// Repeated  - any repeated types.
// Complex   - means that template is applicable for any non-trivially desctructable types, except
//             messages.
// Message   - for any general protobuf message that is represented as the pointer with lazy
//             initialization
// Enum      - any enum types.
// Oneof     - fields that are part of oneof union.
//
// Map and Repeated can be combined with one of Complex, Message or Enum keywords, that indicates
// the specialization of the template.

using namespace ::qtprotoccommon;

const char *CommonTemplates::ProtoSuffix()
{
    return "_proto";
}

const std::vector<std::string> &CommonTemplates::ListOfQmlExceptions()
{
    static std::vector<std::string> vec{ { "id", "property", "import" } };
    return vec;
}

const std::set<std::string_view> &CommonTemplates::ListOfCppExceptions()
{
    static std::set<std::string_view> cppExceptions{
        "NULL",          "alignas",      "alignof",   "and",        "and_eq",
        "asm",           "auto",         "bitand",    "bitor",      "bool",
        "break",         "case",         "catch",     "char",       "class",
        "compl",         "const",        "constexpr", "const_cast", "continue",
        "decltype",      "default",      "delete",    "do",         "double",
        "dynamic_cast",  "else",         "enum",      "explicit",   "export",
        "extern",        "false",        "float",     "for",        "friend",
        "goto",          "if",           "inline",    "int",        "long",
        "mutable",       "namespace",    "new",       "noexcept",   "not",
        "not_eq",        "nullptr",      "operator",  "or",         "or_eq",
        "private",       "protected",    "public",    "register",   "reinterpret_cast",
        "return",        "short",        "signed",    "sizeof",     "static",
        "static_assert", "static_cast",  "struct",    "switch",     "template",
        "this",          "thread_local", "throw",     "true",       "try",
        "typedef",       "typeid",       "typename",  "union",      "unsigned",
        "using",         "virtual",      "void",      "volatile",   "wchar_t",
        "while",         "xor",          "xor_eq",
        // block of Qt Cpp words:
        "signals",       "slots",        "emit"
    };

    return cppExceptions;
}

const char *CommonTemplates::QmlProtobufIncludesTemplate()
{
    return "#include <QtQml/qqmlregistration.h>\n"
           "#include <QtQml/qqmllist.h>\n\n";
}

const char *CommonTemplates::DisclaimerTemplate()
{
    return "/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */\n\n";
}

const char *CommonTemplates::PreambleTemplate()
{
    return "#ifndef $header_guard$\n"
           "#define $header_guard$\n";
}

const char *CommonTemplates::FooterTemplate()
{
    return "#endif // $header_guard$\n";
}

const char *CommonTemplates::InternalIncludeTemplate()
{
    return "#include \"$include$.h\"\n";
}
const char *CommonTemplates::ExternalIncludeTemplate()
{
    return "#include <$include$>\n";
}

const char *CommonTemplates::EnumRegistrationDeclaration()
{
    return "$export_macro$void registerTypes();\n";
}

const char *CommonTemplates::EnumRegistrationDeclarationNoExport()
{
    return "void registerTypes();\n";
}

const char *CommonTemplates::MetaTypeRegistrationDeclaration()
{
    return "$export_macro$static void registerTypes();\n";
}
const char *CommonTemplates::MetaTypeRegistrationMessageDefinition()
{
    return "void $type$::registerTypes()\n{\n"
           "    qRegisterMetaType<$type$>();\n"
           "    qRegisterMetaType<$list_type$>();\n";
}
const char *CommonTemplates::MetaTypeRegistrationGlobalEnumDefinition()
{
    return "void $enum_gadget$::registerTypes()\n{\n";
}
const char *CommonTemplates::MetaTypeRegistrationGlobalEnumTemplate()
{
    return "qRegisterMetaType<$type$>();\n"
           "qRegisterMetaType<$full_type$>();\n";
}
const char *CommonTemplates::UsingMessageTemplate()
{
    return "using $classname$Repeated = QList<$classname$>;\n";
}
const char *CommonTemplates::UsingMapTemplate()
{
    return "using $type$ = QHash<$key_type$, $value_type$>;\n";
}
const char *CommonTemplates::UsingNestedMessageTemplate()
{
    return "using $type$ = $scope_namespaces$::$type$;\n"
           "using $list_type$ = $scope_namespaces$::$list_type$;\n";
}
const char *CommonTemplates::UsingEnumTemplate()
{
    return "using $type$ = $scope_namespaces$::$type$;\n";
}
const char *CommonTemplates::UsingRepeatedEnumTemplate()
{
    return "using $list_type$ = QList<$type$>;\n";
}

const char *CommonTemplates::NamespaceTemplate()
{
    return "namespace $scope_namespaces$ {\n";
}
const char *CommonTemplates::NamespaceClosingTemplate()
{
    return "} // namespace $scope_namespaces$\n";
}
const char *CommonTemplates::EnumGadgetDeclarationTemplate()
{
    return "\nnamespace $enum_gadget$ {\n";
}
const char *CommonTemplates::QNamespaceDeclarationTemplate()
{
    return "Q_NAMESPACE_EXPORT($export_macro$)\n";
}
const char *CommonTemplates::QNamespaceDeclarationNoExportTemplate()
{
    return "Q_NAMESPACE\n";
}
const char *CommonTemplates::ClassMessageForwardDeclarationTemplate()
{
    return "class $classname$;\n";
}

const char *CommonTemplates::EnumForwardDeclarationTemplate()
{
    return "enum $type$ : int32_t;\n"
           "using $list_type$ = QList<$type$>;\n";
}

const char *CommonTemplates::EnumClassForwardDeclarationTemplate()
{
    return "enum class $type$;\n";
}

const char *CommonTemplates::ClassMessageQmlBeginDeclarationTemplate()
{
    return "    QML_VALUE_TYPE($classname_low_case$)\n";
}

const char *CommonTemplates::ClassMessageBeginDeclarationTemplate()
{
    return "\nclass $dataclassname$;\n"
           "class $classname$ : public QProtobufMessage\n"
           "{\n";
}

const char *CommonTemplates::Q_PROTOBUF_OBJECTMacro()
{
    return "Q_PROTOBUF_OBJECT\n";
}

const char *CommonTemplates::Q_PROTOBUF_OBJECT_EXPORTMacro()
{
    return "Q_PROTOBUF_OBJECT_EXPORT($export_macro$)\n";
}

const char *CommonTemplates::ClassMessageDataBeginDeclarationTemplate()
{
    return "\nclass $dataclassname$ : public QSharedData\n"
           "{";
}

const char *CommonTemplates::ConstructorMessageDataDefinitionTemplate()
{
    return "$dataclassname$()\n"
           "    : QSharedData()";
}

const char *CommonTemplates::CopyConstructorMessageDataDefinitionTemplate()
{
    return "$dataclassname$(const $dataclassname$ &other)\n"
           "    : QSharedData(other)";
}

const char *CommonTemplates::PropertyTemplate()
{
    return "Q_PROPERTY($property_type$ $property_name$ READ $property_name$ WRITE "
           "set$property_name_cap$ SCRIPTABLE $scriptable$)\n";
}
const char *CommonTemplates::PropertyRepeatedTemplate()
{
    return "Q_PROPERTY($property_list_type$ $property_name$ READ $property_name$ WRITE "
           "set$property_name_cap$ SCRIPTABLE $scriptable$)\n";
}
const char *CommonTemplates::PropertyRepeatedMessageTemplate()
{
    return "Q_PROPERTY($property_list_type$ $property_name$Data READ $property_name$ WRITE "
           "set$property_name_cap$ SCRIPTABLE $scriptable$)\n";
}
const char *CommonTemplates::PropertyMessageTemplate()
{
    return "Q_PROPERTY($property_type$ *$property_name$_p READ $property_name$_p WRITE "
           "set$property_name_cap$_p SCRIPTABLE false)\n";
}
const char *CommonTemplates::PropertyQmlMessageTemplate()
{
    return "Q_PROPERTY($property_type$ $property_name$ READ $property_name$ WRITE "
           "set$property_name_cap$)\n";
}

const char *CommonTemplates::PropertyOneofTemplate()
{
    return "Q_PROPERTY($property_type$ $property_name$ "
           "READ $property_name$_p WRITE set$property_name_cap$_p)\n";
}
const char *CommonTemplates::PropertyOneofMessageTemplate()
{
    return "Q_PROPERTY($property_type$ *$property_name$_p "
           "READ $property_name$_p WRITE set$property_name_cap$_p SCRIPTABLE false)\n";
}
const char *CommonTemplates::PropertyHasFieldTemplate()
{
    return "Q_PROPERTY(bool has$property_name_cap$ "
           "READ has$property_name_cap$)\n";
}

const char *CommonTemplates::ConstructorMessageDeclarationTemplate()
{
    return "$export_macro$$classname$();\n";
}

const char *CommonTemplates::DestructorMessageDeclarationTemplate()
{
    return "$export_macro$~$classname$();\n";
}

const char *CommonTemplates::MemberSharedDataPointerTemplate()
{
    return "QExplicitlySharedDataPointer<$dataclassname$> dptr;\n";
}

const char *CommonTemplates::MemberTemplate()
{
    return "$scope_type$ m_$property_name$;\n";
}
const char *CommonTemplates::MemberOneofTemplate()
{
    return "QtProtobufPrivate::QProtobufOneof m_$optional_property_name$;\n";
}
const char *CommonTemplates::MemberOptionalTemplate()
{
    return "std::optional<$scope_type$> m_$optional_property_name$;\n";
}
const char *CommonTemplates::MemberRepeatedTemplate()
{
    return "$scope_list_type$ m_$property_name$;\n";
}
const char *CommonTemplates::MemberMessageTemplate()
{
    return "QtProtobufPrivate::QProtobufLazyMessagePointer<$scope_type$> m_$property_name$;\n";
}
const char *CommonTemplates::PublicBlockTemplate()
{
    return "\npublic:\n";
}
const char *CommonTemplates::PrivateBlockTemplate()
{
    return "\nprivate:\n";
}
const char *CommonTemplates::EnumDefinitionTemplate()
{
    return "enum $type$ : int32_t {\n";
}
const char *CommonTemplates::EnumClassDefinitionTemplate()
{
    return "enum class $type$ {\n";
}
const char *CommonTemplates::EnumFieldTemplate()
{
    return "$enumvalue$ = $value$,\n";
}

const char *CommonTemplates::ConstructorMessageDefinitionTemplate()
{
    return "$classname$::$classname$()\n"
           "    : QProtobufMessage(&$classname$::staticMetaObject,"
           " &$classname$::staticPropertyOrdering),\n"
           "      dptr(new $dataclassname$)";
}

const char *CommonTemplates::UseNamespace()
{
    return "using namespace $namespace$;\n";
}

const char *CommonTemplates::CopyConstructorDeclarationTemplate()
{
    return "$export_macro$$classname$(const $classname$ &other);\n";
}
const char *CommonTemplates::MoveConstructorDeclarationTemplate()
{
    return "$export_macro$$classname$($classname$ &&other) noexcept;\n";
}
const char *CommonTemplates::CopyConstructorDefinitionTemplate()
{
    return "$classname$::$classname$(const $classname$ &other)\n"
           "    : QProtobufMessage(other),\n"
           "      dptr(other.dptr)\n"
           "{\n}\n";
}
const char *CommonTemplates::MoveConstructorDefinitionTemplate()
{
    return "$classname$::$classname$($classname$ &&other) noexcept\n"
           "    : QProtobufMessage(std::move(other)),\n"
           "      dptr(std::move(other.dptr))\n"
           "{\n}\n";
}

const char *CommonTemplates::AssignmentOperatorDeclarationTemplate()
{
    return "$export_macro$$classname$ &operator =(const $classname$ &other);\n";
}
const char *CommonTemplates::AssignmentOperatorDefinitionTemplate()
{
    return "$classname$ &$classname$::operator =(const $classname$ &other)\n"
           "{\n"
           "    $classname$ temp(other);\n"
           "    swap(temp);\n"
           "    return *this;\n"
           "}\n";
}

const char *CommonTemplates::MoveAssignmentOperatorDeclarationTemplate()
{
    return "$classname$ &operator =($classname$ &&other) noexcept\n"
           "{\n"
           "    swap(other);\n"
           "    return *this;\n"
           "}\n";
}

const char *CommonTemplates::SwapDeclarationTemplate()
{
    return "void swap($classname$ &other) noexcept\n"
           "{\n"
           "    QProtobufMessage::swap(other);\n"
           "    dptr.swap(other.dptr);\n"
           "}\n";
}

const char *CommonTemplates::EqualityDeclarationTemplate()
{
    return "friend $export_macro$bool comparesEqual(const $classname$ &lhs, "
           "const $classname$ &rhs) noexcept;\n"
           "friend bool operator==(const $classname$ &lhs, const $classname$ &rhs) noexcept\n"
           "{\n"
           "    return comparesEqual(lhs, rhs);\n"
           "}\n"
           "friend bool operator!=(const $classname$ &lhs, const $classname$ &rhs) noexcept\n"
           "{\n"
           "    return !comparesEqual(lhs, rhs);\n"
           "}\n";
}

const char *CommonTemplates::ComparesEqualDefinitionTemplate()
{
    return "bool comparesEqual(const $classname$ &lhs, const $classname$ &rhs) noexcept\n"
           "{\n"
           "    return operator ==(static_cast<const QProtobufMessage&>(lhs),\n"
           "                       static_cast<const QProtobufMessage&>(rhs))";
}
const char *CommonTemplates::EqualOperatorMemberTemplate()
{
    return "lhs.dptr->m_$property_name$ == rhs.dptr->m_$property_name$";
}
const char *CommonTemplates::EqualOperatorMemberMessageTemplate()
{
    return "(lhs.dptr->m_$property_name$ == rhs.dptr->m_$property_name$\n"
           "    || *lhs.dptr->m_$property_name$ == *rhs.dptr->m_$property_name$)";
}
const char *CommonTemplates::EqualOperatorMemberRepeatedTemplate()
{
    return "lhs.dptr->m_$property_name$ == rhs.dptr->m_$property_name$";
}
const char *CommonTemplates::EqualOperatorMemberOneofTemplate()
{
    return "lhs.dptr->m_$optional_property_name$ == rhs.dptr->m_$optional_property_name$";
}

const char *CommonTemplates::PrivateGetterMessageDeclarationTemplate()
{
    return "$export_macro$$getter_type$ *$property_name$_p();\n";
}
const char *CommonTemplates::PrivateGetterMessageDefinitionTemplate()
{
    return "$getter_type$ *$classname$::$property_name$_p()\n{\n"
           "    if (!dptr->m_$property_name$)\n"
           "        dptr.detach();\n"
           "    return dptr->m_$property_name$.get();\n"
           "}\n\n";
}

const char *CommonTemplates::ClearMessageDeclarationTemplate()
{
    return "$export_macro$void clear$property_name_cap$();\n";
}

const char *CommonTemplates::ClearQmlMessageDeclarationTemplate()
{
    return "Q_INVOKABLE $export_macro$void clear$property_name_cap$();\n";
}

const char *CommonTemplates::ClearMessageDefinitionTemplate()
{
    return "void $classname$::clear$property_name_cap$()\n{\n"
           "    if (dptr->m_$property_name$) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$property_name$.reset();\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::GetterMessageDeclarationTemplate()
{
    return "$export_macro$bool has$property_name_cap$() const;\n"
           "$export_macro$$getter_type$ &$property_name$();\n"
           "$export_macro$const $getter_type$ &$property_name$() const;\n";
}
const char *CommonTemplates::GetterMessageDefinitionTemplate()
{
    return "bool $classname$::has$property_name_cap$() const\n{\n"
           "    return dptr->m_$property_name$.operator bool();\n"
           "}\n\n"
           "$getter_type$ &$classname$::$property_name$()\n"
           "{\n"
           "    dptr.detach();\n"
           "    return *dptr->m_$property_name$;\n"
           "}\n"
           "const $getter_type$ &$classname$::$property_name$() const\n"
           "{\n"
           "    return *dptr->m_$property_name$;\n"
           "}\n\n";
}

const char *CommonTemplates::PrivateGetterOneofDeclarationTemplate()
{
    return "$export_macro$$getter_type$ $property_name$_p() const;\n";
}
const char *CommonTemplates::PrivateGetterOneofDefinitionTemplate()
{
    return "$getter_type$ $classname$::$property_name$_p() const\n{\n"
           "    return dptr->m_$optional_property_name$.holdsField($number$) ?\n"
           "        dptr->m_$optional_property_name$.value<$getter_type$>() : "
           "$getter_type$($initializer$);\n"
           "}\n\n";
}
const char *CommonTemplates::PrivateGetterOptionalDefinitionTemplate()
{
    return "$getter_type$ $classname$::$property_name$_p() const\n{\n"
           "    return dptr->m_$optional_property_name$ ?\n"
           "        dptr->m_$optional_property_name$.value() : "
           "$getter_type$();\n"
           "}\n\n";
}

const char *CommonTemplates::PrivateGetterOneofMessageDeclarationTemplate()
{
    return "$export_macro$$getter_type$ *$property_name$_p();\n";
}
const char *CommonTemplates::PrivateGetterOneofMessageDefinitionTemplate()
{
    return "$getter_type$ *$classname$::$property_name$_p()\n{\n"
           "    if (!dptr->m_$optional_property_name$.holdsField($number$))\n"
           "        dptr.detach();\n"
           "    return dptr->m_$optional_property_name$.message<$getter_type$>();\n"
           "}\n\n";
}

const char *CommonTemplates::GetterOneofFieldNumberDeclarationTemplate()
{
    return "$export_macro$$type$ $optional_property_name$Field() const;\n";
}
const char *CommonTemplates::GetterOneofFieldNumberDefinitionTemplate()
{
    return "$classname$::$type$ $classname$::$optional_property_name$Field() const\n{\n"
           "    return "
           "static_cast<$type$>(dptr->m_$optional_property_name$.fieldNumber());\n"
           "}\n";
}

const char *CommonTemplates::GetterOneofDeclarationTemplate()
{
    return "$export_macro$bool has$property_name_cap$() const;\n"
           "$export_macro$$getter_type$ $property_name$() const;\n";
}
const char *CommonTemplates::GetterOneofDefinitionTemplate()
{
    return "bool $classname$::has$property_name_cap$() const\n{\n"
           "    return dptr->m_$optional_property_name$.holdsField($number$);\n"
           "}\n"
           "$getter_type$ $classname$::$property_name$() const\n{\n"
           "    Q_ASSERT(dptr->m_$optional_property_name$.holdsField($number$));\n"
           "    return dptr->m_$optional_property_name$.value<$getter_type$>();\n"
           "}\n\n";
}
const char *CommonTemplates::GetterOptionalDefinitionTemplate()
{
    return "bool $classname$::has$property_name_cap$() const\n{\n"
           "    return dptr->m_$optional_property_name$.has_value();\n"
           "}\n"
           "$getter_type$ $classname$::$property_name$() const\n{\n"
           "    Q_ASSERT(dptr->m_$optional_property_name$.has_value());\n"
           "    return dptr->m_$optional_property_name$.value();\n"
           "}\n\n";
}

const char *CommonTemplates::GetterOneofMessageDeclarationTemplate()
{
    return "$export_macro$bool has$property_name_cap$() const;\n"
           "$export_macro$$getter_type$ &$property_name$() const;\n";
}
const char *CommonTemplates::GetterOneofMessageDefinitionTemplate()
{
    return "bool $classname$::has$property_name_cap$() const\n{\n"
           "    return dptr->m_$optional_property_name$.holdsField($number$);\n"
           "}\n"
           "$getter_type$ &$classname$::$property_name$() const\n{\n"
           "    Q_ASSERT(dptr->m_$optional_property_name$.holdsField($number$));\n"
           "    return *(dptr->m_$optional_property_name$.message<$getter_type$>());\n"
           "}\n\n";
}

const char *CommonTemplates::GetterDeclarationTemplate()
{
    return "$export_macro$$getter_type$ $property_name$() const;\n";
}

const char *CommonTemplates::GetterDefinitionTemplate()
{
    return "$getter_type$ $classname$::$property_name$() const\n{\n"
           "    return dptr->m_$property_name$;\n"
           "}\n\n";
}

const char *CommonTemplates::PrivateSetterMessageDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$_p($setter_type$ *$property_name$);\n";
}
const char *CommonTemplates::PrivateSetterMessageDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$_p($setter_type$ *$property_name$)\n{\n"
           "    if (dptr->m_$property_name$.get() != $property_name$) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$property_name$.reset($property_name$);\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::SetterMessageDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$(const $setter_type$ &$property_name$);\n";
}
const char *CommonTemplates::SetterMessageDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n{\n"
           "    if (*dptr->m_$property_name$ != $property_name$) {\n"
           "        dptr.detach();\n"
           "        *dptr->m_$property_name$ = $property_name$;\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::SetterComplexDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$(const $setter_type$ &$property_name$);\n";
}
const char *CommonTemplates::SetterComplexDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n{\n"
           "    if (dptr->m_$property_name$ != $property_name$) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$property_name$ = $property_name$;\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::PrivateSetterOneofMessageDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$_p($setter_type$ *$property_name$);\n";
}
const char *CommonTemplates::PrivateSetterOneofMessageDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$_p($setter_type$ *$property_name$)\n{\n"
           "    const $setter_type$ &value = *$property_name$;\n"
           "    if (!dptr->m_$optional_property_name$.isEqual(value, $number$)) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$.setValue(value, $number$);\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::PrivateSetterOneofDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$_p($setter_type$ $property_name$);\n";
}
const char *CommonTemplates::PrivateSetterOneofDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$_p($setter_type$ $property_name$)\n{\n"
           "    if (!dptr->m_$optional_property_name$.isEqual($property_name$, $number$)) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$.setValue($property_name$, $number$);\n"
           "    }\n"
           "}\n\n";
}
const char *CommonTemplates::PrivateSetterOptionalDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$_p($setter_type$ $property_name$)\n"
           "{\n"
           "    if (!dptr->m_$optional_property_name$ || dptr->m_$optional_property_name$ != "
           "$property_name$) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$ = $property_name$;\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::ClearOneofDeclarationTemplate()
{
    return "$export_macro$void clear$optional_property_name_cap$();\n";
}
const char *CommonTemplates::ClearQmlOneofDeclarationTemplate()
{
    return "Q_INVOKABLE $export_macro$void clear$optional_property_name_cap$();\n";
}
const char *CommonTemplates::ClearOneofDefinitionTemplate()
{
    return "void $classname$::clear$optional_property_name_cap$()\n{\n"
           "    if (dptr->m_$optional_property_name$.fieldNumber() != "
           "QtProtobuf::InvalidFieldNumber) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$ = QtProtobufPrivate::QProtobufOneof();\n"
           "    }\n"
           "}\n";
}
const char *CommonTemplates::ClearOptionalDefinitionTemplate()
{
    return "void $classname$::clear$optional_property_name_cap$()\n{\n"
           "    if (dptr->m_$optional_property_name$.has_value()) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$.reset();\n"
           "    }\n"
           "}\n";
}

const char *CommonTemplates::SetterOneofDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$(const $setter_type$ &$property_name$);\n";
}
const char *CommonTemplates::SetterOneofDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n{\n"
           "    if (!dptr->m_$optional_property_name$.isEqual($property_name$, $number$)) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$.setValue($property_name$, $number$);\n"
           "    }\n"
           "}\n\n";
}
const char *CommonTemplates::SetterOptionalDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n{\n"
           "    if (!dptr->m_$optional_property_name$ || dptr->m_$optional_property_name$.value() "
           "!= $property_name$) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$optional_property_name$ = $property_name$;\n"
           "    }\n"
           "}\n\n";
}
const char *CommonTemplates::SetterDeclarationTemplate()
{
    return "$export_macro$void set$property_name_cap$(const $setter_type$ &$property_name$);\n";
}

const char *CommonTemplates::SetterDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n"
           "{\n"
           "    if (dptr->m_$property_name$ != $property_name$) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$property_name$ = $property_name$;\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::SetterFloatingPointDefinitionTemplate()
{
    return "void $classname$::set$property_name_cap$(const $setter_type$ &$property_name$)\n"
           "{\n"
           "    if (dptr->m_$property_name$ != $property_name$ ||\n"
           "        std::signbit(dptr->m_$property_name$) != std::signbit($property_name$)) {\n"
           "        dptr.detach();\n"
           "        dptr->m_$property_name$ = $property_name$;\n"
           "    }\n"
           "}\n\n";
}

const char *CommonTemplates::JsonNameOffsetsUintDataTemplate()
{
    return "$json_name_offset$, /* = $json_name$ */\n";
}

const char *CommonTemplates::FieldNumbersUintDataTemplate()
{
    return "$field_number$, /* = $json_name$ */\n";
}

const char *CommonTemplates::QtPropertyIndicesUintDataTemplate()
{
    return "$property_index$, /* = $json_name$ */\n";
}

const char *CommonTemplates::FieldFlagsUintDataTemplate()
{
    return "$field_flags$, /* = $json_name$ */\n";
}

const char *CommonTemplates::PropertyOrderingDataOpeningTemplate()
{
    return "static constexpr struct {\n"
           "    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;\n"
           "    const std::array<uint, $uint_size$> qt_protobuf_$classname$_uint_data;\n"
           "    const char qt_protobuf_$classname$_char_data[$char_size$];\n"
           "} qt_protobuf_$classname$_metadata {\n"
           "    // data\n"
           "    {\n"
           "        $version_number$, /* = version */\n"
           "        $num_fields$, /* = num fields */\n"
           "        $field_number_offset$, /* = field number offset */\n"
           "        $property_index_offset$, /* = property index offset */\n"
           "        $field_flags_offset$, /* = field flags offset */\n"
           "        $message_full_name_size$, /* = message full name length */\n"
           "    },\n";
}

const char *CommonTemplates::PropertyOrderingDataClosingTemplate()
{
    return "};\n\n";
}
const char *CommonTemplates::PropertyOrderingDefinitionTemplate()
{
    return "const QtProtobufPrivate::QProtobufPropertyOrdering $type$::staticPropertyOrdering = {\n"
           "    &qt_protobuf_$classname$_metadata.data\n"
           "};\n\n";
}

const char *CommonTemplates::SimpleBlockEnclosureTemplate()
{
    return "}\n\n";
}
const char *CommonTemplates::SemicolonBlockEnclosureTemplate()
{
    return "};\n";
}
const char *CommonTemplates::InitializerMemberTemplate()
{
    return "m_$property_name$($initializer$)";
}

const char *CommonTemplates::CopyInitializerMemberTemplate()
{
    return "m_$property_name$(other.m_$property_name$)";
}
const char *CommonTemplates::CopyInitializerMemberMessageTemplate()
{
    return "m_$property_name$(other.m_$property_name$\n"
           "                                     ? new $scope_type$(*other.m_$property_name$)\n"
           "                                     : nullptr)";
}
const char *CommonTemplates::CopyInitializerMemberOneofTemplate()
{
    return "m_$optional_property_name$(other.m_$optional_property_name$)";
}
const char *CommonTemplates::EmptyBracesTemplate()
{
    return "\n{\n}\n\n";
}

const char *CommonTemplates::MetaTypeRegistrationLocalEnumTemplate()
{
    return "qRegisterProtobufEnumType<$scope_type$>();\n"
           "qRegisterMetaType<$type$>();\n"
           "qRegisterMetaType<$list_type$>();\n";
}
const char *CommonTemplates::MetaTypeRegistrationMapTemplate()
{
    return "qRegisterMetaType<$scope_type$>();\n"
           "qRegisterProtobufMapType<$key_type$, $value_type$>();\n";
}

const char *CommonTemplates::QEnumNSTemplate()
{
    return "Q_ENUM_NS($type$)\n\n";
}

const char *CommonTemplates::RegisterEnumSerializersTemplate()
{
    return "qRegisterProtobufEnumType<$full_type$>();\n";
}
const char *CommonTemplates::RegistrarTemplate()
{
    return "static QtProtobuf::ProtoTypeRegistrar "
           "ProtoTypeRegistrar$classname$(qRegisterProtobufType<$classname$>);\n";
}
const char *CommonTemplates::ProtobufTypeRegistrarTemplate()
{
    return "static bool Register$proto_name$ProtobufTypes"
           " = [](){ qRegisterProtobufTypes(); return true; }();\n";
}
const char *CommonTemplates::RegistrarEnumTemplate()
{
    return "static QtProtobuf::ProtoTypeRegistrar "
           "ProtoTypeRegistrar$enum_gadget$($enum_gadget$::registerTypes);\n";
}

const char *CommonTemplates::QmlNamedElement()
{
    return "QML_NAMED_ELEMENT($classname$)\n";
}

const char *CommonTemplates::QmlRegisterGlobalEnumTypeTemplate()
{
    return "    qmlRegisterUncreatableMetaObject(\n"
           "        $scope_namespaces$::staticMetaObject,\n"
           "        uri, 1, 0, \"$type$\", "
           "\"You can only use the nested enums of $type$, "
           "but not create its instances in QML scope.\");\n";
}

const char *CommonTemplates::QmlRegisterMessageTypeTemplate()
{
    return "    qmlRegisterUncreatableMetaObject(\n"
           "        $full_type$::staticMetaObject,\n"
           "        uri, 1, 0, \"$type$\", "
           "\"You can only use the nested enums of $type$, "
           "but not create its instances in QML scope.\");\n";
}

const char *CommonTemplates::QDateTimeExtrasTemplate()
{
    return "$export_macro$static Timestamp fromDateTime(const QDateTime &dateTime);\n"
           "$export_macro$QDateTime toDateTime() const;\n";
}

const char *CommonTemplates::RepeatedSuffix()
{
    return "Repeated";
}

// Those marked "Limited" have limited usage in QML, since QML only supports signed integers.
// See https://doc.qt.io/qt-6/qtqml-typesystem-valuetypes.html for types that are supported by the
// QML JS engine.
const std::unordered_map<::google::protobuf::FieldDescriptor::Type, std::string>
        &CommonTemplates::TypeReflection()
{
    static std::unordered_map<::google::protobuf::FieldDescriptor::Type, std::string> map{
        { ::google::protobuf::FieldDescriptor::TYPE_DOUBLE, "double" },
        { ::google::protobuf::FieldDescriptor::TYPE_FLOAT, "float" },
        { ::google::protobuf::FieldDescriptor::TYPE_INT64, "int64" }, // Limited
        { ::google::protobuf::FieldDescriptor::TYPE_UINT64, "uint64" }, // Limited
        { ::google::protobuf::FieldDescriptor::TYPE_INT32, "int32" },
        { ::google::protobuf::FieldDescriptor::TYPE_FIXED64, "fixed64" }, // Limited
        { ::google::protobuf::FieldDescriptor::TYPE_FIXED32, "fixed32" },
        { ::google::protobuf::FieldDescriptor::TYPE_BOOL, "bool" },
        { ::google::protobuf::FieldDescriptor::TYPE_STRING, "QString" },
        { ::google::protobuf::FieldDescriptor::TYPE_BYTES, "QByteArray" },
        { ::google::protobuf::FieldDescriptor::TYPE_UINT32, "uint32" }, // Limited
        { ::google::protobuf::FieldDescriptor::TYPE_SFIXED32, "sfixed32" },
        { ::google::protobuf::FieldDescriptor::TYPE_SFIXED64, "sfixed64" }, // Limited
        { ::google::protobuf::FieldDescriptor::TYPE_SINT32, "sint32" },
        { ::google::protobuf::FieldDescriptor::TYPE_SINT64, "sint64" } // Limited
    };
    return map;
}

const char *CommonTemplates::ProtoFileSuffix()
{
    return ".qpb";
}

const char *CommonTemplates::EnumClassSuffix()
{
    return "Gadget";
}

const char *CommonTemplates::QtProtobufNamespace()
{
    return "QtProtobuf";
}
const char *CommonTemplates::QtProtobufNestedNamespace()
{
    return "_QtProtobufNested";
}

const char *CommonTemplates::DataClassName()
{
    return "_QtProtobufData";
}

const char *CommonTemplates::QtProtobufFieldEnum()
{
    return "QtProtobufFieldEnum";
}
const char *CommonTemplates::FieldEnumTemplate()
{
    return "enum class QtProtobufFieldEnum {\n";
}
const char *CommonTemplates::FieldNumberTemplate()
{
    return "$property_name_cap$ProtoFieldNumber = $number$,\n";
}

const char *CommonTemplates::ExportMacroTemplate()
{
    return "#if defined(QT_SHARED) || !defined(QT_STATIC)\n"
           "#  if defined(QT_BUILD_$export_macro$_LIB)\n"
           "#    define QPB_$export_macro$_EXPORT Q_DECL_EXPORT\n"
           "#  else\n"
           "#    define QPB_$export_macro$_EXPORT Q_DECL_IMPORT\n"
           "#  endif\n"
           "#else\n"
           "#  define QPB_$export_macro$_EXPORT\n"
           "#endif\n";
}

const char *CommonTemplates::MocIncludeTemplate()
{
    return "#include \"$source_file$\"\n";
}
