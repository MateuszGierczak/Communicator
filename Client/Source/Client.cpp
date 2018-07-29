#include "Client.hpp"
#include "View.hpp"
#include "ServerSettings.hpp"
#include "MessageSender.hpp"
#include "Message.hpp"

Client::Client(View& view)
    : view_(view)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
    connect(this, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(handleStateChanged(QAbstractSocket::SocketState)));
    connect(&view_, SIGNAL(connectClient(const ServerSettings&, QString)),
            this, SLOT(handleConnectClient(const ServerSettings&, QString)));
    connect(&view, SIGNAL(disconnectClient()), this, SLOT(handleDisconnectClient()));
}

void Client::handleConnectClient(const ServerSettings& settings, QString nick)
{
    qDebug() << "Client connecting. Host : " << settings.host
             << ", port : " << settings.port << ", nick : " << nick;

    connectToHost(settings.host, settings.port);

    MessageSender::sendMessage(*this, Message{1u, nick});
}

void Client::handleDisconnectClient()
{
    disconnectFromHost();
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
