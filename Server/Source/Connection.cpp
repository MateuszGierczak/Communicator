#include "Connection.hpp"
#include "Message.hpp"
#include "Utils.hpp"

#include <QDataStream>

Connection::Connection(QObject *parent, ConnectionId id)
    : QTcpSocket(parent),
      id_(id)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
}

void Connection::handleRead()
{
    qDebug() << "Received " << bytesAvailable() << " bytes on server site";

    Message message {receiveMsg(*this)};

    qDebug() << "MsgId: " << message.msgId_ << ", nick : " << message.getPayload<QString>();;
}
