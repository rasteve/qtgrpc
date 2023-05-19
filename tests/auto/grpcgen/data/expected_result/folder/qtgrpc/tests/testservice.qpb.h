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
class SimpleIntMessage;
using SimpleIntMessageRepeated = QList<SimpleIntMessage>;
class BlobMessage;
using BlobMessageRepeated = QList<BlobMessage>;

class SimpleStringMessage_QtProtobufData;
class SimpleStringMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(SimpleStringMessage)
    Q_PROPERTY(QString testFieldString READ testFieldString WRITE setTestFieldString SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestFieldStringProtoFieldNumber = 6,
    };
    Q_ENUM(QtProtobufFieldEnum)

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

class SimpleIntMessage_QtProtobufData;
class SimpleIntMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(SimpleIntMessage)
    Q_PROPERTY(QtProtobuf::sint32 testField READ testField WRITE setTestField SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestFieldProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

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

class BlobMessage_QtProtobufData;
class BlobMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(BlobMessage)
    Q_PROPERTY(QByteArray testBytes READ testBytes WRITE setTestBytes SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestBytesProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

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
} // namespace qtgrpc::tests

Q_DECLARE_METATYPE(qtgrpc::tests::SimpleStringMessage)
Q_DECLARE_METATYPE(qtgrpc::tests::SimpleIntMessage)
Q_DECLARE_METATYPE(qtgrpc::tests::BlobMessage)
#endif // QPROTOBUF_TESTSERVICE_H
