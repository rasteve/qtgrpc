// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <QtProtobuf/qabstractprotobufserializer.h>

#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufpropertyordering.h>

QT_BEGIN_NAMESPACE

/*!
    \class QAbstractProtobufSerializer
    \inmodule QtProtobuf
    \since 6.5
    \brief The QAbstractProtobufSerializer class is interface that represents
           basic functions for serialization/deserialization.
    \reentrant

    The QProtobufSerializer class registers serializers/deserializers for
    classes implementing a protobuf message, inheriting \l QProtobufMessage. These
    classes are generated automatically, based on a \c{.proto} file, using the CMake
    function \l qt_add_protobuf or by running
    \l {The qtprotobufgen Tool} {qtprotobufgen} directly.

    This class should be used as a base for specific serializers. The handlers
    property contains all message-specific serializers and should be used while
    serialization/deserialization. Inherited classes should reimplement scope of
    virtual methods that used by registered message
    serialization/deserialization functions.
*/

/*!
    \enum QAbstractProtobufSerializer::DeserializationError

    This enum contains possible errors that can occur during deserialization.
    When an error occurs, call deserializationErrorString() to get a
    human-readable error message.

    \value NoError                      No error occurred.
    \value InvalidHeaderError           Something went wrong while attempting to
                                        decode a header in the message.
    \value NoDeserializerError          While deserializing a message, no
                                        deserializer was found for a type in the
                                        message.
    \value UnexpectedEndOfStreamError   While deserializing a message, the
                                        stream ended unexpectedly.
    \value InvalidFormatError           The data has invalid format. For example
                                        the JSON value doesn't match the field type.
*/

/*!
    Destroys this QAbstractProtobufSerializer.
*/
QAbstractProtobufSerializer::~QAbstractProtobufSerializer() = default;

/*!
    \fn QByteArray QAbstractProtobufSerializer::serializeMessage(const QProtobufMessage *message, const QtProtobufPrivate::QProtobufPropertyOrdering &ordering) const

    This is called by serialize() to serialize a registered Protobuf message
    \a message with \a ordering. \a message must not be \nullptr.
    Returns a QByteArray containing the serialized message.
*/

/*!
    \fn bool QAbstractProtobufSerializer::deserializeMessage(QProtobufMessage *message, const QtProtobufPrivate::QProtobufPropertyOrdering &ordering, QByteArrayView data) const

    This is called by deserialize() to deserialize a registered Protobuf message
    \a message with \a ordering from a QByteArrayView \a data. \a message can be
    assumed to not be \nullptr.
    Returns \c true if deserialization was successful, otherwise \c false.
*/

namespace QtProtobufPrivate {
extern QtProtobufPrivate::QProtobufPropertyOrdering getOrderingByMetaType(QMetaType type);
}

/*!
    \fn QAbstractProtobufSerializer::serialize(const QProtobufMessage *message) const

    Serializes a registered Protobuf message \a message into a QByteArray.
    \a message must not be \nullptr.

    \sa deserialize()
*/
QByteArray QAbstractProtobufSerializer::serialize(const QProtobufMessage *message) const
{
    Q_ASSERT(message != nullptr && message->propertyOrdering() != nullptr
             && message->propertyOrdering()->data != nullptr);
    return serializeMessage(message, *message->propertyOrdering());
}

/*!
    \fn QAbstractProtobufSerializer::deserialize(QProtobufMessage *message, QByteArrayView data) const

    Deserializes a registered Protobuf message \a message from a QByteArray
    \a data. \a message must not be \nullptr.
    Returns \c true if deserialization was successful, otherwise \c false.

    Unexpected/unknown properties in the \a data are skipped.

    \sa serialize()
*/
bool QAbstractProtobufSerializer::deserialize(QProtobufMessage *message, QByteArrayView data) const
{
    Q_ASSERT(message != nullptr && message->propertyOrdering() != nullptr
             && message->propertyOrdering()->data != nullptr);
    // Wipe the message using the default constructor.
    message->metaObject()->metaType().construct(message);
    return deserializeMessage(message, *message->propertyOrdering(), data);
}

QT_END_NAMESPACE
