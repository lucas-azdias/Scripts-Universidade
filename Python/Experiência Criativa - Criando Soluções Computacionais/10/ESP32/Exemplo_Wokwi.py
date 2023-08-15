"""
MicroPython IoT Weather Station Example for Wokwi.com

To view the data:

1. Go to http://www.hivemq.com/demos/websocket-client/
2. Click "Connect"
3. Under Subscriptions, click "Add New Topic Subscription"
4. In the Topic field, type "wokwi-weather" then click "Subscribe"

Now click on the DHT22 sensor in the simulation,
change the temperature/humidity, and you should see
the message appear on the MQTT Broker, in the "Messages" pane.

Copyright (C) 2022, Uri Shaked

https://wokwi.com/arduino/projects/322577683855704658
"""

import network
import time
import dht
import ujson
from umqtt.simple import MQTTClient

# MQTT Server Parameters
MQTT_CLIENT_ID = "conect demo"
MQTT_BROKER    = "broker.mqttdashboard.com"
MQTT_TOPIC_SEND = "exp.criativas/enviar"
MQTT_TOPIC_RECEIVE = "exp.criativas/receber" 
MQTT_USER      = "123456"
MQTT_PASSWORD  = "123456"

#função com a resposta do topico selecionado
def callback(topic, msg):
    print("Mensagem recebida: ", msg.decode())
    client.publish(MQTT_TOPIC_RECEIVE, "Funcionou!!!!!")  

#Parte da comunicação do driver virtual do
print("Connecting to WiFi", end="")
sta_if = network.WLAN(network.STA_IF)
sta_if.active(True)
sta_if.connect('Wokwi-GUEST', '')
while not sta_if.isconnected():
  print(".", end="")
  time.sleep(0.1)
print(" Connected!")

print("Connecting to MQTT server... ", end="")
client = MQTTClient(MQTT_CLIENT_ID, MQTT_BROKER, user=MQTT_USER, password=MQTT_PASSWORD)


#####Criando retorno de informação
client.set_callback(callback)

####Conectando no cliente
client.connect()
print("Connected!")
#Fazendo inscrição no tópico "mensagens" para receber mensagens
client.subscribe(MQTT_TOPIC_RECEIVE)
# Publicação da mensagem que será enviada
client.publish(MQTT_TOPIC_SEND, "É tudo toissss")

while True:
  client.check_msg();