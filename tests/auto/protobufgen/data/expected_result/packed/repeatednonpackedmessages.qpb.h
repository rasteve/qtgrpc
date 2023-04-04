/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QPROTOBUF_REPEATEDNONPACKEDMESSAGES_H
#define QPROTOBUF_REPEATEDNONPACKEDMESSAGES_H

#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qprotobuflazymessagepointer.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qstring.h>

#include <QtCore/qmetatype.h>
#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <memory>


namespace qtprotobufnamespace::tests {
class RepeatedNonPackedIntMessage;
using RepeatedNonPackedIntMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedIntMessage>>;
class RepeatedNonPackedSIntMessage;
using RepeatedNonPackedSIntMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedSIntMessage>>;
class RepeatedNonPackedUIntMessage;
using RepeatedNonPackedUIntMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedUIntMessage>>;
class RepeatedNonPackedInt64Message;
using RepeatedNonPackedInt64MessageRepeated = QList<std::shared_ptr<RepeatedNonPackedInt64Message>>;
class RepeatedNonPackedSInt64Message;
using RepeatedNonPackedSInt64MessageRepeated = QList<std::shared_ptr<RepeatedNonPackedSInt64Message>>;
class RepeatedNonPackedUInt64Message;
using RepeatedNonPackedUInt64MessageRepeated = QList<std::shared_ptr<RepeatedNonPackedUInt64Message>>;
class RepeatedNonPackedFixedIntMessage;
using RepeatedNonPackedFixedIntMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedFixedIntMessage>>;
class RepeatedNonPackedSFixedIntMessage;
using RepeatedNonPackedSFixedIntMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedSFixedIntMessage>>;
class RepeatedNonPackedFixedInt64Message;
using RepeatedNonPackedFixedInt64MessageRepeated = QList<std::shared_ptr<RepeatedNonPackedFixedInt64Message>>;
class RepeatedNonPackedSFixedInt64Message;
using RepeatedNonPackedSFixedInt64MessageRepeated = QList<std::shared_ptr<RepeatedNonPackedSFixedInt64Message>>;
class RepeatedNonPackedBoolMessage;
using RepeatedNonPackedBoolMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedBoolMessage>>;
class RepeatedNonPackedDoubleMessage;
using RepeatedNonPackedDoubleMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedDoubleMessage>>;
class RepeatedNonPackedFloatMessage;
using RepeatedNonPackedFloatMessageRepeated = QList<std::shared_ptr<RepeatedNonPackedFloatMessage>>;
class NonPackedIntMessageWithExtraMember;
using NonPackedIntMessageWithExtraMemberRepeated = QList<std::shared_ptr<NonPackedIntMessageWithExtraMember>>;

class RepeatedNonPackedIntMessage_QtProtobufData;
class RepeatedNonPackedIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedIntMessage)
    Q_PROPERTY(QtProtobuf::int32List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedIntMessage();
    ~RepeatedNonPackedIntMessage();
    RepeatedNonPackedIntMessage(const RepeatedNonPackedIntMessage &other);
    RepeatedNonPackedIntMessage &operator =(const RepeatedNonPackedIntMessage &other);
    RepeatedNonPackedIntMessage(RepeatedNonPackedIntMessage &&other) noexcept;
    RepeatedNonPackedIntMessage &operator =(RepeatedNonPackedIntMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedIntMessage &other) const;
    bool operator !=(const RepeatedNonPackedIntMessage &other) const;

    QtProtobuf::int32List testRepeatedInt() const;
    QtProtobuf::int32List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::int32List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedIntMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedSIntMessage_QtProtobufData;
class RepeatedNonPackedSIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedSIntMessage)
    Q_PROPERTY(QtProtobuf::sint32List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedSIntMessage();
    ~RepeatedNonPackedSIntMessage();
    RepeatedNonPackedSIntMessage(const RepeatedNonPackedSIntMessage &other);
    RepeatedNonPackedSIntMessage &operator =(const RepeatedNonPackedSIntMessage &other);
    RepeatedNonPackedSIntMessage(RepeatedNonPackedSIntMessage &&other) noexcept;
    RepeatedNonPackedSIntMessage &operator =(RepeatedNonPackedSIntMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedSIntMessage &other) const;
    bool operator !=(const RepeatedNonPackedSIntMessage &other) const;

    QtProtobuf::sint32List testRepeatedInt() const;
    QtProtobuf::sint32List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::sint32List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedSIntMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedUIntMessage_QtProtobufData;
class RepeatedNonPackedUIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedUIntMessage)
    Q_PROPERTY(QtProtobuf::uint32List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedUIntMessage();
    ~RepeatedNonPackedUIntMessage();
    RepeatedNonPackedUIntMessage(const RepeatedNonPackedUIntMessage &other);
    RepeatedNonPackedUIntMessage &operator =(const RepeatedNonPackedUIntMessage &other);
    RepeatedNonPackedUIntMessage(RepeatedNonPackedUIntMessage &&other) noexcept;
    RepeatedNonPackedUIntMessage &operator =(RepeatedNonPackedUIntMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedUIntMessage &other) const;
    bool operator !=(const RepeatedNonPackedUIntMessage &other) const;

    QtProtobuf::uint32List testRepeatedInt() const;
    QtProtobuf::uint32List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::uint32List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedUIntMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedInt64Message_QtProtobufData;
class RepeatedNonPackedInt64Message : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedInt64Message)
    Q_PROPERTY(QtProtobuf::int64List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedInt64Message();
    ~RepeatedNonPackedInt64Message();
    RepeatedNonPackedInt64Message(const RepeatedNonPackedInt64Message &other);
    RepeatedNonPackedInt64Message &operator =(const RepeatedNonPackedInt64Message &other);
    RepeatedNonPackedInt64Message(RepeatedNonPackedInt64Message &&other) noexcept;
    RepeatedNonPackedInt64Message &operator =(RepeatedNonPackedInt64Message &&other) noexcept;
    bool operator ==(const RepeatedNonPackedInt64Message &other) const;
    bool operator !=(const RepeatedNonPackedInt64Message &other) const;

    QtProtobuf::int64List testRepeatedInt() const;
    QtProtobuf::int64List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::int64List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedInt64Message_QtProtobufData> dptr;
};

