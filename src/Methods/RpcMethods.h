#pragma once

#include <QJsonArray>

#include "../Rpc/RpcMethod.h"
#include "../Utils.h"
#include "../obs-websocket.h"

class GetVersion : public RpcMethod {
  public:
	  RpcResponse handle(RpcRequest& request) override
	  {
		  QString obsVersion = Utils::OBSVersionString();

		  QVariantHash params;
		  params.insert("pluginVersion", OBS_WEBSOCKET_VERSION);
		  params.insert("programVersion", obsVersion);

		  return RpcResponse::ok(request, params);
	  }
};