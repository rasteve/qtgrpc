// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtGrpc/private/qabstractgrpcchannel_p.h>
#include <QtGrpc/qabstractgrpcchannel.h>
#include <QtGrpc/qgrpccallreply.h>
#include <QtGrpc/qgrpcchanneloptions.h>
#include <QtGrpc/qgrpcdefs.h>
#include <QtGrpc/qgrpcstream.h>

#include <QtCore/qtimer.h>

QT_BEGIN_NAMESPACE

/*!
    \class QAbstractGrpcChannel
    \inmodule QtGrpc
    \brief The QAbstractGrpcChannel class is an interface that represents common
    gRPC channel functionality.

    Implement this interface to create your own custom channel for gRPC
    transportation. We provide the QGrpcHttp2Channel, which is a fully featured
    implementation of the QAbstractGrpcChannel for HTTP/2 communication.
*/

/*!
    \fn virtual std::shared_ptr<QAbstractProtobufSerializer> QAbstractGrpcChannel::serializer() const = 0

    This pure virtual function shall return a shared pointer
    to QAbstractProtobufSerializer.

    This function is called to obtain the QAbstractProtobufSerializer used
    to perform serialization and deserialization of the message.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::call(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0
    \since 6.7

    This pure virtual function is called by public QAbstractGrpcChannel::call
    method when making unary gRPC call. The \a channelOperation is the
    pointer to a channel side \l QGrpcChannelOperation primitive that is
    connected with \l QGrpcCallReply primitive, that is used in
    \l QGrpcClientBase implementations.

    The function should implement the channel-side logic of unary call. The
    implementation must be asynchronous and must not block the thread where
    the function was called.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::startServerStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0
    \since 6.7

    This pure virtual function that the starts of the server-side stream. The
    \a channelOperation is the pointer to a channel side
    \l QGrpcChannelOperation primitive that is connected with \l QGrpcServerStream
    primitive, that is used in \l QGrpcClientBase implementations.

    The function should implement the channel-side logic of server-side stream.
    The implementation must be asynchronous and must not block the thread where
    the function was called.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::startClientStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0
    \since 6.7

    This pure virtual function that the starts of the client-side stream. The
    \a channelOperation is the pointer to a channel side
    \l QGrpcChannelOperation primitive that is connected with
    \l QGrpcClientStream primitive, that is used in \l QGrpcClientBase.

    The function should implement the channel-side logic of client-side stream.
    The implementation must be asynchronous and must not block the thread where
    the function was called.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::startBidirStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0
    \since 6.7

    This pure virtual function that the starts of the bidirectional stream. The
    \a channelOperation is the pointer to a channel side
    \l QGrpcChannelOperation primitive that is connected with
    \l QGrpcBidirStream primitive, that is used in \l QGrpcClientBase.

    The function should implement the channel-side logic of bidirectional
    stream. The implementation must be asynchronous and must not block the
    thread where the function was called.
*/

static std::optional<QGrpcDuration>
deadlineForCall(const QGrpcChannelOptions &channelOptions, const QGrpcCallOptions &callOptions)
{
    if (callOptions.deadline())
        return *callOptions.deadline();
    if (channelOptions.deadline())
        return *channelOptions.deadline();
    return std::nullopt;
}

QAbstractGrpcChannel::QAbstractGrpcChannel()
    : dPtr(std::make_unique<QAbstractGrpcChannelPrivate>(QGrpcChannelOptions{}))
{
}

QAbstractGrpcChannel::QAbstractGrpcChannel(const QGrpcChannelOptions &options)
    : dPtr(std::make_unique<QAbstractGrpcChannelPrivate>(options))
{
}
QAbstractGrpcChannel::~QAbstractGrpcChannel() = default;

/*!
    \internal
    Returns QGrpcChannelOptions used by the channel.
*/
const QGrpcChannelOptions &QAbstractGrpcChannel::channelOptions() const & noexcept
{
    return dPtr->channelOptions;
}

