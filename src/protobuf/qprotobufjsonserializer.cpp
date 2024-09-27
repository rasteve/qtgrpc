// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <QtProtobuf/qprotobufjsonserializer.h>

#include <QtProtobuf/private/protobuffieldpresencechecker_p.h>
#include <QtProtobuf/private/qprotobufdeserializerbase_p.h>
#include <QtProtobuf/private/qprotobufregistration_p.h>
#include <QtProtobuf/private/qprotobufserializerbase_p.h>
#include <QtProtobuf/private/qtprotobufdefs_p.h>
#include <QtProtobuf/private/qtprotobufserializerhelpers_p.h>

#include <QtCore/qcoreapplication.h>
#include <QtCore/qjsonarray.h>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/qvariant.h>
#include <QtCore/qhash.h>
#include <QtCore/private/qnumeric_p.h>

#include <cmath>
#include <limits>
#include <type_traits>

QT_BEGIN_NAMESPACE

/*!
    \class QProtobufJsonSerializer
    \inmodule QtProtobuf
    \since 6.7
    \brief The QProtobufJsonSerializer class is an interface that represents
           basic functions for serialization/deserialization of QProtobufMessage
           objects to JSON.

    The QProtobufJsonSerializer class registers serializers/deserializers for
    classes implementing a protobuf message, inheriting \l QProtobufMessage. These
    classes are generated automatically, based on a \c{.proto} file, using the CMake
    function \l qt_add_protobuf or by running
    \l {The qtprotobufgen Tool} {qtprotobufgen} directly.
*/

using namespace Qt::StringLiterals;
using namespace QtProtobufPrivate;

namespace {

inline QString convertJsonKeyToJsonName(QStringView name)
{
    QString result;
    result.reserve(name.size());
    bool nextUpperCase = false;
    for (const auto &c : name) {
        if (c == QChar::fromLatin1('_')) {
            nextUpperCase = true;
            continue;
        }
        result.append(nextUpperCase ? c.toUpper() : c);
        nextUpperCase = false;
    }
    return result;
}

}

class QProtobufJsonSerializerImpl final : public QProtobufSerializerBase
{
public:
    QProtobufJsonSerializerImpl() = default;
    ~QProtobufJsonSerializerImpl();

    const QJsonObject &result() const { return m_result; }

    void reset();

private:
    bool serializeEnum(QVariant &value, const QProtobufFieldInfo &fieldInfo) override;
    bool serializeScalarField(const QVariant &value, const QProtobufFieldInfo &fieldInfo) override;
    void serializeMessageFieldBegin() override;
    void serializeMessageFieldEnd(const QProtobufMessage *message,
                                  const QProtobufFieldInfo &fieldInfo) override;

    QJsonObject m_result;
    QList<QJsonObject> m_state;

    Q_DISABLE_COPY_MOVE(QProtobufJsonSerializerImpl)
};

class QProtobufJsonSerializerPrivate;
class QProtobufJsonDeserializerImpl final : public QProtobufDeserializerBase
{
public:
    explicit QProtobufJsonDeserializerImpl(QProtobufJsonSerializerPrivate *parent);
    ~QProtobufJsonDeserializerImpl();

    void reset(QJsonObject obj);

    void setError(QAbstractProtobufSerializer::Error error, QAnyStringView errorString) override;
    void setUnexpectedEndOfStreamError();
    void setInvalidFormatError();

private:
    bool deserializeEnum(QVariant &value,
                         const QtProtobufPrivate::QProtobufFieldInfo &fieldInfo) override;
    int nextFieldIndex(QProtobufMessage *message) override;
    bool deserializeScalarField(QVariant &, const QtProtobufPrivate::QProtobufFieldInfo &) override;

    struct JsonDeserializerState
    {
        JsonDeserializerState(const QJsonObject &obj) : obj(obj) { }

        QJsonObject obj = {};
        int index = 0;
        QJsonValue scalarValue = {};
    };

    QList<JsonDeserializerState> m_state;
    QProtobufJsonSerializerPrivate *m_parent = nullptr;
};

class QProtobufJsonSerializerPrivate final
{
    Q_DISABLE_COPY_MOVE(QProtobufJsonSerializerPrivate)

