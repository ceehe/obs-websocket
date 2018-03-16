
#include <src/obs-websocket.h>
#include "WebsocketsServer.h"

WebsocketsServer::WebsocketsServer(int port, QString protocolName)
    : _port(port),
      _protocolName(protocolName)
{
}

WebsocketsServer::~WebsocketsServer()
{
}

void WebsocketsServer::run()
{
    const char* constProtocolName = this->_protocolName.toUtf8().constData();

    static const struct lws_extension exts[] = {
            {"permessage-deflate", lws_extension_callback_pm_deflate, "permessage-deflate"},
            {"deflate-frame", lws_extension_callback_pm_deflate, "deflate_frame"},
            { NULL, NULL, NULL /* terminator */ }
    };

    const struct lws_protocols _protocols[] = {
            {"http-only", lws_callback_http_dummy, 0, 0}, // Default handler
            {
                    constProtocolName,
                    WebsocketsServer::wsCallback,
                    0, // per-session private data allocation size
                    0, // rx buffer size
                    0, // id
                    this, // private protocol data
                    0 // tx packet size
            },
            {NULL, NULL, 0, 0} // Terminator
    };

    struct lws_context_creation_info info = {0};
    info.port = this->_port;
    info.server_string = "obs-websocket";
    info.options |= LWS_SERVER_OPTION_VALIDATE_UTF8;
    info.protocols = _protocols;
    info.extensions = exts;

    this->_lwsContext = lws_create_context(&info);
    if (!this->_lwsContext) {
        blog(LOG_ERROR, "libwebsocket init failed!");
        return;
    }

    int n = 0;
    while(n >= 0 || !this->isInterruptionRequested()) {
        n = lws_service(this->_lwsContext, 10);
    }

    lws_context_destroy(this->_lwsContext);
}

int WebsocketsServer::wsCallback(struct lws *wsInstance,
                                 enum lws_callback_reasons reason,
                                 void *userData, void *in, size_t len)
{
    switch(reason) {
        case LWS_CALLBACK_SERVER_NEW_CLIENT_INSTANTIATED:
            // New client connected and accepted
            break;
        case LWS_CALLBACK_RECEIVE:
            // Incoming data from client
            break;
        case LWS_CALLBACK_SERVER_WRITEABLE:
            // We can send data to the client
            break;
        case LWS_CALLBACK_WS_PEER_INITIATED_CLOSE:
            // Client wants to disconnect
            break;
        default:
            break;
    }
}
