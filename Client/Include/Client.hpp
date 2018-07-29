#pragma once

#include <QTcpSocket>

class View;
class ServerSettings;

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    Client(View&);

private slots:
    void handleConnectClient(const ServerSettings&, QString);
    void handleDisconnectClient();

    void handleRead();
    void handleStateChanged(QAbstractSocket::SocketState);

private:
    View& view_;
};
