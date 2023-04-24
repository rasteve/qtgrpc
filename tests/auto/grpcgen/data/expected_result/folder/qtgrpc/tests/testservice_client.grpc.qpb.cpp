/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#include "qtgrpc/tests/testservice_client.grpc.qpb.h"

namespace qtgrpc::tests {
namespace TestService {
using namespace Qt::StringLiterals;

Client::Client(QObject *parent)
    : QAbstractGrpcClient("qtgrpc.tests.TestService"_L1, parent)
{
}

QGrpcStatus Client::testMethod(const qtgrpc::tests::SimpleStringMessage &arg, qtgrpc::tests::SimpleStringMessage *ret)
{
    return call<qtgrpc::tests::SimpleStringMessage>("testMethod"_L1, arg, ret);
}

std::shared_ptr<QGrpcCallReply> Client::testMethod(const qtgrpc::tests::SimpleStringMessage &arg)
{
    return call<qtgrpc::tests::SimpleStringMessage>("testMethod"_L1, arg);
}

void Client::testMethod(const qtgrpc::tests::SimpleStringMessage &arg, const QObject *context, const std::function<void(std::shared_ptr<QGrpcCallReply>)> &callback)
{
    std::shared_ptr<QGrpcCallReply> reply = call<qtgrpc::tests::SimpleStringMessage>("testMethod"_L1, arg);
    QObject::connect(reply.get(), &QGrpcCallReply::finished, context, [reply, callback]() {
        callback(reply);
    });
}

std::shared_ptr<QGrpcStream> Client::streamTestMethodServerStream(const qtgrpc::tests::SimpleStringMessage &arg)
{
    return startStream<qtgrpc::tests::SimpleStringMessage>("testMethodServerStream"_L1, arg);
}

QGrpcStatus Client::testMethodClientStream(const qtgrpc::tests::SimpleStringMessage &arg, qtgrpc::tests::SimpleStringMessage *ret)
{
    return call<qtgrpc::tests::SimpleStringMessage>("testMethodClientStream"_L1, arg, ret);
}

std::shared_ptr<QGrpcCallReply> Client::testMethodClientStream(const qtgrpc::tests::SimpleStringMessage &arg)
{
    return call<qtgrpc::tests::SimpleStringMessage>("testMethodClientStream"_L1, arg);
}

void Client::testMethodClientStream(const qtgrpc::tests::SimpleStringMessage &arg, const QObject *context, const std::function<void(std::shared_ptr<QGrpcCallReply>)> &callback)
{
    std::shared_ptr<QGrpcCallReply> reply = call<qtgrpc::tests::SimpleStringMessage>("testMethodClientStream"_L1, arg);
    QObject::connect(reply.get(), &QGrpcCallReply::finished, context, [reply, callback]() {
        callback(reply);
    });
}

std::shared_ptr<QGrpcStream> Client::streamTestMethodBiStream(const qtgrpc::tests::SimpleStringMessage &arg)
{
    return startStream<qtgrpc::tests::SimpleStringMessage>("testMethodBiStream"_L1, arg);
}

} // namespace TestService
} // namespace qtgrpc::tests

