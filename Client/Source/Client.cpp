#include "Client.hpp"
#include "View.hpp"
#include "ServerSettings.hpp"

#include <iostream>

Client::Client(const ServerSettings& settings,
               View& view)
    : settings_(settings),
      view_(view)
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
