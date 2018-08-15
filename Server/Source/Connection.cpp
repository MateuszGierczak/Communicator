#include "Connection.hpp"
#include "Message.hpp"
#include "Utils.hpp"

#include <QDataStream>

Connection::Connection(QObject *parent, ConnectionId id)
    : QTcpSocket(parent),
      id_(id)
{}

void Connection::handleRead()
{
    qDebug() << "Received " << bytesAvailable() << " bytes on server site";

    Message message {receiveMsg(*this)};

    qDebug() << "MsgId: " << message.getMsgId() << ", nick : " << message.getPayload<QString>();;
}
