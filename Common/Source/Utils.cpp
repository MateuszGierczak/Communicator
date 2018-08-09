#include "Utils.hpp"

#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>

void sendMsg(QTcpSocket& socket, const Message& message)
{
    QByteArray bytes {};
    QDataStream stream {&bytes, QIODevice::WriteOnly};

    stream << message;

    socket.write(bytes);
}

Message receiveMsg(QTcpSocket& socket)
{
    QByteArray bytes {socket.readAll()};
    QDataStream stream {bytes};

    Message message {};
    stream >> message;

    return message;
}
