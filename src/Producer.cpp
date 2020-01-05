#include "Producer.h"
#include "Message.h"

void Producer::send(Php::Parameters &params) {
  auto message = (Message *)(params[0].implementation());
  this->producer.send(message->message);
}

void registerProducer(Php::Namespace &pulsarNamespace)
{
    Php::Class<Producer> producer("Producer");
    producer.method<&Producer::send>("send");
    pulsarNamespace.add(producer);
}
