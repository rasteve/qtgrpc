// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include "qabstractgrpcchannel.h"
#include "qabstractgrpcchannel_p.h"
#include "qgrpcchanneloperation.h"
#include "qgrpccallreply.h"
#include "qgrpcstream.h"

QT_BEGIN_NAMESPACE

/*!
    \class QAbstractGrpcChannel
    \inmodule QtGrpc
    \brief The QAbstractGrpcChannel class is interface that represents common
    gRPC channel functionality.

    You may implement this interface to create your own channels for gRPC transport.
    QGrpcChannel or QGrpcHttp2Channel, which are full implementations of
    QAbstractGrpcChannel are recommended to use.
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

    This pure virtual function is called by public QAbstractGrpcChannel::call
    method when making unary gRPC call. The \a channelOperation is the
    pointer to a channel side \l QGrpcChannelOperation primitive that is
    connected with \l QGrpcCallReply primitive, that is used in
    \l QAbstractGrpcClient implementations.

    The function should implement the channel-side logic of unary call. The
    implementation must be asynchronous and must not block the thread where
    the function was called.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::startServerStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0

    This pure virtual function that the starts of the server-side stream. The
    \a channelOperation is the pointer to a channel side
    \l QGrpcChannelOperation primitive that is connected with \l QGrpcServerStream
    primitive, that is used in \l QAbstractGrpcClient implementations.

    The function should implement the channel-side logic of server-side stream.
    The implementation must be asynchronous and must not block the thread where
    the function was called.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::startClientStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0

    This pure virtual function that the starts of the client-side stream. The
    \a channelOperation is the pointer to a channel side
    \l QGrpcChannelOperation primitive that is connected with
    \l QGrpcClientStream primitive, that is used in \l QAbstractGrpcClient.

    The function should implement the channel-side logic of client-side stream.
    The implementation must be asynchronous and must not block the thread where
    the function was called.
*/

/*!
    \fn virtual void QAbstractGrpcChannel::startBidirStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0

    This pure virtual function that the starts of the bidirectional stream. The
    \a channelOperation is the pointer to a channel side
    \l QGrpcChannelOperation primitive that is connected with
    \l QGrpcBidirStream primitive, that is used in \l QAbstractGrpcClient.

    The function should implement the channel-side logic of bidirectional
    stream. The implementation must be asynchronous and must not block the
    thread where the function was called.
*/
QAbstractGrpcChannel::QAbstractGrpcChannel() : dPtr(std::make_unique<QAbstractGrpcChannelPrivate>())
{
}
QAbstractGrpcChannel::~QAbstractGrpcChannel() = default;

/*!
    \internal
    Function constructs \l QGrpcCallReply and \l QGrpcChannelOperation
    primitives and makes the required for unary gRPC call connections
    between them.

    The function should not be called directly, but only by
    \l QAbstractGrpcClient implementations.
*/
std::shared_ptr<QGrpcCallReply> QAbstractGrpcChannel::call(QLatin1StringView method,
                                                           QLatin1StringView service,
                                                           QByteArrayView arg,
                                                           const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<QGrpcChannelOperation>(method, service, arg, options);
    QObject::connect(channelOperation.get(), &QGrpcChannelOperation::sendData, []() {
        Q_ASSERT_X(false, "QAbstractGrpcChannel::call",
                   "QAbstractGrpcChannel::call disallows sendData signal from "
                   "QGrpcChannelOperation");
    });
    std::shared_ptr<QGrpcCallReply> reply(new QGrpcCallReply(channelOperation, serializer()),
                                          [](QGrpcCallReply *reply) { reply->deleteLater(); });
    call(channelOperation);
    return reply;
}

/*!
    \internal
    Function constructs \l QGrpcServerStream and \l QGrpcChannelOperation
    primitives and makes the required for server-side gRPC stream connections
    between them.

    The function should not be called directly, but only by
    \l QAbstractGrpcClient implementations.
*/
std::shared_ptr<QGrpcServerStream>
QAbstractGrpcChannel::startServerStream(QLatin1StringView method, QLatin1StringView service,
                                        QByteArrayView arg, const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<QGrpcChannelOperation>(method, service, arg, options);
    QObject::connect(channelOperation.get(), &QGrpcChannelOperation::sendData, []() {
        Q_ASSERT_X(false, "QAbstractGrpcChannel::startServerStream",
                   "QAbstractGrpcChannel::startServerStream disallows sendData signal from "
                   "QGrpcChannelOperation");
    });

    std::shared_ptr<QGrpcServerStream> stream(
            new QGrpcServerStream(channelOperation, serializer()));
    startServerStream(channelOperation);
    return stream;
}

/*!
    \internal
    Function constructs \l QGrpcClientStream and \l QGrpcChannelOperation
    primitives and makes the required for client-side gRPC stream connections
    between them.

    The function should not be called directly, but only by
    \l QAbstractGrpcClient.
*/
std::shared_ptr<QGrpcClientStream>
QAbstractGrpcChannel::startClientStream(QLatin1StringView method, QLatin1StringView service,
                                        QByteArrayView arg, const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<QGrpcChannelOperation>(method, service, arg, options);
    auto stream = std::make_shared<QGrpcClientStream>(channelOperation, serializer());
    startClientStream(channelOperation);
    return stream;
}

/*!
    \internal
    Function constructs \l QGrpcBidirStream and \l QGrpcChannelOperation
    primitives and makes the required for bidirectional gRPC stream connections
    between them.

    The function should not be called directly, but only by
    \l QAbstractGrpcClient.
*/
std::shared_ptr<QGrpcBidirStream>
QAbstractGrpcChannel::startBidirStream(QLatin1StringView method, QLatin1StringView service,
                                       QByteArrayView arg, const QGrpcCallOptions &options)
{
    auto channelOperation = std::make_shared<QGrpcChannelOperation>(method, service, arg, options);
    auto stream = std::make_shared<QGrpcBidirStream>(channelOperation, serializer());
    startBidirStream(channelOperation);
    return stream;
}

QT_END_NAMESPACE
