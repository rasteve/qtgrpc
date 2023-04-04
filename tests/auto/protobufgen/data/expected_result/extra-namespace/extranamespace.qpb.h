/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QPROTOBUF_EXTRANAMESPACE_H
#define QPROTOBUF_EXTRANAMESPACE_H

#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qprotobuflazymessagepointer.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qstring.h>

#include <QtCore/qmetatype.h>
#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <memory>


namespace MyTopLevelNamespace::qtprotobufnamespace::tests {
class EmptyMessage;
using EmptyMessageRepeated = QList<std::shared_ptr<EmptyMessage>>;
class SimpleStringMessage;
using SimpleStringMessageRepeated = QList<std::shared_ptr<SimpleStringMessage>>;
class ComplexMessage;
using ComplexMessageRepeated = QList<std::shared_ptr<ComplexMessage>>;

class EmptyMessage_QtProtobufData;
class EmptyMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(EmptyMessage)

public:
    EmptyMessage();
    ~EmptyMessage();
    EmptyMessage(const EmptyMessage &other);
    EmptyMessage &operator =(const EmptyMessage &other);
    EmptyMessage(EmptyMessage &&other) noexcept;
    EmptyMessage &operator =(EmptyMessage &&other) noexcept;
    bool operator ==(const EmptyMessage &other) const;
    bool operator !=(const EmptyMessage &other) const;
    static void registerTypes();

private:
    QExplicitlySharedDataPointer<EmptyMessage_QtProtobufData> dptr;
};

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

class ComplexMessage_QtProtobufData;
class ComplexMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(ComplexMessage)
    Q_PROPERTY(QtProtobuf::int32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)
    Q_PROPERTY(MyTopLevelNamespace::qtprotobufnamespace::tests::SimpleStringMessage *testComplexField_p READ testComplexField_p WRITE setTestComplexField_p)

public:
    enum QtProtobufFieldEnum {
        TestFieldIntProtoFieldNumber = 1,
        TestComplexFieldProtoFieldNumber = 2,
    };
    Q_ENUM(QtProtobufFieldEnum)

    ComplexMessage();
    ~ComplexMessage();
    ComplexMessage(const ComplexMessage &other);
    ComplexMessage &operator =(const ComplexMessage &other);
    ComplexMessage(ComplexMessage &&other) noexcept;
    ComplexMessage &operator =(ComplexMessage &&other) noexcept;
    bool operator ==(const ComplexMessage &other) const;
    bool operator !=(const ComplexMessage &other) const;

    QtProtobuf::int32 testFieldInt() const;

    SimpleStringMessage &testComplexField() const;
    void setTestFieldInt(const QtProtobuf::int32 &testFieldInt);
    void setTestComplexField(const SimpleStringMessage &testComplexField);
    static void registerTypes();

private:
    SimpleStringMessage *testComplexField_p() const;
    void setTestComplexField_p(SimpleStringMessage *testComplexField);
    QExplicitlySharedDataPointer<ComplexMessage_QtProtobufData> dptr;
};
} // namespace MyTopLevelNamespace::qtprotobufnamespace::tests

Q_DECLARE_METATYPE(MyTopLevelNamespace::qtprotobufnamespace::tests::EmptyMessage)
Q_DECLARE_METATYPE(MyTopLevelNamespace::qtprotobufnamespace::tests::SimpleStringMessage)
Q_DECLARE_METATYPE(MyTopLevelNamespace::qtprotobufnamespace::tests::ComplexMessage)
#endif // QPROTOBUF_EXTRANAMESPACE_H
