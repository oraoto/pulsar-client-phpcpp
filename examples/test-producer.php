<?php

use Pulsar\Client;
use Pulsar\MessageBuilder;

$client = new Client("pulsar://127.0.0.1:6650");

$producer = $client->createProducer("persistent://prop/r1/ns1/test-topic");

$builder = new MessageBuilder();
$builder->setContent("Amazing " . time());
$message = $builder->build();
$producer->send($message);
