#include "MessageReceiver.hpp"

#include <QTcpSocket>
#include <QDataStream>

Message MessageReceiver::receive(QTcpSocket& socket)
{
    QByteArray bytes {socket.readAll()};
    QDataStream stream {bytes};

    Message message {};
    stream >> message;

    return message;
}
