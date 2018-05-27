#include "Server.hpp"
#include "ServerSettings.hpp"
#include "Connection.hpp"

#include <iostream>

Server::Server(const ServerSettings& settings)
    : settings_(settings)
{}

void Server::run()
{
    if(listen(QHostAddress::Any, settings_.port))
    {
        std::cout << "Listening..." << std::endl;
    }
}

void Server::handleDisconnectConnection()
{
    Connection* connection = qobject_cast<Connection*>(sender());

    connections_.erase(connection->getId());

    std::cout << "Client with ID = " << connection->getId() << " disconnected."
              << " Number of connected clients = " << connections_.size() << std::endl;
}

void Server::incomingConnection(qintptr descriptor)
{
    auto client = std::make_unique<Connection>();

    std::cout << "Client with ID = " << client->getId() << " connected" << std::endl;

    client->setSocketDescriptor(descriptor);

    connect(client.get(), SIGNAL(disconnected()), this, SLOT(handleDisconnectConnection()));

    connections_.insert({client->getId(), std::move(client)});
}
