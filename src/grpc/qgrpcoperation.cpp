// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtCore/private/qobject_p.h>
#include <QtCore/qatomic.h>
#include <QtCore/qeventloop.h>
#include <QtCore/qpointer.h>
#include <QtGrpc/private/qtgrpcglobal_p.h>
#include <QtGrpc/qgrpcchanneloperation.h>
#include <QtGrpc/qgrpcoperation.h>

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

/*!
    \class QGrpcOperation
    \inmodule QtGrpc
    \brief The QGrpcOperation class implements common logic to
           handle the gRPC communication from the client side.
*/

/*!
    \fn template <typename T> std::optional<T> QGrpcOperation::read() const

    Reads a message from a raw byte array stored within this QGrpcOperation
    instance.

    Returns an optional deserialized message. On failure, \c {std::nullopt} is
    returned.

    The error can be retrieved using \l deserializationError.

    \sa read, deserializationError, deserializationErrorString
*/

/*!
    \fn void QGrpcOperation::finished(const QGrpcStatus &status)

    This signal indicates the end of communication for this call.

    If this signal is emitted the respective operation when it's finished with
    the respective \a status.
*/

class QGrpcOperationPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QGrpcOperation)
public:
    QGrpcOperationPrivate(std::shared_ptr<QGrpcChannelOperation> _channelOperation)
        : channelOperation(std::move(_channelOperation))
    {
    }

    QByteArray data;
    std::shared_ptr<QGrpcChannelOperation> channelOperation;
    QAtomicInteger<bool> isFinished{ false };
};

QGrpcOperation::QGrpcOperation(std::shared_ptr<QGrpcChannelOperation> channelOperation,
                               QObject *parent)
    : QObject(*new QGrpcOperationPrivate(std::move(channelOperation)), parent)
{
    [[maybe_unused]] bool valid = QObject::connect(d_func()->channelOperation.get(),
                                                   &QGrpcChannelOperation::messageReceived, this,
                                                   [this](const QByteArray &data) {
                                                       Q_D(QGrpcOperation);
                                                       d->data = data;
                                                   });
    Q_ASSERT_X(valid, "QGrpcOperation::QGrpcOperation",
               "Unable to make connection to the 'messageReceived' signal");

    valid = QObject::connect(d_func()->channelOperation.get(), &QGrpcChannelOperation::finished,
                             this, [this](const QGrpcStatus &status) {
                                 if (!isFinished()) {
                                     d_func()->isFinished.storeRelaxed(true);
                                     emit this->finished(status);
                                 }
                             });
    Q_ASSERT_X(valid, "QGrpcOperation::QGrpcOperation",
               "Unable to make connection to the 'finished' signal");
}

QGrpcOperation::~QGrpcOperation() = default;

/*!
    \internal
    Getter of the data received from the channel.
*/
QByteArray QGrpcOperation::data() const noexcept
{
    return d_func()->data;
}

/*!
    \since 6.8
    Reads a message from a raw byte array which is stored within this
    QGrpcOperation instance.

    The function writes the deserialized value to the \a message pointer.

    If the deserialization is successful, this function returns \c true.
    Otherwise, it returns \c false, and the error can be retrieved with \l
    deserializationError.

    \sa read, deserializationError, deserializationErrorString
*/
bool QGrpcOperation::read(QProtobufMessage *message) const
{
    Q_ASSERT_X(message != nullptr, "QGrpcOperation::read",
               "Can't read to nullptr QProtobufMessage");
    const auto ser = d_func()->channelOperation->serializer();
    return ser && ser->deserialize(message, data());
}

/*!
   \since 6.8

   Returns the last deserialization error.

   \sa QAbstractProtobufSerializer::deserializationError
*/
QAbstractProtobufSerializer::DeserializationError QGrpcOperation::deserializationError() const
{
    const auto ser = d_func()->channelOperation->serializer();
    if (!ser)
        return QAbstractProtobufSerializer::NoDeserializerError;
    return ser->deserializationError();
}

/*!
   \since 6.8

   Returns the last deserialization error string.

   \sa QAbstractProtobufSerializer::deserializationErrorString
*/
QString QGrpcOperation::deserializationErrorString() const
{
    const auto ser = d_func()->channelOperation->serializer();
    if (!ser)
        return QStringLiteral("serializer not available");
    return ser->deserializationErrorString();
}

/*!
    Getter of the metadata received from the channel. For the HTTP2 channels it
    usually contains the HTTP headers received from the server.
*/
const QGrpcMetadata &QGrpcOperation::metadata() const noexcept
{
    return d_func()->channelOperation->serverMetadata();
}

/*!
    Getter of the method that this operation was initialized with.
*/
QLatin1StringView QGrpcOperation::method() const noexcept
{
    return d_func()->channelOperation->method();
}

/*!
    T.B.A
*/
void QGrpcOperation::cancel()
{
    if (!isFinished()) {
        d_func()->isFinished.storeRelaxed(true);
        emit d_func()->channelOperation->cancelRequested();
        Q_EMIT finished(QGrpcStatus{ QGrpcStatus::Cancelled,
                                     tr("Operation is cancelled by client") });
    }
}

/*!
    Returns true when QGrpcOperation finished its workflow,
    meaning it was finished, canceled, or error occurred, otherwise returns false.
*/
bool QGrpcOperation::isFinished() const noexcept
{
    return d_func()->isFinished.loadRelaxed();
}

/*!
    \internal
    Returns a pointer to the assigned channel-side QGrpcChannelOperation.
*/
QGrpcChannelOperation *QGrpcOperation::channelOperation() const noexcept
{
    return d_func()->channelOperation.get();
}

QT_END_NAMESPACE

#include "moc_qgrpcoperation.cpp"
