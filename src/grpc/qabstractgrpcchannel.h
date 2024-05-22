// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QABSTRACTGRPCCHANNEL_H
#define QABSTRACTGRPCCHANNEL_H

#include <QtGrpc/qgrpccalloptions.h>
#include <QtGrpc/qgrpcstatus.h>
#include <QtGrpc/qtgrpcglobal.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qstring.h>
#include <QtCore/qthread.h>

#include <memory>

QT_BEGIN_NAMESPACE

class QAbstractProtobufSerializer;
class QAbstractGrpcChannelPrivate;
class QGrpcBidirStream;
class QGrpcCallReply;
class QGrpcChannelOperation;
class QGrpcChannelOptions;
class QGrpcClientBase;
class QGrpcClientStream;
class QGrpcServerStream;

class Q_GRPC_EXPORT QAbstractGrpcChannel
{
public:
    virtual ~QAbstractGrpcChannel();

    [[nodiscard]] virtual std::shared_ptr<QAbstractProtobufSerializer>
    serializer() const noexcept = 0;

    // Abstract interface should never be a rvalue.
    void channelOptions() && = delete;

protected:
    std::shared_ptr<QGrpcCallReply> call(QLatin1StringView method, QLatin1StringView service,
                                         QByteArrayView arg,
                                         const QGrpcCallOptions &options);
    std::shared_ptr<QGrpcServerStream>
    startServerStream(QLatin1StringView method, QLatin1StringView service, QByteArrayView arg,
                      const QGrpcCallOptions &options);
    std::shared_ptr<QGrpcClientStream>
    startClientStream(QLatin1StringView method, QLatin1StringView service, QByteArrayView arg,
                      const QGrpcCallOptions &options);
    std::shared_ptr<QGrpcBidirStream>
    startBidirStream(QLatin1StringView method, QLatin1StringView service, QByteArrayView arg,
                     const QGrpcCallOptions &options);

    virtual void call(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0;
    virtual void startServerStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0;
    virtual void startClientStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0;
    virtual void startBidirStream(std::shared_ptr<QGrpcChannelOperation> channelOperation) = 0;

    [[nodiscard]] const QGrpcChannelOptions &channelOptions() const & noexcept;

    friend class QGrpcClientBase;
    explicit QAbstractGrpcChannel(const QGrpcChannelOptions &options);

private:
    Q_DISABLE_COPY_MOVE(QAbstractGrpcChannel)
    std::unique_ptr<QAbstractGrpcChannelPrivate> dPtr;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QAbstractGrpcChannel *)
Q_DECLARE_METATYPE(std::shared_ptr<QAbstractGrpcChannel>)

#endif // QABSTRACTGRPCCHANNEL_H
