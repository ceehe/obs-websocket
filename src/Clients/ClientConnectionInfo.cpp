#include "ClientConnectionInfo.h"

ClientConnectionInfo::ClientConnectionInfo(
        const QString &ipAddress,
        const QHash<QString, QString>& headers
) : ipAddress(ipAddress), headers(headers)
{
}

const QString& ClientConnectionInfo::getIpAddress() const
{
    return this->ipAddress;
}

const QHash<QString, QString> ClientConnectionInfo::getHeaders() const
{
    return QHash<QString, QString>(this->headers);
}
