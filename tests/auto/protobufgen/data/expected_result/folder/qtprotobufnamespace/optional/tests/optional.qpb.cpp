/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#include "qtprotobufnamespace/optional/tests/optional.qpb.h"
#include <QtProtobuf/qprotobufserializer.h>
#include <cmath>

namespace qtprotobufnamespace::optional::tests {

class TestStringMessage_QtProtobufData : public QSharedData
{
public:
    TestStringMessage_QtProtobufData()
        : QSharedData()
    {
    }

    TestStringMessage_QtProtobufData(const TestStringMessage_QtProtobufData &other)
        : QSharedData(other),
          m_stringField(other.m_stringField)
    {
    }

    QString m_stringField;
};

TestStringMessage::~TestStringMessage() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_TestStringMessage_uint_data;
    const char qt_protobuf_TestStringMessage_char_data[66];
} qt_protobuf_TestStringMessage_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        52, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        53, /* = stringField */
        65, /* = end-of-string-marker */
        // Field numbers:
        2, /* = stringField */
        // Property indices:
        0, /* = stringField */
        // Field flags:
        QtProtobufPrivate::NoFlags, /* = stringField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.optional.tests.TestStringMessage\0" /* = full message name */
    /* field char_data: */
    "stringField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering TestStringMessage::staticPropertyOrdering = {
    &qt_protobuf_TestStringMessage_metadata.data
};

void TestStringMessage::registerTypes()
{
    qRegisterMetaType<TestStringMessage>();
    qRegisterMetaType<TestStringMessageRepeated>();
}

TestStringMessage::TestStringMessage()
    : QProtobufMessage(&TestStringMessage::staticMetaObject, &TestStringMessage::staticPropertyOrdering),
      dptr(new TestStringMessage_QtProtobufData)
{
}

TestStringMessage::TestStringMessage(const TestStringMessage &other)
    : QProtobufMessage(other),
      dptr(other.dptr)
{
}
TestStringMessage &TestStringMessage::operator =(const TestStringMessage &other)
{
    QProtobufMessage::operator=(other);
    dptr = other.dptr;
    return *this;
}
TestStringMessage::TestStringMessage(TestStringMessage &&other) noexcept
    : QProtobufMessage(std::move(other)),
      dptr(std::move(other.dptr))
{
}
TestStringMessage &TestStringMessage::operator =(TestStringMessage &&other) noexcept
{
    QProtobufMessage::operator=(std::move(other));
    dptr.swap(other.dptr);
    return *this;
}
bool TestStringMessage::operator ==(const TestStringMessage &other) const
{
    return QProtobufMessage::isEqual(*this, other)
        && dptr->m_stringField == other.dptr->m_stringField;
}

bool TestStringMessage::operator !=(const TestStringMessage &other) const
{
    return !this->operator ==(other);
}

QString TestStringMessage::stringField() const
{
    return dptr->m_stringField;
}

void TestStringMessage::setStringField(const QString &stringField)
{
    if (dptr->m_stringField != stringField) {
        dptr.detach();
        dptr->m_stringField = stringField;
    }
}


class OptionalMessage_QtProtobufData : public QSharedData
{
public:
    OptionalMessage_QtProtobufData()
        : QSharedData(),
          m_testField(0),
          m_testFieldBool(false),
          m_testFieldMessage(nullptr),
          m_testFieldMessageOpt(nullptr)
    {
    }

    OptionalMessage_QtProtobufData(const OptionalMessage_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField),
          m_testFieldBool(other.m_testFieldBool),
          m_testFieldBytes(other.m_testFieldBytes),
          m_testFieldString(other.m_testFieldString),
          m_testFieldMessage(other.m_testFieldMessage
                                               ? new TestStringMessage(*other.m_testFieldMessage)
                                               : nullptr),
          m_testFieldMessageOpt(other.m_testFieldMessageOpt
                                               ? new TestStringMessage(*other.m_testFieldMessageOpt)
                                               : nullptr)
    {
    }

    QtProtobuf::sint32 m_testField;
    std::optional<QtProtobuf::sint32> m_testFieldOpt;
    bool m_testFieldBool;
    std::optional<bool> m_testFieldBoolOpt;
    QByteArray m_testFieldBytes;
    std::optional<QByteArray> m_testFieldBytesOpt;
    QString m_testFieldString;
    std::optional<QString> m_testFieldStringOpt;
    QtProtobufPrivate::QProtobufLazyMessagePointer<TestStringMessage> m_testFieldMessage;
    QtProtobufPrivate::QProtobufLazyMessagePointer<TestStringMessage> m_testFieldMessageOpt;
};

