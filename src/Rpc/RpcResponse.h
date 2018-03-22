#pragma once

#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtCore/QHash>
#include "RpcRequest.h"

class RpcResponse {
  public:
    static RpcResponse ofRequest(const RpcRequest& request);
    static const RpcResponse ok(const RpcRequest& request, const QVariant& result = QVariant());
    static const RpcResponse fail(const RpcRequest& request, const QString& error);

    RpcResponse(const QString& id, const QString& methodName);

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
