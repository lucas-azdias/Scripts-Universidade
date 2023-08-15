from machine import Pin, PWM
from time import sleep


control1 = Pin(22, Pin.PULL_UP)
control2 = Pin(23, Pin.PULL_UP)

in1 = Pin(32, Pin.PULL_UP)
in2 = Pin(33, Pin.PULL_UP)
in3 = Pin(13, Pin.PULL_UP)
in4 = Pin(14, Pin.PULL_UP)

buzzer = PWM(Pin(4))

def value_output(value, f):
    if value == 1:
        buzzer.freq(f)
        buzzer.duty(512)
    else:
        print("Sem sinal")
        buzzer.duty(0)

while True:
    c1 = control1.value()
    c2 = control2.value()
    if c1 == 0 and c2 == 0:
        value_output(in1.value(), 1000)
    elif c1 == 0 and c2 == 1:
        value_output(in2.value(), 1500)
    elif c1 == 1 and c2 == 0:
        value_output(in3.value(), 2000)
    elif c1 == 1 and c2 == 1:
        value_output(in4.value(), 2500)
    sleep(0.5)
