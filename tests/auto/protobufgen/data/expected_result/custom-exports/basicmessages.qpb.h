/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef BASICMESSAGES_QPB_H
#define BASICMESSAGES_QPB_H

#include "tst_qtprotobufgen_custom_exports_gen_exports.qpb.h"

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
class EmptyMessage;
using EmptyMessageRepeated = QList<EmptyMessage>;
namespace EmptyMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace EmptyMessage_QtProtobufNested

class SimpleBoolMessage;
using SimpleBoolMessageRepeated = QList<SimpleBoolMessage>;
namespace SimpleBoolMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleBoolMessage_QtProtobufNested

class SimpleIntMessage;
using SimpleIntMessageRepeated = QList<SimpleIntMessage>;
namespace SimpleIntMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleIntMessage_QtProtobufNested

class SimpleSIntMessage;
using SimpleSIntMessageRepeated = QList<SimpleSIntMessage>;
namespace SimpleSIntMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleSIntMessage_QtProtobufNested

class SimpleUIntMessage;
using SimpleUIntMessageRepeated = QList<SimpleUIntMessage>;
namespace SimpleUIntMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleUIntMessage_QtProtobufNested

class SimpleInt64Message;
using SimpleInt64MessageRepeated = QList<SimpleInt64Message>;
namespace SimpleInt64Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleInt64Message_QtProtobufNested

class SimpleSInt64Message;
using SimpleSInt64MessageRepeated = QList<SimpleSInt64Message>;
namespace SimpleSInt64Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleSInt64Message_QtProtobufNested

class SimpleUInt64Message;
using SimpleUInt64MessageRepeated = QList<SimpleUInt64Message>;
namespace SimpleUInt64Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleUInt64Message_QtProtobufNested

class SimpleStringMessage;
using SimpleStringMessageRepeated = QList<SimpleStringMessage>;
namespace SimpleStringMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleStringMessage_QtProtobufNested

class SimpleFloatMessage;
using SimpleFloatMessageRepeated = QList<SimpleFloatMessage>;
namespace SimpleFloatMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleFloatMessage_QtProtobufNested

class SimpleDoubleMessage;
using SimpleDoubleMessageRepeated = QList<SimpleDoubleMessage>;
namespace SimpleDoubleMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleDoubleMessage_QtProtobufNested

class SimpleBytesMessage;
using SimpleBytesMessageRepeated = QList<SimpleBytesMessage>;
namespace SimpleBytesMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleBytesMessage_QtProtobufNested

class SimpleFixedInt32Message;
using SimpleFixedInt32MessageRepeated = QList<SimpleFixedInt32Message>;
namespace SimpleFixedInt32Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleFixedInt32Message_QtProtobufNested

class SimpleFixedInt64Message;
using SimpleFixedInt64MessageRepeated = QList<SimpleFixedInt64Message>;
namespace SimpleFixedInt64Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleFixedInt64Message_QtProtobufNested

class SimpleSFixedInt32Message;
using SimpleSFixedInt32MessageRepeated = QList<SimpleSFixedInt32Message>;
namespace SimpleSFixedInt32Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleSFixedInt32Message_QtProtobufNested

class SimpleSFixedInt64Message;
using SimpleSFixedInt64MessageRepeated = QList<SimpleSFixedInt64Message>;
namespace SimpleSFixedInt64Message_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleSFixedInt64Message_QtProtobufNested

class ComplexMessage;
using ComplexMessageRepeated = QList<ComplexMessage>;
namespace ComplexMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace ComplexMessage_QtProtobufNested


class EmptyMessage_QtProtobufData;
class EmptyMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

