// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qprotobufmessage_p.h"
#include "qprotobufmessage.h"

#include <QtCore/qmetaobject.h>

QT_BEGIN_NAMESPACE
/*!
    \class QProtobufMessage
    \inmodule QtProtobuf

    \brief Base class for all protobuf messages.

    Provides access to the properties of a message, using setProperty()
    and property(), without depending on what the message is.
*/


/*!
    \internal
    Used from generated classes to construct the QProtobufMessage base class.
    Internally the \a metaObject is used to query QMetaProperty
*/
QProtobufMessage::QProtobufMessage(const QMetaObject *metaObject)
    : d_ptr(new QProtobufMessagePrivate)
{
    d_ptr->metaObject = metaObject;
}

/*!
    \internal
    The QMetaObject which was passed to the QProtobufMessage constructor.
*/
const QMetaObject *QProtobufMessage::metaObject() const
{
    return d_ptr->metaObject;
}

/*!
    \internal
*/
int QProtobufMessagePrivate::getPropertyIndex(QAnyStringView propertyName) const
{
    return propertyName.visit([this](auto propertyName) {
        if constexpr (std::is_same_v<QStringView, decltype(propertyName)>) {
            return metaObject->indexOfProperty(propertyName.toLatin1().constData());
        } else if constexpr (std::is_same_v<QUtf8StringView, decltype(propertyName)>) {
            return metaObject->indexOfProperty(propertyName.toString().toLatin1().constData());
        } else if constexpr (std::is_same_v<QLatin1StringView, decltype(propertyName)>) {
            return metaObject->indexOfProperty(propertyName.constData());
        }
        return -1;
    });
}

/*!
    Set the property \a propertyName to the value stored in \a value.

    If the \a propertyName isn't part of the known fields then the value will
    not be written and the function returns \c false.

    Returns \c false if it failed to store the \a value on the property.
    Otherwise \c{true}.
*/
bool QProtobufMessage::setProperty(QAnyStringView propertyName, const QVariant &value)
{
    Q_D(QProtobufMessage);

    int index = d->getPropertyIndex(propertyName);
    const QMetaProperty &property = d->metaObject->property(index);
    if (!property.isValid())
        return false;
    return property.writeOnGadget(this, value);
}

/*!
    Get the value of the property \a propertyName.

    If the \a propertyName isn't known then the returned QVariant is invalid.
*/
QVariant QProtobufMessage::property(QAnyStringView propertyName) const
{
    Q_D(const QProtobufMessage);

    int index = d->getPropertyIndex(propertyName);
    const QMetaProperty &property = d->metaObject->property(index);
    return property.readOnGadget(this);
}

/*!
    \internal
*/
QProtobufMessage::QProtobufMessage(const QProtobufMessage &other)
    : d_ptr(new QProtobufMessagePrivate(*other.d_ptr))
{
}

/*!
    \internal
*/
QProtobufMessage &QProtobufMessage::operator=(const QProtobufMessage &other)
{
    if (this != &other)
        *d_ptr = *other.d_ptr;
    return *this;
}

/*!
    \internal
*/
QProtobufMessage::~QProtobufMessage()
{
    delete d_ptr;
}

/*!
    \internal
*/
bool QProtobufMessage::isEqual(const QProtobufMessage &lhs, const QProtobufMessage &rhs) noexcept
{
    if (lhs.d_ptr == rhs.d_ptr)
        return true;
    return lhs.d_func()->unknownEntries == rhs.d_func()->unknownEntries;
}

QT_END_NAMESPACE

#include "moc_qprotobufmessage.cpp"
