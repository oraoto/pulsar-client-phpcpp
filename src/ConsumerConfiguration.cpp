#include "ConsumerConfiguration.h"
#include "Message.h"
#include <pulsar/ConsumerType.h>

#define CONSUMER_CONFIGURATION_CLASS_NAME "Pulsar\\ConsumerConfiguration"

Php::Value ConsumerConfiguration::setConsumerType(Php::Parameters &params) {
    auto consumerType = pulsar::ConsumerType((params[0].numericValue()));
    this->config.setConsumerType(consumerType);
    return Php::Object(CONSUMER_CONFIGURATION_CLASS_NAME, this);
}

void registerConsumerConfiguration(Php::Namespace &pulsarNamespace) {
    Php::Class<ConsumerConfiguration> consumerConfiguration(
        "ConsumerConfiguration");
    consumerConfiguration.method<&ConsumerConfiguration::setConsumerType>(
        "setConsumerType");
    pulsarNamespace.add(consumerConfiguration);
}
