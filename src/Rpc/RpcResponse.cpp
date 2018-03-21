#include "RpcResponse.h"

RpcResponse::RpcResponse(QString id, QString methodName)
    : id(id),
      methodName(methodName),
      error(QString::Null())
{
}

RpcResponse RpcResponse::ofRequest(RpcRequest request)
{
    return RpcResponse(request.getId(), request.getMethodName());
}

RpcResponse RpcResponse::ok(RpcRequest request, QVariant result)
{
    RpcResponse response = ofRequest(request);
    response.result = result;
    response.error = QString::Null();
    return response;
}

RpcResponse RpcResponse::fail(RpcRequest request, QString error)
{
    RpcResponse response = ofRequest(request);
    response.result = QVariant();
    response.error = error;
    return response;
}

const QString& RpcResponse::getId()
{
    return id;
}

const QString& RpcResponse::getMethodName()
{
    return methodName;
}

const QVariant& RpcResponse::getResult()
{
    return result;
}

const QString& RpcResponse::getError()
{
    return error;
}