OptionalMessage::~OptionalMessage() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 41> qt_protobuf_OptionalMessage_uint_data;
    const char qt_protobuf_OptionalMessage_char_data[211];
} qt_protobuf_OptionalMessage_metadata {
    // data
    {
        0, /* = version */
        10, /* = num fields */
        11, /* = field number offset */
        21, /* = property index offset */
        31, /* = field flags offset */
        50, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        51, /* = testField */
        61, /* = testFieldOpt */
        74, /* = testFieldBool */
        88, /* = testFieldBoolOpt */
        105, /* = testFieldBytes */
        120, /* = testFieldBytesOpt */
        138, /* = testFieldString */
        154, /* = testFieldStringOpt */
        173, /* = testFieldMessage */
        190, /* = testFieldMessageOpt */
        210, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        2, /* = testFieldOpt */
        3, /* = testFieldBool */
        4, /* = testFieldBoolOpt */
        5, /* = testFieldBytes */
        6, /* = testFieldBytesOpt */
        7, /* = testFieldString */
        8, /* = testFieldStringOpt */
        9, /* = testFieldMessage */
        10, /* = testFieldMessageOpt */
        // Property indices:
        0, /* = testField */
        1, /* = testFieldOpt */
        3, /* = testFieldBool */
        4, /* = testFieldBoolOpt */
        6, /* = testFieldBytes */
        7, /* = testFieldBytesOpt */
        9, /* = testFieldString */
        10, /* = testFieldStringOpt */
        12, /* = testFieldMessage */
        13, /* = testFieldMessageOpt */
        // Field flags:
        QtProtobufPrivate::NoFlags, /* = testField */
        QtProtobufPrivate::Optional, /* = testFieldOpt */
        QtProtobufPrivate::NoFlags, /* = testFieldBool */
        QtProtobufPrivate::Optional, /* = testFieldBoolOpt */
        QtProtobufPrivate::NoFlags, /* = testFieldBytes */
        QtProtobufPrivate::Optional, /* = testFieldBytesOpt */
        QtProtobufPrivate::NoFlags, /* = testFieldString */
        QtProtobufPrivate::Optional, /* = testFieldStringOpt */
        QtProtobufPrivate::NoFlags, /* = testFieldMessage */
        QtProtobufPrivate::NoFlags, /* = testFieldMessageOpt */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.optional.tests.OptionalMessage\0" /* = full message name */
    /* field char_data: */
    "testField\0testFieldOpt\0testFieldBool\0testFieldBoolOpt\0testFieldBytes\0"
    "testFieldBytesOpt\0testFieldString\0testFieldStringOpt\0testFieldMessage\0testFieldMessageOpt\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering OptionalMessage::staticPropertyOrdering = {
    &qt_protobuf_OptionalMessage_metadata.data
};

void OptionalMessage::registerTypes()
{
    qRegisterMetaType<OptionalMessage>();
    qRegisterMetaType<OptionalMessageRepeated>();
}

OptionalMessage::OptionalMessage()
    : QProtobufMessage(&OptionalMessage::staticMetaObject, &OptionalMessage::staticPropertyOrdering),
      dptr(new OptionalMessage_QtProtobufData)
{
}

OptionalMessage::OptionalMessage(const OptionalMessage &other)
    : QProtobufMessage(other),
      dptr(other.dptr)
{
}
OptionalMessage &OptionalMessage::operator =(const OptionalMessage &other)
{
    QProtobufMessage::operator=(other);
    dptr = other.dptr;
    return *this;
}
OptionalMessage::OptionalMessage(OptionalMessage &&other) noexcept
    : QProtobufMessage(std::move(other)),
      dptr(std::move(other.dptr))
{
}
OptionalMessage &OptionalMessage::operator =(OptionalMessage &&other) noexcept
{
    QProtobufMessage::operator=(std::move(other));
    dptr.swap(other.dptr);
    return *this;
}
bool OptionalMessage::operator ==(const OptionalMessage &other) const
{
    return QProtobufMessage::isEqual(*this, other)
        && dptr->m_testField == other.dptr->m_testField
        && dptr->m_testFieldBool == other.dptr->m_testFieldBool
        && dptr->m_testFieldBytes == other.dptr->m_testFieldBytes
        && dptr->m_testFieldString == other.dptr->m_testFieldString
        && (dptr->m_testFieldMessage == other.dptr->m_testFieldMessage
            || *dptr->m_testFieldMessage == *other.dptr->m_testFieldMessage);
}

bool OptionalMessage::operator !=(const OptionalMessage &other) const
{
    return !this->operator ==(other);
}

QtProtobuf::sint32 OptionalMessage::testField() const
{
    return dptr->m_testField;
}

QtProtobuf::sint32 OptionalMessage::testFieldOpt_p() const
{
    return dptr->m_testFieldOpt ?
        dptr->m_testFieldOpt.value() : QtProtobuf::sint32();
}

bool OptionalMessage::hasTestFieldOpt() const
{
    return dptr->m_testFieldOpt.has_value();
}
QtProtobuf::sint32 OptionalMessage::testFieldOpt() const
{
    Q_ASSERT(dptr->m_testFieldOpt.has_value());
    return dptr->m_testFieldOpt.value();
}

bool OptionalMessage::testFieldBool() const
{
    return dptr->m_testFieldBool;
}

bool OptionalMessage::testFieldBoolOpt_p() const
{
    return dptr->m_testFieldBoolOpt ?
        dptr->m_testFieldBoolOpt.value() : bool();
}

bool OptionalMessage::hasTestFieldBoolOpt() const
{
    return dptr->m_testFieldBoolOpt.has_value();
}
bool OptionalMessage::testFieldBoolOpt() const
{
    Q_ASSERT(dptr->m_testFieldBoolOpt.has_value());
    return dptr->m_testFieldBoolOpt.value();
}

QByteArray OptionalMessage::testFieldBytes() const
{
    return dptr->m_testFieldBytes;
}

QByteArray OptionalMessage::testFieldBytesOpt_p() const
{
    return dptr->m_testFieldBytesOpt ?
        dptr->m_testFieldBytesOpt.value() : QByteArray();
}

bool OptionalMessage::hasTestFieldBytesOpt() const
{
    return dptr->m_testFieldBytesOpt.has_value();
}
QByteArray OptionalMessage::testFieldBytesOpt() const
{
    Q_ASSERT(dptr->m_testFieldBytesOpt.has_value());
    return dptr->m_testFieldBytesOpt.value();
}

QString OptionalMessage::testFieldString() const
{
    return dptr->m_testFieldString;
}

QString OptionalMessage::testFieldStringOpt_p() const
{
    return dptr->m_testFieldStringOpt ?
        dptr->m_testFieldStringOpt.value() : QString();
}

bool OptionalMessage::hasTestFieldStringOpt() const
{
    return dptr->m_testFieldStringOpt.has_value();
}
QString OptionalMessage::testFieldStringOpt() const
{
    Q_ASSERT(dptr->m_testFieldStringOpt.has_value());
    return dptr->m_testFieldStringOpt.value();
}

TestStringMessage *OptionalMessage::testFieldMessage_p() const
{
    return dptr->m_testFieldMessage ? dptr->m_testFieldMessage.get() : nullptr;
}

bool OptionalMessage::hasTestFieldMessage() const
{
    return dptr->m_testFieldMessage.operator bool();
}

TestStringMessage &OptionalMessage::testFieldMessage() const
{
    return *dptr->m_testFieldMessage;
}

void OptionalMessage::clearTestFieldMessage()
{
    if (dptr->m_testFieldMessage) {
        dptr.detach();
        dptr->m_testFieldMessage.reset();
    }
}

TestStringMessage *OptionalMessage::testFieldMessageOpt_p() const
{
    return dptr->m_testFieldMessageOpt ? dptr->m_testFieldMessageOpt.get() : nullptr;
}

bool OptionalMessage::hasTestFieldMessageOpt() const
{
    return dptr->m_testFieldMessageOpt.operator bool();
}

TestStringMessage &OptionalMessage::testFieldMessageOpt() const
{
    return *dptr->m_testFieldMessageOpt;
}

void OptionalMessage::clearTestFieldMessageOpt()
{
    if (dptr->m_testFieldMessageOpt) {
        dptr.detach();
        dptr->m_testFieldMessageOpt.reset();
    }
}

void OptionalMessage::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}

