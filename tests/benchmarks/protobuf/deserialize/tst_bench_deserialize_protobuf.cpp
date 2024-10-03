// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtTest/qtest.h>

#include <QtProtobuf/qprotobufserializer.h>

#include "bench.qpb.h"

using namespace Qt::StringLiterals;

class tst_ProtoDeserialize : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();
    void deserialize_data();
    void deserialize();

private:
    QByteArray benchBuffer;
};

std::array<std::pair<QString, QByteArray>, 3> data = {
    std::make_pair("qtbench.SimpleBoolMessage", QByteArray::fromHex("0801")),
    std::make_pair("qtbench.SimpleBytesMessage",
                   QByteArray::fromHex("0a0c48656c6c6f20776f726c6421")),
    std::make_pair("qtbench.RecursiveMessage",
                   QByteArray::fromHex("080112120802120e0803120a08041206080512020806")),
};

void tst_ProtoDeserialize::initTestCase()
{
    qtbench::ScalarTypes s;
    s.setField1(std::numeric_limits<QtProtobuf::int32>::min());
    s.setField2(std::numeric_limits<QtProtobuf::uint32>::max());
    s.setField3(std::numeric_limits<QtProtobuf::sint32>::max());
    s.setField4(std::numeric_limits<QtProtobuf::fixed32>::max());
    s.setField5(std::numeric_limits<QtProtobuf::sfixed32>::min());
    s.setField6(std::numeric_limits<QtProtobuf::int64>::min());
    s.setField7(std::numeric_limits<QtProtobuf::uint64>::max());
    s.setField8(std::numeric_limits<QtProtobuf::sint64>::min());
    s.setField9(std::numeric_limits<QtProtobuf::fixed64>::max());
    s.setField10(std::numeric_limits<QtProtobuf::sfixed64>::min());
    s.setField11(42.0);
    s.setField12(42.0);
    s.setField13("Hello Qt!"_L1);
    s.setField14("Hello Qt!"_ba);
    s.setField15(qtbench::ScalarTypes::EnumType::Value3);

    qtbench::ScalarTypesRepeated r;
    r.setField1({ s, s, s, s, s, s, s, s, s, s, });
    r.setField2({ qtbench::ScalarTypes::EnumType::Value1, qtbench::ScalarTypes::EnumType::Value2,
                  qtbench::ScalarTypes::EnumType::Value3, qtbench::ScalarTypes::EnumType::Value3,
                  qtbench::ScalarTypes::EnumType::Value2, qtbench::ScalarTypes::EnumType::Value1,
                  qtbench::ScalarTypes::EnumType::Value2, qtbench::ScalarTypes::EnumType::Value3,
                  qtbench::ScalarTypes::EnumType::Value1, qtbench::ScalarTypes::EnumType::Value2,
                  qtbench::ScalarTypes::EnumType::Value1, qtbench::ScalarTypes::EnumType::Value3 });

    qtbench::MapTypes m;
    m.setField1({
        { 0,                                             r },
        { std::numeric_limits<QtProtobuf::int32>::max(), r },
        { std::numeric_limits<QtProtobuf::int32>::min(), r }
    });
    m.setField2({
        { ""_L1,           r },
        { "Hellow Qt!"_L1, r }
    });

    qtbench::BenchmarkMessage msg;
    msg.setField1({ m });

    QProtobufSerializer serializer;
    benchBuffer = msg.serialize(&serializer);
}

void tst_ProtoDeserialize::deserialize_data()
{
    QTest::addColumn<QString>("name");
    QTest::addColumn<QByteArray>("data");

    for (auto &&[name, value] : data)
        QTest::newRow(qPrintable(name)) << name << value;

    for (auto i : {1, 10, 100, 1000}) {
        QTest::addRow("qtbench.BenchmarkMessage x %d", i)
            << "qtbench.BenchmarkMessage" << benchBuffer.repeated(i);
    }
}

void tst_ProtoDeserialize::deserialize()
{
    QFETCH(QString, name);
    QFETCH(QByteArray, data);

    QProtobufSerializer serializer;
    QBENCHMARK {
        QProtobufMessagePointer res = QProtobufMessage::constructByName(name);
        QVERIFY(res);
        QVERIFY(res->deserialize(&serializer, data));
    }
}

QTEST_MAIN(tst_ProtoDeserialize)

#include "tst_bench_deserialize_protobuf.moc"
