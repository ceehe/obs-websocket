#pragma once

#include <QJsonArray>

#include "src/Rpc/RpcMethod.h"
#include "src/Utils.h"
#include "src/obs-websocket.h"

class GetVersion : public RpcMethod {
  public:
	  const RpcResponse handle(const RpcRequest& request) override
	  {
		  QString obsVersion = Utils::OBSVersionString();

		  QVariantHash params;
		  params.insert("pluginVersion", OBS_WEBSOCKET_VERSION);
		  params.insert("programVersion", obsVersion);

		  return RpcResponse::ok(request, params);
	  }
};