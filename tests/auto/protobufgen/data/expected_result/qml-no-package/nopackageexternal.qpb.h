/* This file is autogenerated. DO NOT CHANGE. All changes will be lost */

#ifndef QPROTOBUF_NOPACKAGEEXTERNAL_H
#define QPROTOBUF_NOPACKAGEEXTERNAL_H

#include <QtProtobuf/qprotobufmessage.h>
#include <QtProtobuf/qprotobufobject.h>
#include <QtProtobuf/qprotobuflazymessagepointer.h>

#include <QtQml/qqmlregistration.h>
#include <QtQml/qqmllist.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qstring.h>

#include <QtCore/qmetatype.h>
#include <QtCore/qlist.h>
#include <QtCore/qshareddata.h>

#include <memory>

#if defined(QT_SHARED) || !defined(QT_STATIC)
#  if defined(QT_BUILD_TST_QTPROTOBUFGENPLUGIN_LIB)
#    define QPB_TST_QTPROTOBUFGENPLUGIN_EXPORT Q_DECL_EXPORT
#  else
#    define QPB_TST_QTPROTOBUFGENPLUGIN_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define QPB_TST_QTPROTOBUFGENPLUGIN_EXPORT
#endif

class SimpleIntMessageExt;
using SimpleIntMessageExtRepeated = QList<std::shared_ptr<SimpleIntMessageExt>>;

class SimpleIntMessageExt_QtProtobufData;
class QPB_TST_QTPROTOBUFGENPLUGIN_EXPORT SimpleIntMessageExt : public QProtobufMessage
{
    Q_GADGET
    Q_PROTOBUF_OBJECT
    Q_DECLARE_PROTOBUF_SERIALIZERS(SimpleIntMessageExt)
    QML_VALUE_TYPE(simpleIntMessageExt)
    Q_PROPERTY(QtProtobuf::int32 testFieldInt_p READ testFieldInt WRITE setTestFieldInt SCRIPTABLE false)
    Q_PROPERTY(int testFieldInt READ testFieldInt_p WRITE setTestFieldInt_p SCRIPTABLE true)

public:
    enum QtProtobufFieldEnum {
        TestFieldIntProtoFieldNumber = 1,
    };
    Q_ENUM(QtProtobufFieldEnum)

    SimpleIntMessageExt();
    ~SimpleIntMessageExt();
    SimpleIntMessageExt(const SimpleIntMessageExt &other);
    SimpleIntMessageExt &operator =(const SimpleIntMessageExt &other);
    SimpleIntMessageExt(SimpleIntMessageExt &&other) noexcept;
    SimpleIntMessageExt &operator =(SimpleIntMessageExt &&other) noexcept;
    bool operator ==(const SimpleIntMessageExt &other) const;
    bool operator !=(const SimpleIntMessageExt &other) const;

    QtProtobuf::int32 testFieldInt() const;
    void setTestFieldInt(const QtProtobuf::int32 &testFieldInt);
    static void registerTypes();

private:
    int testFieldInt_p() const;
    void setTestFieldInt_p(const int &testFieldInt);
    QExplicitlySharedDataPointer<SimpleIntMessageExt_QtProtobufData> dptr;
};

Q_DECLARE_METATYPE(SimpleIntMessageExt)
Q_DECLARE_METATYPE(QQmlListProperty<SimpleIntMessageExt>)
#endif // QPROTOBUF_NOPACKAGEEXTERNAL_H
