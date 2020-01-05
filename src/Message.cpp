#include "Message.h"

Message::Message(pulsar::Message msg) {
  this->message = msg;
}

Php::Value Message::getDataAsString()
{
  return this->message.getDataAsString();
}

void registerMessage(Php::Namespace &pulsarNamespace)
{
  Php::Class<Message> message("Message");
  message.method<&Message::getDataAsString>("getDataAsString");
  pulsarNamespace.add(message);
}
