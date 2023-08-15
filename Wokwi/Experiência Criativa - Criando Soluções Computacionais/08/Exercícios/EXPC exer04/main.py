from machine import Pin, Signal, PWM
from dht import DHT22
from time import sleep


dht_sensor = DHT22(Pin(15))
button = Pin(13, Pin.IN, Pin.PULL_DOWN)

led = Pin(26, Pin.OUT)
buzzer = PWM(Pin(27))


while True:
    # Measure data
    dht_sensor.measure()

    # Saves data
    temperature = dht_sensor.temperature()
    humidity = dht_sensor.humidity()

    # Prensents data if button is pressed
    if button.value() == 1:
        print("Temperatura: " + str(temperature) + "ºC")
        print("Umidade: " + str(humidity) + "%")
    
    # Gives temperature alert if necessary:
    if temperature > 70:
        print("DANGER! HIGH TEMPERATURE DETECTED!")
        buzzer.freq(1000)
        buzzer.duty(512)
        led.on()
        sleep(0.2)
        led.off()
    else:
        buzzer.duty(0)
    
    # Gives humidity alert if necessary:
    if humidity > 85:
        print("DANGER! HIGH HUMIDITY DETECTED!")
