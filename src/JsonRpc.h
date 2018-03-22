#pragma once

#include <QJsonDocument>
#include <QWebSocket>
#include <QString>

#include "Rpc/RpcResponse.h"
#include "Rpc/RpcRequest.h"
#include "Rpc/RpcHandler.h"

class JsonRpc {
public:
	JsonRpc(RpcHandler* handler);
	void handleTextMessage(QWebSocket* client, QString& messageBody);
private:
	static RpcRequest jsonToRequest(const QJsonDocument& requestBody);
	static QJsonDocument responseToJson(RpcResponse& response);

	static bool requestDocumentIsValid(const QJsonDocument& request);
	static QJsonDocument anonymousError(const QString& error);
	static void sendToClient(QWebSocket* client, const QJsonDocument& document);

	RpcHandler* rpcHandler;
};