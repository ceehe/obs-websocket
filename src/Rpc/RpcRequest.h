#pragma once

#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QVariantHash>

class RpcRequest {
  public:
    RpcRequest(const QString &id, const QString &methodName,
        QVariantHash params);
    QHash<QString, QVariant> immutableParams();
    QString getId();
    QString getMethodName();
  private:
    QString id;
    QString methodName;
    QVariantHash parameters;
};