public:
    using QtProtobufFieldEnum = EmptyMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT EmptyMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~EmptyMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT EmptyMessage(const EmptyMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT EmptyMessage &operator =(const EmptyMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT EmptyMessage(EmptyMessage &&other) noexcept;
    EmptyMessage &operator =(EmptyMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(EmptyMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const EmptyMessage &lhs, const EmptyMessage &rhs) noexcept;
    friend bool operator==(const EmptyMessage &lhs, const EmptyMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const EmptyMessage &lhs, const EmptyMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<EmptyMessage_QtProtobufData> dptr;
};
namespace EmptyMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

} // namespace EmptyMessage_QtProtobufNested

class SimpleBoolMessage_QtProtobufData;
class SimpleBoolMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(bool testFieldBool READ testFieldBool WRITE setTestFieldBool SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleBoolMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBoolMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleBoolMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBoolMessage(const SimpleBoolMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBoolMessage &operator =(const SimpleBoolMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBoolMessage(SimpleBoolMessage &&other) noexcept;
    SimpleBoolMessage &operator =(SimpleBoolMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleBoolMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT bool testFieldBool() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldBool(bool testFieldBool);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleBoolMessage &lhs, const SimpleBoolMessage &rhs) noexcept;
    friend bool operator==(const SimpleBoolMessage &lhs, const SimpleBoolMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleBoolMessage &lhs, const SimpleBoolMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleBoolMessage_QtProtobufData> dptr;
};
namespace SimpleBoolMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldBoolProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleBoolMessage_QtProtobufNested

class SimpleIntMessage_QtProtobufData;
class SimpleIntMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::int32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleIntMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleIntMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleIntMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleIntMessage(const SimpleIntMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleIntMessage &operator =(const SimpleIntMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleIntMessage(SimpleIntMessage &&other) noexcept;
    SimpleIntMessage &operator =(SimpleIntMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleIntMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::int32 testFieldInt() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::int32 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleIntMessage &lhs, const SimpleIntMessage &rhs) noexcept;
    friend bool operator==(const SimpleIntMessage &lhs, const SimpleIntMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleIntMessage &lhs, const SimpleIntMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleIntMessage_QtProtobufData> dptr;
};
namespace SimpleIntMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleIntMessage_QtProtobufNested

class SimpleSIntMessage_QtProtobufData;
class SimpleSIntMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleSIntMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSIntMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleSIntMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSIntMessage(const SimpleSIntMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSIntMessage &operator =(const SimpleSIntMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSIntMessage(SimpleSIntMessage &&other) noexcept;
    SimpleSIntMessage &operator =(SimpleSIntMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleSIntMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::sint32 testFieldInt() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::sint32 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleSIntMessage &lhs, const SimpleSIntMessage &rhs) noexcept;
    friend bool operator==(const SimpleSIntMessage &lhs, const SimpleSIntMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleSIntMessage &lhs, const SimpleSIntMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleSIntMessage_QtProtobufData> dptr;
};
namespace SimpleSIntMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleSIntMessage_QtProtobufNested

class SimpleUIntMessage_QtProtobufData;
class SimpleUIntMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::uint32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleUIntMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUIntMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleUIntMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUIntMessage(const SimpleUIntMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUIntMessage &operator =(const SimpleUIntMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUIntMessage(SimpleUIntMessage &&other) noexcept;
    SimpleUIntMessage &operator =(SimpleUIntMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleUIntMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::uint32 testFieldInt() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::uint32 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleUIntMessage &lhs, const SimpleUIntMessage &rhs) noexcept;
    friend bool operator==(const SimpleUIntMessage &lhs, const SimpleUIntMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleUIntMessage &lhs, const SimpleUIntMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleUIntMessage_QtProtobufData> dptr;
};
namespace SimpleUIntMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleUIntMessage_QtProtobufNested

class SimpleInt64Message_QtProtobufData;
class SimpleInt64Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::int64 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE false)

public:
    using QtProtobufFieldEnum = SimpleInt64Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleInt64Message(const SimpleInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleInt64Message &operator =(const SimpleInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleInt64Message(SimpleInt64Message &&other) noexcept;
    SimpleInt64Message &operator =(SimpleInt64Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleInt64Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::int64 testFieldInt() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::int64 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleInt64Message &lhs, const SimpleInt64Message &rhs) noexcept;
    friend bool operator==(const SimpleInt64Message &lhs, const SimpleInt64Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleInt64Message &lhs, const SimpleInt64Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleInt64Message_QtProtobufData> dptr;
};
namespace SimpleInt64Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleInt64Message_QtProtobufNested

class SimpleSInt64Message_QtProtobufData;
class SimpleSInt64Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::sint64 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE false)

public:
    using QtProtobufFieldEnum = SimpleSInt64Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleSInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSInt64Message(const SimpleSInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSInt64Message &operator =(const SimpleSInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSInt64Message(SimpleSInt64Message &&other) noexcept;
    SimpleSInt64Message &operator =(SimpleSInt64Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleSInt64Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::sint64 testFieldInt() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::sint64 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleSInt64Message &lhs, const SimpleSInt64Message &rhs) noexcept;
    friend bool operator==(const SimpleSInt64Message &lhs, const SimpleSInt64Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleSInt64Message &lhs, const SimpleSInt64Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleSInt64Message_QtProtobufData> dptr;
};
namespace SimpleSInt64Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleSInt64Message_QtProtobufNested

class SimpleUInt64Message_QtProtobufData;
class SimpleUInt64Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::uint64 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleUInt64Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleUInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUInt64Message(const SimpleUInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUInt64Message &operator =(const SimpleUInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleUInt64Message(SimpleUInt64Message &&other) noexcept;
    SimpleUInt64Message &operator =(SimpleUInt64Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleUInt64Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::uint64 testFieldInt() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::uint64 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleUInt64Message &lhs, const SimpleUInt64Message &rhs) noexcept;
    friend bool operator==(const SimpleUInt64Message &lhs, const SimpleUInt64Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleUInt64Message &lhs, const SimpleUInt64Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleUInt64Message_QtProtobufData> dptr;
};
namespace SimpleUInt64Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleUInt64Message_QtProtobufNested

class SimpleStringMessage_QtProtobufData;
class SimpleStringMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QString testFieldString READ testFieldString WRITE setTestFieldString SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleStringMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleStringMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleStringMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleStringMessage(const SimpleStringMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleStringMessage &operator =(const SimpleStringMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleStringMessage(SimpleStringMessage &&other) noexcept;
    SimpleStringMessage &operator =(SimpleStringMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleStringMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QString testFieldString() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldString(const QString &testFieldString);
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldString(QString &&testFieldString);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleStringMessage &lhs, const SimpleStringMessage &rhs) noexcept;
    friend bool operator==(const SimpleStringMessage &lhs, const SimpleStringMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleStringMessage &lhs, const SimpleStringMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleStringMessage_QtProtobufData> dptr;
};
namespace SimpleStringMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldStringProtoFieldNumber = 6,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleStringMessage_QtProtobufNested

class SimpleFloatMessage_QtProtobufData;
class SimpleFloatMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(float testFieldFloat READ testFieldFloat WRITE setTestFieldFloat SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleFloatMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFloatMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleFloatMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFloatMessage(const SimpleFloatMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFloatMessage &operator =(const SimpleFloatMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFloatMessage(SimpleFloatMessage &&other) noexcept;
    SimpleFloatMessage &operator =(SimpleFloatMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleFloatMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT float testFieldFloat() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldFloat(float testFieldFloat);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleFloatMessage &lhs, const SimpleFloatMessage &rhs) noexcept;
    friend bool operator==(const SimpleFloatMessage &lhs, const SimpleFloatMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleFloatMessage &lhs, const SimpleFloatMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleFloatMessage_QtProtobufData> dptr;
};
namespace SimpleFloatMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldFloatProtoFieldNumber = 7,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleFloatMessage_QtProtobufNested

class SimpleDoubleMessage_QtProtobufData;
class SimpleDoubleMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(double testFieldDouble READ testFieldDouble WRITE setTestFieldDouble SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleDoubleMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleDoubleMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleDoubleMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleDoubleMessage(const SimpleDoubleMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleDoubleMessage &operator =(const SimpleDoubleMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleDoubleMessage(SimpleDoubleMessage &&other) noexcept;
    SimpleDoubleMessage &operator =(SimpleDoubleMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleDoubleMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT double testFieldDouble() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldDouble(double testFieldDouble);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleDoubleMessage &lhs, const SimpleDoubleMessage &rhs) noexcept;
    friend bool operator==(const SimpleDoubleMessage &lhs, const SimpleDoubleMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleDoubleMessage &lhs, const SimpleDoubleMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleDoubleMessage_QtProtobufData> dptr;
};
namespace SimpleDoubleMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldDoubleProtoFieldNumber = 8,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleDoubleMessage_QtProtobufNested

class SimpleBytesMessage_QtProtobufData;
class SimpleBytesMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QByteArray testFieldBytes READ testFieldBytes WRITE setTestFieldBytes SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleBytesMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBytesMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleBytesMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBytesMessage(const SimpleBytesMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBytesMessage &operator =(const SimpleBytesMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleBytesMessage(SimpleBytesMessage &&other) noexcept;
    SimpleBytesMessage &operator =(SimpleBytesMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleBytesMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QByteArray testFieldBytes() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldBytes(const QByteArray &testFieldBytes);
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldBytes(QByteArray &&testFieldBytes);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleBytesMessage &lhs, const SimpleBytesMessage &rhs) noexcept;
    friend bool operator==(const SimpleBytesMessage &lhs, const SimpleBytesMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleBytesMessage &lhs, const SimpleBytesMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleBytesMessage_QtProtobufData> dptr;
};
namespace SimpleBytesMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldBytesProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleBytesMessage_QtProtobufNested

class SimpleFixedInt32Message_QtProtobufData;
class SimpleFixedInt32Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::fixed32 testFieldFixedInt32 READ testFieldFixedInt32 WRITE setTestFieldFixedInt32 SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleFixedInt32Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt32Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleFixedInt32Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt32Message(const SimpleFixedInt32Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt32Message &operator =(const SimpleFixedInt32Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt32Message(SimpleFixedInt32Message &&other) noexcept;
    SimpleFixedInt32Message &operator =(SimpleFixedInt32Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleFixedInt32Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::fixed32 testFieldFixedInt32() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldFixedInt32(QtProtobuf::fixed32 testFieldFixedInt32);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleFixedInt32Message &lhs, const SimpleFixedInt32Message &rhs) noexcept;
    friend bool operator==(const SimpleFixedInt32Message &lhs, const SimpleFixedInt32Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleFixedInt32Message &lhs, const SimpleFixedInt32Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleFixedInt32Message_QtProtobufData> dptr;
};
namespace SimpleFixedInt32Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldFixedInt32ProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleFixedInt32Message_QtProtobufNested

class SimpleFixedInt64Message_QtProtobufData;
class SimpleFixedInt64Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::fixed64 testFieldFixedInt64 READ testFieldFixedInt64 WRITE setTestFieldFixedInt64 SCRIPTABLE false)

public:
    using QtProtobufFieldEnum = SimpleFixedInt64Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleFixedInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt64Message(const SimpleFixedInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt64Message &operator =(const SimpleFixedInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleFixedInt64Message(SimpleFixedInt64Message &&other) noexcept;
    SimpleFixedInt64Message &operator =(SimpleFixedInt64Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleFixedInt64Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::fixed64 testFieldFixedInt64() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldFixedInt64(QtProtobuf::fixed64 testFieldFixedInt64);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleFixedInt64Message &lhs, const SimpleFixedInt64Message &rhs) noexcept;
    friend bool operator==(const SimpleFixedInt64Message &lhs, const SimpleFixedInt64Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleFixedInt64Message &lhs, const SimpleFixedInt64Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleFixedInt64Message_QtProtobufData> dptr;
};
namespace SimpleFixedInt64Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldFixedInt64ProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleFixedInt64Message_QtProtobufNested

class SimpleSFixedInt32Message_QtProtobufData;
class SimpleSFixedInt32Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::sfixed32 testFieldFixedInt32 READ testFieldFixedInt32 WRITE setTestFieldFixedInt32 SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleSFixedInt32Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt32Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleSFixedInt32Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt32Message(const SimpleSFixedInt32Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt32Message &operator =(const SimpleSFixedInt32Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt32Message(SimpleSFixedInt32Message &&other) noexcept;
    SimpleSFixedInt32Message &operator =(SimpleSFixedInt32Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleSFixedInt32Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::sfixed32 testFieldFixedInt32() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldFixedInt32(QtProtobuf::sfixed32 testFieldFixedInt32);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleSFixedInt32Message &lhs, const SimpleSFixedInt32Message &rhs) noexcept;
    friend bool operator==(const SimpleSFixedInt32Message &lhs, const SimpleSFixedInt32Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleSFixedInt32Message &lhs, const SimpleSFixedInt32Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleSFixedInt32Message_QtProtobufData> dptr;
};
namespace SimpleSFixedInt32Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldFixedInt32ProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleSFixedInt32Message_QtProtobufNested

class SimpleSFixedInt64Message_QtProtobufData;
class SimpleSFixedInt64Message : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::sfixed64 testFieldFixedInt64 READ testFieldFixedInt64 WRITE setTestFieldFixedInt64 SCRIPTABLE false)

public:
    using QtProtobufFieldEnum = SimpleSFixedInt64Message_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~SimpleSFixedInt64Message();
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt64Message(const SimpleSFixedInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt64Message &operator =(const SimpleSFixedInt64Message &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleSFixedInt64Message(SimpleSFixedInt64Message &&other) noexcept;
    SimpleSFixedInt64Message &operator =(SimpleSFixedInt64Message &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(SimpleSFixedInt64Message &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::sfixed64 testFieldFixedInt64() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldFixedInt64(QtProtobuf::sfixed64 testFieldFixedInt64);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const SimpleSFixedInt64Message &lhs, const SimpleSFixedInt64Message &rhs) noexcept;
    friend bool operator==(const SimpleSFixedInt64Message &lhs, const SimpleSFixedInt64Message &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const SimpleSFixedInt64Message &lhs, const SimpleSFixedInt64Message &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<SimpleSFixedInt64Message_QtProtobufData> dptr;
};
namespace SimpleSFixedInt64Message_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldFixedInt64ProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleSFixedInt64Message_QtProtobufNested

class ComplexMessage_QtProtobufData;
class ComplexMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)
    Q_PROPERTY(QtProtobuf::int32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)
    Q_PROPERTY(qtprotobufnamespace::tests::SimpleStringMessage *testComplexField_p READ testComplexField_p WRITE setTestComplexField_p SCRIPTABLE false)
    Q_PROPERTY(bool hasTestComplexField READ hasTestComplexField)

public:
    using QtProtobufFieldEnum = ComplexMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_CUSTOM_EXPORT_NAME_EXPORT ComplexMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ~ComplexMessage();
    QPB_CUSTOM_EXPORT_NAME_EXPORT ComplexMessage(const ComplexMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT ComplexMessage &operator =(const ComplexMessage &other);
    QPB_CUSTOM_EXPORT_NAME_EXPORT ComplexMessage(ComplexMessage &&other) noexcept;
    ComplexMessage &operator =(ComplexMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(ComplexMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }

    QPB_CUSTOM_EXPORT_NAME_EXPORT QtProtobuf::int32 testFieldInt() const;

    QPB_CUSTOM_EXPORT_NAME_EXPORT bool hasTestComplexField() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT const SimpleStringMessage &testComplexField() const;
    QPB_CUSTOM_EXPORT_NAME_EXPORT void clearTestComplexField();
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestFieldInt(QtProtobuf::int32 testFieldInt);
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestComplexField(const SimpleStringMessage &testComplexField);
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestComplexField(SimpleStringMessage &&testComplexField);
    QPB_CUSTOM_EXPORT_NAME_EXPORT static void registerTypes();

private:
    friend QPB_CUSTOM_EXPORT_NAME_EXPORT bool comparesEqual(const ComplexMessage &lhs, const ComplexMessage &rhs) noexcept;
    friend bool operator==(const ComplexMessage &lhs, const ComplexMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const ComplexMessage &lhs, const ComplexMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QPB_CUSTOM_EXPORT_NAME_EXPORT SimpleStringMessage *testComplexField_p();
    QPB_CUSTOM_EXPORT_NAME_EXPORT void setTestComplexField_p(SimpleStringMessage *testComplexField);
    QExplicitlySharedDataPointer<ComplexMessage_QtProtobufData> dptr;
};
namespace ComplexMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_CUSTOM_EXPORT_NAME_EXPORT)

enum class QtProtobufFieldEnum {
    TestFieldIntProtoFieldNumber = 1,
    TestComplexFieldProtoFieldNumber = 2,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace ComplexMessage_QtProtobufNested
} // namespace qtprotobufnamespace::tests

#endif // BASICMESSAGES_QPB_H
