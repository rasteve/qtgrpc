// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QPROTOBUFREGISTRATION_H
#define QPROTOBUFREGISTRATION_H

#if 0
#  pragma qt_sync_skip_header_check
#  pragma qt_sync_stop_processing
#endif

#include <QtCore/qmetatype.h>
#include <QtCore/qmetaobject.h>
#include <QtCore/qhash.h>

#include <QtProtobuf/qtprotobufglobal.h>
#include <QtProtobuf/qtprotobuftypes.h>
#include <QtProtobuf/qprotobufbaseserializer.h>
#include <QtProtobuf/qprotobufmessage.h>

QT_BEGIN_NAMESPACE

namespace QtProtobuf {
using RegisterFunction = void (*)();
// This struct is used for type registrations in generated code
struct ProtoTypeRegistrar
{
    Q_PROTOBUF_EXPORT explicit ProtoTypeRegistrar(QtProtobuf::RegisterFunction initializer);
};
}


namespace QtProtobufPrivate {
extern Q_PROTOBUF_EXPORT void registerOrdering(QMetaType type, QProtobufPropertyOrdering ordering);

using Serializer = void (*)(const QProtobufBaseSerializer *, const QVariant &,
                            const QProtobufPropertyOrderingInfo &);
using Deserializer = void (*)(const QProtobufBaseSerializer *, QVariant &);

/*!
 \private
 \brief SerializationHandlers contains set of objects that required for class
 serialization/deserialization
 */
struct SerializationHandler
{
    Serializer serializer = nullptr; /*!< serializer assigned to class */
    Deserializer deserializer = nullptr; /*!< deserializer assigned to class */
};

extern Q_PROTOBUF_EXPORT SerializationHandler findHandler(QMetaType type);
extern Q_PROTOBUF_EXPORT void registerHandler(QMetaType type, const SerializationHandler &handlers);

/*!
 \private
 \brief default serializer template for type T that inherits from QProtobufMessage
 */
template <typename T,
          typename std::enable_if_t<std::is_base_of<QProtobufMessage, T>::value, int> = 0>
void serializeObject(const QProtobufBaseSerializer *serializer, const QVariant &value,
                     const QProtobufPropertyOrderingInfo &fieldInfo)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");
    serializer->serializeObject(value.value<T *>(), T::staticPropertyOrdering, fieldInfo);
}

/*!
 \private
 \brief default serializer template for list of type T objects that inherits from QProtobufMessage
 */
template <typename V,
          typename std::enable_if_t<std::is_base_of<QProtobufMessage, V>::value, int> = 0>
void serializeList(const QProtobufBaseSerializer *serializer, const QVariant &listValue,
                   const QProtobufPropertyOrderingInfo &fieldInfo)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufSerializer", "Serializer is null");
    for (const auto &value : listValue.value<QList<V>>()) {
        serializer->serializeListObject(&value, V::staticPropertyOrdering, fieldInfo);
    }
}

/*!
 \private
 \brief default serializer template for map of key K, value V
 */
template <typename K, typename V,
          typename std::enable_if_t<!std::is_base_of<QProtobufMessage, V>::value, int> = 0>
void serializeMap(const QProtobufBaseSerializer *serializer, const QVariant &value,
                  const QProtobufPropertyOrderingInfo &fieldInfo)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufSerializer", "Serializer is null");
    for (const auto &[k, v] : value.value<QHash<K, V>>().asKeyValueRange()) {
        serializer->serializeMapPair(QVariant::fromValue<K>(k), QVariant::fromValue<V>(v),
                                     fieldInfo);
    }
}

/*!
 \private
 \brief default serializer template for map of type key K, value V. Specialization for V that
 inherits from QProtobufMessage
 */
template <typename K, typename V,
          typename std::enable_if_t<std::is_base_of<QProtobufMessage, V>::value, int> = 0>
void serializeMap(const QProtobufBaseSerializer *serializer, const QVariant &value,
                  const QProtobufPropertyOrderingInfo &fieldInfo)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufSerializer", "Serializer is null");
    for (const auto &[k, v] : value.value<QHash<K, V>>().asKeyValueRange()) {
        serializer->serializeMapPair(QVariant::fromValue<K>(k), QVariant::fromValue<V *>(&v),
                                     fieldInfo);
    }
}

/*!
 \private
 \brief default serializer template for enum types
 */
template <typename T, typename std::enable_if_t<std::is_enum<T>::value, int> = 0>
void serializeEnum(const QProtobufBaseSerializer *serializer, const QVariant &value,
                   const QProtobufPropertyOrderingInfo &fieldInfo)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");
    static const QMetaEnum metaEnum = QMetaEnum::fromType<T>();
    serializer->serializeEnum(QtProtobuf::int64(value.value<T>()), metaEnum,
                              fieldInfo);
}

/*!
 \private
 \brief default serializer template for enum list types
 */
template <typename T, typename std::enable_if_t<std::is_enum<T>::value, int> = 0>
void serializeEnumList(const QProtobufBaseSerializer *serializer, const QVariant &value,
                       const QProtobufPropertyOrderingInfo &fieldInfo)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");
    static const QMetaEnum metaEnum = QMetaEnum::fromType<T>();
    QList<QtProtobuf::int64> intList;
    for (auto enumValue : value.value<QList<T>>()) {
        intList.append(QtProtobuf::int64(enumValue));
    }
    serializer->serializeEnumList(intList, metaEnum, fieldInfo);
}

/*!
 \private
 \brief default deserializer template for type T that inherits from QProtobufMessage
 */
template <typename T,
          typename std::enable_if_t<std::is_base_of<QProtobufMessage, T>::value, int> = 0>
