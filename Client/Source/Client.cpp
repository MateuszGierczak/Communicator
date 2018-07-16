#include "Client.hpp"
#include "View.hpp"
#include "ServerSettings.hpp"
#include "MessageSender.hpp"

Client::Client(View& view)
    : view_(view)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
    connect(&view_, SIGNAL(connectClient(const ServerSettings&, QString)),
            this, SLOT(handleConnectClient(const ServerSettings&, QString)));
}

void Client::handleConnectClient(const ServerSettings& settings, QString nick)
{
    qDebug() << "Client connecting. Host : " << settings.host
             << ", port : " << settings.port << ", nick : " << nick;

    connectToHost(settings.host, settings.port);

    MessageSender::sendMessage(*this, nick);
}

void Client::handleRead()
{
    qDebug() << "Received data on client site";
}
