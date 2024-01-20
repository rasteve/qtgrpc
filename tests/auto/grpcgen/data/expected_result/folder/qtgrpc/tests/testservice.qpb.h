/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QPROTOBUF_TESTSERVICE_H
#define QPROTOBUF_TESTSERVICE_H

#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qprotobuflazymessagepointer.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qstring.h>

#include <QtCore/qmetatype.h>
#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <memory>


namespace qtgrpc::tests {
class SimpleStringMessage;
using SimpleStringMessageRepeated = QList<SimpleStringMessage>;
namespace SimpleStringMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleStringMessage_QtProtobufNested

class SimpleIntMessage;
using SimpleIntMessageRepeated = QList<SimpleIntMessage>;
namespace SimpleIntMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace SimpleIntMessage_QtProtobufNested

class BlobMessage;
using BlobMessageRepeated = QList<BlobMessage>;
namespace BlobMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace BlobMessage_QtProtobufNested


class SimpleStringMessage_QtProtobufData;
class SimpleStringMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_PROPERTY(QString testFieldString READ testFieldString WRITE setTestFieldString SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleStringMessage_QtProtobufNested::QtProtobufFieldEnum;
    SimpleStringMessage();
    ~SimpleStringMessage();
    SimpleStringMessage(const SimpleStringMessage &other);
    SimpleStringMessage &operator =(const SimpleStringMessage &other);
    SimpleStringMessage(SimpleStringMessage &&other) noexcept;
    SimpleStringMessage &operator =(SimpleStringMessage &&other) noexcept;
    bool operator ==(const SimpleStringMessage &other) const;
    bool operator !=(const SimpleStringMessage &other) const;

    QString testFieldString() const;
    void setTestFieldString(const QString &testFieldString);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<SimpleStringMessage_QtProtobufData> dptr;
};
namespace SimpleStringMessage_QtProtobufNested {
Q_NAMESPACE

enum class QtProtobufFieldEnum {
    TestFieldStringProtoFieldNumber = 6,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleStringMessage_QtProtobufNested

class SimpleIntMessage_QtProtobufData;
class SimpleIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = SimpleIntMessage_QtProtobufNested::QtProtobufFieldEnum;
    SimpleIntMessage();
    ~SimpleIntMessage();
    SimpleIntMessage(const SimpleIntMessage &other);
    SimpleIntMessage &operator =(const SimpleIntMessage &other);
    SimpleIntMessage(SimpleIntMessage &&other) noexcept;
    SimpleIntMessage &operator =(SimpleIntMessage &&other) noexcept;
    bool operator ==(const SimpleIntMessage &other) const;
    bool operator !=(const SimpleIntMessage &other) const;

    QtProtobuf::sint32 testField() const;
    void setTestField(const QtProtobuf::sint32 &testField);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<SimpleIntMessage_QtProtobufData> dptr;
};
namespace SimpleIntMessage_QtProtobufNested {
Q_NAMESPACE

enum class QtProtobufFieldEnum {
    TestFieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace SimpleIntMessage_QtProtobufNested

class BlobMessage_QtProtobufData;
class BlobMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_PROPERTY(QByteArray testBytes READ testBytes WRITE setTestBytes SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = BlobMessage_QtProtobufNested::QtProtobufFieldEnum;
    BlobMessage();
    ~BlobMessage();
    BlobMessage(const BlobMessage &other);
    BlobMessage &operator =(const BlobMessage &other);
    BlobMessage(BlobMessage &&other) noexcept;
    BlobMessage &operator =(BlobMessage &&other) noexcept;
    bool operator ==(const BlobMessage &other) const;
    bool operator !=(const BlobMessage &other) const;

    QByteArray testBytes() const;
    void setTestBytes(const QByteArray &testBytes);
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<BlobMessage_QtProtobufData> dptr;
};
namespace BlobMessage_QtProtobufNested {
Q_NAMESPACE

enum class QtProtobufFieldEnum {
    TestBytesProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace BlobMessage_QtProtobufNested
} // namespace qtgrpc::tests

Q_DECLARE_METATYPE(qtgrpc::tests::SimpleStringMessage)
Q_DECLARE_METATYPE(qtgrpc::tests::SimpleIntMessage)
Q_DECLARE_METATYPE(qtgrpc::tests::BlobMessage)
#endif // QPROTOBUF_TESTSERVICE_H