void OptionalMessage::setTestFieldOpt(const QtProtobuf::sint32 &testFieldOpt)
{
    if (!dptr->m_testFieldOpt || dptr->m_testFieldOpt.value() != testFieldOpt) {
        dptr.detach();
        dptr->m_testFieldOpt = testFieldOpt;
    }
}

void OptionalMessage::setTestFieldOpt_p(QtProtobuf::sint32 testFieldOpt)
{
    if (!dptr->m_testFieldOpt || dptr->m_testFieldOpt != testFieldOpt) {
        dptr.detach();
        dptr->m_testFieldOpt = testFieldOpt;
    }
}

void OptionalMessage::clearTestFieldOpt()
{
    if (dptr->m_testFieldOpt.has_value()) {
        dptr.detach();
        dptr->m_testFieldOpt.reset();
    }}
void OptionalMessage::setTestFieldBool(const bool &testFieldBool)
{
    if (dptr->m_testFieldBool != testFieldBool) {
        dptr.detach();
        dptr->m_testFieldBool = testFieldBool;
    }
}

void OptionalMessage::setTestFieldBoolOpt(const bool &testFieldBoolOpt)
{
    if (!dptr->m_testFieldBoolOpt || dptr->m_testFieldBoolOpt.value() != testFieldBoolOpt) {
        dptr.detach();
        dptr->m_testFieldBoolOpt = testFieldBoolOpt;
    }
}

