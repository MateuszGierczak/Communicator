#pragma once

#include <QtNetwork/QTcpServer>

class ServerSettings;

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(const ServerSettings&);

    void run();

private slots:
    void handleNewConnection();

private:
    const ServerSettings& settings_;
};
