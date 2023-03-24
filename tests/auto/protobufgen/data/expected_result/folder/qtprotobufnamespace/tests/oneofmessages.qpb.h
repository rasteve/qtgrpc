/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QPROTOBUF_ONEOFMESSAGES_H
#define QPROTOBUF_ONEOFMESSAGES_H

#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qprotobuflazymessagepointer.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qstring.h>
#include <QtProtobuf/qprotobufoneof.h>
#include "basicmessages.qpb.h"

#include <QtCore/qmetatype.h>
#include <QtCore/qlist.h>

#include <memory>


namespace qtprotobufnamespace::tests {
class OneofSimpleMessage;
using OneofSimpleMessageRepeated = QList<std::shared_ptr<OneofSimpleMessage>>;
class OneofComplexMessage;
using OneofComplexMessageRepeated = QList<std::shared_ptr<OneofComplexMessage>>;

class OneofSimpleMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(OneofSimpleMessage)
    Q_PROPERTY(QtProtobuf::int32 testOneofFieldInt READ testOneofFieldInt_p WRITE setTestOneofFieldInt_p)
    Q_PROPERTY(bool hasTestOneofFieldInt READ hasTestOneofFieldInt)
    Q_PROPERTY(QtProtobuf::int32 testOneofFieldSecondInt READ testOneofFieldSecondInt_p WRITE setTestOneofFieldSecondInt_p)
    Q_PROPERTY(bool hasTestOneofFieldSecondInt READ hasTestOneofFieldSecondInt)

public:
    enum QtProtobufFieldEnum {
        TestOneofFieldIntProtoFieldNumber = 1,
        TestOneofFieldSecondIntProtoFieldNumber = 2,
    };
    Q_ENUM(QtProtobufFieldEnum)

    enum class TestOneofFields {
        UninitializedField = QtProtobuf::InvalidFieldNumber,
        TestOneofFieldInt = 1,
        TestOneofFieldSecondInt = 2,
    };
    Q_ENUM(TestOneofFields)

    OneofSimpleMessage();
    ~OneofSimpleMessage();
    OneofSimpleMessage(const OneofSimpleMessage &other);
    OneofSimpleMessage &operator =(const OneofSimpleMessage &other);
    OneofSimpleMessage(OneofSimpleMessage &&other) noexcept;
    OneofSimpleMessage &operator =(OneofSimpleMessage &&other) noexcept;
    bool operator ==(const OneofSimpleMessage &other) const;
    bool operator !=(const OneofSimpleMessage &other) const;

    bool hasTestOneofFieldInt() const;
    QtProtobuf::int32 testOneofFieldInt() const;

    bool hasTestOneofFieldSecondInt() const;
    QtProtobuf::int32 testOneofFieldSecondInt() const;
    TestOneofFields testOneofField() const;
    void setTestOneofFieldInt(const QtProtobuf::int32 &testOneofFieldInt);
    void setTestOneofFieldSecondInt(const QtProtobuf::int32 &testOneofFieldSecondInt);
    void clearTestOneof();
    static void registerTypes();

private:
    QtProtobuf::int32 testOneofFieldInt_p() const;
    QtProtobuf::int32 testOneofFieldSecondInt_p() const;
    void setTestOneofFieldInt_p(QtProtobuf::int32 testOneofFieldInt);
    void setTestOneofFieldSecondInt_p(QtProtobuf::int32 testOneofFieldSecondInt);
    QtProtobufPrivate::QProtobufOneof m_testOneof;
};

class OneofComplexMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(OneofComplexMessage)
    Q_PROPERTY(QtProtobuf::int32 testFieldInt READ testFieldInt WRITE setTestFieldInt SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::int32 testOneofFieldInt READ testOneofFieldInt_p WRITE setTestOneofFieldInt_p)
    Q_PROPERTY(bool hasTestOneofFieldInt READ hasTestOneofFieldInt)
    Q_PROPERTY(qtprotobufnamespace::tests::ComplexMessage *testOneofComplexField READ testOneofComplexField_p WRITE setTestOneofComplexField_p)
    Q_PROPERTY(bool hasTestOneofComplexField READ hasTestOneofComplexField)
    Q_PROPERTY(qtprotobufnamespace::tests::ComplexMessage *testOneofSecondComplexField READ testOneofSecondComplexField_p WRITE setTestOneofSecondComplexField_p)
    Q_PROPERTY(bool hasTestOneofSecondComplexField READ hasTestOneofSecondComplexField)
    Q_PROPERTY(QtProtobuf::int32 secondFieldInt READ secondFieldInt_p WRITE setSecondFieldInt_p)
    Q_PROPERTY(bool hasSecondFieldInt READ hasSecondFieldInt)
    Q_PROPERTY(qtprotobufnamespace::tests::ComplexMessage *secondComplexField READ secondComplexField_p WRITE setSecondComplexField_p)
    Q_PROPERTY(bool hasSecondComplexField READ hasSecondComplexField)
    Q_PROPERTY(qtprotobufnamespace::tests::ComplexMessage *secondSecondComplexField READ secondSecondComplexField_p WRITE setSecondSecondComplexField_p)
    Q_PROPERTY(bool hasSecondSecondComplexField READ hasSecondSecondComplexField)

