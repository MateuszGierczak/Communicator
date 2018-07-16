#include "Connection.hpp"

#include <QDataStream>

#include <iostream>

ConnectionId Connection::nextId_ {1};

Connection::Connection()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

void Connection::handleRead()
{
    auto numOfReadBytes = bytesAvailable();
    std::cout << "Received " << numOfReadBytes << " bytes on server site" << std::endl;

    QByteArray bytes {readAll()};
    QDataStream stream {bytes};

    QString nick {};
    stream >> nick;

    std::cout << "Nick: " << nick.toStdString() << std::endl;
}
