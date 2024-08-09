/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#include "qmltestservice_client.grpc.qpb.h"

namespace qtgrpc::tests {
namespace TestService {
using namespace Qt::StringLiterals;

QmlClient::QmlClient(QObject *parent)
    : Client(parent)
{
}


void QmlClient::testMethod(const qtgrpc::tests::SimpleStringMessage &arg,
                const QJSValue &finishCallback,
                const QJSValue &errorCallback,
                const QGrpcCallOptions &options)
{
    QJSEngine *jsEngine = qjsEngine(this);
    if (jsEngine == nullptr) {
        qWarning() << "Unable to call QmlClient::testMethod, it's only callable from JS engine context";
        return;
    }

    QtGrpcQuickFunctional::makeCallConnections<qtgrpc::tests::SimpleStringMessage>(jsEngine,
                        call("testMethod"_L1, arg, options),                        finishCallback, errorCallback);
}


void QmlClient::testMethodServerStream(const qtgrpc::tests::SimpleStringMessage &arg,
            const QJSValue &messageCallback,
            const QJSValue &finishCallback,
            const QJSValue &errorCallback)
{
    testMethodServerStream(arg, messageCallback, finishCallback, errorCallback, {});
}

void QmlClient::testMethodServerStream(const qtgrpc::tests::SimpleStringMessage &arg,
            const QJSValue &messageCallback,
            const QJSValue &finishCallback,
            const QJSValue &errorCallback,
            const QGrpcCallOptions &options)
{
    QJSEngine *jsEngine = qjsEngine(this);
    if (jsEngine == nullptr) {
        qWarning() << "Unable to call QmlClient::testMethodServerStream, it's only callable from JS engine context";
        return;
    }

    QtGrpcQuickFunctional::makeServerStreamConnections<qtgrpc::tests::SimpleStringMessage>(jsEngine,
                        startStream<QGrpcServerStream>("testMethodServerStream"_L1, arg, options),
                        messageCallback, finishCallback, errorCallback);
}


TestMethodClientStreamSender *QmlClient::testMethodClientStream(const qtgrpc::tests::SimpleStringMessage &arg,
            const QJSValue &finishCallback,
            const QJSValue &errorCallback)
{
    return testMethodClientStream(arg, finishCallback, errorCallback, {});
}

TestMethodClientStreamSender *QmlClient::testMethodClientStream(const qtgrpc::tests::SimpleStringMessage &arg,
        const QJSValue &finishCallback,
        const QJSValue &errorCallback,
        const QGrpcCallOptions &options)
{
    QJSEngine *jsEngine = qjsEngine(this);
    if (jsEngine == nullptr) {
        qWarning() << "Unable to call QmlClient::testMethodClientStream, it's only callable from JS engine context";
        return nullptr;
    }

    auto stream = startStream<QGrpcClientStream>("testMethodClientStream"_L1, arg, options);
    QtGrpcQuickFunctional::makeClientStreamConnections<qtgrpc::tests::SimpleStringMessage>(jsEngine,
                        stream, finishCallback, errorCallback);
    auto *sender = new TestMethodClientStreamSender(std::move(stream));
    QJSEngine::setObjectOwnership(sender, QJSEngine::JavaScriptOwnership);
    return sender;
}


TestMethodBiStreamSender *QmlClient::testMethodBiStream(const qtgrpc::tests::SimpleStringMessage &arg,
            const QJSValue &messageCallback,
            const QJSValue &finishCallback,
            const QJSValue &errorCallback)
{
    return testMethodBiStream(arg, messageCallback, finishCallback, errorCallback, {});
}

TestMethodBiStreamSender *QmlClient::testMethodBiStream(const qtgrpc::tests::SimpleStringMessage &arg,
    const QJSValue &messageCallback,
    const QJSValue &finishCallback,
    const QJSValue &errorCallback,
    const QGrpcCallOptions &options)
{
    QJSEngine *jsEngine = qjsEngine(this);
    if (jsEngine == nullptr) {
        qWarning() << "Unable to call QmlClient::testMethodBiStream, it's only callable from JS engine context";
        return nullptr;
    }

    auto stream = startStream<QGrpcBidirStream>("testMethodBiStream"_L1, arg, options);
    QtGrpcQuickFunctional::makeBidirStreamConnections<qtgrpc::tests::SimpleStringMessage>(jsEngine,
                        stream, messageCallback, finishCallback, errorCallback);
    auto *sender = new TestMethodBiStreamSender(std::move(stream));
    QJSEngine::setObjectOwnership(sender, QJSEngine::JavaScriptOwnership);
    return sender;
}

} // namespace TestService
} // namespace qtgrpc::tests

