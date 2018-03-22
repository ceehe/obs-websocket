#include "RpcHandler.h"

#include "Methods/RpcMethods.h"

RpcHandler::RpcHandler()
{
	this->builtinMethodHandlers.insert("GetVersion", new GetVersion());
}

RpcHandler::~RpcHandler()
{
}

const RpcResponse RpcHandler::processCall(const RpcRequest& request)
{
	QString methodName = request.getMethodName();

	// Try to resolve the method from the built-in ones
	RpcMethod* method = this->builtinMethodHandlers.value(methodName, nullptr);
	if (method) {
		return method->handle(request);
	} else {
		// Otherwise let's try from the 3rd party ones
		RpcMethod* thirdPartyMethod =
			this->thirdPartyMethodHandlers.value(methodName, nullptr);
		if (thirdPartyMethod) {
			return thirdPartyMethod->handle(request);
		}
	}

	return RpcResponse::fail(request, "Method not found",
							 RpcErrorCode::MethodNotFound);
}