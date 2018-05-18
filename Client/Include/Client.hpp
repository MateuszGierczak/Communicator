#pragma once

#include <memory>

#include <QTcpSocket>

class ServerSettings;

class Client
{
public:
    Client(const ServerSettings&);
private:
    QTcpSocket socket_ {};
};
