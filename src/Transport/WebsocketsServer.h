
#ifndef OBS_WEBSOCKET_WEBSOCKETSSERVER_H
#define OBS_WEBSOCKET_WEBSOCKETSSERVER_H

#include <libwebsockets.h>
#include <QtCore/QThread>

class WebsocketsServer : QThread
{
  public:
    WebsocketsServer(int port, QString protocolName);
    ~WebsocketsServer();
    static int wsCallback(
            struct lws* wsInstance,
            enum lws_callback_reasons reason,
            void* userData,
            void* in,
            size_t len
    );

  private:
    void run() override;

    int _port;
    QString _protocolName;
    struct lws_context* _lwsContext;
};


#endif //OBS_WEBSOCKET_WEBSOCKETSSERVER_H
