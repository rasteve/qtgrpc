/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */


#include "annotation.qpb.h"

#include <QtProtobuf/qprotobufregistration.h>

#include <cmath>

namespace qtprotobufnamespace::tests {

class AnnotatedMessage1_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage1_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage1_QtProtobufData(const AnnotatedMessage1_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage1::~AnnotatedMessage1() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage1_uint_data;
    const char qt_protobuf_AnnotatedMessage1_char_data[55];
} qt_protobuf_AnnotatedMessage1_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage1\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage1::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage1_metadata.data
};

void AnnotatedMessage1::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage1>();
    qRegisterMetaType<AnnotatedMessage1Repeated>();
}

AnnotatedMessage1::AnnotatedMessage1()
    : QProtobufMessage(&AnnotatedMessage1::staticMetaObject, &AnnotatedMessage1::staticPropertyOrdering),
      dptr(new AnnotatedMessage1_QtProtobufData)
{
}

AnnotatedMessage1::AnnotatedMessage1(const AnnotatedMessage1 &other)
    = default;
AnnotatedMessage1 &AnnotatedMessage1::operator =(const AnnotatedMessage1 &other)
{
    AnnotatedMessage1 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage1::AnnotatedMessage1(AnnotatedMessage1 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage1 &lhs, const AnnotatedMessage1 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage1::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage1::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage2_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage2_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage2_QtProtobufData(const AnnotatedMessage2_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage2::~AnnotatedMessage2() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage2_uint_data;
    const char qt_protobuf_AnnotatedMessage2_char_data[55];
} qt_protobuf_AnnotatedMessage2_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage2\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage2::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage2_metadata.data
};

void AnnotatedMessage2::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage2>();
    qRegisterMetaType<AnnotatedMessage2Repeated>();
}

AnnotatedMessage2::AnnotatedMessage2()
    : QProtobufMessage(&AnnotatedMessage2::staticMetaObject, &AnnotatedMessage2::staticPropertyOrdering),
      dptr(new AnnotatedMessage2_QtProtobufData)
{
}

AnnotatedMessage2::AnnotatedMessage2(const AnnotatedMessage2 &other)
    = default;
AnnotatedMessage2 &AnnotatedMessage2::operator =(const AnnotatedMessage2 &other)
{
    AnnotatedMessage2 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage2::AnnotatedMessage2(AnnotatedMessage2 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage2 &lhs, const AnnotatedMessage2 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage2::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage2::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage3_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage3_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage3_QtProtobufData(const AnnotatedMessage3_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage3::~AnnotatedMessage3() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage3_uint_data;
    const char qt_protobuf_AnnotatedMessage3_char_data[55];
} qt_protobuf_AnnotatedMessage3_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage3\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage3::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage3_metadata.data
};

void AnnotatedMessage3::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage3>();
    qRegisterMetaType<AnnotatedMessage3Repeated>();
}

AnnotatedMessage3::AnnotatedMessage3()
    : QProtobufMessage(&AnnotatedMessage3::staticMetaObject, &AnnotatedMessage3::staticPropertyOrdering),
      dptr(new AnnotatedMessage3_QtProtobufData)
{
}

AnnotatedMessage3::AnnotatedMessage3(const AnnotatedMessage3 &other)
    = default;
AnnotatedMessage3 &AnnotatedMessage3::operator =(const AnnotatedMessage3 &other)
{
    AnnotatedMessage3 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage3::AnnotatedMessage3(AnnotatedMessage3 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage3 &lhs, const AnnotatedMessage3 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage3::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage3::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage4_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage4_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage4_QtProtobufData(const AnnotatedMessage4_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage4::~AnnotatedMessage4() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage4_uint_data;
    const char qt_protobuf_AnnotatedMessage4_char_data[55];
} qt_protobuf_AnnotatedMessage4_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage4\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage4::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage4_metadata.data
};

void AnnotatedMessage4::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage4>();
    qRegisterMetaType<AnnotatedMessage4Repeated>();
}

AnnotatedMessage4::AnnotatedMessage4()
    : QProtobufMessage(&AnnotatedMessage4::staticMetaObject, &AnnotatedMessage4::staticPropertyOrdering),
      dptr(new AnnotatedMessage4_QtProtobufData)
{
}

