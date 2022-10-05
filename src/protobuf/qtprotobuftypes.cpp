// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <QtProtobuf/qtprotobufglobal.h>

#include <QtCore/qmutex.h>

#include "qtprotobuftypes.h"
#include "qprotobufobject.h"

#include <mutex>
#include <limits>

QT_BEGIN_NAMESPACE

#define registerProtobufType(X) qRegisterMetaType<X>(#X)

namespace QtProtobufPrivate {
    constexpr uint jsonNameOffsetsOffset = 0;
    // Use this constant to make the +/- 1 more easily readable
    constexpr int NullTerminator = 1;
    QUtf8StringView QProtobufPropertyOrdering::getJsonName(int index) const
    {
        Q_ASSERT(data);
        const uint stringOffset = uint_dataForIndex(index, jsonNameOffsetsOffset);
        const char *name = char_data() + stringOffset;
        // This is fine because we store an extra offset for end-of-string
        const uint nameLength =
                uint_dataForIndex(index + 1, jsonNameOffsetsOffset) - NullTerminator - stringOffset;
        return { name, qsizetype(nameLength) };
    }

    int QProtobufPropertyOrdering::getFieldNumber(int index) const
    {
        Q_ASSERT(data);
        uint fieldNumber = uint_dataForIndex(index, data->fieldNumberOffset);
        if (Q_UNLIKELY(fieldNumber > uint(std::numeric_limits<int>::max())))
            return -1;
        return int(fieldNumber);
    }

    int QProtobufPropertyOrdering::getPropertyIndex(int index) const
    {
        Q_ASSERT(data);
        uint propertyIndex = uint_dataForIndex(index, data->propertyIndexOffset);
        if (Q_UNLIKELY(propertyIndex > uint(std::numeric_limits<int>::max())))
            return -1;
        return int(propertyIndex);
    }

    int QProtobufPropertyOrdering::indexOfFieldNumber(int fieldNumber) const
    {
        Q_ASSERT(data);
        if (Q_LIKELY(fieldNumber > 0)) {
            for (int i = 0; i < fieldCount(); ++i) {
                if (uint_dataForIndex(i, data->fieldNumberOffset) == static_cast<uint>(fieldNumber))
                    return i;
            }
        }
        return -1;
    }

    const uint *QProtobufPropertyOrdering::uint_data() const
    {
        Q_ASSERT(data);
        Q_ASSERT(data->version == 0);
        quintptr dataPtr = quintptr(data);
        dataPtr += sizeof(Data);
#if 0 // if Data is ever not just a bunch of uints, remove the #if 0
        if (dataPtr % alignof(uint) != 0)
            dataPtr += alignof(uint) - (dataPtr % alignof(uint));
#else
        static_assert(alignof(Data) == alignof(uint));
#endif
        return reinterpret_cast<const uint *>(dataPtr);
    }

    const char *QProtobufPropertyOrdering::char_data() const
    {
        Q_ASSERT(data);
        const uint LastOffset = data->propertyIndexOffset;
        const uint *u_data = &uint_dataForIndex(int(data->numFields - 1), LastOffset);
        ++u_data;
        quintptr uptr_data = quintptr(u_data);
        if (size_t(uptr_data) % alignof(char) != 0)
            uptr_data += alignof(char) - size_t(uptr_data) % alignof(char);
        const char *c_data = reinterpret_cast<const char *>(uptr_data);
        return c_data;
    }

    const uint &QProtobufPropertyOrdering::uint_dataForIndex(int index, uint offset) const
    {
        Q_ASSERT(data);
        Q_ASSERT(index >= 0);
        Q_ASSERT(uint(index) < data->numFields
                 || (offset == jsonNameOffsetsOffset && uint(index) == data->numFields));
        return *(uint_data() + offset + index);
    }
}

namespace QtProtobuf {

template<typename T>
void registerBasicConverters()
{
    QMetaType::registerConverter<int32_t, T>(T::fromType);
    QMetaType::registerConverter<T, int32_t>(T::toType);
    QMetaType::registerConverter<int64_t, T>(T::fromType);
    QMetaType::registerConverter<T, int64_t>(T::toType);
    QMetaType::registerConverter<uint32_t, T>(T::fromType);
    QMetaType::registerConverter<T, uint32_t>(T::toType);
    QMetaType::registerConverter<uint64_t, T>(T::fromType);
    QMetaType::registerConverter<T, uint64_t>(T::toType);
    if constexpr (!std::is_same_v<long long, int64_t>) {
        QMetaType::registerConverter<long long, T>(T::fromType);
        QMetaType::registerConverter<T, long long>(T::toType);
        QMetaType::registerConverter<unsigned long long, T>(T::fromType);
        QMetaType::registerConverter<T, unsigned long long>(T::toType);
    }
    QMetaType::registerConverter<double, T>(T::fromType);
    QMetaType::registerConverter<T, double>(T::toType);
    QMetaType::registerConverter<T, QString>(T::toString);
}

Q_CONSTINIT QBasicMutex registerMutex;
std::vector<QtProtobuf::RegisterFunction> &registerFunctions()
{
    // no need for implicit sharing etc, so stick with std::vector
    static std::vector<QtProtobuf::RegisterFunction> registrationList;
    return registrationList;
}

ProtoTypeRegistrar::ProtoTypeRegistrar(QtProtobuf::RegisterFunction initializer)
{
    std::scoped_lock lock(registerMutex);
    QtProtobuf::registerFunctions().push_back(initializer);
}

} // namespace QtProtobuf

