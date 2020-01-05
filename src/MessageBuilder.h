#pragma once

#include <phpcpp.h>
#include <pulsar/MessageBuilder.h>

class MessageBuilder : public Php::Base {
  public:

    pulsar::MessageBuilder builder;

    MessageBuilder() {}

    Php::Value setContent(Php::Parameters &params);

    Php::Value build();
};

void registerMessageBuilder(Php::Namespace &pulsarNamespace);
