#pragma once

#include "Connection.hpp"

#include <QMap>
#include <QTcpServer>

class ServerSettings;

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject*, const ServerSettings&);

    void run();

private slots:
    void handleDisconnectConnection();

private:
    void incomingConnection(qintptr descriptor) override;

    const ServerSettings& settings_;

    QMap<ConnectionId, Connection*> connections_;
};
