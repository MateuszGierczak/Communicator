#pragma once

#include <QTcpSocket>

class ServerSettings;

class Client
{
public:
    Client(const ServerSettings&);

    void run();
private:
    const ServerSettings& settings_;

    QTcpSocket socket_ {};
};
