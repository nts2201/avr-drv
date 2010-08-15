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

/* avr/../io_pin/iom16u4_pin.h - definitions for ATmega16U4 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom16u4_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA16U4_H_
#define _AVR_PIN_ATMEGA16U4_H_ 1


/* Device Pin Definitions */
#define INT6_DDR   DDRE
#define INT6_PORT  PORTE
#define INT6_PIN   PINE
#define INT6_BIT   6

#define AIN0_DDR   DDRE
#define AIN0_PORT  PORTE
#define AIN0_PIN   PINE
#define AIN0_BIT   6

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

#define RTS_DDR   DDRB
#define RTS_PORT  PORTB
#define RTS_PIN   PINB
#define RTS_BIT   7

#define OC0B_DDR   DDRD
#define OC0B_PORT  PORTD
#define OC0B_PIN   PIND
#define OC0B_BIT   0

#define SCL_DDR   DDRD
#define SCL_PORT  PORTD
#define SCL_PIN   PIND
#define SCL_BIT   0

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   0

#define SDA_DDR   DDRD
#define SDA_PORT  PORTD
#define SDA_PIN   PIND
#define SDA_BIT   1

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   1

#define RXD1_DDR   DDRD
#define RXD1_PORT  PORTD
#define RXD1_PIN   PIND
#define RXD1_BIT   2

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

#define XCK1_DDR   DDRD
#define XCK1_PORT  PORTD
#define XCK1_PIN   PIND
#define XCK1_BIT   5

#define CTS_DDR   DDRD
#define CTS_PORT  PORTD
#define CTS_PIN   PIND
#define CTS_BIT   5

#define ICP1_DDR   DDRD
#define ICP1_PORT  PORTD
#define ICP1_PIN   PIND
#define ICP1_BIT   4

#define ADC8_DDR   DDRD
#define ADC8_PORT  PORTD
#define ADC8_PIN   PIND
#define ADC8_BIT   4

#define OC4D_DDR   DDRD
#define OC4D_PORT  PORTD
#define OC4D_PIN   PIND
#define OC4D_BIT   6

#define ADC9_DDR   DDRD
#define ADC9_PORT  PORTD
#define ADC9_PIN   PIND
#define ADC9_BIT   6

#define T0_DDR   DDRD
#define T0_PORT  PORTD
#define T0_PIN   PIND
#define T0_BIT   7

#define OC4D_DDR   DDRD
#define OC4D_PORT  PORTD
#define OC4D_PIN   PIND
#define OC4D_BIT   7

#define ADC10_DDR   DDRD
#define ADC10_PORT  PORTD
#define ADC10_PIN   PIND
#define ADC10_BIT   7

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define ADC11_DDR   DDRB
#define ADC11_PORT  PORTB
#define ADC11_PIN   PINB
#define ADC11_BIT   4

#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   5

#define OC4B_DDR   DDRB
#define OC4B_PORT  PORTB
#define OC4B_PIN   PINB
#define OC4B_BIT   5

#define ADC12_DDR   DDRB
#define ADC12_PORT  PORTB
#define ADC12_PIN   PINB
#define ADC12_BIT   5

#define PCINT6_DDR   DDRB
#define PCINT6_PORT  PORTB
#define PCINT6_PIN   PINB
#define PCINT6_BIT   6

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   6

#define OC4B_DDR   DDRB
#define OC4B_PORT  PORTB
#define OC4B_PIN   PINB
#define OC4B_BIT   6

#define ADC13_DDR   DDRB
#define ADC13_PORT  PORTB
#define ADC13_PIN   PINB
#define ADC13_BIT   6

#define OC3A_DDR   DDRC
#define OC3A_PORT  PORTC
#define OC3A_PIN   PINC
#define OC3A_BIT   6

#define OC4A_DDR   DDRC
#define OC4A_PORT  PORTC
#define OC4A_PIN   PINC
#define OC4A_BIT   6

#define ICP3_DDR   DDRC
#define ICP3_PORT  PORTC
#define ICP3_PIN   PINC
#define ICP3_BIT   7

#define OC4A_DDR   DDRC
#define OC4A_PORT  PORTC
#define OC4A_PIN   PINC
#define OC4A_BIT   7

#define ADC7_DDR   DDRF
#define ADC7_PORT  PORTF
#define ADC7_PIN   PINF
#define ADC7_BIT   7

#define ADC6_DDR   DDRF
#define ADC6_PORT  PORTF
#define ADC6_PIN   PINF
#define ADC6_BIT   6

#define ADC5_DDR   DDRF
#define ADC5_PORT  PORTF
#define ADC5_PIN   PINF
#define ADC5_BIT   5

#define ADC4_DDR   DDRF
#define ADC4_PORT  PORTF
#define ADC4_PIN   PINF
#define ADC4_BIT   4

#define ADC1_DDR   DDRF
#define ADC1_PORT  PORTF
#define ADC1_PIN   PINF
#define ADC1_BIT   1

#define ADC0_DDR   DDRF
#define ADC0_PORT  PORTF
#define ADC0_PIN   PINF
#define ADC0_BIT   0

#endif /* _AVR_PIN_ATMEGA16U4_H_ */

