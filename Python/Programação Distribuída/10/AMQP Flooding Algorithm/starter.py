#!/usr/bin/env python3

# AMQP Basico - starter
# SDC - PUCPR
# Prof. Luiz Lima Jr.
#
# o "starter" envia uma mensagem "externa"
# a um ou mais componentes do sistema
# que passam entao a assumir o papel de
# iniciadores

from pika import BlockingConnection
from pika.adapters.blocking_connection import BlockingChannel
from sys import argv

# Garantees enough args were passed
if len(argv) < 3:
	print(f"ERROR! {argv[0]} <message> <dest1> [<dest2] ...")
	exit(1)

message = argv[1]
dests = argv[2:]

# Creates a connection and a channel for communication
conn = BlockingConnection() # Connection
channel = conn.channel() # One channel in a connection

# Function to send messages
def send(message:str, destiny:str, channel:BlockingChannel) -> None:
    channel.basic_publish(
        exchange="",
        routing_key=destiny,
        body=message
    )

# Publish a message to every destiny
for dest in dests:
	channel.queue_declare(queue=dest, auto_delete=True)
	send(message, dest, channel)
	print(f'Message "{message}" sent to {dest}')

# Finish the program
conn.close()
