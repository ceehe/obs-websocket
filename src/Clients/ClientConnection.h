#pragma once

#include <QtCore/QString>
#include "ClientConnectionInfo.h"

class ClientConnection
{
    public:
        virtual void sendTextMessage(QString& message) = 0;
        virtual const ClientConnectionInfo& getConnectionInfo() = 0;
};
