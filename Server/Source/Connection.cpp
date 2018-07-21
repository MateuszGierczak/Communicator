#include "Connection.hpp"
#include "Message.hpp"

#include <QDataStream>

ConnectionId Connection::nextId_ {1};

Connection::Connection(QObject *parent) : QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
}

void Connection::handleRead()
{
    qDebug() << "Received " << bytesAvailable() << " bytes on server site";

    QByteArray bytes {readAll()};
    QDataStream stream {bytes};

    Message message {};
    stream >> message;

    qDebug() << "MsgId: " << message.msgId_ << ", nick : " << message.getPayload<QString>();;
}
