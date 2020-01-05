#include "MessageBuilder.h"
#include "Message.h"

Php::Value MessageBuilder::setContent(Php::Parameters &params)
{
  std::string content = params[0];
  this->builder.setContent(content);
  return Php::Object("Pulsar\\MessageBuilder", this);
}

Php::Value MessageBuilder::build()
{
  auto message = this->builder.build();
  return Php::Object("Pulsar\\Message", new Message(message));
}

void registerMessageBuilder(Php::Namespace &pulsarNamespace)
{
  Php::Class<MessageBuilder> messageBuilder("MessageBuilder");
  messageBuilder.method<&MessageBuilder::build>("build");
  messageBuilder.method<&MessageBuilder::setContent>("setContent");
  pulsarNamespace.add(messageBuilder);
}