AnnotatedMessage4::AnnotatedMessage4(const AnnotatedMessage4 &other)
    = default;
AnnotatedMessage4 &AnnotatedMessage4::operator =(const AnnotatedMessage4 &other)
{
    AnnotatedMessage4 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage4::AnnotatedMessage4(AnnotatedMessage4 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage4 &lhs, const AnnotatedMessage4 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage4::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage4::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage5_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage5_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage5_QtProtobufData(const AnnotatedMessage5_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage5::~AnnotatedMessage5() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage5_uint_data;
    const char qt_protobuf_AnnotatedMessage5_char_data[55];
} qt_protobuf_AnnotatedMessage5_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage5\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage5::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage5_metadata.data
};

void AnnotatedMessage5::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage5>();
    qRegisterMetaType<AnnotatedMessage5Repeated>();
}

AnnotatedMessage5::AnnotatedMessage5()
    : QProtobufMessage(&AnnotatedMessage5::staticMetaObject, &AnnotatedMessage5::staticPropertyOrdering),
      dptr(new AnnotatedMessage5_QtProtobufData)
{
}

AnnotatedMessage5::AnnotatedMessage5(const AnnotatedMessage5 &other)
    = default;
AnnotatedMessage5 &AnnotatedMessage5::operator =(const AnnotatedMessage5 &other)
{
    AnnotatedMessage5 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage5::AnnotatedMessage5(AnnotatedMessage5 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage5 &lhs, const AnnotatedMessage5 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage5::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage5::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage6_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage6_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage6_QtProtobufData(const AnnotatedMessage6_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage6::~AnnotatedMessage6() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage6_uint_data;
    const char qt_protobuf_AnnotatedMessage6_char_data[55];
} qt_protobuf_AnnotatedMessage6_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage6\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage6::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage6_metadata.data
};

void AnnotatedMessage6::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage6>();
    qRegisterMetaType<AnnotatedMessage6Repeated>();
}

AnnotatedMessage6::AnnotatedMessage6()
    : QProtobufMessage(&AnnotatedMessage6::staticMetaObject, &AnnotatedMessage6::staticPropertyOrdering),
      dptr(new AnnotatedMessage6_QtProtobufData)
{
}

AnnotatedMessage6::AnnotatedMessage6(const AnnotatedMessage6 &other)
    = default;
AnnotatedMessage6 &AnnotatedMessage6::operator =(const AnnotatedMessage6 &other)
{
    AnnotatedMessage6 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage6::AnnotatedMessage6(AnnotatedMessage6 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage6 &lhs, const AnnotatedMessage6 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage6::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage6::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage7_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage7_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage7_QtProtobufData(const AnnotatedMessage7_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage7::~AnnotatedMessage7() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage7_uint_data;
    const char qt_protobuf_AnnotatedMessage7_char_data[55];
} qt_protobuf_AnnotatedMessage7_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage7\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage7::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage7_metadata.data
};

void AnnotatedMessage7::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage7>();
    qRegisterMetaType<AnnotatedMessage7Repeated>();
}

AnnotatedMessage7::AnnotatedMessage7()
    : QProtobufMessage(&AnnotatedMessage7::staticMetaObject, &AnnotatedMessage7::staticPropertyOrdering),
      dptr(new AnnotatedMessage7_QtProtobufData)
{
}

AnnotatedMessage7::AnnotatedMessage7(const AnnotatedMessage7 &other)
    = default;
AnnotatedMessage7 &AnnotatedMessage7::operator =(const AnnotatedMessage7 &other)
{
    AnnotatedMessage7 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage7::AnnotatedMessage7(AnnotatedMessage7 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage7 &lhs, const AnnotatedMessage7 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage7::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage7::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage8_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage8_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage8_QtProtobufData(const AnnotatedMessage8_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage8::~AnnotatedMessage8() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage8_uint_data;
    const char qt_protobuf_AnnotatedMessage8_char_data[55];
} qt_protobuf_AnnotatedMessage8_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage8\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage8::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage8_metadata.data
};

void AnnotatedMessage8::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage8>();
    qRegisterMetaType<AnnotatedMessage8Repeated>();
}