class RepeatedNonPackedSInt64Message_QtProtobufData;
class RepeatedNonPackedSInt64Message : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedSInt64Message)
    Q_PROPERTY(QtProtobuf::sint64List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedSInt64Message();
    ~RepeatedNonPackedSInt64Message();
    RepeatedNonPackedSInt64Message(const RepeatedNonPackedSInt64Message &other);
    RepeatedNonPackedSInt64Message &operator =(const RepeatedNonPackedSInt64Message &other);
    RepeatedNonPackedSInt64Message(RepeatedNonPackedSInt64Message &&other) noexcept;
    RepeatedNonPackedSInt64Message &operator =(RepeatedNonPackedSInt64Message &&other) noexcept;
    bool operator ==(const RepeatedNonPackedSInt64Message &other) const;
    bool operator !=(const RepeatedNonPackedSInt64Message &other) const;

    QtProtobuf::sint64List testRepeatedInt() const;
    QtProtobuf::sint64List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::sint64List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedSInt64Message_QtProtobufData> dptr;
};

class RepeatedNonPackedUInt64Message_QtProtobufData;
class RepeatedNonPackedUInt64Message : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedUInt64Message)
    Q_PROPERTY(QtProtobuf::uint64List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedUInt64Message();
    ~RepeatedNonPackedUInt64Message();
    RepeatedNonPackedUInt64Message(const RepeatedNonPackedUInt64Message &other);
    RepeatedNonPackedUInt64Message &operator =(const RepeatedNonPackedUInt64Message &other);
    RepeatedNonPackedUInt64Message(RepeatedNonPackedUInt64Message &&other) noexcept;
    RepeatedNonPackedUInt64Message &operator =(RepeatedNonPackedUInt64Message &&other) noexcept;
    bool operator ==(const RepeatedNonPackedUInt64Message &other) const;
    bool operator !=(const RepeatedNonPackedUInt64Message &other) const;

    QtProtobuf::uint64List testRepeatedInt() const;
    QtProtobuf::uint64List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::uint64List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedUInt64Message_QtProtobufData> dptr;
};

