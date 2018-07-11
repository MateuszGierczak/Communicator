#include "Client.hpp"
#include "View.hpp"
#include "ServerSettings.hpp"

#include <iostream>

Client::Client(View& view)
    : view_(view)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
    connect(&view_, SIGNAL(connectClient(ServerSettings, QString)),
            this, SLOT(handleConnectClient(ServerSettings, QString)));
}

void Client::handleConnectClient(ServerSettings settings, QString nick)
{
    connectToHost(settings.host, settings.port);
}

void Client::handleRead()
{
    std::cout << "Received data on client site" << std::endl;
}