void deserializeObject(const QProtobufBaseSerializer *serializer, QVariant &to)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");
    Q_ASSERT_X(to.isNull() || to.metaType() == QMetaType::fromType<T *>(),
               "QProtobufBaseSerializer",
               "Property should be either uninitialized or contain a valid pointer");

    T *value = to.value<T *>();
    if (value == nullptr) {
        value = new T;
        to = QVariant::fromValue<T *>(value);
    }
    serializer->deserializeObject(value, T::staticPropertyOrdering);
}

/*!
 \private
 \brief default deserializer template for list of type T objects that inherits from QProtobufMessage
 */
template <typename V,
          typename std::enable_if_t<std::is_base_of<QProtobufMessage, V>::value, int> = 0>
void deserializeList(const QProtobufBaseSerializer *serializer, QVariant &previous)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");

    V newValue;
    serializer->deserializeListObject(&newValue, V::staticPropertyOrdering);
    QList<V> list = previous.value<QList<V>>();
    list.append(newValue);
    previous.setValue(list);
}

/*!
 \private
 *
 \brief default deserializer template for map of key K, value V
 */
template <typename K, typename V,
          typename std::enable_if_t<!std::is_base_of<QProtobufMessage, V>::value, int> = 0>
void deserializeMap(const QProtobufBaseSerializer *serializer, QVariant &previous)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");

    QHash<K, V> out = previous.value<QHash<K, V>>();
    QVariant key = QVariant::fromValue<K>(K());
    QVariant value = QVariant::fromValue<V>(V());

    if (serializer->deserializeMapPair(key, value)) {
        out[key.value<K>()] = value.value<V>();
        previous = QVariant::fromValue<QHash<K, V>>(out);
    }
}

/*!
 \private
 *
 \brief default deserializer template for map of type key K, value V. Specialization for V
        that inherits from QProtobufMessage
 */
template <typename K, typename V,
          typename std::enable_if_t<std::is_base_of<QProtobufMessage, V>::value, int> = 0>
void deserializeMap(const QProtobufBaseSerializer *serializer, QVariant &previous)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");

    auto out = previous.value<QHash<K, V>>();
    QVariant key = QVariant::fromValue<K>(K());
    QVariant value = QVariant::fromValue<V *>(nullptr);

    bool ok = serializer->deserializeMapPair(key, value);
    V *valuePtr = value.value<V *>();
    if (ok) {
        out[key.value<K>()] = valuePtr ? *valuePtr : V();
        previous = QVariant::fromValue<QHash<K, V>>(out);
    }
    delete valuePtr;
}

/*!
 \private
 *
 \brief default deserializer template for enum type T
 */
template <typename T, typename std::enable_if_t<std::is_enum<T>::value, int> = 0>
void deserializeEnum(const QProtobufBaseSerializer *serializer, QVariant &to)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");
    static const QMetaEnum metaEnum = QMetaEnum::fromType<T>();
    QtProtobuf::int64 intValue;
    if (serializer->deserializeEnum(intValue, metaEnum))
        to = QVariant::fromValue<T>(static_cast<T>(intValue._t));
}

/*!
 \private
 *
 \brief default deserializer template for enumList type T
 */
template <typename T, typename std::enable_if_t<std::is_enum<T>::value, int> = 0>
void deserializeEnumList(const QProtobufBaseSerializer *serializer, QVariant &previous)
{
    Q_ASSERT_X(serializer != nullptr, "QProtobufBaseSerializer", "Serializer is null");
    static const QMetaEnum metaEnum = QMetaEnum::fromType<T>();
    QList<QtProtobuf::int64> intList;
    if (!serializer->deserializeEnumList(intList, metaEnum))
        return;
    QList<T> enumList = previous.value<QList<T>>();
    for (auto intValue : intList)
        enumList.append(static_cast<T>(intValue._t));
    previous = QVariant::fromValue<QList<T>>(enumList);
}
} // namespace QtProtobufPrivate

Q_PROTOBUF_EXPORT void qRegisterProtobufTypes();

template<typename T>
inline void qRegisterProtobufType()
{
    T::registerTypes();
    QtProtobufPrivate::registerOrdering(QMetaType::fromType<T>(), T::staticPropertyOrdering);
    QtProtobufPrivate::registerHandler(
        QMetaType::fromType<T *>(),
        { QtProtobufPrivate::serializeObject<T>, QtProtobufPrivate::deserializeObject<T> });
    QtProtobufPrivate::registerHandler(
        QMetaType::fromType<QList<T>>(),
        { QtProtobufPrivate::serializeList<T>, QtProtobufPrivate::deserializeList<T> });
}

template<typename K, typename V>
inline void qRegisterProtobufMapType()
{
    QtProtobufPrivate::registerHandler(
        QMetaType::fromType<QHash<K, V>>(),
        { QtProtobufPrivate::serializeMap<K, V>, QtProtobufPrivate::deserializeMap<K, V> });
}

#ifdef Q_QDOC
template<typename T>
inline void qRegisterProtobufEnumType();
#else // !Q_QDOC
template<typename T, typename std::enable_if_t<std::is_enum<T>::value, int> = 0>
inline void qRegisterProtobufEnumType()
{
    QtProtobufPrivate::registerHandler(
        QMetaType::fromType<T>(),
        { QtProtobufPrivate::serializeEnum<T>, QtProtobufPrivate::deserializeEnum<T> });
    QtProtobufPrivate::registerHandler(
        QMetaType::fromType<QList<T>>(),
        { QtProtobufPrivate::serializeEnumList<T>, QtProtobufPrivate::deserializeEnumList<T> });
}
#endif // Q_QDOC

QT_END_NAMESPACE

#endif // QPROTOBUFREGISTRATION_H
