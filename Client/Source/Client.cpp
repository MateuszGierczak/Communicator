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
    connect(&view_, SIGNAL(connectClient(QString)), this, SLOT(handleConnectClient(QString)));
}

void Client::handleConnectClient(QString nick)
{
    connectToHost(settings_.host.data(), settings_.port);
}

void Client::handleRead()
{
    std::cout << "Received data on client site" << std::endl;
}
