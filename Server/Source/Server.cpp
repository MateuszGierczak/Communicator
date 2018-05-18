#include "Server.hpp"

#include <QtDebug>

void Server::start()
{
    if(listen())
    {
        qDebug() << "Listening...";
    }
}

void Server::incomingConnection(qintptr descriptor)
{
    qDebug() << "Someone connected to server";
}
