/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef ANNOTATION_QPB_H
#define ANNOTATION_QPB_H

#include "tst_qtprotobufgen_copy_comments_exports.qpb.h"

#include <QtProtobuf/qprotobuflazymessagepointer.h>
#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qtprotobuftypes.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qlist.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

namespace qtprotobufnamespace::tests {
class AnnotatedMessage1;
namespace AnnotatedMessage1_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage1_QtProtobufNested

class AnnotatedMessage2;
namespace AnnotatedMessage2_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage2_QtProtobufNested

class AnnotatedMessage3;
namespace AnnotatedMessage3_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage3_QtProtobufNested

class AnnotatedMessage4;
namespace AnnotatedMessage4_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage4_QtProtobufNested

class AnnotatedMessage5;
namespace AnnotatedMessage5_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage5_QtProtobufNested

class AnnotatedMessage6;
namespace AnnotatedMessage6_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage6_QtProtobufNested

class AnnotatedMessage7;
namespace AnnotatedMessage7_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage7_QtProtobufNested

class AnnotatedMessage8;
namespace AnnotatedMessage8_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage8_QtProtobufNested

class AnnotatedMessage9;
namespace AnnotatedMessage9_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace AnnotatedMessage9_QtProtobufNested

#ifdef QT_USE_PROTOBUF_LIST_ALIASES
using AnnotatedMessage1Repeated = QList<AnnotatedMessage1>;
using AnnotatedMessage2Repeated = QList<AnnotatedMessage2>;
using AnnotatedMessage3Repeated = QList<AnnotatedMessage3>;
using AnnotatedMessage4Repeated = QList<AnnotatedMessage4>;
using AnnotatedMessage5Repeated = QList<AnnotatedMessage5>;
using AnnotatedMessage6Repeated = QList<AnnotatedMessage6>;
using AnnotatedMessage7Repeated = QList<AnnotatedMessage7>;
using AnnotatedMessage8Repeated = QList<AnnotatedMessage8>;
using AnnotatedMessage9Repeated = QList<AnnotatedMessage9>;
#endif // QT_USE_PROTOBUF_LIST_ALIASES

/* test annotation */
class AnnotatedMessage1_QtProtobufData;
class AnnotatedMessage1 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage1_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage1();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage1();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage1(const AnnotatedMessage1 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage1 &operator =(const AnnotatedMessage1 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage1(AnnotatedMessage1 &&other) noexcept;
    AnnotatedMessage1 &operator =(AnnotatedMessage1 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage1 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /**
     * \brief Field annotation
     */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage1 &lhs, const AnnotatedMessage1 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage1 &lhs, const AnnotatedMessage1 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage1 &lhs, const AnnotatedMessage1 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage1_QtProtobufData> dptr;
};
namespace AnnotatedMessage1_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage1_QtProtobufNested

/* test annotation */
class AnnotatedMessage2_QtProtobufData;
class AnnotatedMessage2 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage2_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage2();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage2();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage2(const AnnotatedMessage2 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage2 &operator =(const AnnotatedMessage2 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage2(AnnotatedMessage2 &&other) noexcept;
    AnnotatedMessage2 &operator =(AnnotatedMessage2 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage2 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /*!
     * \brief Field annotation
     */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage2 &lhs, const AnnotatedMessage2 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage2 &lhs, const AnnotatedMessage2 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage2 &lhs, const AnnotatedMessage2 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage2_QtProtobufData> dptr;
};
namespace AnnotatedMessage2_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage2_QtProtobufNested

/* test annotation */
class AnnotatedMessage3_QtProtobufData;
class AnnotatedMessage3 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage3_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage3();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage3();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage3(const AnnotatedMessage3 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage3 &operator =(const AnnotatedMessage3 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage3(AnnotatedMessage3 &&other) noexcept;
    AnnotatedMessage3 &operator =(AnnotatedMessage3 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage3 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /*
     * Field annotation
     * Field annotation secondline
     */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage3 &lhs, const AnnotatedMessage3 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage3 &lhs, const AnnotatedMessage3 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage3 &lhs, const AnnotatedMessage3 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage3_QtProtobufData> dptr;
};
namespace AnnotatedMessage3_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage3_QtProtobufNested

/* test annotation */
class AnnotatedMessage4_QtProtobufData;
class AnnotatedMessage4 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage4_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage4();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage4();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage4(const AnnotatedMessage4 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage4 &operator =(const AnnotatedMessage4 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage4(AnnotatedMessage4 &&other) noexcept;
    AnnotatedMessage4 &operator =(AnnotatedMessage4 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage4 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage4 &lhs, const AnnotatedMessage4 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage4 &lhs, const AnnotatedMessage4 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage4 &lhs, const AnnotatedMessage4 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage4_QtProtobufData> dptr;
};
namespace AnnotatedMessage4_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage4_QtProtobufNested

/*! \brief test annotation */
class AnnotatedMessage5_QtProtobufData;
class AnnotatedMessage5 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage5_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage5();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage5();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage5(const AnnotatedMessage5 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage5 &operator =(const AnnotatedMessage5 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage5(AnnotatedMessage5 &&other) noexcept;
    AnnotatedMessage5 &operator =(AnnotatedMessage5 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage5 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /* Field annotation */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage5 &lhs, const AnnotatedMessage5 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage5 &lhs, const AnnotatedMessage5 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage5 &lhs, const AnnotatedMessage5 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage5_QtProtobufData> dptr;
};
namespace AnnotatedMessage5_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage5_QtProtobufNested

/** \brief test annotation */
class AnnotatedMessage6_QtProtobufData;
class AnnotatedMessage6 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage6_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage6();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage6();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage6(const AnnotatedMessage6 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage6 &operator =(const AnnotatedMessage6 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage6(AnnotatedMessage6 &&other) noexcept;
    AnnotatedMessage6 &operator =(AnnotatedMessage6 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage6 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /** Field annotation */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage6 &lhs, const AnnotatedMessage6 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage6 &lhs, const AnnotatedMessage6 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage6 &lhs, const AnnotatedMessage6 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage6_QtProtobufData> dptr;
};
namespace AnnotatedMessage6_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage6_QtProtobufNested

/*!
 * \brief test annotation
 */
class AnnotatedMessage7_QtProtobufData;
class AnnotatedMessage7 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage7_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage7();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage7();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage7(const AnnotatedMessage7 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage7 &operator =(const AnnotatedMessage7 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage7(AnnotatedMessage7 &&other) noexcept;
    AnnotatedMessage7 &operator =(AnnotatedMessage7 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage7 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /*! Field annotation */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage7 &lhs, const AnnotatedMessage7 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage7 &lhs, const AnnotatedMessage7 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage7 &lhs, const AnnotatedMessage7 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage7_QtProtobufData> dptr;
};
namespace AnnotatedMessage7_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage7_QtProtobufNested

/**
 * \brief test annotation
 */
class AnnotatedMessage8_QtProtobufData;
class AnnotatedMessage8 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage8_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage8();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage8();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage8(const AnnotatedMessage8 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage8 &operator =(const AnnotatedMessage8 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage8(AnnotatedMessage8 &&other) noexcept;
    AnnotatedMessage8 &operator =(AnnotatedMessage8 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage8 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /* Field annotation */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage8 &lhs, const AnnotatedMessage8 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage8 &lhs, const AnnotatedMessage8 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage8 &lhs, const AnnotatedMessage8 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage8_QtProtobufData> dptr;
};
namespace AnnotatedMessage8_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage8_QtProtobufNested

/*
 * test annotation
 * test annotation secondline
 */
class AnnotatedMessage9_QtProtobufData;
class AnnotatedMessage9 : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = AnnotatedMessage9_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage9();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT ~AnnotatedMessage9();
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage9(const AnnotatedMessage9 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage9 &operator =(const AnnotatedMessage9 &other);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT AnnotatedMessage9(AnnotatedMessage9 &&other) noexcept;
    AnnotatedMessage9 &operator =(AnnotatedMessage9 &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(AnnotatedMessage9 &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT Q_IMPLICIT operator QVariant() const;

    /* Field annotation */
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT QtProtobuf::sint32 testField() const;
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT void setTestField(QtProtobuf::sint32 testField);
    QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT bool comparesEqual(const AnnotatedMessage9 &lhs, const AnnotatedMessage9 &rhs) noexcept;
    friend bool operator==(const AnnotatedMessage9 &lhs, const AnnotatedMessage9 &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const AnnotatedMessage9 &lhs, const AnnotatedMessage9 &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<AnnotatedMessage9_QtProtobufData> dptr;
};
namespace AnnotatedMessage9_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTPROTOBUFGEN_COPY_COMMENTS_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace AnnotatedMessage9_QtProtobufNested
} // namespace qtprotobufnamespace::tests

#endif // ANNOTATION_QPB_H
