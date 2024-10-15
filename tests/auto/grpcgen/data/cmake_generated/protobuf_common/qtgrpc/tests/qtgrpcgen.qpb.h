/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QTGRPCGEN_QPB_H
#define QTGRPCGEN_QPB_H

#include "tst_qtgrpcgen_protobuf_common_exports.qpb.h"

#include <QtProtobuf/qprotobuflazymessagepointer.h>
#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qtprotobuftypes.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qlist.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

namespace qtgrpc::tests {
class IntMessage;
using IntMessageRepeated = QList<IntMessage>;
namespace IntMessage_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace IntMessage_QtProtobufNested


class IntMessage_QtProtobufData;
class IntMessage : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT_EXPORT(QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT)
    Q_PROPERTY(QtProtobuf::sint32 field READ field WRITE setField SCRIPTABLE true)

public:
    using QtProtobufFieldEnum = IntMessage_QtProtobufNested::QtProtobufFieldEnum;
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT IntMessage();
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT ~IntMessage();
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT IntMessage(const IntMessage &other);
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT IntMessage &operator =(const IntMessage &other);
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT IntMessage(IntMessage &&other) noexcept;
    IntMessage &operator =(IntMessage &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(IntMessage &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT Q_IMPLICIT operator QVariant() const;

    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT QtProtobuf::sint32 field() const;
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT void setField(QtProtobuf::sint32 field);
    QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT static void registerTypes();

private:
    friend QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT bool comparesEqual(const IntMessage &lhs, const IntMessage &rhs) noexcept;
    friend bool operator==(const IntMessage &lhs, const IntMessage &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const IntMessage &lhs, const IntMessage &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<IntMessage_QtProtobufData> dptr;
};
namespace IntMessage_QtProtobufNested {
Q_NAMESPACE_EXPORT(QPB_TST_QTGRPCGEN_PROTOBUF_COMMON_EXPORT)

enum class QtProtobufFieldEnum {
    FieldProtoFieldNumber = 1,
};
Q_ENUM_NS(QtProtobufFieldEnum)

} // namespace IntMessage_QtProtobufNested
} // namespace qtgrpc::tests

#endif // QTGRPCGEN_QPB_H
