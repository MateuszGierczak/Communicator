#pragma once

#include <QTcpSocket>

class Connection : public QTcpSocket
{
    Q_OBJECT

public:
    Connection(qintptr);

private slots:
    void handleRead();

private:
};
