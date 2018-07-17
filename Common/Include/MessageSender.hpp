#pragma once

struct Message;
struct QTcpSocket;

struct MessageSender
{
    static void sendMessage(QTcpSocket&, const Message&);
};
