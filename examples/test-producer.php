<?php

use Pulsar\Client;
use Pulsar\MessageBuilder;

$client = new Client("pulsar://10.217.0.224:6650");

$producer = $client->createProducer("persistent://prop/r1/ns1/test-topic");

$prop = [
    "a" => 1,
];

$builder = new MessageBuilder();
$builder->setContent("Amazing " . time())
        ->setProperties($prop);

unset($prop);

$message = $builder->setDeliverAfter(5000)->build();
$producer->send($message);
