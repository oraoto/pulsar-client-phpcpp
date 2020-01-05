#pragma once

#include <phpcpp.h>
#include <pulsar/Producer.h>

class Producer : public Php::Base {

  public:
    pulsar::Producer producer;

    Producer() {}

    void send(Php::Parameters &params);
};

void registerProducer(Php::Namespace &pulsarNamespace);
