/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#include "nopackage.qpb.h"
#include <QtProtobuf/qprotobufregistration.h>
#include <cmath>

static QtProtobuf::ProtoTypeRegistrar ProtoTypeRegistrarTestEnumGadget(TestEnumGadget::registerTypes);
void TestEnumGadget::registerTypes()
{
    qRegisterMetaType<TestEnum>();
    qRegisterMetaType<::TestEnumGadget::TestEnum>();
    qRegisterProtobufEnumType<::TestEnumGadget::TestEnum>();
}


class EmptyMessage_QtProtobufData : public QSharedData
{
public:
    EmptyMessage_QtProtobufData()
        : QSharedData()
    {
    }

    EmptyMessage_QtProtobufData(const EmptyMessage_QtProtobufData &other)
        : QSharedData(other)
    {
    }

};

EmptyMessage::~EmptyMessage() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 1> qt_protobuf_EmptyMessage_uint_data;
    const char qt_protobuf_EmptyMessage_char_data[14];
} qt_protobuf_EmptyMessage_metadata {
    // data
    {
        0, /* = version */
        0, /* = num fields */
        1, /* = field number offset */
        1, /* = property index offset */
        1, /* = field flags offset */
        12, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        13, /* = end-of-string-marker */
        // Field numbers:
        // Property indices:
        // Field flags:
    },
    // char_data
    /* metadata char_data: */
    "EmptyMessage\0" /* = full message name */
    /* field char_data: */
    ""
};

const QtProtobufPrivate::QProtobufPropertyOrdering EmptyMessage::staticPropertyOrdering = {
    &qt_protobuf_EmptyMessage_metadata.data
};

void EmptyMessage::registerTypes()
{
    qRegisterMetaType<EmptyMessage>();
    qRegisterMetaType<EmptyMessageRepeated>();
}

EmptyMessage::EmptyMessage()
    : QProtobufMessage(&EmptyMessage::staticMetaObject, &EmptyMessage::staticPropertyOrdering),
      dptr(new EmptyMessage_QtProtobufData)
{
}

EmptyMessage::EmptyMessage(const EmptyMessage &other)
    : QProtobufMessage(other),
      dptr(other.dptr)
{
}
EmptyMessage &EmptyMessage::operator =(const EmptyMessage &other)
{
    QProtobufMessage::operator=(other);
    dptr = other.dptr;
    return *this;
}
EmptyMessage::EmptyMessage(EmptyMessage &&other) noexcept
    : QProtobufMessage(std::move(other)),
      dptr(std::move(other.dptr))
{
}
EmptyMessage &EmptyMessage::operator =(EmptyMessage &&other) noexcept
{
    QProtobufMessage::operator=(std::move(other));
    dptr.swap(other.dptr);
    return *this;
}
bool EmptyMessage::operator ==(const EmptyMessage &other) const
{
    return QProtobufMessage::isEqual(*this, other);
}

bool EmptyMessage::operator !=(const EmptyMessage &other) const
{
    return !this->operator ==(other);
}


class SimpleIntMessage_QtProtobufData : public QSharedData
{
public:
    SimpleIntMessage_QtProtobufData()
        : QSharedData(),
          m_testFieldInt(0)
    {
    }

    SimpleIntMessage_QtProtobufData(const SimpleIntMessage_QtProtobufData &other)
        : QSharedData(other),
          m_testFieldInt(other.m_testFieldInt)
    {
    }

    QtProtobuf::int32 m_testFieldInt;
};

SimpleIntMessage::~SimpleIntMessage() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_SimpleIntMessage_uint_data;
    const char qt_protobuf_SimpleIntMessage_char_data[31];
} qt_protobuf_SimpleIntMessage_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        16, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        17, /* = testFieldInt */
        30, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testFieldInt */
        // Property indices:
        0, /* = testFieldInt */
        // Field flags:
        QtProtobufPrivate::NoFlags, /* = testFieldInt */
    },
    // char_data
    /* metadata char_data: */
    "SimpleIntMessage\0" /* = full message name */
    /* field char_data: */
    "testFieldInt\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering SimpleIntMessage::staticPropertyOrdering = {
    &qt_protobuf_SimpleIntMessage_metadata.data
};

void SimpleIntMessage::registerTypes()
{
    qRegisterMetaType<SimpleIntMessage>();
    qRegisterMetaType<SimpleIntMessageRepeated>();
}

