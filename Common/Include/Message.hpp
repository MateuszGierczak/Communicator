#pragma once

#include "MessageTypeTraits.hpp"

#include <QtGlobal>
#include <QDataStream>

struct Message
{
    Message() = default;

    template<typename PayloadType>
    Message(const PayloadType& data)
        : msgId_(MessageTypeTraits<PayloadType>::id_)
    {
        QDataStream stream {&payload_, QIODevice::WriteOnly};
        stream << data;
    }

    template<typename PayloadType>
    PayloadType getPayload()
    {
        PayloadType payload {};
        QDataStream stream {&payload_, QIODevice::ReadOnly};
        stream >> payload;

        return payload;
    }

    quint8 getMsgId() const { return msgId_; }

    friend inline QDataStream& operator<<(QDataStream&, const Message&);
    friend inline QDataStream& operator>>(QDataStream&, Message&);

private:
    quint8 msgId_ {};
    QByteArray payload_ {};
};

inline QDataStream& operator<<(QDataStream& stream, const Message& message)
{
    return stream << message.msgId_ << message.payload_;
}

inline QDataStream& operator>>(QDataStream& stream, Message& message)
{
    return stream >> message.msgId_ >> message.payload_;
}
