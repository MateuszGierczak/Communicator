#pragma once

#include <QTcpSocket>

using ConnectionId = unsigned int;

class Connection : public QTcpSocket
{
    Q_OBJECT

public:
    Connection(QObject*, ConnectionId);

    ConnectionId getId() const { return id_; }

private slots:
    void handleRead();

private:
    const ConnectionId id_ {};
};
