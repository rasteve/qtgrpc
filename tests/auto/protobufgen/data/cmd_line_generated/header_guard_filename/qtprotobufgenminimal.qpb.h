/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QTPROTOBUFGENMINIMAL_QPB_H
#define QTPROTOBUFGENMINIMAL_QPB_H

#include <QtProtobuf/qprotobuflazymessagepointer.h>
#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qtprotobuftypes.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qlist.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qshareddata.h>
#include <QtCore/qstring.h>

namespace qt::protobuf {
class Empty;
namespace Empty_QtProtobufNested {
enum class QtProtobufFieldEnum;
} // namespace Empty_QtProtobufNested

#ifdef QT_USE_PROTOBUF_LIST_ALIASES
using EmptyRepeated = QList<Empty>;
#endif // QT_USE_PROTOBUF_LIST_ALIASES

class Empty_QtProtobufData;
class Empty : public QProtobufMessage
{
    Q_PROTOBUF_OBJECT

public:
    using QtProtobufFieldEnum = Empty_QtProtobufNested::QtProtobufFieldEnum;
    Empty();
    ~Empty();
    Empty(const Empty &other);
    Empty &operator =(const Empty &other);
    Empty(Empty &&other) noexcept;
    Empty &operator =(Empty &&other) noexcept
    {
        swap(other);
        return *this;
    }
    void swap(Empty &other) noexcept
    {
        QProtobufMessage::swap(other);
        dptr.swap(other.dptr);
    }
    Q_IMPLICIT operator QVariant() const;
    static void registerTypes();

private:
    friend bool comparesEqual(const Empty &lhs, const Empty &rhs) noexcept;
    friend bool operator==(const Empty &lhs, const Empty &rhs) noexcept
    {
        return comparesEqual(lhs, rhs);
    }
    friend bool operator!=(const Empty &lhs, const Empty &rhs) noexcept
    {
        return !comparesEqual(lhs, rhs);
    }
    QExplicitlySharedDataPointer<Empty_QtProtobufData> dptr;
};
namespace Empty_QtProtobufNested {
Q_NAMESPACE

} // namespace Empty_QtProtobufNested
} // namespace qt::protobuf

#endif // QTPROTOBUFGENMINIMAL_QPB_H
