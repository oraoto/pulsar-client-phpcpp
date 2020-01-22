#pragma once

#include <pulsar/MessageId.h>
#include <phpcpp.h>

class MessageId : public Php::Base {
  public:
    pulsar::MessageId messageId;

    MessageId(pulsar::MessageId msgId);

    static Php::Value earliest(Php::Parameters &params);
    static Php::Value latest(Php::Parameters &params);

    Php::Value getTopicName();
    void setTopicName(Php::Parameters &params);

    Php::Value serialize(Php::Parameters &params);
    static Php::Value deserialize(Php::Parameters &params);
};

void registerMessageId(Php::Namespace &pulsarNamespace);
