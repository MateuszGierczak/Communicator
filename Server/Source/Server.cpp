#include "Server.hpp"
#include "ServerSettings.hpp"
#include "Connection.hpp"

#include <QDebug>

Server::Server(const ServerSettings& settings)
    : settings_(settings)
{}

void Server::run()
{
    if(listen(QHostAddress::Any, settings_.port))
    {
        qDebug() << "Listening...";
    }
}

void Server::handleDisconnectConnection()
{
    Connection* connection = qobject_cast<Connection*>(sender());

    connections_.remove(connection->getId());

    qDebug() << "Client with ID = " << connection->getId() << " disconnected."
              << " Number of connected clients = " << connections_.size();
}

void Server::incomingConnection(qintptr descriptor)
{
    auto client = new Connection(this);

    qDebug() << "Client with ID = " << client->getId() << " connected";

    client->setSocketDescriptor(descriptor);

    connect(client, SIGNAL(disconnected()), this, SLOT(handleDisconnectConnection()));
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));

    connections_.insert(client->getId(), client);
}
