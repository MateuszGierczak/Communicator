#include "Server.hpp"
#include "ServerSettings.hpp"

#include <iostream>

Server::Server(const ServerSettings& settings)
{
    if(listen(QHostAddress::Any, settings.port))
    {
        std::cout << "Listening..." << std::endl;
    }
}

void Server::incomingConnection(qintptr descriptor)
{
    std::cout << "Someone connected to server" << std::endl;
}
