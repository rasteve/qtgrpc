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

#include <memory>


namespace qtprotobufnamespace::tests {
class EmptyMessage;
using EmptyMessageRepeated = QList<std::shared_ptr<EmptyMessage>>;
class SimpleStringMessage;
using SimpleStringMessageRepeated = QList<std::shared_ptr<SimpleStringMessage>>;
class ComplexMessage;
using ComplexMessageRepeated = QList<std::shared_ptr<ComplexMessage>>;

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
};

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

    QString testFieldString() const
    {
        return m_testFieldString;
    }

    void setTestFieldString(const QString &testFieldString);
    static void registerTypes();

private:
    QString m_testFieldString;
};

class ComplexMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(ComplexMessage)
    Q_PROPERTY(QtProtobuf::int32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)
    Q_PROPERTY(qtprotobufnamespace::tests::SimpleStringMessage *testComplexField_p READ testComplexField_p WRITE setTestComplexField_p)

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

    QtProtobuf::int32 testFieldInt() const
    {
        return m_testFieldInt;
    }


    SimpleStringMessage &testComplexField() const;
    void setTestFieldInt(const QtProtobuf::int32 &testFieldInt)
    {
        if (m_testFieldInt != testFieldInt)
            m_testFieldInt = testFieldInt;
    }

    void setTestComplexField(const SimpleStringMessage &testComplexField);
    static void registerTypes();

private:
    SimpleStringMessage *testComplexField_p() const;
    void setTestComplexField_p(SimpleStringMessage *testComplexField);
    QtProtobuf::int32 m_testFieldInt;
    QtProtobufPrivate::QProtobufLazyMessagePointer<SimpleStringMessage> m_testComplexField;
};
} // namespace qtprotobufnamespace::tests

Q_DECLARE_METATYPE(qtprotobufnamespace::tests::EmptyMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::SimpleStringMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::ComplexMessage)
#endif // QPROTOBUF_EXTRANAMESPACE_H
