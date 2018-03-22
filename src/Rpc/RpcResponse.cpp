#include "RpcResponse.h"

RpcResponse::RpcResponse(const QString& id, const QString& methodName)
    : id(id),
      methodName(methodName),
      error(QString::Null())
{
}

RpcResponse RpcResponse::ofRequest(const RpcRequest& request)
{
    return RpcResponse(request.getId(), request.getMethodName());
}

const RpcResponse RpcResponse::ok(const RpcRequest& request, const QVariant& result)
{
    RpcResponse response = ofRequest(request);
    response.result = result;
    response.error = QString::Null();
    return response;
}

const RpcResponse RpcResponse::fail(const RpcRequest& request, const QString& error)
{
    RpcResponse response = ofRequest(request);
    response.result = QVariant();
    response.error = error;
    return response;
}

const QString& RpcResponse::getId() const
{
    return id;
}

const QString& RpcResponse::getMethodName() const
{
    return methodName;
}

const QVariant& RpcResponse::getResult() const
{
    return result;
}

const QString& RpcResponse::getError() const
{
    return error;
}
