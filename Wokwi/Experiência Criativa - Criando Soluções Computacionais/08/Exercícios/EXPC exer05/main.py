from machine import Pin, Signal
from time import sleep


segs = [
    Signal(Pin(22, Pin.OUT), invert=True),    # Segment A
    Signal(Pin(23, Pin.OUT), invert=True),    # Segment B
    Signal(Pin(4, Pin.OUT), invert=True),     # Segment C
    Signal(Pin(5, Pin.OUT), invert=True),     # Segment D
    Signal(Pin(18, Pin.OUT), invert=True),    # Segment E
    Signal(Pin(21, Pin.OUT), invert=True),    # Segment F
    Signal(Pin(19, Pin.OUT), invert=True)     # Segment G
]

digits = [
    (True, True, True, True, True, True, False),         # 0
    (False, True, True, False, False, False, False),     # 1
    (True, True, False, True, True, False, True),        # 2
    (True, True, True, True, False, False, True),        # 3
    (False, True, True, False, False, True, True),       # 4
    (True, False, True, True, False, True, True),        # 5
    (True, False, True, True, True, True, True),         # 6
    (True, True, True, False, False, False, False),      # 7
    (True, True, True, True, True, True, True),          # 8
    (True, True, True, True, False, True, True),         # 9
    (True, True, True, False, True, True, True),         # A
    (False, False, True, True, True, True, True),        # B
    (True, False, False, True, True, True, False),       # C
    (False, True, True, True, True, False, True),        # D
    (True, False, False, True, True, True, True),        # E
    (True, False, False, False, True, True, True),       # F
]


def set_digit(number):
    pattern = digits[number]
    for i in range(len(segs)):
        if pattern[i]:
            segs[i].on()
        else:
            segs[i].off()


while True:
    for i in range(len(digits)):
        set_digit(i)
        sleep(0.5)
    
    for i in range(len(digits)):
        set_digit(len(digits) - i - 1)
        sleep(0.5)