class RepeatedNonPackedFixedIntMessage_QtProtobufData;
class RepeatedNonPackedFixedIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedFixedIntMessage)
    Q_PROPERTY(QtProtobuf::fixed32List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedFixedIntMessage();
    ~RepeatedNonPackedFixedIntMessage();
    RepeatedNonPackedFixedIntMessage(const RepeatedNonPackedFixedIntMessage &other);
    RepeatedNonPackedFixedIntMessage &operator =(const RepeatedNonPackedFixedIntMessage &other);
    RepeatedNonPackedFixedIntMessage(RepeatedNonPackedFixedIntMessage &&other) noexcept;
    RepeatedNonPackedFixedIntMessage &operator =(RepeatedNonPackedFixedIntMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedFixedIntMessage &other) const;
    bool operator !=(const RepeatedNonPackedFixedIntMessage &other) const;

    QtProtobuf::fixed32List testRepeatedInt() const;
    QtProtobuf::fixed32List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::fixed32List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedFixedIntMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedSFixedIntMessage_QtProtobufData;
class RepeatedNonPackedSFixedIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedSFixedIntMessage)
    Q_PROPERTY(QtProtobuf::sfixed32List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedSFixedIntMessage();
    ~RepeatedNonPackedSFixedIntMessage();
    RepeatedNonPackedSFixedIntMessage(const RepeatedNonPackedSFixedIntMessage &other);
    RepeatedNonPackedSFixedIntMessage &operator =(const RepeatedNonPackedSFixedIntMessage &other);
    RepeatedNonPackedSFixedIntMessage(RepeatedNonPackedSFixedIntMessage &&other) noexcept;
    RepeatedNonPackedSFixedIntMessage &operator =(RepeatedNonPackedSFixedIntMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedSFixedIntMessage &other) const;
    bool operator !=(const RepeatedNonPackedSFixedIntMessage &other) const;

    QtProtobuf::sfixed32List testRepeatedInt() const;
    QtProtobuf::sfixed32List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::sfixed32List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedSFixedIntMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedFixedInt64Message_QtProtobufData;
class RepeatedNonPackedFixedInt64Message : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedFixedInt64Message)
    Q_PROPERTY(QtProtobuf::fixed64List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedFixedInt64Message();
    ~RepeatedNonPackedFixedInt64Message();
    RepeatedNonPackedFixedInt64Message(const RepeatedNonPackedFixedInt64Message &other);
    RepeatedNonPackedFixedInt64Message &operator =(const RepeatedNonPackedFixedInt64Message &other);
    RepeatedNonPackedFixedInt64Message(RepeatedNonPackedFixedInt64Message &&other) noexcept;
    RepeatedNonPackedFixedInt64Message &operator =(RepeatedNonPackedFixedInt64Message &&other) noexcept;
    bool operator ==(const RepeatedNonPackedFixedInt64Message &other) const;
    bool operator !=(const RepeatedNonPackedFixedInt64Message &other) const;

    QtProtobuf::fixed64List testRepeatedInt() const;
    QtProtobuf::fixed64List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::fixed64List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedFixedInt64Message_QtProtobufData> dptr;
};

class RepeatedNonPackedSFixedInt64Message_QtProtobufData;
class RepeatedNonPackedSFixedInt64Message : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedSFixedInt64Message)
    Q_PROPERTY(QtProtobuf::sfixed64List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedSFixedInt64Message();
    ~RepeatedNonPackedSFixedInt64Message();
    RepeatedNonPackedSFixedInt64Message(const RepeatedNonPackedSFixedInt64Message &other);
    RepeatedNonPackedSFixedInt64Message &operator =(const RepeatedNonPackedSFixedInt64Message &other);
    RepeatedNonPackedSFixedInt64Message(RepeatedNonPackedSFixedInt64Message &&other) noexcept;
    RepeatedNonPackedSFixedInt64Message &operator =(RepeatedNonPackedSFixedInt64Message &&other) noexcept;
    bool operator ==(const RepeatedNonPackedSFixedInt64Message &other) const;
    bool operator !=(const RepeatedNonPackedSFixedInt64Message &other) const;

    QtProtobuf::sfixed64List testRepeatedInt() const;
    QtProtobuf::sfixed64List &testRepeatedInt();
    void setTestRepeatedInt(const QtProtobuf::sfixed64List &testRepeatedInt);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedSFixedInt64Message_QtProtobufData> dptr;
};

