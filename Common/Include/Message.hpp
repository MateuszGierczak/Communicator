#pragma once

#include <QtGlobal>
#include <QDataStream>

struct Message
{
    Message() = default;

    template<typename PayloadType>
    Message(quint8 msgId, const PayloadType& data) : msgId_(msgId)
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

    quint8 msgId_ {};
    QByteArray payload_ {};
};

QDataStream& operator<<(QDataStream& stream, const Message& message)
{
    return stream << message.msgId_ << message.payload_;
}

QDataStream& operator>>(QDataStream& stream, Message& message)
{
    return stream >> message.msgId_ >> message.payload_;
}
