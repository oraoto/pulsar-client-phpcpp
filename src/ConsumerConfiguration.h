#pragma once

#include <phpcpp.h>
#include <pulsar/ConsumerConfiguration.h>

class ConsumerConfiguration : public Php::Base {

  public:
    pulsar::ConsumerConfiguration config;

    ConsumerConfiguration(){};

    Php::Value setConsumerType(Php::Parameters &params);
};

void registerConsumerConfiguration(Php::Namespace &pulsarNamespace);
