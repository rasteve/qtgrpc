// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QGRPCSERIALIZATIONFORMAT_H
#define QGRPCSERIALIZATIONFORMAT_H

#include <QtCore/qbytearrayview.h>
#include <QtCore/qtclasshelpermacros.h>
#include <QtGrpc/qtgrpcglobal.h>

#include <memory>

QT_BEGIN_NAMESPACE

class QGrpcSerializationFormatPrivate;
class QAbstractProtobufSerializer;

class QGrpcSerializationFormat final
{
public:
    enum Format : quint8 {
        Default = 0,
        Protobuf,
        Json,
    };

    Q_GRPC_EXPORT explicit QGrpcSerializationFormat(Format format = Format::Default);
    Q_GRPC_EXPORT QGrpcSerializationFormat(QByteArrayView suffix,
                                           std::shared_ptr<QAbstractProtobufSerializer> serializer);

    Q_GRPC_EXPORT ~QGrpcSerializationFormat();

    Q_GRPC_EXPORT QGrpcSerializationFormat(const QGrpcSerializationFormat &);
    Q_GRPC_EXPORT QGrpcSerializationFormat(QGrpcSerializationFormat &&);

    Q_GRPC_EXPORT QGrpcSerializationFormat &operator=(const QGrpcSerializationFormat &);
    Q_GRPC_EXPORT QGrpcSerializationFormat &operator=(QGrpcSerializationFormat &&);

    [[nodiscard]] Q_GRPC_EXPORT QByteArray suffix() const noexcept;
    [[nodiscard]] Q_GRPC_EXPORT std::shared_ptr<QAbstractProtobufSerializer>
    serializer() const noexcept;

private:
    std::unique_ptr<QGrpcSerializationFormatPrivate> dPtr;
};

QT_END_NAMESPACE

#endif // QGRPCSERIALIZATIONFORMAT_H
