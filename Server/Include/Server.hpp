#pragma once

#include <QtNetwork/QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    void start();

private:
    void incomingConnection(qintptr descriptor) override;
};
