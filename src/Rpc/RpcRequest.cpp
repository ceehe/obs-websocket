#include "RpcRequest.h"

RpcRequest::RpcRequest(const QString &id, const QString &methodName,
    const QVariantHash& params)
        : id(id),
          methodName(methodName),
          parameters(params)
{
}

QVariantHash RpcRequest::immutableParams()
{
    return QVariantHash(parameters);
}

const QString& RpcRequest::getId()
{
    return this->id;
}

const QString& RpcRequest::getMethodName()
{
    return this->methodName;
}
