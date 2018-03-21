#include "RpcRequest.h"

RpcRequest::RpcRequest(const QString &id, const QString &methodName,
    QHash<QString, QVariant> params)
        : id(id),
          methodName(methodName),
          parameters(params)
{
}

QHash<QString, QVariant> RpcRequest::immutableParams()
{
    return QHash<QString, QVariant>(parameters);
}

QString RpcRequest::getId()
{
    return this->id;
}

QString RpcRequest::getMethodName()
{
    return this->methodName;
}
