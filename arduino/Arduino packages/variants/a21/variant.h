 /*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_A21_
#define _VARIANT_A21_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

#define USE_LFXO      // Board uses 32khz crystal for LF
// define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (48)
#define NUM_DIGITAL_PINS     (48)
#define NUM_ANALOG_INPUTS    (6)
#define NUM_ANALOG_OUTPUTS   (0)

// LEDs
#define PIN_LED_G             (6)
#define PIN_LED_RGB_RED       (8)
#define PIN_LED_RGB_GREEN     (41)
#define PIN_LED_RGB_BLUE      (12)

#define LED_BUILTIN          PIN_LED_G
#define LED_CONN             PIN_LED_RGB_GREEN

#define LED_RED              PIN_LED_RGB_RED
#define LED_GREEN            PIN_LED_RGB_GREEN
#define LED_BLUE             PIN_LED_RGB_BLUE

#define LED_STATE_ON         0         // State when LED is litted

/*
 * Buttons
 */
// #define PIN_BUTTON_SW1          38  // Button
// #define PIN_BUTTON_SW2          18  // Reset pin


/*
 * Analog pins
 */
#define PIN_A0               (31)  // EGPIO1
#define PIN_A1               (30)  // EGPIO2
#define PIN_A2               (29)  // EGPIO3
#define PIN_A3               (28)  // EGPIO4
#define PIN_A4               (2)   // EGPIO5
#define PIN_A5               (3)   // EGPIO6
#define PIN_A6               (0xff)
#define PIN_A7               (0xff)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
static const uint8_t A3  = PIN_A3 ;
static const uint8_t A4  = PIN_A4 ;
static const uint8_t A5  = PIN_A5 ;
static const uint8_t A6  = PIN_A6 ;
static const uint8_t A7  = PIN_A7 ;
#define ADC_RESOLUTION    14

// Other pins
// #define PIN_AREF           (2)
// #define PIN_NFC1           (9)
// #define PIN_NFC2           (10)

// static const uint8_t AREF = PIN_AREF;

/*
 * Serial interfaces
 */

// Arduino Header D0, D1
#define PIN_SERIAL1_RX      (15) // P0.15 BGP1
#define PIN_SERIAL1_TX      (22) // P0.22 BGP2

// Connected to Jlink CDC
#define PIN_SERIAL2_RX      (8) 
#define PIN_SERIAL2_TX      (6)

/*
 * SPI Interfaces
 */
// #define SPI_INTERFACES_COUNT 1

// #define PIN_SPI_MISO         (46)
// #define PIN_SPI_MOSI         (45)
// #define PIN_SPI_SCK          (47)

// static const uint8_t SS   = 44 ;
// static const uint8_t MOSI = PIN_SPI_MOSI ;
// static const uint8_t MISO = PIN_SPI_MISO ;
// static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
// #define WIRE_INTERFACES_COUNT 1

// #define PIN_WIRE_SDA         (26)
// #define PIN_WIRE_SCL         (27)

// QSPI Pins
// #define PIN_QSPI_SCK         19
// #define PIN_QSPI_CS          17
// #define PIN_QSPI_IO0         20
// #define PIN_QSPI_IO1         21
// #define PIN_QSPI_IO2         22
// #define PIN_QSPI_IO3         23

// On-board QSPI Flash
// #define EXTERNAL_FLASH_DEVICES   MX25R6435F
// #define EXTERNAL_FLASH_USE_QSPI

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
