#pragma once

#include <phpcpp.h>
#include <pulsar/MessageBuilder.h>

class MessageBuilder : public Php::Base {
  public:
    pulsar::MessageBuilder builder;

    MessageBuilder() {}

    Php::Value setContent(Php::Parameters &params);

    Php::Value build();

    Php::Value setProperty(Php::Parameters &params);

    Php::Value setPartitionKey(Php::Parameters &params);

    Php::Value setOrderingKey(Php::Parameters &params);
    Php::Value setDeliverAfter(Php::Parameters &params);
    Php::Value setDeliverAt(Php::Parameters &params);
    Php::Value setEventTimestamp(Php::Parameters &params);
    Php::Value setSequenceId(Php::Parameters &params);

    Php::Value disableReplication(Php::Parameters &params);

    Php::Value setProperties(Php::Parameters &params);
    // TODO
    // Php::Value setReplicationClusters(Php::Parameters &params);
    // Php::Value create();
};

void registerMessageBuilder(Php::Namespace &pulsarNamespace);
