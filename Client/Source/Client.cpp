#include "Client.hpp"
#include "View.hpp"
#include "ServerSettings.hpp"
#include "Utils.hpp"
#include "Message.hpp"

Client::Client(View& view)
    : view_(view)
{
    connect(this, &QIODevice::readyRead, this, &Client::handleRead);
    connect(this, &QAbstractSocket::stateChanged, this, &Client::handleStateChanged);
    connect(&view_, &View::connectClient, this, &Client::handleConnectClient);
    connect(&view, &View::disconnectClient, [&](){ disconnectFromHost(); });
}

void Client::handleConnectClient(const ServerSettings& settings, QString nick)
{
    qDebug() << "Client connecting. Host : " << settings.host
             << ", port : " << settings.port << ", nick : " << nick;

    connectToHost(settings.host, settings.port);

    sendMsg(*this, Message{1u, nick});
}

void Client::handleRead()
{
    qDebug() << "Received data on client site";
}

void Client::handleStateChanged(QAbstractSocket::SocketState state)
{
   if(state == QAbstractSocket::ConnectedState)
   {
       view_.updateAfterClientConnected();
   }
   else if(state == QAbstractSocket::UnconnectedState)
   {
       view_.updateAfterClientDisconnected();
   }
}
