// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QTQMLGRPCSTREAMSENDER_H
#define QTQMLGRPCSTREAMSENDER_H

#include <QtGrpcQuick/qtgrpcquickexports.h>

#include <QtGrpc/qgrpcstream.h>

#include <QtProtobuf/qprotobufmessage.h>

QT_BEGIN_NAMESPACE

#if 0 // Avoid generating any CaMeL-case header aliases.
#  pragma qt_sync_suspend_processing
#endif

namespace QtQmlGrpcStreamSender {
bool isValidStream(const QGrpcOperation *stream);
}

class QQmlGrpcClientStreamSenderPrivate;
class Q_GRPCQUICK_EXPORT QQmlGrpcClientStreamSender : public QObject
{
    Q_OBJECT
public:
    ~QQmlGrpcClientStreamSender() override;

protected:
    explicit  QQmlGrpcClientStreamSender(std::shared_ptr<QGrpcClientStream> stream,
                                         QObject *parent = nullptr);

    void writeMessageImpl(const QProtobufMessage &message) const;

private:
    Q_DECLARE_PRIVATE(QQmlGrpcClientStreamSender)
    Q_DISABLE_COPY_MOVE(QQmlGrpcClientStreamSender)
};

class QQmlGrpcBidiStreamSenderPrivate;
class Q_GRPCQUICK_EXPORT QQmlGrpcBidiStreamSender : public QObject
{
    Q_OBJECT
public:
    ~QQmlGrpcBidiStreamSender() override;

protected:
    explicit QQmlGrpcBidiStreamSender(std::shared_ptr<QGrpcBidiStream> stream,
                                       QObject *parent = nullptr);

    void writeMessageImpl(const QProtobufMessage &message) const;

private:
    Q_DECLARE_PRIVATE(QQmlGrpcBidiStreamSender)
    Q_DISABLE_COPY_MOVE(QQmlGrpcBidiStreamSender)
};

#if 0
#  pragma qt_sync_resume_processing
#endif

QT_END_NAMESPACE

#endif // QTQMLGRPCSTREAMSENDER_H
