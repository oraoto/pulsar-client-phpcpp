<?php

use Pulsar\Client;
use Pulsar\MessageBuilder;

$client = new Client("pulsar://127.0.0.1:6650");

$consumer = $client->subscribe("persistent://prop/r1/ns1/test-topic", "consumer-1");

while (true) {
    $message = $consumer->receive();
    var_dump($message->getDataAsString());
    $consumer->acknowledge($message);
}
