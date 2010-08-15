/* Copyright (c) 2010 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

/* avr/../io_pin/iom168a_pin.h - definitions for ATmega168A */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom168a_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA168A_H_
#define _AVR_PIN_ATMEGA168A_H_ 1


/* Device Pin Definitions */
#define PCINT19_DDR   DDRD
#define PCINT19_PORT  PORTD
#define PCINT19_PIN   PIND
#define PCINT19_BIT   3

#define OC2B_DDR   DDRD
#define OC2B_PORT  PORTD
#define OC2B_PIN   PIND
#define OC2B_BIT   3

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   3

#define XCK_DDR   DDRD
#define XCK_PORT  PORTD
#define XCK_PIN   PIND
#define XCK_BIT   4

#define T0_DDR   DDRD
#define T0_PORT  PORTD
#define T0_PIN   PIND
#define T0_BIT   4

#define PCINT20_DDR   DDRD
#define PCINT20_PORT  PORTD
#define PCINT20_PIN   PIND
#define PCINT20_BIT   4

#define PCINT6_DDR   DDRB
#define PCINT6_PORT  PORTB
#define PCINT6_PIN   PINB
#define PCINT6_BIT   6

#define PCINT7_DDR   DDRB
#define PCINT7_PORT  PORTB
#define PCINT7_PIN   PINB
#define PCINT7_BIT   7

#define OC0B_DDR   DDRD
#define OC0B_PORT  PORTD
#define OC0B_PIN   PIND
#define OC0B_BIT   5

#define PCINT21_DDR   DDRD
#define PCINT21_PORT  PORTD
#define PCINT21_PIN   PIND
#define PCINT21_BIT   5

#define AIN0_DDR   DDRD
#define AIN0_PORT  PORTD
#define AIN0_PIN   PIND
#define AIN0_BIT   6

#define OC0A_DDR   DDRD
#define OC0A_PORT  PORTD
#define OC0A_PIN   PIND
#define OC0A_BIT   6

#define PCINT22_DDR   DDRD
#define PCINT22_PORT  PORTD
#define PCINT22_PIN   PIND
#define PCINT22_BIT   6

#define AIN1_DDR   DDRD
#define AIN1_PORT  PORTD
#define AIN1_PIN   PIND
#define AIN1_BIT   7

#define PCINT23_DDR   DDRD
#define PCINT23_PORT  PORTD
#define PCINT23_PIN   PIND
#define PCINT23_BIT   7

#define ICP1_DDR   DDRB
#define ICP1_PORT  PORTB
#define ICP1_PIN   PINB
#define ICP1_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   1

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   1

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   2

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   2

#define PCINT2_DDR   DDRB
#define PCINT2_PORT  PORTB
#define PCINT2_PIN   PINB
#define PCINT2_BIT   2

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   3

#define OC2A_DDR   DDRB
#define OC2A_PORT  PORTB
#define OC2A_PIN   PINB
#define OC2A_BIT   3

#define PCINT3_DDR   DDRB
#define PCINT3_PORT  PORTB
#define PCINT3_PIN   PINB
#define PCINT3_BIT   3

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   4

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   5

#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define ADC0_DDR   DDRC
#define ADC0_PORT  PORTC
#define ADC0_PIN   PINC
#define ADC0_BIT   0

#define PCINT8_DDR   DDRC
#define PCINT8_PORT  PORTC
#define PCINT8_PIN   PINC
#define PCINT8_BIT   0

#define ADC1_DDR   DDRC
#define ADC1_PORT  PORTC
#define ADC1_PIN   PINC
#define ADC1_BIT   1

#define PCINT9_DDR   DDRC
#define PCINT9_PORT  PORTC
#define PCINT9_PIN   PINC
#define PCINT9_BIT   1

#define ADC2_DDR   DDRC
#define ADC2_PORT  PORTC
#define ADC2_PIN   PINC
#define ADC2_BIT   2

#define PCINT10_DDR   DDRC
#define PCINT10_PORT  PORTC
#define PCINT10_PIN   PINC
#define PCINT10_BIT   2

#define ADC3_DDR   DDRC
#define ADC3_PORT  PORTC
#define ADC3_PIN   PINC
#define ADC3_BIT   3

#define PCINT11_DDR   DDRC
#define PCINT11_PORT  PORTC
#define PCINT11_PIN   PINC
#define PCINT11_BIT   3

#define ADC4_DDR   DDRC
#define ADC4_PORT  PORTC
#define ADC4_PIN   PINC
#define ADC4_BIT   4

#define SDA_DDR   DDRC
#define SDA_PORT  PORTC
#define SDA_PIN   PINC
#define SDA_BIT   4

#define PCINT12_DDR   DDRC
#define PCINT12_PORT  PORTC
#define PCINT12_PIN   PINC
#define PCINT12_BIT   4

#define ADC5_DDR   DDRC
#define ADC5_PORT  PORTC
#define ADC5_PIN   PINC
#define ADC5_BIT   5

#define SCL_DDR   DDRC
#define SCL_PORT  PORTC
#define SCL_PIN   PINC
#define SCL_BIT   5

#define PCINT13_DDR   DDRC
#define PCINT13_PORT  PORTC
#define PCINT13_PIN   PINC
#define PCINT13_BIT   5

#define PCINT14_DDR   DDRC
#define PCINT14_PORT  PORTC
#define PCINT14_PIN   PINC
#define PCINT14_BIT   6

#define RXD_DDR   DDRD
#define RXD_PORT  PORTD
#define RXD_PIN   PIND
#define RXD_BIT   0

#define PCINT16_DDR   DDRD
#define PCINT16_PORT  PORTD
#define PCINT16_PIN   PIND
#define PCINT16_BIT   0

#define TXD_DDR   DDRD
#define TXD_PORT  PORTD
#define TXD_PIN   PIND
#define TXD_BIT   1

#define PCINT17_DDR   DDRD
#define PCINT17_PORT  PORTD
#define PCINT17_PIN   PIND
#define PCINT17_BIT   1

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   2

#define PCINT18_DDR   DDRD
#define PCINT18_PORT  PORTD
#define PCINT18_PIN   PIND
#define PCINT18_BIT   2

#endif /* _AVR_PIN_ATMEGA168A_H_ */

