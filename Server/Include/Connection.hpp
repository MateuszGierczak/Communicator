#pragma once

#include <QTcpSocket>

class Connection : public QTcpSocket
{
    Q_OBJECT

public:
    Connection();

    unsigned int getId() const { return id_; }

private slots:
    void handleRead();

private:
    static unsigned int nextId_;

    const unsigned int id_ {nextId_++};
};
