#pragma once

#include <QTcpSocket>

class View;
class ServerSettings;

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    Client(const ServerSettings&,
           View&);

    void run();

private slots:
    void handleRead();

private:
    const ServerSettings& settings_;
    View& view_;
};
