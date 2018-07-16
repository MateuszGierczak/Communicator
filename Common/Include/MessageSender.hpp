#pragma once

#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>

struct MessageSender
{
    template<typename T>
    static void sendMessage(QTcpSocket& socket, const T& message)
    {
        QByteArray bytes {};
        QDataStream stream {&bytes, QIODevice::WriteOnly};

        stream << message;

        socket.write(bytes);
    }
};
