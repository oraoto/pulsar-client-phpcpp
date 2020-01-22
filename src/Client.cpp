#include "Client.h"
#include "Consumer.h"
#include "ConsumerConfiguration.h"
#include "Producer.h"

void Client::__construct(Php::Parameters &params) {
    std::string serviceUrl = params[0];
    this->client = new ::pulsar::Client(serviceUrl);
}

Php::Value Client::createProducer(Php::Parameters &params) {
    Producer *producer = new Producer();
    this->client->createProducer(params[0], producer->producer);
    return Php::Object("Pulsar\\Producer", producer);
}

Php::Value Client::subscribe(Php::Parameters &params) {
    Consumer *consumer = new Consumer();

    if (params.size() == 2 && params[0].isString() && params[1].isString()) {
        std::string topic = params[0];
        std::string consumerName = params[1];
        this->client->subscribe(topic, consumerName, consumer->consumer);
        return Php::Object("Pulsar\\Consumer", consumer);
    }

    if (params.size() == 3 && params[0].isString() && params[1].isString() &&
        params[2].isObject()) {
        std::string topic = params[0];
        std::string consumerName = params[1];
        auto conf = (ConsumerConfiguration *)(params[2].implementation());
        this->client->subscribe(topic, consumerName, conf->config,
                                consumer->consumer);
        return Php::Object("Pulsar\\Consumer", consumer);
    }

    return Php::Object("Pulsar\\Consumer", consumer);
}

void registerClient(Php::Namespace &pulsarNamespace) {
    Php::Class<Client> client("Client");
    client.method<&Client::__construct>("__construct");
    client.method<&Client::createProducer>("createProducer");
    client.method<&Client::subscribe>("subscribe");
    pulsarNamespace.add(client);
}
