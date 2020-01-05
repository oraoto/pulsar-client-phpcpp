#include <phpcpp.h>
#include "Message.h"
#include "MessageBuilder.h"
#include "Producer.h"
#include "Consumer.h"
#include "Client.h"

extern "C"
{
  PHPCPP_EXPORT void *get_module()
  {
    static Php::Extension extension("pulsar-phpcpp", "0.1");

    Php::Namespace pulsarNamespace("Pulsar");

    registerMessage(pulsarNamespace);
    registerMessageBuilder(pulsarNamespace);
    registerProducer(pulsarNamespace);
    registerConsumer(pulsarNamespace);
    registerClient(pulsarNamespace);

    extension.add(pulsarNamespace);

    return extension;
  }
}
