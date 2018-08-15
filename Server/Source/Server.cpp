#include "Server.hpp"
#include "ServerSettings.hpp"
#include "Utils.hpp"
#include "Message.hpp"
#include "MessagesIds.hpp"

#include <QDebug>

Server::Server(QObject* parent, const ServerSettings& settings)
    : QTcpServer(parent),
      settings_(settings)
{}

void Server::run()
{
    if(listen(QHostAddress::Any, settings_.port))
    {
        qDebug() << "Listening...";
    }
}

void Server::handleDisconnectConnection()
{
    Connection* connection = qobject_cast<Connection*>(sender());

    connections_.remove(connection->getId());

    qDebug() << "Client with ID = " << connection->getId() << " disconnected."
             << " Number of connected clients = " << connections_.size();
}

void Server::incomingConnection(qintptr descriptor)
{
    static ConnectionId nextConnectionId {1};

    auto client = new Connection(this, nextConnectionId++);

    qDebug() << "Client with ID = " << client->getId() << " connected";

    client->setSocketDescriptor(descriptor);

    connect(client, SIGNAL(disconnected()), this, SLOT(handleDisconnectConnection()));
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
    connect(client, SIGNAL(readyRead()), this, SLOT(handleUserSetupReq()));

    connections_.insert(client->getId(), client);
}

void Server::handleUserSetupReq()
{
    Connection* connection = qobject_cast<Connection*>(sender());

    Message message {receiveMsg(*connection)};

    if(message.getMsgId() == CLIENT_SETUP_REQ)
    {
        qDebug() << "Received CLIENT_SETUP_REQ, nick: " << message.getPayload<QString>();

        disconnect(connection, SIGNAL(readyRead()), this, SLOT(handleUserSetupReq()));
    }
}

