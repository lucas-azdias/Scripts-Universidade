from machine import Pin


switch1 = Pin(12, Pin.PULL_UP)
switch2 = Pin(13, Pin.PULL_UP)
led = Pin(2, Pin.OUT)

while True:
    state1 = switch1.value()
    state2 = switch2.value()
    if (state1 == 1 and state2 == 1):
        led.on()
    else:
        led.off()
