#pragma once

#include "Connection.hpp"

#include <vector>
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
    void handleNewConnection();

private:
    const ServerSettings& settings_;

    std::vector<std::unique_ptr<Connection>> connections_;
};
