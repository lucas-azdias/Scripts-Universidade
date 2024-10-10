#!/usr/bin/env python3

# Componentes Basico
# PD - PUCPR
# Prof. Luiz Lima Jr.

from pika import BasicProperties, BlockingConnection
from pika.spec import Basic
from pika.adapters.blocking_connection import BlockingChannel
from sys import argv

# Garantees enough args were passed
if len(argv) < 2:
	print(f"ERROR! {argv[0]} <id> [<link1> ...]")
	exit(1)

id = argv[1]
neighbors = argv[2:]

msg_historic = []

print(f"My id: {id}")
print(f"My neighbors: {neighbors}")

# Creates a connection and a channel for communication
conn = BlockingConnection() # Connection
channel = conn.channel() # One channel in a connection

# Declare queue (if already exists, has no effect)
channel.queue_declare(queue=id, auto_delete=True)

# Function to send messages
def send(message:str, destiny:str, channel:BlockingChannel) -> None:
    channel.basic_publish(
        exchange="",
        routing_key=destiny,
        body=message,
        properties=BasicProperties(
            headers={'origin': id}
        )
    )

# Function to receive messages
def receive(message:str, origin:str, channel:BlockingChannel) -> None:
    print(f"Message received: \"{message}\"")

    # Ignores already received messages
    if message in msg_historic:
        print("Message already received")
        return

    # Adds non-received message to historic
    msg_historic.append(message)

    # Has origin (not starter)
    if origin:
        print(f"Message origin: \"{origin}\"")
    else:
        print(f"Message is starter")

    # Send message to all neighbors (excluding origin)
    for neighbor in neighbors:
        if neighbor == origin:
            print("A")
            continue
        send(message, neighbor, channel)

# Function to treat messages callbacks
def callback(channel:BlockingChannel, method:Basic.Deliver, properties:BasicProperties, body:bytes) -> None:
    try:
        origin = properties.headers['origin']
    except Exception:
        origin = None

    receive(body.decode(encoding="utf-8"), origin, channel)

# Basic consuming of the messages in the queue
channel.basic_consume(queue=id, on_message_callback=callback, auto_ack=True)

# Activate the consuming
print("Awaiting messages...")
try:
    channel.start_consuming()
except KeyboardInterrupt:
    channel.stop_consuming()

# Finish the program
conn.close()
