#include "MessageId.h"
#include <string>

#define MESSAGE_ID_CLASS_NAME "Pulsar\\MessageId"

MessageId::MessageId(pulsar::MessageId messageId) { this->messageId = messageId; }

static Php::Value earliest()
{
    auto messageId = new MessageId(pulsar::MessageId::earliest());
    return Php::Object(MESSAGE_ID_CLASS_NAME, messageId);
}

static Php::Value latest()
{
    auto messageId = new MessageId(pulsar::MessageId::latest());
    return Php::Object(MESSAGE_ID_CLASS_NAME, messageId);
}

Php::Value MessageId::getTopicName()
{
    return this->messageId.getTopicName();
}

void MessageId::setTopicName(Php::Parameters &params)
{
    return this->messageId.setTopicName(params[0]);
}

Php::Value MessageId::deserialize(Php::Parameters &params)
{
    auto messageId = new MessageId(pulsar::MessageId::deserialize(params[0]));
    return Php::Object(MESSAGE_ID_CLASS_NAME, messageId);
}

Php::Value MessageId::serialize(Php::Parameters &params)
{
    std::string *result = new std::string();
    this->messageId.serialize(*result);
    return result;
}

void registerMessageId(Php::Namespace &pulsarNamespace)
{
    Php::Class<MessageId> messageId("MessageId");
    messageId.method<&MessageId::earliest>("earliest");
    messageId.method<&MessageId::latest>("latest");
    messageId.method<&MessageId::getTopicName>("getTopicName");
    messageId.method<&MessageId::serialize>("serialize");
    messageId.method<&MessageId::deserialize>("deserialize");
}