void OptionalMessage::setTestFieldBoolOpt_p(bool testFieldBoolOpt)
{
    if (!dptr->m_testFieldBoolOpt || dptr->m_testFieldBoolOpt != testFieldBoolOpt) {
        dptr.detach();
        dptr->m_testFieldBoolOpt = testFieldBoolOpt;
    }
}

void OptionalMessage::clearTestFieldBoolOpt()
{
    if (dptr->m_testFieldBoolOpt.has_value()) {
        dptr.detach();
        dptr->m_testFieldBoolOpt.reset();
    }}
void OptionalMessage::setTestFieldBytes(const QByteArray &testFieldBytes)
{
    if (dptr->m_testFieldBytes != testFieldBytes) {
        dptr.detach();
        dptr->m_testFieldBytes = testFieldBytes;
    }
}

void OptionalMessage::setTestFieldBytesOpt(const QByteArray &testFieldBytesOpt)
{
    if (!dptr->m_testFieldBytesOpt || dptr->m_testFieldBytesOpt.value() != testFieldBytesOpt) {
        dptr.detach();
        dptr->m_testFieldBytesOpt = testFieldBytesOpt;
    }
}

void OptionalMessage::setTestFieldBytesOpt_p(QByteArray testFieldBytesOpt)
{
    if (!dptr->m_testFieldBytesOpt || dptr->m_testFieldBytesOpt != testFieldBytesOpt) {
        dptr.detach();
        dptr->m_testFieldBytesOpt = testFieldBytesOpt;
    }
}

void OptionalMessage::clearTestFieldBytesOpt()
{
    if (dptr->m_testFieldBytesOpt.has_value()) {
        dptr.detach();
        dptr->m_testFieldBytesOpt.reset();
    }}
void OptionalMessage::setTestFieldString(const QString &testFieldString)
{
    if (dptr->m_testFieldString != testFieldString) {
        dptr.detach();
        dptr->m_testFieldString = testFieldString;
    }
}

void OptionalMessage::setTestFieldStringOpt(const QString &testFieldStringOpt)
{
    if (!dptr->m_testFieldStringOpt || dptr->m_testFieldStringOpt.value() != testFieldStringOpt) {
        dptr.detach();
        dptr->m_testFieldStringOpt = testFieldStringOpt;
    }
}

void OptionalMessage::setTestFieldStringOpt_p(QString testFieldStringOpt)
{
    if (!dptr->m_testFieldStringOpt || dptr->m_testFieldStringOpt != testFieldStringOpt) {
        dptr.detach();
        dptr->m_testFieldStringOpt = testFieldStringOpt;
    }
}

void OptionalMessage::clearTestFieldStringOpt()
{
    if (dptr->m_testFieldStringOpt.has_value()) {
        dptr.detach();
        dptr->m_testFieldStringOpt.reset();
    }}
void OptionalMessage::setTestFieldMessage_p(TestStringMessage *testFieldMessage)
{
    if (dptr->m_testFieldMessage.get() != testFieldMessage) {
        dptr.detach();
        dptr->m_testFieldMessage.reset(testFieldMessage);
    }
}

void OptionalMessage::setTestFieldMessage(const TestStringMessage &testFieldMessage)
{
    if (*dptr->m_testFieldMessage != testFieldMessage) {
        dptr.detach();
        *dptr->m_testFieldMessage = testFieldMessage;
    }
}

void OptionalMessage::setTestFieldMessageOpt_p(TestStringMessage *testFieldMessageOpt)
{
    if (dptr->m_testFieldMessageOpt.get() != testFieldMessageOpt) {
        dptr.detach();
        dptr->m_testFieldMessageOpt.reset(testFieldMessageOpt);
    }
}

void OptionalMessage::setTestFieldMessageOpt(const TestStringMessage &testFieldMessageOpt)
{
    if (*dptr->m_testFieldMessageOpt != testFieldMessageOpt) {
        dptr.detach();
        *dptr->m_testFieldMessageOpt = testFieldMessageOpt;
    }
}

} // namespace qtprotobufnamespace::optional::tests

#include "moc_optional.qpb.cpp"
