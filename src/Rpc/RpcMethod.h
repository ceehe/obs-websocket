#pragma once

#include "RpcRequest.h"
#include "RpcResponse.h"

class RpcMethod {
  public:
    virtual RpcResponse handle(RpcRequest request) = 0;
};