    // Tests if V is JSON compatible integer
    // int32 | int64 | uint32 | sint32 | sint64 | fixed32 | sfixed32 | sfixed64
    template <typename V>
    struct IsJsonInt
        : std::integral_constant<
              bool,
              std::is_same_v<V, QtProtobuf::int32> || std::is_same_v<V, QtProtobuf::int64>
                  || std::is_same_v<V, QtProtobuf::uint32> || std::is_same_v<V, QtProtobuf::sint32>
                  || std::is_same_v<V, QtProtobuf::sint64> || std::is_same_v<V, QtProtobuf::fixed32>
                  || std::is_same_v<V, QtProtobuf::sfixed32>
                  || std::is_same_v<V, QtProtobuf::sfixed64>>
    {
    };

    // Tests if V is JSON incompatible 64-bit unsigned integer
    // uint64 | fixed64
    template <typename V>
    struct IsJsonInt64
        : std::integral_constant<
              bool, std::is_same_v<V, QtProtobuf::uint64> || std::is_same_v<V, QtProtobuf::fixed64>>
    {
    };

    // Tests if V is JSON compatible floating point number
    // float | double
    template <typename V>
    struct IsJsonFloatingPoint
        : std::integral_constant<bool, std::is_same_v<V, float> || std::is_same_v<V, double>>
    {
    };

public:
    using Serializer = std::function<QJsonValue(const QVariant &)>;
    using Deserializer = std::function<QVariant(const QJsonValue&, bool &ok)>;

    struct SerializationHandlers {
        // serializer assigned to class
        Serializer serializer;
        // deserializer assigned to class
        Deserializer deserializer;
        ProtobufFieldPresenceChecker::Function isPresent;
    };

    template <typename T>
    static SerializationHandlers createCommonHandler()
    {
        return { QProtobufJsonSerializerPrivate::serializeCommon<T>,
                 QProtobufJsonSerializerPrivate::deserializeCommon<T>,
                 ProtobufFieldPresenceChecker::isPresent<T> };
    }

    template <typename L, typename T>
    static SerializationHandlers createCommonListHandler()
    {
        return { QProtobufJsonSerializerPrivate::serializeList<L>,
                 QProtobufJsonSerializerPrivate::deserializeList<L, T>,
                 ProtobufFieldPresenceChecker::isPresent<L> };
    }

    template<typename T,
              std::enable_if_t<std::is_same_v<T, float> || std::is_same_v<T, double>, bool> = true>
    static bool isPresent(const QVariant &value)
    {
        const T val = value.value<T>();
        return val != 0 || std::signbit(val);
    }

    using SerializerRegistry = QHash<int/*metatypeid*/, SerializationHandlers>;

    template <typename T>
    static QJsonValue serializeCommon(const QVariant &propertyValue)
    {
        return serialize(propertyValue.value<T>());
    }

    template <typename T, std::enable_if_t<IsJsonInt<T>::value, bool> = true>
    static QJsonValue serialize(T propertyValue)
    {
        return QJsonValue(qint64(propertyValue));
    }

    template <typename T, std::enable_if_t<IsJsonInt64<T>::value, bool> = true>
    static QJsonValue serialize(T propertyValue)
    {
        return QJsonValue(QString::number(propertyValue));
    }

    template <typename T, std::enable_if_t<IsJsonFloatingPoint<T>::value, bool> = true>
    static QJsonValue serialize(T propertyValue)
    {
        if (propertyValue == -std::numeric_limits<T>::infinity())
            return QJsonValue("-Infinity"_L1);

        if (propertyValue == std::numeric_limits<T>::infinity())
            return QJsonValue("Infinity"_L1);

        if (propertyValue != propertyValue)
            return QJsonValue("NaN"_L1);

        return QJsonValue(propertyValue);
    }

    static QJsonValue serialize(bool propertyValue) { return QJsonValue(propertyValue); }

    static QJsonValue serialize(const QString &propertyValue) { return QJsonValue(propertyValue); }

    static QJsonValue serialize(const QByteArray &propertyValue)
    {
        return QJsonValue(QString::fromUtf8(propertyValue.toBase64()));
    }

