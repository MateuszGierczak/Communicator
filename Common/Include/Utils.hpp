#pragma once

#include "Message.hpp"

struct QTcpSocket;

void sendMsg(QTcpSocket&, const Message&);
Message receiveMsg(QTcpSocket&);
