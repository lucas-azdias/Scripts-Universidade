from machine import Pin, PWM
# PWM -> Pulse Width Modulation (allows for controlling signal with frequency)
from time import sleep

# Obs.: VIN -> 5V | 3V3 -> 3.3V

# PWM -> set for this Pin with this frequency (50 is default for servo)
servo = PWM(Pin(15, Pin.OUT), freq=50)

def angle_on_servo(angle:float) -> int:
    return int(angle * (123 - 24) / 180 + 24)
    # 0 degrees -> default is 24
    # 180 degrees -> default is 123

button = Pin(4, Pin.IN, Pin.PULL_DOWN)
led = Pin(2, Pin.OUT)

servo.duty(angle_on_servo(0)) 
sleep(1.5)
led.on()
while True:
    angle = float(input("Rotation angle: "))
    print("Waiting button pressed to apply...")
    while True:
        if button.value() == 1:
            led.off()
            servo.duty(angle_on_servo(angle))
            sleep(1.5)
            print()
            break
    led.on()
