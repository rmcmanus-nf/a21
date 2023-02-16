# Author:  Jeff B.
# Co-author: Rob M.
# Description:  Accelerometer demo that utilizes BLE to broadcast values for graphing using Adafruit's BlueFruit app.
# History:
#       2022-12-21 RM:  Added UART service for pushing data.
import time
import board
import microcontroller
import adafruit_adxl34x
import digitalio
from analogio import AnalogIn

from adafruit_ble import BLERadio
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.nordic import UARTService

ble = BLERadio()
uart_server = UARTService()
advertisement = ProvideServicesAdvertisement(uart_server)

uart_server.reset_input_buffer()
led_r = digitalio.DigitalInOut(board.LED2_R)
led_r.direction = digitalio.Direction.OUTPUT

led_b = digitalio.DigitalInOut(board.LED2_B)
led_b.direction = digitalio.Direction.OUTPUT

led_g = digitalio.DigitalInOut(board.LED2_G)
led_g.direction = digitalio.Direction.OUTPUT

CS = digitalio.DigitalInOut(microcontroller.pin.P0_05)
CS.direction = digitalio.Direction.OUTPUT

ALT = digitalio.DigitalInOut(microcontroller.pin.P0_27)
ALT.direction = digitalio.Direction.OUTPUT

def red_on():
    led_r.value = 0

def blue_on():
    led_b.value = 0

def green_on():
    led_g.value = 0

# def green1_on():
    # led_g1.value = 0

def led_off():
    led_g.value = 1
    led_r.value = 1
    led_b.value = 1

    
def accel_on():
    #print("Accel On!")
    CS.value = 1
    ALT.value = 1


green_on()
time.sleep(1)
led_off()

taking_off = False
landing = False
in_air = False

# Set timer for testing
# t = 10 # 5 seconds

i2c = board.I2C()  # uses board.SCL and board.SDA

# For ADXL343 @ address 0x1d
accel_on() # Turn on accelerometer
accelerometer = adafruit_adxl34x.ADXL345(i2c, address=0x1d)


while True:
    led_off()
    # g1_off()
    # Bluetooth
    if not ble.connected:
        ble.start_advertising(advertisement)

    while not ble.connected:
        red_on()
        time.sleep(0.8)
        led_off()
        time.sleep(0.8)

    ble.stop_advertising()

    if ble.connected:
        # green_on()
        pass

    while ble.connected: # and t
        time.sleep(0.1)
        
        # Send measurements
        try:
            data = accelerometer.acceleration
            # Print to virtual COM interface
            print("%f %f %f" % data)

            # Send over UART BLE for wireless plotting.
            uart_server.write(str(data[0]) + ',' + str(data[1]) + ',' + str(data[2]) + '\n')

            
        except:
            pass

    print('Disconnected')
