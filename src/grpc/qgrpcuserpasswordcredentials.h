// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2019 Alexey Edelev <semlanik@gmail.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#ifndef QGRPCUSERPASSWORDCREDENTIALS_H
#define QGRPCUSERPASSWORDCREDENTIALS_H

#include <QtGrpc/qgrpccredentials.h>
#include <QtGrpc/qtgrpcglobal.h>

QT_BEGIN_NAMESPACE

class QGrpcUserPasswordCredentials final : public QGrpcCallCredentials
{
public:
    QGrpcUserPasswordCredentials(const QString &userName, const QString &password);
    QGrpcUserPasswordCredentials(const QByteArray &userNameField, const QString &userName,
                                 const QByteArray &passwordField, const QString &password);

    ~QGrpcUserPasswordCredentials() override = default;
    QGrpcCredentialMap operator()() const override { return m_map; }

private:
    QGrpcUserPasswordCredentials();
    QGrpcCredentialMap m_map;
};

QT_END_NAMESPACE

#endif // QGRPCUSERPASSWORDCREDENTIALS_H