/*!
    \internal
    Function constructs \l QGrpcCallReply and \l QGrpcChannelOperation
    primitives and makes the required for unary gRPC call connections
    between them.

    The function should not be called directly, but only by
    \l QGrpcClientBase implementations.
*/
std::shared_ptr<QGrpcCallReply> QAbstractGrpcChannel::call(QLatin1StringView method,
                                                           QLatin1StringView service,
                                                           QByteArrayView arg,
                                                           const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<
        QGrpcChannelOperation>(method, service, arg, options, serializer(),
                               QGrpcChannelOperation::PrivateConstructor());

    QObject::connect(channelOperation.get(), &QGrpcChannelOperation::writeMessageRequested,
                     channelOperation.get(), []() {
                         Q_ASSERT_X(false, "QAbstractGrpcChannel::call",
                                    "QAbstractGrpcChannel::call disallows the "
                                    "'writeMessageRequested' signal from "
                                    "QGrpcChannelOperation");
                     });

    auto reply = std::make_shared<QGrpcCallReply>(channelOperation);
    call(channelOperation);

    if (auto deadline = deadlineForCall(dPtr->channelOptions, channelOperation->callOptions()))
        QTimer::singleShot(*deadline, reply.get(), &QGrpcCallReply::cancel);

    return reply;
}

/*!
    \internal
    Function constructs \l QGrpcServerStream and \l QGrpcChannelOperation
    primitives and makes the required for server-side gRPC stream connections
    between them.

    The function should not be called directly, but only by
    \l QGrpcClientBase implementations.
*/
std::shared_ptr<QGrpcServerStream>
QAbstractGrpcChannel::startServerStream(QLatin1StringView method, QLatin1StringView service,
                                        QByteArrayView arg, const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<
        QGrpcChannelOperation>(method, service, arg, options, serializer(),
                               QGrpcChannelOperation::PrivateConstructor());

    QObject::connect(channelOperation.get(), &QGrpcChannelOperation::writeMessageRequested,
                     channelOperation.get(), []() {
                         Q_ASSERT_X(false, "QAbstractGrpcChannel::startServerStream",
                                    "QAbstractGrpcChannel::startServerStream disallows "
                                    "the 'writeMessageRequested' signal from "
                                    "QGrpcChannelOperation");
                     });

    auto stream = std::make_shared<QGrpcServerStream>(channelOperation);
    startServerStream(channelOperation);

    if (auto deadline = deadlineForCall(dPtr->channelOptions, channelOperation->callOptions()))
        QTimer::singleShot(*deadline, stream.get(), &QGrpcServerStream::cancel);

    return stream;
}

/*!
    \internal
    Function constructs \l QGrpcClientStream and \l QGrpcChannelOperation
    primitives and makes the required for client-side gRPC stream connections
    between them.

    The function should not be called directly, but only by
    \l QGrpcClientBase.
*/
std::shared_ptr<QGrpcClientStream>
QAbstractGrpcChannel::startClientStream(QLatin1StringView method, QLatin1StringView service,
                                        QByteArrayView arg, const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<
        QGrpcChannelOperation>(method, service, arg, options, serializer(),
                               QGrpcChannelOperation::PrivateConstructor());

    auto stream = std::make_shared<QGrpcClientStream>(channelOperation);
    startClientStream(channelOperation);

    if (auto deadline = deadlineForCall(dPtr->channelOptions, channelOperation->callOptions()))
        QTimer::singleShot(*deadline, stream.get(), &QGrpcClientStream::cancel);

    return stream;
}

/*!
    \internal
    Function constructs \l QGrpcBidirStream and \l QGrpcChannelOperation
    primitives and makes the required for bidirectional gRPC stream connections
    between them.

    The function should not be called directly, but only by
    \l QGrpcClientBase.
*/
std::shared_ptr<QGrpcBidirStream>
QAbstractGrpcChannel::startBidirStream(QLatin1StringView method, QLatin1StringView service,
                                       QByteArrayView arg, const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<
        QGrpcChannelOperation>(method, service, arg, options, serializer(),
                               QGrpcChannelOperation::PrivateConstructor());

    auto stream = std::make_shared<QGrpcBidirStream>(channelOperation);
    startBidirStream(channelOperation);

    if (auto deadline = deadlineForCall(dPtr->channelOptions, channelOperation->callOptions()))
        QTimer::singleShot(*deadline, stream.get(), &QGrpcBidirStream::cancel);

    return stream;
}

QT_END_NAMESPACE
