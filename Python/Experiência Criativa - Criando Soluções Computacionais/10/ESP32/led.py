from machine import Pin
import time

led = Pin(2, Pin.OUT)  # Pino GPIO 2 é o LED embutido na placa ESP32

while True:
    led.on()  # Acende o LED
    time.sleep(1)  # Aguarda 1 segundo
    led.off()  # Apaga o LED
    time.sleep(1)  # Aguarda 1 segundo
