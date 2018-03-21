#pragma once

#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QHash>
#include "RpcRequest.h"

class RpcResponse {
  public:
    static RpcResponse ofRequest(RpcRequest request);
    static RpcResponse ok(RpcRequest request, QVariant result = QVariant());
    static RpcResponse fail(RpcRequest request, QString error);

    RpcResponse(QString id, QString methodName);

    const QString& getId();
    const QString& getMethodName();
    const QVariant& getResult();
    const QString& getError();
  private:
    QString id;
    QString error;
    QString methodName;
    QVariant result;
};
