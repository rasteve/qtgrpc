/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef Q_PROTOBUF_anymessages_H
#define Q_PROTOBUF_anymessages_H

#include <QtProtobuf/QProtobufMessage>
#include <QtCore/QMetaType>
#include <QtCore/QList>

#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qprotobuflazymessagepointer.h>

#include <memory>

#include <QByteArray>
#include <QString>
#include <QtProtobufWellKnownTypes/qprotobufanysupport.h>


namespace qtproto::tests {
class AnyMessage;
using AnyMessageRepeated = QList<std::shared_ptr<AnyMessage>>;
class RepeatedAnyMessage;
using RepeatedAnyMessageRepeated = QList<std::shared_ptr<RepeatedAnyMessage>>;
class TwoAnyMessage;
using TwoAnyMessageRepeated = QList<std::shared_ptr<TwoAnyMessage>>;
class Example;
using ExampleRepeated = QList<std::shared_ptr<Example>>;
class SimpleMessage;
using SimpleMessageRepeated = QList<std::shared_ptr<SimpleMessage>>;

class  AnyMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(AnyMessage)
    Q_PROPERTY(QtProtobuf::Any field READ field WRITE setField SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        FieldProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    AnyMessage();
    ~AnyMessage();
    AnyMessage(const AnyMessage &other);
    AnyMessage &operator =(const AnyMessage &other);
    AnyMessage(AnyMessage &&other) noexcept;
    AnyMessage &operator =(AnyMessage &&other) noexcept;
    bool operator ==(const AnyMessage &other) const;
    bool operator !=(const AnyMessage &other) const;

    QtProtobuf::Any field() const {
        return m_field;
    }

    void setField(const QtProtobuf::Any &field);
    static void registerTypes();

private:
    QtProtobuf::Any m_field;
};


class  RepeatedAnyMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(RepeatedAnyMessage)
    Q_PROPERTY(QList<QtProtobuf::Any> anysData READ anys WRITE setAnys SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        AnysProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    RepeatedAnyMessage();
    ~RepeatedAnyMessage();
    RepeatedAnyMessage(const RepeatedAnyMessage &other);
    RepeatedAnyMessage &operator =(const RepeatedAnyMessage &other);
    RepeatedAnyMessage(RepeatedAnyMessage &&other) noexcept;
    RepeatedAnyMessage &operator =(RepeatedAnyMessage &&other) noexcept;
    bool operator ==(const RepeatedAnyMessage &other) const;
    bool operator !=(const RepeatedAnyMessage &other) const;

    QList<QtProtobuf::Any> anys() const {
        return m_anys;
    }

    QList<QtProtobuf::Any> &anys() {
        return m_anys;
    }

    void setAnys(const QList<QtProtobuf::Any> &anys);
    static void registerTypes();

private:
    QList<QtProtobuf::Any> m_anys;
};


class  TwoAnyMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(TwoAnyMessage)
    Q_PROPERTY(QtProtobuf::Any one READ one WRITE setOne SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::Any two READ two WRITE setTwo SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        OneProtoFieldNumber = 1,
        TwoProtoFieldNumber = 2,
    };
    Q_ENUM(QtProtobufFieldEnum)

    TwoAnyMessage();
    ~TwoAnyMessage();
    TwoAnyMessage(const TwoAnyMessage &other);
    TwoAnyMessage &operator =(const TwoAnyMessage &other);
    TwoAnyMessage(TwoAnyMessage &&other) noexcept;
    TwoAnyMessage &operator =(TwoAnyMessage &&other) noexcept;
    bool operator ==(const TwoAnyMessage &other) const;
    bool operator !=(const TwoAnyMessage &other) const;

    QtProtobuf::Any one() const {
        return m_one;
    }


    QtProtobuf::Any two() const {
        return m_two;
    }

    void setOne(const QtProtobuf::Any &one);
    void setTwo(const QtProtobuf::Any &two);
    static void registerTypes();

private:
    QtProtobuf::Any m_one;
    QtProtobuf::Any m_two;
};


class  Example : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(Example)
    Q_PROPERTY(QString str READ str WRITE setStr SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 i READ i WRITE setI SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 j READ j WRITE setJ SCRIPTABLE true)
    Q_PROPERTY(QtProtobuf::sint32 h READ h WRITE setH SCRIPTABLE true)
    Q_PROPERTY(QString str2 READ str2 WRITE setStr2 SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        StrProtoFieldNumber = 1,
        IProtoFieldNumber = 2,
        JProtoFieldNumber = 3,
        HProtoFieldNumber = 4,
        Str2ProtoFieldNumber = 5,
    };
    Q_ENUM(QtProtobufFieldEnum)

    Example();
    ~Example();
    Example(const Example &other);
    Example &operator =(const Example &other);
    Example(Example &&other) noexcept;
    Example &operator =(Example &&other) noexcept;
    bool operator ==(const Example &other) const;
    bool operator !=(const Example &other) const;

    QString str() const {
        return m_str;
    }


    QtProtobuf::sint32 i() const {
        return m_i;
    }


    QtProtobuf::sint32 j() const {
        return m_j;
    }


    QtProtobuf::sint32 h() const {
        return m_h;
    }


    QString str2() const {
        return m_str2;
    }

    void setStr(const QString &str);
    void setI(const QtProtobuf::sint32 &i) {
        if (m_i != i)
            m_i = i;
    }

    void setJ(const QtProtobuf::sint32 &j) {
        if (m_j != j)
            m_j = j;
    }

    void setH(const QtProtobuf::sint32 &h) {
        if (m_h != h)
            m_h = h;
    }

    void setStr2(const QString &str2);
    static void registerTypes();

private:
    QString m_str;
    QtProtobuf::sint32 m_i;
    QtProtobuf::sint32 m_j;
    QtProtobuf::sint32 m_h;
    QString m_str2;
};


class  SimpleMessage : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(SimpleMessage)
    Q_PROPERTY(QtProtobuf::int32 i READ i WRITE setI SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        IProtoFieldNumber = 500000,
    };
    Q_ENUM(QtProtobufFieldEnum)

    SimpleMessage();
    ~SimpleMessage();
    SimpleMessage(const SimpleMessage &other);
    SimpleMessage &operator =(const SimpleMessage &other);
    SimpleMessage(SimpleMessage &&other) noexcept;
    SimpleMessage &operator =(SimpleMessage &&other) noexcept;
    bool operator ==(const SimpleMessage &other) const;
    bool operator !=(const SimpleMessage &other) const;

    QtProtobuf::int32 i() const {
        return m_i;
    }

    void setI(const QtProtobuf::int32 &i) {
        if (m_i != i)
            m_i = i;
    }

    static void registerTypes();

private:
    QtProtobuf::int32 m_i;
};

} // namespace qtproto::tests

Q_DECLARE_METATYPE(qtproto::tests::AnyMessage)
Q_DECLARE_METATYPE(qtproto::tests::RepeatedAnyMessage)
Q_DECLARE_METATYPE(qtproto::tests::TwoAnyMessage)
Q_DECLARE_METATYPE(qtproto::tests::Example)
Q_DECLARE_METATYPE(qtproto::tests::SimpleMessage)
#endif // Q_PROTOBUF_anymessages_H
