#pragma once

#include <memory>

#include <QTcpSocket>

class ServerSettings;

class Client
{
public:
    Client(const ServerSettings&);

    void run();
private:
    const ServerSettings& settings;

    QTcpSocket socket_ {};
};
