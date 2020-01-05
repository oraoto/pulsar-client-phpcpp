#include "Consumer.h"
#include "Message.h"

Php::Value Consumer::receive(Php::Parameters &params) {
  Message *message = new Message();
  this->consumer.receive(message->message);
  return Php::Object("Pulsar\\Message", message);
}

void Consumer::acknowledge(Php::Parameters &params) {
  auto message = (Message *)(params[0].implementation());
  this->consumer.acknowledge(message->message);
}

void registerConsumer(Php::Namespace &pulsarNamespace)
{
    Php::Class<Consumer> consumer("Consumer");
    consumer.method<&Consumer::receive>("receive");
    consumer.method<&Consumer::acknowledge>("acknowledge");
    pulsarNamespace.add(consumer);
}
