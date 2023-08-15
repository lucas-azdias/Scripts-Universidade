import time
import network
from umqtt.simple import MQTTClient

# Configuração MQTT
MQTT_CLIENT_ID = "conect demo"
MQTT_BROKER = "broker.mqttdashboard.com"
MQTT_TOPIC_SEND = "exp.criativas/enviar"
MQTT_TOPIC_RECEIVE = "exp.criativas/receber"

# Configuração da rede Wi-Fi
WIFI_SSID = "Link_One_0727F0"
WIFI_PASSWORD = "santiago"

# Função de callback para recebimento de mensagens MQTT
def callback(topic, msg):
    print("Mensagem recebida: ", msg.decode())
    client.publish(MQTT_TOPIC_RECEIVE, "ok")  # Envia "ok" como resposta

# Conexão à rede Wi-Fi
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(WIFI_SSID, WIFI_PASSWORD)
while not wifi.isconnected():
    pass

print("Conectado à rede Wi-Fi:", WIFI_SSID)


# Configuração do cliente MQTT
client = MQTTClient(MQTT_CLIENT_ID, MQTT_BROKER)
client.set_callback(callback)

# Conexão e subscrição aos tópicos MQTT
client.connect()
client.subscribe(MQTT_TOPIC_RECEIVE)

# Publicação da mensagem que será enviada
client.publish(MQTT_TOPIC_SEND, "ahhhhhhhhhh lelek lek lek lek lek")

# Aguarda a resposta do computador cliente por 5 segundos
start_time = time.time()
while time.time() - start_time < 5:
    client.check_msg()
    time.sleep(0.1)
    