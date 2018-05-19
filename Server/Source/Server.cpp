#include "Server.hpp"
#include "ServerSettings.hpp"

#include <iostream>

Server::Server(const ServerSettings& settings)
    : settings_(settings)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));
}

void Server::run()
{
    if(listen(QHostAddress::Any, settings_.port))
    {
        std::cout << "Listening..." << std::endl;
    }
}

void Server::handleNewConnection()
{
    std::cout << "Someone connected to server" << std::endl;
}