    template <typename L>
    static QJsonValue serializeList(const QVariant &propertyValue)
    {
        QJsonArray arr;
        L listValue = propertyValue.value<L>();
        for (const auto &value : listValue) {
            arr.append(serialize(value));
        }
        return QJsonValue(arr);
    }

    QProtobufJsonSerializerPrivate() : deserializer(this)
    {
        [[maybe_unused]] static bool initialized = []() -> bool {
            handlers[qMetaTypeId<QtProtobuf::int32>()] = createCommonHandler<QtProtobuf::int32>();
            handlers[qMetaTypeId<QtProtobuf::sfixed32>()] = createCommonHandler<
                QtProtobuf::sfixed32>();
            handlers[qMetaTypeId<QtProtobuf::sint32>()] = createCommonHandler<QtProtobuf::sint32>();
            handlers[qMetaTypeId<QtProtobuf::uint32>()] = createCommonHandler<QtProtobuf::uint32>();
            handlers[qMetaTypeId<QtProtobuf::fixed32>()] = createCommonHandler<
                QtProtobuf::fixed32>();
            handlers[qMetaTypeId<QtProtobuf::sint64>()] = createCommonHandler<QtProtobuf::sint64>();
            handlers[qMetaTypeId<QtProtobuf::int64>()] = createCommonHandler<QtProtobuf::int64>();
            handlers[qMetaTypeId<QtProtobuf::sfixed64>()] = createCommonHandler<
                QtProtobuf::sfixed64>();
            handlers[qMetaTypeId<QtProtobuf::uint64>()] = createCommonHandler<QtProtobuf::uint64>();
            handlers[qMetaTypeId<QtProtobuf::fixed64>()] = createCommonHandler<
                QtProtobuf::fixed64>();
            handlers[qMetaTypeId<bool>()] = createCommonHandler<bool>();
            handlers[QMetaType::QString] = createCommonHandler<QString>();
            handlers[QMetaType::QByteArray] = createCommonHandler<QByteArray>();
            handlers[QMetaType::Float] = { QProtobufJsonSerializerPrivate::serializeCommon<float>,
                                           QProtobufJsonSerializerPrivate::deserializeCommon<float>,
                                           QProtobufJsonSerializerPrivate::isPresent<float> };
            handlers[QMetaType::Double] = {
                QProtobufJsonSerializerPrivate::serializeCommon<double>,
                QProtobufJsonSerializerPrivate::deserializeCommon<double>,
                QProtobufJsonSerializerPrivate::isPresent<double>
            };

            handlers[qMetaTypeId<QtProtobuf::boolList>()] = createCommonListHandler<
                QtProtobuf::boolList, bool>();
            handlers[qMetaTypeId<QtProtobuf::int32List>()] = createCommonListHandler<
                QtProtobuf::int32List, QtProtobuf::int32>();
            handlers[qMetaTypeId<QtProtobuf::int64List>()] = createCommonListHandler<
                QtProtobuf::int64List, QtProtobuf::int64>();
            handlers[qMetaTypeId<QtProtobuf::sint32List>()] = createCommonListHandler<
                QtProtobuf::sint32List, QtProtobuf::sint32>();
            handlers[qMetaTypeId<QtProtobuf::sint64List>()] = createCommonListHandler<
                QtProtobuf::sint64List, QtProtobuf::sint64>();
            handlers[qMetaTypeId<QtProtobuf::uint32List>()] = createCommonListHandler<
                QtProtobuf::uint32List, QtProtobuf::uint32>();
            handlers[qMetaTypeId<QtProtobuf::uint64List>()] = createCommonListHandler<
                QtProtobuf::uint64List, QtProtobuf::uint64>();
            handlers[qMetaTypeId<QtProtobuf::fixed32List>()] = createCommonListHandler<
                QtProtobuf::fixed32List, QtProtobuf::fixed32>();
            handlers[qMetaTypeId<QtProtobuf::fixed64List>()] = createCommonListHandler<
                QtProtobuf::fixed64List, QtProtobuf::fixed64>();
            handlers[qMetaTypeId<QtProtobuf::sfixed32List>()] = createCommonListHandler<
                QtProtobuf::sfixed32List, QtProtobuf::sfixed32>();
            handlers[qMetaTypeId<QtProtobuf::sfixed64List>()] = createCommonListHandler<
                QtProtobuf::sfixed64List, QtProtobuf::sfixed64>();
            handlers[qMetaTypeId<QtProtobuf::floatList>()] = createCommonListHandler<
                QtProtobuf::floatList, float>();
            handlers[qMetaTypeId<QtProtobuf::doubleList>()] = createCommonListHandler<
                QtProtobuf::doubleList, double>();
            handlers[qMetaTypeId<QStringList>()] = createCommonListHandler<QStringList, QString>();
            handlers[qMetaTypeId<QByteArrayList>()] = createCommonListHandler<QByteArrayList,
                                                                              QByteArray>();
            return true;
        }();
    }
    ~QProtobufJsonSerializerPrivate() = default;