SimpleIntMessage::SimpleIntMessage()
    : QProtobufMessage(&SimpleIntMessage::staticMetaObject, &SimpleIntMessage::staticPropertyOrdering),
      dptr(new SimpleIntMessage_QtProtobufData)
{
}

SimpleIntMessage::SimpleIntMessage(const SimpleIntMessage &other)
    : QProtobufMessage(other),
      dptr(other.dptr)
{
}
SimpleIntMessage &SimpleIntMessage::operator =(const SimpleIntMessage &other)
{
    QProtobufMessage::operator=(other);
    dptr = other.dptr;
    return *this;
}
SimpleIntMessage::SimpleIntMessage(SimpleIntMessage &&other) noexcept
    : QProtobufMessage(std::move(other)),
      dptr(std::move(other.dptr))
{
}
SimpleIntMessage &SimpleIntMessage::operator =(SimpleIntMessage &&other) noexcept
{
    QProtobufMessage::operator=(std::move(other));
    dptr.swap(other.dptr);
    return *this;
}
bool SimpleIntMessage::operator ==(const SimpleIntMessage &other) const
{
    return QProtobufMessage::isEqual(*this, other)
        && dptr->m_testFieldInt == other.dptr->m_testFieldInt;
}

bool SimpleIntMessage::operator !=(const SimpleIntMessage &other) const
{
    return !this->operator ==(other);
}

QtProtobuf::int32 SimpleIntMessage::testFieldInt() const
{
    return dptr->m_testFieldInt;
}

void SimpleIntMessage::setTestFieldInt(const QtProtobuf::int32 &testFieldInt)
{
    if (dptr->m_testFieldInt != testFieldInt) {
        dptr.detach();
        dptr->m_testFieldInt = testFieldInt;
    }
}


class NoPackageExternalMessage_QtProtobufData : public QSharedData
{
public:
    NoPackageExternalMessage_QtProtobufData()
        : QSharedData(),
          m_testField(nullptr)
    {
    }

    NoPackageExternalMessage_QtProtobufData(const NoPackageExternalMessage_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField
                                               ? new SimpleIntMessageExt(*other.m_testField)
                                               : nullptr)
    {
    }

    QtProtobufPrivate::QProtobufLazyMessagePointer<SimpleIntMessageExt> m_testField;
};

NoPackageExternalMessage::~NoPackageExternalMessage() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_NoPackageExternalMessage_uint_data;
    const char qt_protobuf_NoPackageExternalMessage_char_data[36];
} qt_protobuf_NoPackageExternalMessage_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        24, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        25, /* = testField */
        35, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        QtProtobufPrivate::ExplicitPresence, /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "NoPackageExternalMessage\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering NoPackageExternalMessage::staticPropertyOrdering = {
    &qt_protobuf_NoPackageExternalMessage_metadata.data
};

void NoPackageExternalMessage::registerTypes()
{
    qRegisterMetaType<NoPackageExternalMessage>();
    qRegisterMetaType<NoPackageExternalMessageRepeated>();
}

NoPackageExternalMessage::NoPackageExternalMessage()
    : QProtobufMessage(&NoPackageExternalMessage::staticMetaObject, &NoPackageExternalMessage::staticPropertyOrdering),
      dptr(new NoPackageExternalMessage_QtProtobufData)
{
}

NoPackageExternalMessage::NoPackageExternalMessage(const NoPackageExternalMessage &other)
    : QProtobufMessage(other),
      dptr(other.dptr)
{
}
NoPackageExternalMessage &NoPackageExternalMessage::operator =(const NoPackageExternalMessage &other)
{
    QProtobufMessage::operator=(other);
    dptr = other.dptr;
    return *this;
}
NoPackageExternalMessage::NoPackageExternalMessage(NoPackageExternalMessage &&other) noexcept
    : QProtobufMessage(std::move(other)),
      dptr(std::move(other.dptr))
{
}
NoPackageExternalMessage &NoPackageExternalMessage::operator =(NoPackageExternalMessage &&other) noexcept
{
    QProtobufMessage::operator=(std::move(other));
    dptr.swap(other.dptr);
    return *this;
}
bool NoPackageExternalMessage::operator ==(const NoPackageExternalMessage &other) const
{
    return QProtobufMessage::isEqual(*this, other)
        && (dptr->m_testField == other.dptr->m_testField
            || *dptr->m_testField == *other.dptr->m_testField);
}

bool NoPackageExternalMessage::operator !=(const NoPackageExternalMessage &other) const
{
    return !this->operator ==(other);
}

