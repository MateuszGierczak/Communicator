#include "Client.hpp"
#include "View.hpp"
#include "ServerSettings.hpp"

Client::Client(View& view)
    : view_(view)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
    connect(&view_, SIGNAL(connectClient(ServerSettings, QString)),
            this, SLOT(handleConnectClient(ServerSettings, QString)));
}

void Client::handleConnectClient(ServerSettings settings, QString nick)
{
    qDebug() << "Client connecting. Host : " << settings.host
             << ", port : " << settings.port << ", nick : " << nick;

    connectToHost(settings.host, settings.port);
}

void Client::handleRead()
{
    qDebug() << "Received data on client site";
}
