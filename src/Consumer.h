#pragma once

#include <phpcpp.h>
#include <pulsar/Consumer.h>
#include <pulsar/ConsumerType.h>

class Consumer : public Php::Base {

  public:
    pulsar::Consumer consumer;

    Consumer() {}

    Php::Value receive(Php::Parameters &params);

    void acknowledge(Php::Parameters &params);
};

void registerConsumer(Php::Namespace &pulsarNamespace);
