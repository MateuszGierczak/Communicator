#pragma once

#include "Connection.hpp"

#include <map>
#include <memory>
#include <QtNetwork/QTcpServer>

class ServerSettings;

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(const ServerSettings&);

    void run();

private slots:
    void handleDisconnectConnection();

private:
    void incomingConnection(qintptr descriptor) override;

    const ServerSettings& settings_;

    std::map<ConnectionId, std::unique_ptr<Connection>> connections_;
};