    template <typename T>
    static QVariant deserializeCommon(const QJsonValue &value, bool &ok)
    {
        ok = false;
        return QVariant::fromValue<T>(deserialize<T>(value, ok));
    }

    template <typename T, std::enable_if_t<IsJsonInt<T>::value, bool> = true>
    static T deserialize(const QJsonValue &value, bool &ok)
    {
        auto variantValue = value.toVariant();
        qint64 raw = 0;
        switch (variantValue.metaType().id()) {
        case QMetaType::QString: // TODO: check if string has prepending/appending whitespaces.
        case QMetaType::LongLong:
            raw = variantValue.toLongLong(&ok);
            break;
        case QMetaType::Double: {
            double d = value.toDouble();
            ok = convertDoubleTo(d, &raw) && double(raw) == d;
        } break;
        default:
            break;
        }

        // For types that "smaller" than qint64 we need to check if the value fits its limits range
        if constexpr (sizeof(T) != sizeof(qint64)) {
            if (ok) {
                if constexpr (std::is_same_v<T, QtProtobuf::sfixed32>
                              || std::is_same_v<T, QtProtobuf::int32>) {
                    using limits = std::numeric_limits<qint32>;
                    ok = raw >= limits::min() && raw <= limits::max();
                } else if constexpr (std::is_same_v<T, QtProtobuf::fixed32>) {
                    using limits = std::numeric_limits<quint32>;
                    ok = raw >= limits::min() && raw <= limits::max();
                } else {
                    using limits = std::numeric_limits<T>;
                    ok = raw >= limits::min() && raw <= limits::max();
                }
            }
        }

        return T(raw);
    }

    template <typename T, std::enable_if_t<IsJsonInt64<T>::value, bool> = true>
    static T deserialize(const QJsonValue &value, bool &ok)
    {
        quint64 raw = 0;
        auto variantValue = value.toVariant();
        switch (variantValue.metaType().id()) {
        case QMetaType::QString:
        case QMetaType::LongLong:
            // Here we attempt converting the value to ULongLong
            raw = variantValue.toULongLong(&ok);
            break;
        case QMetaType::Double: {
            double d = value.toDouble();
            ok = convertDoubleTo(d, &raw) && double(raw) == d;
        } break;
        default:
            break;
        }
        return T(raw);
    }

    template <typename T, std::enable_if_t<IsJsonFloatingPoint<T>::value, bool> = true>
    static T deserialize(const QJsonValue &value, bool &ok)
    {
        ok = true;
        QByteArray data = value.toVariant().toByteArray();
        if (data.toLower() == "-infinity"_ba)
            return -std::numeric_limits<T>::infinity();

        if (data.toLower() == "infinity"_ba)
            return std::numeric_limits<T>::infinity();

        if (data.toLower() == "nan"_ba)
            return T(NAN);

        if constexpr (std::is_same_v<T, float>)
            return data.toFloat(&ok);
        else
            return data.toDouble(&ok);
    }

    template <typename T, std::enable_if_t<std::is_same_v<T, bool>, bool> = true>
    static bool deserialize(const QJsonValue &value, bool &ok)
    {
        if (value.isBool()) {
            ok = true;
            return value.toBool();
        } else if (value.isString()) {
            if (value.toString() == "true"_L1) {
                ok = true;
                return true;
            } else if (value.toString() == "false"_L1) {
                ok = true;
                return false;
            }
        }
        return false;
    }

