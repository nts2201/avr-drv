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

/* avr/../io_pin/iousb162_pin.h - definitions for AT90USB162 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iousb162_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_AT90USB162_H_
#define _AVR_PIN_AT90USB162_H_ 1


/* Device Pin Definitions */
#define PCINT11_DDR   DDRC
#define PCINT11_PORT  PORTC
#define PCINT11_PIN   PINC
#define PCINT11_BIT   2

#define OC0B_DDR   DDRD
#define OC0B_PORT  PORTD
#define OC0B_PIN   PIND
#define OC0B_BIT   0

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   0

#define AIN0_DDR   DDRD
#define AIN0_PORT  PORTD
#define AIN0_PIN   PIND
#define AIN0_BIT   1

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   1

#define RXD1_DDR   DDRD
#define RXD1_PORT  PORTD
#define RXD1_PIN   PIND
#define RXD1_BIT   2

#define AIN1_DDR   DDRD
#define AIN1_PORT  PORTD
#define AIN1_PIN   PIND
#define AIN1_BIT   2

#define INT2_DDR   DDRD
#define INT2_PORT  PORTD
#define INT2_PIN   PIND
#define INT2_BIT   2

#define TXD1_DDR   DDRD
#define TXD1_PORT  PORTD
#define TXD1_PIN   PIND
#define TXD1_BIT   3

#define INT3_DDR   DDRD
#define INT3_PORT  PORTD
#define INT3_PIN   PIND
#define INT3_BIT   3

#define INT5_DDR   DDRD
#define INT5_PORT  PORTD
#define INT5_PIN   PIND
#define INT5_BIT   4

#define XCK1_DDR   DDRD
#define XCK1_PORT  PORTD
#define XCK1_PIN   PIND
#define XCK1_BIT   5

#define PCINT12_DDR   DDRD
#define PCINT12_PORT  PORTD
#define PCINT12_PIN   PIND
#define PCINT12_BIT   5

#define RTS_DDR   DDRD
#define RTS_PORT  PORTD
#define RTS_PIN   PIND
#define RTS_BIT   6

#define INT6_DDR   DDRD
#define INT6_PORT  PORTD
#define INT6_PIN   PIND
#define INT6_BIT   6

#define CTS_DDR   DDRD
#define CTS_PORT  PORTD
#define CTS_PIN   PIND
#define CTS_BIT   7

#define T0_DDR   DDRD
#define T0_PORT  PORTD
#define T0_PIN   PIND
#define T0_BIT   7

#define INT7_DDR   DDRD
#define INT7_PORT  PORTD
#define INT7_PIN   PIND
#define INT7_BIT   7

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define SCLK_DDR   DDRB
#define SCLK_PORT  PORTB
#define SCLK_PIN   PINB
#define SCLK_BIT   1

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   1

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   2

#define PCINT2_DDR   DDRB
#define PCINT2_PORT  PORTB
#define PCINT2_PIN   PINB
#define PCINT2_BIT   2

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   3

#define PCINT3_DDR   DDRB
#define PCINT3_PORT  PORTB
#define PCINT3_PIN   PINB
#define PCINT3_BIT   3

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define PCINT6_DDR   DDRB
#define PCINT6_PORT  PORTB
#define PCINT6_PIN   PINB
#define PCINT6_BIT   6

#define PCINT7_DDR   DDRB
#define PCINT7_PORT  PORTB
#define PCINT7_PIN   PINB
#define PCINT7_BIT   7

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   7

#define OC1C_DDR   DDRB
#define OC1C_PORT  PORTB
#define OC1C_PIN   PINB
#define OC1C_BIT   7

#define INT4_DDR   DDRC
#define INT4_PORT  PORTC
#define INT4_PIN   PINC
#define INT4_BIT   7

#define ICP1_DDR   DDRC
#define ICP1_PORT  PORTC
#define ICP1_PIN   PINC
#define ICP1_BIT   7

#define OC1A_DDR   DDRC
#define OC1A_PORT  PORTC
#define OC1A_PIN   PINC
#define OC1A_BIT   6

#define PCINT8_DDR   DDRC
#define PCINT8_PORT  PORTC
#define PCINT8_PIN   PINC
#define PCINT8_BIT   6

#define PCINT9_DDR   DDRC
#define PCINT9_PORT  PORTC
#define PCINT9_PIN   PINC
#define PCINT9_BIT   5

#define OC1B_DDR   DDRC
#define OC1B_PORT  PORTC
#define OC1B_PIN   PINC
#define OC1B_BIT   5

#define PCINT10_DDR   DDRC
#define PCINT10_PORT  PORTC
#define PCINT10_PIN   PINC
#define PCINT10_BIT   4

#endif /* _AVR_PIN_AT90USB162_H_ */