static void qRegisterBaseTypes()
{
    [[maybe_unused]] // definitely unused
    static bool registered = [] {
        registerProtobufType(QtProtobuf::int32);
        registerProtobufType(QtProtobuf::int64);
        registerProtobufType(QtProtobuf::uint32);
        registerProtobufType(QtProtobuf::uint64);
        registerProtobufType(QtProtobuf::sint32);
        registerProtobufType(QtProtobuf::sint64);
        registerProtobufType(QtProtobuf::fixed32);
        registerProtobufType(QtProtobuf::fixed64);
        registerProtobufType(QtProtobuf::sfixed32);
        registerProtobufType(QtProtobuf::sfixed64);
        registerProtobufType(QtProtobuf::boolean);

        registerProtobufType(QtProtobuf::int32List);
        registerProtobufType(QtProtobuf::int64List);
        registerProtobufType(QtProtobuf::uint32List);
        registerProtobufType(QtProtobuf::uint64List);
        registerProtobufType(QtProtobuf::sint32List);
        registerProtobufType(QtProtobuf::sint64List);
        registerProtobufType(QtProtobuf::fixed32List);
        registerProtobufType(QtProtobuf::fixed64List);
        registerProtobufType(QtProtobuf::sfixed32List);
        registerProtobufType(QtProtobuf::sfixed64List);

        registerProtobufType(QtProtobuf::doubleList);
        registerProtobufType(QtProtobuf::floatList);
        registerProtobufType(QtProtobuf::boolList);

        QtProtobuf::registerBasicConverters<QtProtobuf::int32>();
        QtProtobuf::registerBasicConverters<QtProtobuf::int64>();
        QtProtobuf::registerBasicConverters<QtProtobuf::sfixed32>();
        QtProtobuf::registerBasicConverters<QtProtobuf::sfixed64>();
        QtProtobuf::registerBasicConverters<QtProtobuf::fixed32>();
        QtProtobuf::registerBasicConverters<QtProtobuf::fixed64>();
        return true;
    }();
}

/*!
    Calling this function registers all, currently known, protobuf types with
    the serializer registry.

    \note You should not have to call this function manually, as it is called
    automatically upon attempting serialization or deserialization of a protobuf
    message.
*/
void qRegisterProtobufTypes()
{
    qRegisterBaseTypes();

    std::vector<QtProtobuf::RegisterFunction> registrationList;
    // Move the list to a local variable, emptying the global one.
    {
        std::scoped_lock lock(QtProtobuf::registerMutex);
        registrationList.swap(QtProtobuf::registerFunctions());
    }

    for (QtProtobuf::RegisterFunction registerFunc : registrationList)
        registerFunc();
}

QT_IMPL_METATYPE_EXTERN_TAGGED(QtProtobuf::int32, QtProtobuf_int32)
QT_IMPL_METATYPE_EXTERN_TAGGED(QtProtobuf::int64, QtProtobuf_int64)
QT_IMPL_METATYPE_EXTERN_TAGGED(QtProtobuf::fixed32, QtProtobuf_fixed32)
QT_IMPL_METATYPE_EXTERN_TAGGED(QtProtobuf::fixed64, QtProtobuf_fixed64)
QT_IMPL_METATYPE_EXTERN_TAGGED(QtProtobuf::sfixed32, QtProtobuf_sfixed32)
QT_IMPL_METATYPE_EXTERN_TAGGED(QtProtobuf::sfixed64, QtProtobuf_sfixed64)

/*!
    \inmodule QtProtobuf
    \enum QtProtobuf::WireTypes
    \brief The WireTypes enumeration reflects protobuf default wiretypes.

    See https://developers.google.com/protocol-buffers/docs/encoding for details.

    The following table shows the values in the enumeration and their
    corresponding types:

    \value Unknown          Invalid wire type
    \value Varint           int32, int64, uint32, uint64, sint32, sint64, bool, enum
    \value Fixed64          fixed64, sfixed64, double
    \value LengthDelimited  string, bytes, embedded messages, packed repeated fields
    \value StartGroup       groups. Deprecated in proto syntax 3. Not supported by QtProtobuf.
    \value EndGroup         groups. Deprecated in proto syntax 3. Not supported by QtProtobuf.
    \value Fixed32          fixed32, sfixed32, float
*/

/*!
    \inmodule QtProtobuf
    \class QProtobufPropertyOrderingInfo
    \internal
    \brief Holds a property's index in the property system, and the json_name.

    This class is used by the QAbstractProtobufSerializer to help serialize/
    deserialize protobuf messages.

    \sa QProtobufPropertyOrdering
*/

/*!
    \typealias QProtobufPropertyOrdering
    \internal

    A map between the property field index and an instance of
    QProtobufPropertyOrderingInfo.

    \sa Q_PROTOBUF_OBJECT
*/

