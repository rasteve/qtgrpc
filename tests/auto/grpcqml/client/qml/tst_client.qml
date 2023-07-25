// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

import QtQuick
import QtTest
import QmlTestUri
import qtgrpc.tests

TestCase {
    id: root
    name: "qtgrpcClientRegistration"

    property simpleStringMessage messageArg;
    property simpleStringMessage messageResponse;

    property bool calbackCalled: false
    property var clientQml
    property var grpcChannel
    property var grpcChannelDeadline
    property var setResponse: function(value) { root.messageResponse = value }
    property var errorCallback: function() { root.calbackCalled = true }

    function createClientItem() {
        return Qt.createQmlObject("import QtQuick; import QtGrpcQuick; \
                                   import qtgrpc.tests; QmlClient {}", root)
    }

    function createGrpcChannelItem() {
        return Qt.createQmlObject("import QtQuick; import QtGrpcQuick; GrpcHttp2Channel { \
                                   options: GrpcChannelOptions { \
                                   host: \"http://localhost:50051\"} }", root)
    }

    function createGrpcChannelWithDeadlineItem() {
        return Qt.createQmlObject("import QtQuick; import QtGrpcQuick; GrpcHttp2Channel { \
                                   options: GrpcChannelOptions { \
                                   host: \"http://localhost:50051\"; \
                                   deadline: { 1000 } }  }", root)
    }

    function test_1clientTypes_data() {
        return [
                    { tag: "Grpc Client created",
                        field: typeof clientQml, answer: "object" },
                    { tag: "Grpc Http2 Channel created",
                        field: typeof grpcChannel, answer: "object" },
                    { tag: "Grpc Http2 Deadline Channel created",
                        field: typeof grpcChannelDeadline, answer: "object" }
                ]
    }

    function test_1clientTypes(data) {
        compare(data.field, data.answer)
    }

    function test_ChannelOptions_data() {
        return [
                    { tag: "grpcChannelOptions URL is set",
                        field: grpcChannel.options.host, answer: "http://localhost:50051" },
                    { tag: "grpcChannelOptions deadline is set",
                        field: grpcChannelDeadline.options.deadline, answer: 1000 },
                    { tag: "errorCallback() is called",
                        field: root.calbackCalled, answer: true }
                ]
    }

    function test_ChannelOptions(data) {
        compare(data.field, data.answer)
    }

    Component.onCompleted: {
        clientQml = root.createClientItem()
        grpcChannel = root.createGrpcChannelItem()
        grpcChannelDeadline = root.createGrpcChannelWithDeadlineItem()
        clientQml.channel = grpcChannel.channel
        clientQml.testMethod(root.messageArg, root.setResponse, root.errorCallback)
    }
}
