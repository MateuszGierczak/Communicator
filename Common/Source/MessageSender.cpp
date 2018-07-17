#include "MessageSender.hpp"
#include "Message.hpp"

#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>

void MessageSender::sendMessage(QTcpSocket &socket, const Message &message)
{
    QByteArray bytes {};
    QDataStream stream {&bytes, QIODevice::WriteOnly};

    stream << message;

    socket.write(bytes);
}
