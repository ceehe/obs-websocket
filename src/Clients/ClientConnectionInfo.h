#pragma once

#include <QtCore/QString>
#include <QtCore/QHash>

class ClientConnectionInfo
{
    public:
        ClientConnectionInfo(const QString& ipAddress,
                             const QHash<QString, QString>& headers);
        const QString& getIpAddress() const;
        const QHash<QString, QString> getHeaders() const;
    private:
        QString ipAddress;
        QHash<QString, QString> headers;
};
