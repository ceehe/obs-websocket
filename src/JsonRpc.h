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
	void handleTextMessage(QWebSocket* client, QString messageBody);
private:
	static RpcRequest jsonToRequest(QJsonDocument requestBody);
	static QJsonDocument responseToJson(RpcResponse response);

	static bool requestDocumentIsValid(QJsonDocument request);
	static QJsonDocument anonymousError(QString error);
	static void sendToClient(QWebSocket* client, QJsonDocument document);

	RpcHandler* rpcHandler;
};