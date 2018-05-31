#pragma once

#include <QTcpSocket>

class ServerSettings;

class Client : public QTcpSocket
{
public:
    Client(const ServerSettings&);

    void run();
private:
    const ServerSettings& settings_;
};