SimpleIntMessageExt *NoPackageExternalMessage::testField_p()
{
    if (!dptr->m_testField)
        dptr.detach();
    return dptr->m_testField.get();
}

bool NoPackageExternalMessage::hasTestField() const
{
    return dptr->m_testField.operator bool();
}

SimpleIntMessageExt &NoPackageExternalMessage::testField() const
{
    return *dptr->m_testField;
}

void NoPackageExternalMessage::clearTestField()
{
    if (dptr->m_testField) {
        dptr.detach();
        dptr->m_testField.reset();
    }
}

void NoPackageExternalMessage::setTestField_p(SimpleIntMessageExt *testField)
{
    if (dptr->m_testField.get() != testField) {
        dptr.detach();
        dptr->m_testField.reset(testField);
    }
}

void NoPackageExternalMessage::setTestField(const SimpleIntMessageExt &testField)
{
    if (*dptr->m_testField != testField) {
        dptr.detach();
        *dptr->m_testField = testField;
    }
}


class NoPackageMessage_QtProtobufData : public QSharedData
{
public:
    NoPackageMessage_QtProtobufData()
        : QSharedData(),
          m_testField(nullptr)
    {
    }

    NoPackageMessage_QtProtobufData(const NoPackageMessage_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField
                                               ? new SimpleIntMessage(*other.m_testField)
                                               : nullptr)
    {
    }

    QtProtobufPrivate::QProtobufLazyMessagePointer<SimpleIntMessage> m_testField;
};

NoPackageMessage::~NoPackageMessage() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_NoPackageMessage_uint_data;
    const char qt_protobuf_NoPackageMessage_char_data[28];
} qt_protobuf_NoPackageMessage_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        16, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        17, /* = testField */
        27, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        QtProtobufPrivate::ExplicitPresence, /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "NoPackageMessage\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering NoPackageMessage::staticPropertyOrdering = {
    &qt_protobuf_NoPackageMessage_metadata.data
};

void NoPackageMessage::registerTypes()
{
    qRegisterMetaType<NoPackageMessage>();
    qRegisterMetaType<NoPackageMessageRepeated>();
}

NoPackageMessage::NoPackageMessage()
    : QProtobufMessage(&NoPackageMessage::staticMetaObject, &NoPackageMessage::staticPropertyOrdering),
      dptr(new NoPackageMessage_QtProtobufData)
{
}

NoPackageMessage::NoPackageMessage(const NoPackageMessage &other)
    : QProtobufMessage(other),
      dptr(other.dptr)
{
}
NoPackageMessage &NoPackageMessage::operator =(const NoPackageMessage &other)
{
    QProtobufMessage::operator=(other);
    dptr = other.dptr;
    return *this;
}
NoPackageMessage::NoPackageMessage(NoPackageMessage &&other) noexcept
    : QProtobufMessage(std::move(other)),
      dptr(std::move(other.dptr))
{
}
NoPackageMessage &NoPackageMessage::operator =(NoPackageMessage &&other) noexcept
{
    QProtobufMessage::operator=(std::move(other));
    dptr.swap(other.dptr);
    return *this;
}
bool NoPackageMessage::operator ==(const NoPackageMessage &other) const
{
    return QProtobufMessage::isEqual(*this, other)
        && (dptr->m_testField == other.dptr->m_testField
            || *dptr->m_testField == *other.dptr->m_testField);
}

bool NoPackageMessage::operator !=(const NoPackageMessage &other) const
{
    return !this->operator ==(other);
}

SimpleIntMessage *NoPackageMessage::testField_p()
{
    if (!dptr->m_testField)
        dptr.detach();
    return dptr->m_testField.get();
}

bool NoPackageMessage::hasTestField() const
{
    return dptr->m_testField.operator bool();
}

SimpleIntMessage &NoPackageMessage::testField() const
{
    return *dptr->m_testField;
}

void NoPackageMessage::clearTestField()
{
    if (dptr->m_testField) {
        dptr.detach();
        dptr->m_testField.reset();
    }
}

void NoPackageMessage::setTestField_p(SimpleIntMessage *testField)
{
    if (dptr->m_testField.get() != testField) {
        dptr.detach();
        dptr->m_testField.reset(testField);
    }
}

void NoPackageMessage::setTestField(const SimpleIntMessage &testField)
{
    if (*dptr->m_testField != testField) {
        dptr.detach();
        *dptr->m_testField = testField;
    }
}


#include "moc_nopackage.qpb.cpp"
