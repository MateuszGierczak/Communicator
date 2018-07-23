#include "Connection.hpp"
#include "Message.hpp"
#include "MessageReceiver.hpp"

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

    Message message {MessageReceiver::receive(*this)};

    qDebug() << "MsgId: " << message.msgId_ << ", nick : " << message.getPayload<QString>();;
}