    template <typename T, std::enable_if_t<std::is_same_v<T, QString>, bool> = true>
    static QString deserialize(const QJsonValue &value, bool &ok)
    {
        ok = value.isString();
        return value.toString();
    }

    template <typename T, std::enable_if_t<std::is_same_v<T, QByteArray>, bool> = true>
    static QByteArray deserialize(const QJsonValue &value, bool &ok)
    {
        QByteArray data = value.toVariant().toByteArray();
        if (value.isString()) {
            ok = true;
            return QByteArray::fromBase64(data);
        }
        return {};
    }

    template <typename L /*list*/, typename T /*element*/>
    static QVariant deserializeList(const QJsonValue &value, bool &ok)
    {
        if (!value.isArray()) {
            ok = false;
            return {};
        }

        L list;
        QJsonArray array = value.toArray();
        for (auto arrayValue : array) {
            ok = false;
            T value = deserialize<T>(arrayValue, ok);
            if (!ok)
                break;
            list.append(value);
        }
        return QVariant::fromValue(list);
    }

    void clearError();

    QAbstractProtobufSerializer::Error lastError = QAbstractProtobufSerializer::Error::None;
    QString lastErrorString;

    static SerializerRegistry handlers;

    QProtobufJsonSerializerImpl serializer;
    QProtobufJsonDeserializerImpl deserializer;
};

QProtobufJsonSerializerImpl::~QProtobufJsonSerializerImpl() = default;

void QProtobufJsonSerializerImpl::reset()
{
    m_result = {};
    m_state.clear();
}

bool QProtobufJsonSerializerImpl::serializeEnum(QVariant &value,
                                                const QProtobufFieldInfo &fieldInfo)

{
    const auto jsonName = fieldInfo.jsonName();
    if (fieldInfo.fieldFlags().testFlag(QtProtobufPrivate::FieldFlag::Repeated)) {
        if (!value.convert(QMetaType::fromType<QStringList>()))
            return false;
        if (!ProtobufFieldPresenceChecker::isPresent<QStringList>(value))
            return true;
        m_result.insert(jsonName.toString(),
                        QProtobufJsonSerializerPrivate::serializeList<QStringList>(value));
    } else {
        if (!value.convert(QMetaType::fromType<QString>()))
            return false;
        if (!ProtobufFieldPresenceChecker::isPresent<QString>(value)
            && !isOneofOrOptionalField(fieldInfo.fieldFlags())) {
            return true;
        }
        m_result.insert(jsonName.toString(),
                        QProtobufJsonSerializerPrivate::serializeCommon<QString>(value));
    }
    return true;
}

bool QProtobufJsonSerializerImpl::serializeScalarField(const QVariant &value,
                                                       const QProtobufFieldInfo &fieldInfo)
{
    const auto it = QProtobufJsonSerializerPrivate::handlers.constFind(value.userType());
    // Is not a protobuf scalar value type
    if (it == QProtobufJsonSerializerPrivate::handlers.cend())
        return false;

    // Field is empty
    if (!it->isPresent(value) && !isOneofOrOptionalField(fieldInfo.fieldFlags()))
        return true;

    // If serializer is not defined we should use the standard QJsonValue cast from variant
    m_result.insert(fieldInfo.jsonName().toString(),
                    it->serializer ? it->serializer(value) : QJsonValue::fromVariant(value));
    return true;
}

void QProtobufJsonSerializerImpl::serializeMessageFieldBegin()
{
    m_state.emplaceBack(std::move(m_result));
    m_result = {};
}