/*!
    \namespace QtProtobuf
    \brief The QtProtobuf namespace contains type aliases and classes needed to support QtProtobuf.
    \inmodule QtProtobuf
*/

/*!
    \class template<typename T, int = 0> struct QtProtobuf::transparent
    \internal Only used to create new, unique types for numeric types.
*/

/*!
    \typealias QtProtobuf::int32

    int32 is a regular signed 32-bit integer that is represented in protobuf as
    a variable size integer, an alias for WireTypes::Varint.
*/

/*!
    \typealias QtProtobuf::int64

    int64 is a regular signed 64-bit integer that is represented in protobuf as
    a variable size integer, an alias for WireTypes::Varint.
*/

/*!
    \typealias QtProtobuf::uint32

    uint32 is an unsigned 32-bit integer that is represented in protobuf as
    variable size integer, an alias for WireTypes::Varint.
*/

/*!
    \typealias QtProtobuf::uint64

    uint64 is an unsigned 64-bit integer that is represented in protobuf as
    variable size integer, an alias for WireTypes::Varint.
*/

/*!
    \typealias QtProtobuf::sint32

    sint32 is a 32-bit integer with forced sign marker that is represented in
    protobuf as variable size integer, an alias for WireTypes::Varint.
    sint32 is serialized using ZigZag conversion to reduce size of negative
    numbers.

    See https://developers.google.com/protocol-buffers/docs/encoding#signed-integers for details.
*/

/*!
    \typealias QtProtobuf::sint64

    sint64 is a 64-bit integer with forced sign marker that is represented in
    protobuf as variable size integer, an alias for WireTypes::Varint.
    sint64 is serialized using ZigZag conversion to reduce size of negative numbers.

    See https://developers.google.com/protocol-buffers/docs/encoding#signed-integers for details.
*/

/*!
    \typealias QtProtobuf::fixed32

    fixed32 is an unsigned 32-bit integer that is represented in protobuf as a
    fixed size 32-bit field, an alias for WireTypes::Fixed32.
*/

/*!
    \typealias QtProtobuf::fixed64

    fixed64 is an unsigned 64-bit integer that is represented in protobuf as a
    fixed size 64-bit field, an alias for WireTypes::Fixed64.
*/

/*!
    \typealias QtProtobuf::sfixed32

    sfixed32 is a signed 32-bit integer that is represented in protobuf as a
    fixed size 32-bit field, an alias for WireTypes::Fixed32.
*/

/*!
    \typealias QtProtobuf::sfixed64

    sfixed64 is a signed 64-bit integer that is represented in protobuf as a
    fixed size 64-bit field, an alias for WireTypes::Fixed64.
*/

/*!
    \typealias QtProtobuf::int32List

    Alias for a list of QtProtobuf::int32.
*/

/*!
    \typealias QtProtobuf::int64List

    Alias for a list of QtProtobuf::int64.
*/

/*!
    \typealias QtProtobuf::uint32List

    Alias for a list of QtProtobuf::uint32.
*/

/*!
    \typealias QtProtobuf::uint64List

    Alias for a list of QtProtobuf::uint64.
*/

/*!
    \typealias QtProtobuf::sint32List

    Alias for a list of QtProtobuf::sint32.
*/

/*!
    \typealias QtProtobuf::sint64List

    Alias for a list of QtProtobuf::sint64.
*/

/*!
    \typealias QtProtobuf::fixed32List

    Alias for a list of QtProtobuf::fixed32.
*/

/*!
    \typealias QtProtobuf::fixed64List

    Alias for a list of QtProtobuf::fixed64.
*/

/*!
    \typealias QtProtobuf::sfixed32List

    Alias for a list of QtProtobuf::sfixed32.
*/

/*!
    \typealias QtProtobuf::sfixed64List

    Alias for a list of QtProtobuf::sfixed64.
*/

/*!
    \typealias QtProtobuf::floatList

    Alias for a list of float.
*/

/*!
    \typealias QtProtobuf::doubleList

    Alias for a list of double.
*/

/*!
    \typealias QtProtobuf::boolList

    Alias for a list of bool.
*/

/*!
    \typealias QtProtobuf::RegisterFunction
    \internal
*/

/*!
    \fn template <typename T> struct QtProtobuf::ProtoTypeRegistrar
    \internal

    Used in the type registration process.
*/

/*!
    \fn template<typename T> bool QtProtobuf::repeatedValueCompare(const QList<std::shared_ptr<T>> &a, const QList<std::shared_ptr<T>> &b)
    \fn template<typename K, typename V> bool QtProtobuf::repeatedValueCompare(const QHash<K, V> &a, const QHash<K, V> &b)
    \fn template<typename K, typename V> bool repeatedValueCompare(const QHash<K, std::shared_ptr<V>> &a, const QHash<K, std::shared_ptr<V>> &b)

    Compares two \c{repeated} fields (essentially a list) to each other.
    Returns \c true if the two fields are equal, \c false otherwise.

    These functions are used in the generated code to implement operator==.
*/


QT_END_NAMESPACE
