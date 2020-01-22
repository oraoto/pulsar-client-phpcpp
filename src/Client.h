#pragma once

#include <phpcpp.h>
#include <pulsar/Client.h>

class Client : public Php::Base {

  public:
    pulsar::Client *client;

    ~Client() {}

    void __construct(Php::Parameters &params);

    Php::Value createProducer(Php::Parameters &params);

    Php::Value subscribe(Php::Parameters &params);

    // Php::Value createReader(Php::Parameters &params);

    // Php::Value getPartitionsForTopic(Php::Parameters &params);

    // void close();

    // void shutdown();
};

void registerClient(Php::Namespace &pulsarNamespace);
