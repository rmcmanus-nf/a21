# Overview

# Hardware Overview
TBD


# Demo
Once the A21 board has been properly setup, simply plugging the device into a USB port will provide the user a virtualized file system.  A file called ```code.py``` can be modified and used to run the users program.  A seperate terminal can be setup using any serial program (e.g. Putty, Teraterm) on the proper COM port.  This is useful to see the program execution via print statements, and also provides debug information in the event of any errors.

There are a variety of demonstrations located in the [examples](./examples) folder.

As a direct example, to simply cycle through the RGB LEDs, use the code provided below. <br>

```
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
```

# Additional CircuitPython Libraries

Accelerometer
We can utilize a library for ADXL134X driver communication.<br>
https://learn.adafruit.com/adxl345-digital-accelerometer/python-and-circuitpython


# Board Setup
If the board has not been flashed, or needs to be set back up with CircuitPython, the bootloader and application firmware will need to be reloaded.

Easiest way to get going is to flash the FULL HEX image.

If you'd like the ability to load UF2 images, you can flash the bootloader first, then you'll see a USB drive you can copy and paste one of the UF2 images in the releases folder.

## Releases (Files)
```a21_v1.3_full_image.hex``` - Complete CircuitPython image, ready to go.<br>

## Bootloader Software
For this section, make sure you are connected to the J2 port.

For fashing the initial bootloader image, you'll need to use Segger's J-Flash and Commander software.  This is packaged by Segger's Documentation and Software Pack.  This can be obtained for Windows, here:
https://www.segger.com/downloads/jlink/JLink_Windows.exe

You'll want to disable the MSD Support for now as described in the following document (see section Disable Mass Storage on PCA10056 J-Link):
https://learn.adafruit.com/circuitpython-on-the-nrf52/nrf52840-bootloader



## Uploading firmware

1.  Download and install J-Link software and documentation pack from the segger website.
2.  Connect your nRF52840 microcontroller to your computer using a J-Link programmer.
4.  Open J-Flash, and use the ```nrf52840.jflash``` project file. (Is this true for programming A21?)
2.  Connect by using the menu bar and select Target->Connect.
3.  Open the bootloader hex image ```a21_v1.3_full_image.hex```
4.  Select Target->Manual Programming->Erase Chip to erase target.
5.  Select Target->Manual Programming->Program to progarm starget.
6.  Select Target->Manual Programming->Start Application to start program in target.
7.  After the programming process is complete, press the "Verify" button to verify that the .hex file has been correctly programmed into the nRF52840 microcontroller.
8.  Once the verification process is complete, disconnect the J-Link and power off the target device.

You should be ready to start developing in circuitpython.

