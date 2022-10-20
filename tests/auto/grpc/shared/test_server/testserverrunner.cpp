// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include "testserverrunner.h"

#include <QDebug>
#include <QFile>
#include <QString>

#include "testservice.grpc.pb.h"
#include <grpc++/grpc++.h>

#include <memory>

namespace {
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::Status;
using qtgrpc::tests::BlobMessage;
using qtgrpc::tests::SimpleIntMessage;
using qtgrpc::tests::SimpleStringMessage;
using qtgrpc::tests::TestService;

// Logic and data behind the server's behavior.
class TestServiceServiceImpl final : public qtgrpc::tests::TestService::Service
{
    grpc::Status testMethod(grpc::ServerContext *, const SimpleStringMessage *request,
                            SimpleStringMessage *response) override;

    grpc::Status testMethodServerStream(grpc::ServerContext *, const SimpleStringMessage *request,
                                        grpc::ServerWriter<SimpleStringMessage> *writer) override;

    grpc::Status testMethodBlobServerStream(grpc::ServerContext *, const BlobMessage *request,
                                            grpc::ServerWriter<BlobMessage> *writer) override;
    grpc::Status testMethodStatusMessage(grpc::ServerContext *, const SimpleStringMessage *request,
                                         SimpleStringMessage *) override;
    grpc::Status testMethodNonCompatibleArgRet(grpc::ServerContext *,
                                               const SimpleIntMessage *request,
                                               SimpleStringMessage *response) override;
};
}

Status TestServiceServiceImpl::testMethod(grpc::ServerContext *, const SimpleStringMessage *request,
                                          SimpleStringMessage *response)
{
    qInfo() << "testMethod called with: " << request->testfieldstring();
    response->set_testfieldstring(request->testfieldstring());
    if (request->testfieldstring() == "sleep") {
        QThread::sleep(1);
    }
    return Status();
}

Status TestServiceServiceImpl::testMethodServerStream(grpc::ServerContext *,
                                                      const SimpleStringMessage *request,
                                                      ServerWriter<SimpleStringMessage> *writer)

{
    qInfo() << "testMethodServerStream called with: " << request->testfieldstring();
    SimpleStringMessage msg;

    msg.set_testfieldstring(request->testfieldstring() + "1");
    QThread::sleep(1);
    qInfo() << "send back " << (request->testfieldstring() + "1");
    writer->Write(msg);

    msg.set_testfieldstring(request->testfieldstring() + "2");
    QThread::sleep(1);
    qInfo() << "send back " << (request->testfieldstring() + "2");
    writer->Write(msg);

    msg.set_testfieldstring(request->testfieldstring() + "3");
    QThread::sleep(1);
    qInfo() << "send back " << (request->testfieldstring() + "3");
    writer->Write(msg);

    msg.set_testfieldstring(request->testfieldstring() + "4");
    QThread::sleep(1);
    qInfo() << "send back " << (request->testfieldstring() + "4");
    writer->WriteLast(msg, grpc::WriteOptions());

    return Status();
}

Status TestServiceServiceImpl::testMethodBlobServerStream(grpc::ServerContext *,
                                                          const BlobMessage *request,
                                                          ServerWriter<BlobMessage> *writer)

{
    qInfo() << "testMethodBlobServerStream called with testbytes size: "
            << request->testbytes().size();
    BlobMessage msg;
    msg.set_allocated_testbytes(new std::string(request->testbytes()));
    writer->Write(msg);
    return Status();
}

Status TestServiceServiceImpl::testMethodStatusMessage(ServerContext *,
                                                       const SimpleStringMessage *request,
                                                       SimpleStringMessage *)
{
    return Status(grpc::StatusCode::UNIMPLEMENTED, request->testfieldstring());
}

Status TestServiceServiceImpl::testMethodNonCompatibleArgRet(grpc::ServerContext *,
                                                             const SimpleIntMessage *request,
                                                             SimpleStringMessage *response)
{
    qInfo() << "testMethodNonCompatibleArgRet called with: " << request->testfield();
    response->set_testfieldstring(std::to_string(request->testfield()));
    return Status();
}

void SecureTestServer::run()
{
    QString server_uri("localhost:60051");

    TestServiceServiceImpl service;

    QFile cfile(":/keys/cert.pem");
    cfile.open(QFile::ReadOnly);
    QString cert = cfile.readAll();

    QFile kfile(":/keys/key.pem");
    kfile.open(QFile::ReadOnly);
    QString key = kfile.readAll();

    grpc::SslServerCredentialsOptions opts(GRPC_SSL_DONT_REQUEST_CLIENT_CERTIFICATE);
    opts.pem_key_cert_pairs.push_back({ key.toStdString(), cert.toStdString() });

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_uri.toStdString(), grpc::SslServerCredentials(opts));
#ifndef Q_OS_WINDOWS
    QString socket_uri("unix:///tmp/test.sock");
    builder.AddListeningPort(socket_uri.toStdString(), grpc::SslServerCredentials(opts));
#endif
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    if (!server) {
        qDebug() << "Creating grpc::Server failed.";
        return;
    }
#ifdef Q_OS_WINDOWS
    qDebug() << "Server listening on " << server_uri;
#else
    qDebug() << "Server listening on " << server_uri << "and" << socket_uri;
#endif

    server->Wait();
}

void TestServer::run()
{
    QString server_uri("127.0.0.1:50051");
    TestServiceServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_uri.toStdString(), grpc::InsecureServerCredentials());
#ifndef Q_OS_WINDOWS
    QString socket_uri("unix:///tmp/test.sock");
    builder.AddListeningPort(socket_uri.toStdString(), grpc::InsecureServerCredentials());
#endif
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    if (!server) {
        qDebug() << "Creating grpc::Server failed.";
        return;
    }
#ifdef Q_OS_WINDOWS
    qDebug() << "Server listening on " << server_uri;
#else
    qDebug() << "Server listening on " << server_uri << "and" << socket_uri;
#endif
    server->Wait();
}