void QProtobufJsonSerializerImpl::serializeMessageFieldEnd(const QProtobufMessage *message,
                                                           const QProtobufFieldInfo &field)
{
    QJsonObject store = m_state.takeLast();
    QString fieldName = field.jsonName().toString();
    if (field.fieldFlags().testFlag(QtProtobufPrivate::FieldFlag::Repeated)) {
        // Repeated fields are stored in array property
        // "repeatedField": [{...}, {...}, ...]
        QJsonArray array = store.value(fieldName).toArray();
        array.append(m_result);
        store.insert(fieldName, array);
    } else if (field.fieldFlags().testFlag(QtProtobufPrivate::FieldFlag::Map)) {
        // Maps are stored as fields in inner JSON object
        // "mapField": { "key1": "value1", ... }
        QJsonObject mapObject = store.value(fieldName).toObject();
        // We don't need to serialize key in general, since all JSON object fields should be
        // represented as strings, and types that can be map keys have valid string converters.
        mapObject.insert(message->property("key").toString(), m_result.value("value"_L1));
        store.insert(fieldName, mapObject);
    } else {
        store.insert(fieldName, m_result);
    }
    m_result = store;
}

QProtobufJsonDeserializerImpl::QProtobufJsonDeserializerImpl(QProtobufJsonSerializerPrivate *parent)
    : m_parent(parent)
{
}

QProtobufJsonDeserializerImpl::~QProtobufJsonDeserializerImpl()
    = default;

void QProtobufJsonDeserializerImpl::reset(QJsonObject obj)
{
    m_state.clear();
    if (!obj.isEmpty())
        m_state.push_back({ obj });
}

void QProtobufJsonDeserializerImpl::setError(QAbstractProtobufSerializer::Error error,
                                             QAnyStringView errorString)
{
    m_parent->lastError = error;
    m_parent->lastErrorString = errorString.toString();
}

bool QProtobufJsonDeserializerImpl::deserializeEnum(QVariant &value,
                                                    const QtProtobufPrivate::QProtobufFieldInfo
                                                        &fieldInfo)
{
    bool ok = false;
    auto &state = m_state.last();
    if (fieldInfo.fieldFlags().testFlag(QtProtobufPrivate::FieldFlag::Repeated)) {
        value = QProtobufJsonSerializerPrivate::deserializeList<QStringList,
                                                                QString>(state.scalarValue, ok);
    } else {
        // It's allowed to pass single enum value as numeric value.
        // Make the backward value conversion and deserialize enum as QtProtobuf::int64.
        if (state.scalarValue.isString()) {
            value = QProtobufJsonSerializerPrivate::deserializeCommon<QString>(state.scalarValue,
                                                                               ok);
        } else {
            value = QProtobufJsonSerializerPrivate::deserializeCommon<
                QtProtobuf::int64>(state.scalarValue, ok);
        }
    }

    return ok;
}

int QProtobufJsonDeserializerImpl::nextFieldIndex(QProtobufMessage *message)
{
    const auto *ordering = message->propertyOrdering();
    const int fieldCount = ordering->fieldCount();
    if (fieldCount == 0)
        return -1;

    JsonDeserializerState &state = m_state.last();
    state.scalarValue = {};
    while (state.index < fieldCount) {
        const auto jsonName = ordering->jsonName(state.index);
        const auto keys = state.obj.keys();
        const auto it = std::find_if(keys.constBegin(), keys.constEnd(),
                                     [&jsonName](const auto &val) {
                                         return jsonName == val
                                             || jsonName == convertJsonKeyToJsonName(val);
                                     });

        if (it == keys.constEnd()) {
            ++state.index;
            continue;
        }

        QtProtobufPrivate::FieldFlags flags = ordering->fieldFlags(state.index);
        QJsonValue val = state.obj.value(*it);
        if (val.isNull()) {
            ++state.index;
            continue;
        }

        int index = state.index;
        if (flags.testFlags({ QtProtobufPrivate::FieldFlag::Message,
                              QtProtobufPrivate::FieldFlag::Repeated })) {
            if (!val.isArray()) {
                setInvalidFormatError();
                return -1;
            }

            auto array = val.toArray();
            if (array.isEmpty()) {
                ++state.index;
                continue;
            }

            if (!array.at(0).isObject()) {
                setInvalidFormatError();
                return -1;
            }

            auto nextObject = array.takeAt(0).toObject();
            state.obj.insert(*it, array);
            m_state.push_back({ nextObject });
        } else if (flags.testFlag(QtProtobufPrivate::FieldFlag::Map)) {
            if (!val.isObject()) {
                setInvalidFormatError();
                return -1;
            }

            auto mapObject = val.toObject();
            if (mapObject.isEmpty()) {
                ++state.index;
                continue;
            }

            QString key = mapObject.begin().key();
            QJsonObject nextObject;
            nextObject.insert("key"_L1, key);
            nextObject.insert("value"_L1, mapObject.take(key));
            state.obj.insert(*it, mapObject);
            m_state.push_back({ nextObject });
        } else if (flags.testFlag(QtProtobufPrivate::FieldFlag::Message)) {
            if (!val.isObject()) {
                setInvalidFormatError();
                return -1;
            }

            auto nextObject = val.toObject();
            ++state.index;
            m_state.push_back({ nextObject });
        } else {
            state.scalarValue = val;
            ++state.index;
        }
        return index;
    }

    m_state.pop_back();
    return -1;
}

