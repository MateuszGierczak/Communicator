#include "Client.hpp"
#include "ServerSettings.hpp"

#include <iostream>

Client::Client(const ServerSettings& settings)
    : settings_(settings)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
}

void Client::handleRead()
{
    std::cout << "Received data on client site" << std::endl;
}

void Client::run()
{
    connectToHost(settings_.host.data(), settings_.port);
}