AnnotatedMessage8::AnnotatedMessage8()
    : QProtobufMessage(&AnnotatedMessage8::staticMetaObject, &AnnotatedMessage8::staticPropertyOrdering),
      dptr(new AnnotatedMessage8_QtProtobufData)
{
}

AnnotatedMessage8::AnnotatedMessage8(const AnnotatedMessage8 &other)
    = default;
AnnotatedMessage8 &AnnotatedMessage8::operator =(const AnnotatedMessage8 &other)
{
    AnnotatedMessage8 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage8::AnnotatedMessage8(AnnotatedMessage8 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage8 &lhs, const AnnotatedMessage8 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage8::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage8::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}


class AnnotatedMessage9_QtProtobufData : public QSharedData
{
public:
    AnnotatedMessage9_QtProtobufData()
        : QSharedData(),
          m_testField(0)
    {
    }

    AnnotatedMessage9_QtProtobufData(const AnnotatedMessage9_QtProtobufData &other)
        : QSharedData(other),
          m_testField(other.m_testField)
    {
    }

    QtProtobuf::sint32 m_testField;
};

AnnotatedMessage9::~AnnotatedMessage9() = default;

static constexpr struct {
    QtProtobufPrivate::QProtobufPropertyOrdering::Data data;
    const std::array<uint, 5> qt_protobuf_AnnotatedMessage9_uint_data;
    const char qt_protobuf_AnnotatedMessage9_char_data[55];
} qt_protobuf_AnnotatedMessage9_metadata {
    // data
    {
        0, /* = version */
        1, /* = num fields */
        2, /* = field number offset */
        3, /* = property index offset */
        4, /* = field flags offset */
        43, /* = message full name length */
    },
    // uint_data
    {
        // JSON name offsets:
        44, /* = testField */
        54, /* = end-of-string-marker */
        // Field numbers:
        1, /* = testField */
        // Property indices:
        0, /* = testField */
        // Field flags:
        uint(QtProtobufPrivate::FieldFlag::NoFlags), /* = testField */
    },
    // char_data
    /* metadata char_data: */
    "qtprotobufnamespace.tests.AnnotatedMessage9\0" /* = full message name */
    /* field char_data: */
    "testField\0"
};

const QtProtobufPrivate::QProtobufPropertyOrdering AnnotatedMessage9::staticPropertyOrdering = {
    &qt_protobuf_AnnotatedMessage9_metadata.data
};

void AnnotatedMessage9::registerTypes()
{
    qRegisterMetaType<AnnotatedMessage9>();
    qRegisterMetaType<AnnotatedMessage9Repeated>();
}

AnnotatedMessage9::AnnotatedMessage9()
    : QProtobufMessage(&AnnotatedMessage9::staticMetaObject, &AnnotatedMessage9::staticPropertyOrdering),
      dptr(new AnnotatedMessage9_QtProtobufData)
{
}

AnnotatedMessage9::AnnotatedMessage9(const AnnotatedMessage9 &other)
    = default;
AnnotatedMessage9 &AnnotatedMessage9::operator =(const AnnotatedMessage9 &other)
{
    AnnotatedMessage9 temp(other);
    swap(temp);
    return *this;
}
AnnotatedMessage9::AnnotatedMessage9(AnnotatedMessage9 &&other) noexcept
    = default;
bool comparesEqual(const AnnotatedMessage9 &lhs, const AnnotatedMessage9 &rhs) noexcept
{
    return operator ==(static_cast<const QProtobufMessage&>(lhs),
                       static_cast<const QProtobufMessage&>(rhs))
        && lhs.dptr->m_testField == rhs.dptr->m_testField;
}

QtProtobuf::sint32 AnnotatedMessage9::testField() const
{
    return dptr->m_testField;
}

void AnnotatedMessage9::setTestField(const QtProtobuf::sint32 &testField)
{
    if (dptr->m_testField != testField) {
        dptr.detach();
        dptr->m_testField = testField;
    }
}

} // namespace qtprotobufnamespace::tests

#include "moc_annotation.qpb.cpp"
