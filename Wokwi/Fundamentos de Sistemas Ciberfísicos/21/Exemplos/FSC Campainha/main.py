from machine import Pin


# leds as outputs
led_on = Pin(2, Pin.OUT)
led_off = Pin(15, Pin.OUT)

# button as input (pull_down defines the pull_down resistor on (default as low))
# Obs.: with pull_up, the pull_up resistor on (default as high)
button = Pin(4, Pin.IN, Pin.PULL_DOWN)

while True:
    if button.value() == 1:
        led_on.on()
        led_off.off()
    else:
        led_on.off()
        led_off.on()
        
    print("Status:", button.value())