class RepeatedNonPackedBoolMessage_QtProtobufData;
class RepeatedNonPackedBoolMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedBoolMessage)
    Q_PROPERTY(QtProtobuf::boolList testRepeatedBool READ testRepeatedBool WRITE setTestRepeatedBool SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedBoolProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedBoolMessage();
    ~RepeatedNonPackedBoolMessage();
    RepeatedNonPackedBoolMessage(const RepeatedNonPackedBoolMessage &other);
    RepeatedNonPackedBoolMessage &operator =(const RepeatedNonPackedBoolMessage &other);
    RepeatedNonPackedBoolMessage(RepeatedNonPackedBoolMessage &&other) noexcept;
    RepeatedNonPackedBoolMessage &operator =(RepeatedNonPackedBoolMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedBoolMessage &other) const;
    bool operator !=(const RepeatedNonPackedBoolMessage &other) const;

    QtProtobuf::boolList testRepeatedBool() const;
    QtProtobuf::boolList &testRepeatedBool();
    void setTestRepeatedBool(const QtProtobuf::boolList &testRepeatedBool);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedBoolMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedDoubleMessage_QtProtobufData;
class RepeatedNonPackedDoubleMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedDoubleMessage)
    Q_PROPERTY(QtProtobuf::doubleList testRepeatedDouble READ testRepeatedDouble WRITE setTestRepeatedDouble SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedDoubleProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedDoubleMessage();
    ~RepeatedNonPackedDoubleMessage();
    RepeatedNonPackedDoubleMessage(const RepeatedNonPackedDoubleMessage &other);
    RepeatedNonPackedDoubleMessage &operator =(const RepeatedNonPackedDoubleMessage &other);
    RepeatedNonPackedDoubleMessage(RepeatedNonPackedDoubleMessage &&other) noexcept;
    RepeatedNonPackedDoubleMessage &operator =(RepeatedNonPackedDoubleMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedDoubleMessage &other) const;
    bool operator !=(const RepeatedNonPackedDoubleMessage &other) const;

    QtProtobuf::doubleList testRepeatedDouble() const;
    QtProtobuf::doubleList &testRepeatedDouble();
    void setTestRepeatedDouble(const QtProtobuf::doubleList &testRepeatedDouble);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedDoubleMessage_QtProtobufData> dptr;
};

class RepeatedNonPackedFloatMessage_QtProtobufData;
class RepeatedNonPackedFloatMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedNonPackedFloatMessage)
    Q_PROPERTY(QtProtobuf::floatList testRepeatedFloat READ testRepeatedFloat WRITE setTestRepeatedFloat SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedFloatProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedNonPackedFloatMessage();
    ~RepeatedNonPackedFloatMessage();
    RepeatedNonPackedFloatMessage(const RepeatedNonPackedFloatMessage &other);
    RepeatedNonPackedFloatMessage &operator =(const RepeatedNonPackedFloatMessage &other);
    RepeatedNonPackedFloatMessage(RepeatedNonPackedFloatMessage &&other) noexcept;
    RepeatedNonPackedFloatMessage &operator =(RepeatedNonPackedFloatMessage &&other) noexcept;
    bool operator ==(const RepeatedNonPackedFloatMessage &other) const;
    bool operator !=(const RepeatedNonPackedFloatMessage &other) const;

    QtProtobuf::floatList testRepeatedFloat() const;
    QtProtobuf::floatList &testRepeatedFloat();
    void setTestRepeatedFloat(const QtProtobuf::floatList &testRepeatedFloat);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<RepeatedNonPackedFloatMessage_QtProtobufData> dptr;
};

class NonPackedIntMessageWithExtraMember_QtProtobufData;
class NonPackedIntMessageWithExtraMember : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(NonPackedIntMessageWithExtraMember)
    Q_PROPERTY(QtProtobuf::int32List testRepeatedInt READ testRepeatedInt WRITE setTestRepeatedInt SCRIPTABLE true)
    Q_PROPERTY(QString extra READ extra WRITE setExtra SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestRepeatedIntProtoFieldNumber = 1,
        ExtraProtoFieldNumber = 2,
    };
    Q_ENUM(QtProtobufFieldEnum)

    NonPackedIntMessageWithExtraMember();
    ~NonPackedIntMessageWithExtraMember();
    NonPackedIntMessageWithExtraMember(const NonPackedIntMessageWithExtraMember &other);
    NonPackedIntMessageWithExtraMember &operator =(const NonPackedIntMessageWithExtraMember &other);
    NonPackedIntMessageWithExtraMember(NonPackedIntMessageWithExtraMember &&other) noexcept;
    NonPackedIntMessageWithExtraMember &operator =(NonPackedIntMessageWithExtraMember &&other) noexcept;
    bool operator ==(const NonPackedIntMessageWithExtraMember &other) const;
    bool operator !=(const NonPackedIntMessageWithExtraMember &other) const;

    QtProtobuf::int32List testRepeatedInt() const;
    QtProtobuf::int32List &testRepeatedInt();

    QString extra() const;
    void setTestRepeatedInt(const QtProtobuf::int32List &testRepeatedInt);
    void setExtra(const QString &extra);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<NonPackedIntMessageWithExtraMember_QtProtobufData> dptr;
};
} // namespace qtprotobufnamespace::tests

Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedIntMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedSIntMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedUIntMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedInt64Message)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedSInt64Message)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedUInt64Message)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedFixedIntMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedSFixedIntMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedFixedInt64Message)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedSFixedInt64Message)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedBoolMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedDoubleMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::RepeatedNonPackedFloatMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::NonPackedIntMessageWithExtraMember)
#endif // QPROTOBUF_REPEATEDNONPACKEDMESSAGES_H
