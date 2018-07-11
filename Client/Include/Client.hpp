#pragma once

#include "ServerSettings.hpp"

#include <QTcpSocket>

class View;

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    Client(View&);

private slots:
    void handleConnectClient(ServerSettings, QString);
    void handleRead();

private:
    View& view_;
};
