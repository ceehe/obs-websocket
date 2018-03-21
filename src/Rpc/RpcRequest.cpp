#include "RpcRequest.h"

RpcRequest::RpcRequest(const QString &id, const QString &methodName,
    QVariantHash params)
        : id(id),
          methodName(methodName),
          parameters(params)
{
}

QVariantHash RpcRequest::immutableParams()
{
    return QVariantHash(parameters);
}

QString RpcRequest::getId()
{
    return this->id;
}

QString RpcRequest::getMethodName()
{
    return this->methodName;
}
