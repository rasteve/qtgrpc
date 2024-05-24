// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
#include <grpcclienttestbase.h>

#include <QtCore/QTimer>
#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <testservice_client.grpc.qpb.h>
#include <message_latency_defs.h>

using namespace Qt::Literals::StringLiterals;
using namespace qtgrpc::tests;

class QtGrpcClientBidirStreamTest : public GrpcClientTestBase
{
    Q_OBJECT
public:
    QtGrpcClientBidirStreamTest()
        : GrpcClientTestBase(
                Channels{ GrpcClientTestBase::Channel::Qt })
    {
    }

private Q_SLOTS:
    void valid();
    void sequentialSendWithDone();
};

void QtGrpcClientBidirStreamTest::valid()
{
    const int ExpectedMessageCount = 4;

    SimpleStringMessage request;
    request.setTestFieldString("Stream");

    auto stream = client()->testMethodBiStream(request);

    QString fullResponse;
    int i = 0;
    QObject::connect(stream.get(), &QGrpcBidirStream::messageReceived, this,
                     [stream, &request, &fullResponse, &i]() {
                         if (const auto rsp = stream->read<SimpleStringMessage>()) {
                             fullResponse += rsp->testFieldString() + QString::number(++i);
                             stream->writeMessage(request);
                         }
                     });

    QSignalSpy streamFinishedSpy(stream.get(), &QGrpcServerStream::finished);
    QVERIFY(streamFinishedSpy.isValid());

    QTRY_COMPARE_EQ_WITH_TIMEOUT(streamFinishedSpy.count(), 1,
                                 MessageLatencyWithThreshold * ExpectedMessageCount);

    auto args = streamFinishedSpy.first();
    QCOMPARE(args.count(), 1);
    QCOMPARE_EQ(args.first().value<QGrpcStatus>().code(), QGrpcStatus::StatusCode::Ok);

    QCOMPARE_EQ(fullResponse, "Stream11Stream22Stream33Stream44");
}

void QtGrpcClientBidirStreamTest::sequentialSendWithDone()
{
    const int ExpectedMessageCount = 4;

    SimpleStringMessage request;
    request.setTestFieldString("Stream");

    auto stream = client()->testMethodBiStreamWithDone(request);

    QString fullResponse;
    int i = 0;
    QObject::connect(stream.get(), &QGrpcBidirStream::messageReceived, this,
                     [stream, &request, &fullResponse, &i, ExpectedMessageCount]() {
                         Q_UNUSED(ExpectedMessageCount)
                         if (const auto rsp = stream->read<SimpleStringMessage>()) {
                             fullResponse += rsp->testFieldString() + QString::number(++i);
                             if (i == (ExpectedMessageCount - 1)) {
                                 stream->writesDone();
                                 request.setTestFieldString("StreamWrong");
                             }
                             stream->writeMessage(request);
                         }
                     });

    QSignalSpy streamFinishedSpy(stream.get(), &QGrpcServerStream::finished);
    QVERIFY(streamFinishedSpy.isValid());

    QTRY_COMPARE_EQ_WITH_TIMEOUT(streamFinishedSpy.count(), 1,
                                 MessageLatencyWithThreshold * ExpectedMessageCount);

    auto args = streamFinishedSpy.first();
    QCOMPARE(args.count(), 1);
    QCOMPARE_EQ(args.first().value<QGrpcStatus>().code(), QGrpcStatus::StatusCode::Ok);

    QCOMPARE_EQ(fullResponse, "Stream11Stream22Stream33");
}

QTEST_MAIN(QtGrpcClientBidirStreamTest)

#include "tst_grpc_client_bidirstream.moc"
