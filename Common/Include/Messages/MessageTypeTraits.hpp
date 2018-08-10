#pragma once

#include "MessagesIds.hpp"

template<typename MessageType>
struct MessageTypeTraits
{
    static MessageId id_;
};

template<typename MessageType>
MessageId MessageTypeTraits<MessageType>::id_ = INVALID_MESSAGE_ID;
