#pragma once

#include "MessageTypeTraits.hpp"
#include <QString>
#include <QDataStream>

struct ClientSetupReq
{
    QString nick_ {};
};

template<> MessageId MessageTypeTraits<ClientSetupReq>::id_ = CLIENT_SETUP_REQ;

QDataStream& operator<<(QDataStream& stream, const ClientSetupReq& msg)
{
    return stream << msg.nick_;
}

QDataStream& operator>>(QDataStream& stream, ClientSetupReq& msg)
{
    return stream >> msg.nick_;
}



