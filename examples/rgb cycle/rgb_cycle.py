# Author:  Rob M.
# Description:  Simple RGB cycle demo
#
import time
import board
import digitalio

print("Hello World!")

led_r = digitalio.DigitalInOut(board.LED2_R)
led_r.direction = digitalio.Direction.OUTPUT

led_g = digitalio.DigitalInOut(board.LED2_G)
led_g.direction = digitalio.Direction.OUTPUT

led_b = digitalio.DigitalInOut(board.LED2_B)
led_b.direction = digitalio.Direction.OUTPUT

print("Hello World!")

def red_on():
    print('Red On!')
    led_r.value = 0
    led_g.value = 1
    led_b.value = 1

def green_on():
    print('Green On!')
    led_r.value = 1
    led_g.value = 0
    led_b.value = 1

def blue_on():
    print('Blue On!')
    led_r.value = 1
    led_g.value = 1
    led_b.value = 0

for i in range(1,10):

    red_on()
    time.sleep(1)
    blue_on()
    time.sleep(1)
    green_on()
    time.sleep(1)
