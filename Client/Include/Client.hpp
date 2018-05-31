#pragma once

#include <QTcpSocket>

class ServerSettings;

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    Client(const ServerSettings&);

    void run();

private slots:
    void handleRead();

private:
    const ServerSettings& settings_;
};