bool QProtobufJsonDeserializerImpl::deserializeScalarField(QVariant &value,
                                                           const QProtobufFieldInfo &)
{
    auto handler = QProtobufJsonSerializerPrivate::handlers.constFind(value.userType());
    if (handler == QProtobufJsonSerializerPrivate::handlers.constEnd()
        || !handler.value().deserializer) {
        return false;
    }

    bool ok = false;
    value = handler.value().deserializer(m_state.last().scalarValue, ok);
    if (!ok)
        setInvalidFormatError();
    return true;
}

void QProtobufJsonDeserializerImpl::setUnexpectedEndOfStreamError()
{
    setError(QAbstractProtobufSerializer::Error::UnexpectedEndOfStream,
             QCoreApplication::translate("QtProtobuf", "JSON: Unexpected end of stream"));
}

void QProtobufJsonDeserializerImpl::setInvalidFormatError()
{
    setError(QAbstractProtobufSerializer::Error::InvalidFormat,
             QCoreApplication::translate("QtProtobuf",
                                         "JSON: One or more fields have invalid format"));
}

QProtobufJsonSerializerPrivate::SerializerRegistry QProtobufJsonSerializerPrivate::handlers = {};

void QProtobufJsonSerializerPrivate::clearError()
{
    lastError = QAbstractProtobufSerializer::Error::None;
    lastErrorString.clear();
}

QProtobufJsonSerializer::QProtobufJsonSerializer() : d_ptr(new QProtobufJsonSerializerPrivate)
{
}

QProtobufJsonSerializer::~QProtobufJsonSerializer() = default;

/*!
   Returns the last deserialization error for the serializer instance.
   \sa lastErrorString()
*/
QAbstractProtobufSerializer::Error QProtobufJsonSerializer::lastError() const
{
    return d_ptr->lastError;
}

/*!
   Returns the last deserialization error string for the serializer instance.
   \sa lastError()
*/
QString QProtobufJsonSerializer::lastErrorString() const
{
    return d_ptr->lastErrorString;
}

QByteArray QProtobufJsonSerializer::serializeMessage(const QProtobufMessage *message) const
{
    d_ptr->clearError();
    d_ptr->serializer.reset();
    d_ptr->serializer.serializeMessage(message);
    auto result = QJsonDocument(d_ptr->serializer.result()).toJson(QJsonDocument::Compact);
    d_ptr->serializer.reset();
    return result;
}

bool QProtobufJsonSerializer::deserializeMessage(QProtobufMessage *message,
                                                 QByteArrayView data) const
{
    d_ptr->clearError();
    QJsonParseError err;
    auto document = QJsonDocument::fromJson(data.toByteArray(), &err);
    if (err.error != QJsonParseError::NoError) {
        d_ptr->deserializer.setUnexpectedEndOfStreamError();
        return false;
    }

    if (!document.isObject()) {
        d_ptr->deserializer.setInvalidFormatError();
        return false;
    }

    if (auto obj = document.object(); !obj.isEmpty()) {
        d_ptr->deserializer.reset(obj);
        bool result = d_ptr->deserializer.deserializeMessage(message);
        d_ptr->deserializer.reset({});
        return result;
    }
    return true;
}

QT_END_NAMESPACE
