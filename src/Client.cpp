#include "Client.h"
#include "Producer.h"
#include "Consumer.h"

void Client::__construct(Php::Parameters &params)
{
    std::string serviceUrl = params[0];
    this->client = new ::pulsar::Client(serviceUrl);
}

Php::Value Client::createProducer(Php::Parameters &params)
{
    Producer *producer = new Producer();
    this->client->createProducer(params[0], producer->producer);
    return Php::Object("Pulsar\\Producer", producer);
}

Php::Value Client::subscribe(Php::Parameters &params)
{
    Consumer *consumer = new Consumer();
    this->client->subscribe(params[0].stringValue(), params[1].stringValue(), consumer->consumer);
    return Php::Object("Pulsar\\Consumer", consumer);
}

void registerClient(Php::Namespace &pulsarNamespace)
{
    Php::Class<Client> client("Client");
    client.method<&Client::__construct>("__construct");
    client.method<&Client::createProducer>("createProducer");
    client.method<&Client::subscribe>("subscribe");
    pulsarNamespace.add(client);
}
