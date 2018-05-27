#include "Connection.hpp"

#include <iostream>

unsigned int Connection::nextId_ {1};

Connection::Connection()
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

void Connection::handleRead()
{
    std::cout << "Received data" << std::endl;
}
