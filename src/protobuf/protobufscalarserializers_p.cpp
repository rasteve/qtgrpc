// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <QtProtobuf/private/protobufscalarserializers_p.h>

QT_BEGIN_NAMESPACE

/*
    Gets length of a byte-array and prepends to it its serialized length value
    using the appropriate serialization algorithm

    Returns 'data' with its length prepended
*/
QByteArray ProtobufScalarSerializers::prependLengthDelimitedSize(const QByteArray &data)
{
    return serializeVarintCommon<uint32_t>(data.size()) + data;
}

std::optional<QByteArray>
ProtobufScalarSerializers::deserializeLengthDelimited(QProtobufSelfcheckIterator &it)
{
    if (it.bytesLeft() != 0) {
        if (auto opt = deserializeVarintCommon<QtProtobuf::uint64>(it); opt) {
            if (quint64 length = opt.value(); it.isValid() && quint64(it.bytesLeft()) >= length
                && length <= quint64(QByteArray::maxSize())) {
                QByteArray result(it.data(), qsizetype(length));
                it += length;
                return { std::move(result) };
            }
        }
    }
    return std::nullopt;
}

QT_END_NAMESPACE