public:
    enum QtProtobufFieldEnum {
        TestFieldIntProtoFieldNumber = 1,
        TestOneofFieldIntProtoFieldNumber = 42,
        TestOneofComplexFieldProtoFieldNumber = 3,
        TestOneofSecondComplexFieldProtoFieldNumber = 4,
        SecondFieldIntProtoFieldNumber = 43,
        SecondComplexFieldProtoFieldNumber = 5,
        SecondSecondComplexFieldProtoFieldNumber = 6,
    };
    Q_ENUM(QtProtobufFieldEnum)

    enum class TestOneofFields {
        UninitializedField = QtProtobuf::InvalidFieldNumber,
        TestOneofFieldInt = 42,
        TestOneofComplexField = 3,
        TestOneofSecondComplexField = 4,
    };
    Q_ENUM(TestOneofFields)

    enum class SecondOneofFields {
        UninitializedField = QtProtobuf::InvalidFieldNumber,
        SecondFieldInt = 43,
        SecondComplexField = 5,
        SecondSecondComplexField = 6,
    };
    Q_ENUM(SecondOneofFields)

    OneofComplexMessage();
    ~OneofComplexMessage();
    OneofComplexMessage(const OneofComplexMessage &other);
    OneofComplexMessage &operator =(const OneofComplexMessage &other);
    OneofComplexMessage(OneofComplexMessage &&other) noexcept;
    OneofComplexMessage &operator =(OneofComplexMessage &&other) noexcept;
    bool operator ==(const OneofComplexMessage &other) const;
    bool operator !=(const OneofComplexMessage &other) const;

    QtProtobuf::int32 testFieldInt() const
    {
        return m_testFieldInt;
    }


    bool hasTestOneofFieldInt() const;
    QtProtobuf::int32 testOneofFieldInt() const;

    bool hasTestOneofComplexField() const;
    ComplexMessage &testOneofComplexField() const;

    bool hasTestOneofSecondComplexField() const;
    ComplexMessage &testOneofSecondComplexField() const;

    bool hasSecondFieldInt() const;
    QtProtobuf::int32 secondFieldInt() const;

    bool hasSecondComplexField() const;
    ComplexMessage &secondComplexField() const;

    bool hasSecondSecondComplexField() const;
    ComplexMessage &secondSecondComplexField() const;
    TestOneofFields testOneofField() const;
    SecondOneofFields secondOneofField() const;
    void setTestFieldInt(const QtProtobuf::int32 &testFieldInt)
    {
        if (m_testFieldInt != testFieldInt)
            m_testFieldInt = testFieldInt;
    }

    void setTestOneofFieldInt(const QtProtobuf::int32 &testOneofFieldInt);
    void setTestOneofComplexField(const ComplexMessage &testOneofComplexField);
    void setTestOneofSecondComplexField(const ComplexMessage &testOneofSecondComplexField);
    void setSecondFieldInt(const QtProtobuf::int32 &secondFieldInt);
    void setSecondComplexField(const ComplexMessage &secondComplexField);
    void setSecondSecondComplexField(const ComplexMessage &secondSecondComplexField);
    void clearTestOneof();
    void clearSecondOneof();
    static void registerTypes();

private:
    QtProtobuf::int32 testOneofFieldInt_p() const;
    ComplexMessage *testOneofComplexField_p() const;
    ComplexMessage *testOneofSecondComplexField_p() const;
    QtProtobuf::int32 secondFieldInt_p() const;
    ComplexMessage *secondComplexField_p() const;
    ComplexMessage *secondSecondComplexField_p() const;
    void setTestOneofFieldInt_p(QtProtobuf::int32 testOneofFieldInt);
    void setTestOneofComplexField_p(ComplexMessage *testOneofComplexField);
    void setTestOneofSecondComplexField_p(ComplexMessage *testOneofSecondComplexField);
    void setSecondFieldInt_p(QtProtobuf::int32 secondFieldInt);
    void setSecondComplexField_p(ComplexMessage *secondComplexField);
    void setSecondSecondComplexField_p(ComplexMessage *secondSecondComplexField);
    QtProtobuf::int32 m_testFieldInt;
    QtProtobufPrivate::QProtobufOneof m_testOneof;
    QtProtobufPrivate::QProtobufOneof m_secondOneof;
};
} // namespace qtprotobufnamespace::tests

Q_DECLARE_METATYPE(qtprotobufnamespace::tests::OneofSimpleMessage)
Q_DECLARE_METATYPE(qtprotobufnamespace::tests::OneofComplexMessage)
#endif // QPROTOBUF_ONEOFMESSAGES_H
