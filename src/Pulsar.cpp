#include "Client.h"
#include "Consumer.h"
#include "ConsumerConfiguration.h"
#include "Message.h"
#include "MessageBuilder.h"
#include "Producer.h"
#include <phpcpp.h>

extern "C" {
PHPCPP_EXPORT void *get_module() {
    static Php::Extension extension("pulsar-phpcpp", "0.1");

    Php::Namespace pulsarNamespace("Pulsar");

    registerMessage(pulsarNamespace);
    registerMessageBuilder(pulsarNamespace);
    registerProducer(pulsarNamespace);
    registerConsumer(pulsarNamespace);
    registerClient(pulsarNamespace);
    registerConsumerConfiguration(pulsarNamespace);

    extension.add(pulsarNamespace);

    return extension;
}
}
