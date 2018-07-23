#pragma once

#include "Message.hpp"

class QTcpSocket;

struct MessageReceiver
{
    static Message receive(QTcpSocket &);
};
