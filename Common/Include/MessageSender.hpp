#pragma once

#include <QTcpSocket>

struct MessageSender
{
    static void sendMessage(QTcpSocket&);
};
