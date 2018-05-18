#pragma once

#include <QtNetwork/QTcpServer>

class ServerSettings;

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(const ServerSettings&);

private:
    void incomingConnection(qintptr descriptor) override;
};
