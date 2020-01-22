#include "MessageBuilder.h"
#include "Message.h"
#include <chrono>

#define MESSAGE_BUILDER_CLASS_NAME "Pulsar\\MessageBuilder"

Php::Value MessageBuilder::setContent(Php::Parameters &params) {
    std::string content = params[0];
    this->builder.setContent(content);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setProperty(Php::Parameters &params) {
    std::string name = params[0];
    std::string value = params[1];
    this->builder.setProperty(name, value);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setPartitionKey(Php::Parameters &params) {
    std::string partitionKey = params[0];
    this->builder.setPartitionKey(partitionKey);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setOrderingKey(Php::Parameters &params) {
    std::string orderingKey = params[0];
    this->builder.setOrderingKey(orderingKey);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setDeliverAfter(Php::Parameters &params) {
    int delay = params[0];
    this->builder.setDeliverAfter(std::chrono::milliseconds(delay));
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setDeliverAt(Php::Parameters &params) {
    int64_t deliveryTimestamp = params[0];
    this->builder.setDeliverAt(deliveryTimestamp);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setEventTimestamp(Php::Parameters &params) {
    int64_t eventTimestamp = params[0];
    this->builder.setDeliverAt(eventTimestamp);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setSequenceId(Php::Parameters &params) {
    int64_t sequenceId = params[0];
    this->builder.setSequenceId(sequenceId);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::disableReplication(Php::Parameters &params) {
    bool flag = params[0];
    this->builder.disableReplication(flag);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::setProperties(Php::Parameters &params) {
    std::map<std::string, std::string> properties;
    for (auto v : params[0].mapValue()) {
        properties[v.first] = v.second.stringValue();
    }
    this->builder.setProperties(properties);
    return Php::Object(MESSAGE_BUILDER_CLASS_NAME, this);
}

Php::Value MessageBuilder::build() {
    auto message = this->builder.build();
    return Php::Object("Pulsar\\Message", new Message(message));
}

void registerMessageBuilder(Php::Namespace &pulsarNamespace) {
    Php::Class<MessageBuilder> builder("MessageBuilder");
    builder.method<&MessageBuilder::setContent>("setContent");
    builder.method<&MessageBuilder::setProperty>("setProperty");
    builder.method<&MessageBuilder::setProperties>("setProperties");
    builder.method<&MessageBuilder::setPartitionKey>("setPartiionKey");
    builder.method<&MessageBuilder::setOrderingKey>("setOrderingKey");
    builder.method<&MessageBuilder::setDeliverAfter>("setDeliverAfter");
    builder.method<&MessageBuilder::setDeliverAt>("setDeliverAt");
    builder.method<&MessageBuilder::setEventTimestamp>("setEventTimestamp");
    builder.method<&MessageBuilder::setSequenceId>("sequenceId");
    builder.method<&MessageBuilder::disableReplication>("disableReplication");
    builder.method<&MessageBuilder::build>("build");
    pulsarNamespace.add(builder);
}
