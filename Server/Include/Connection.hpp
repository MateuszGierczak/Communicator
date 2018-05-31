#pragma once

#include <QTcpSocket>

using ConnectionId = unsigned int;

class Connection : public QTcpSocket
{
    Q_OBJECT

public:
    Connection();

    unsigned int getId() const { return id_; }

private slots:
    void handleRead();

private:
    static ConnectionId nextId_;

    const ConnectionId id_ {nextId_++};
};
