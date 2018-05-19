#include "Connection.hpp"

#include <iostream>

Connection::Connection(qintptr descriptor)
{
    connect(this, SIGNAL(readyRead()), this, SLOT(handleRead()));

    setSocketDescriptor(descriptor);
}

void Connection::handleRead()
{
    std::cout << "Received data" << std::endl;
}
