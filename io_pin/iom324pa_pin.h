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

/* avr/../io_pin/iom324pa_pin.h - definitions for ATmega324PA */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom324pa_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA324PA_H_
#define _AVR_PIN_ATMEGA324PA_H_ 1


/* Device Pin Definitions */
#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   5

#define PCINT13_DDR   DDRB
#define PCINT13_PORT  PORTB
#define PCINT13_PIN   PINB
#define PCINT13_BIT   5

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   6

#define PCINT14_DDR   DDRB
#define PCINT14_PORT  PORTB
#define PCINT14_PIN   PINB
#define PCINT14_BIT   6

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   7

#define PCINT15_DDR   DDRB
#define PCINT15_PORT  PORTB
#define PCINT15_PIN   PINB
#define PCINT15_BIT   7

#define RXD_DDR   DDRD
#define RXD_PORT  PORTD
#define RXD_PIN   PIND
#define RXD_BIT   0

#define PCINT24_DDR   DDRD
#define PCINT24_PORT  PORTD
#define PCINT24_PIN   PIND
#define PCINT24_BIT   0

#define TXD_DDR   DDRD
#define TXD_PORT  PORTD
#define TXD_PIN   PIND
#define TXD_BIT   1

#define PCINT25_DDR   DDRD
#define PCINT25_PORT  PORTD
#define PCINT25_PIN   PIND
#define PCINT25_BIT   1

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   2

#define PCINT26_DDR   DDRD
#define PCINT26_PORT  PORTD
#define PCINT26_PIN   PIND
#define PCINT26_BIT   2

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   3

#define PCINT27_DDR   DDRD
#define PCINT27_PORT  PORTD
#define PCINT27_PIN   PIND
#define PCINT27_BIT   3

#define OC1B_DDR   DDRD
#define OC1B_PORT  PORTD
#define OC1B_PIN   PIND
#define OC1B_BIT   4

#define PCINT28_DDR   DDRD
#define PCINT28_PORT  PORTD
#define PCINT28_PIN   PIND
#define PCINT28_BIT   4

#define OC1A_DDR   DDRD
#define OC1A_PORT  PORTD
#define OC1A_PIN   PIND
#define OC1A_BIT   5

#define PCINT29_DDR   DDRD
#define PCINT29_PORT  PORTD
#define PCINT29_PIN   PIND
#define PCINT29_BIT   5

#define ICP_DDR   DDRD
#define ICP_PORT  PORTD
#define ICP_PIN   PIND
#define ICP_BIT   6

#define OC2B_DDR   DDRD
#define OC2B_PORT  PORTD
#define OC2B_PIN   PIND
#define OC2B_BIT   6

#define PCINT30_DDR   DDRD
#define PCINT30_PORT  PORTD
#define PCINT30_PIN   PIND
#define PCINT30_BIT   6

#define OC2A_DDR   DDRD
#define OC2A_PORT  PORTD
#define OC2A_PIN   PIND
#define OC2A_BIT   7

#define PCINT31_DDR   DDRD
#define PCINT31_PORT  PORTD
#define PCINT31_PIN   PIND
#define PCINT31_BIT   7

#define SCL_DDR   DDRC
#define SCL_PORT  PORTC
#define SCL_PIN   PINC
#define SCL_BIT   0

#define PCINT16_DDR   DDRC
#define PCINT16_PORT  PORTC
#define PCINT16_PIN   PINC
#define PCINT16_BIT   0

#define SDA_DDR   DDRC
#define SDA_PORT  PORTC
#define SDA_PIN   PINC
#define SDA_BIT   1

#define PCINT17_DDR   DDRC
#define PCINT17_PORT  PORTC
#define PCINT17_PIN   PINC
#define PCINT17_BIT   1

#define PCINT18_DDR   DDRC
#define PCINT18_PORT  PORTC
#define PCINT18_PIN   PINC
#define PCINT18_BIT   2

#define PCINT19_DDR   DDRC
#define PCINT19_PORT  PORTC
#define PCINT19_PIN   PINC
#define PCINT19_BIT   3

#define PCINT20_DDR   DDRC
#define PCINT20_PORT  PORTC
#define PCINT20_PIN   PINC
#define PCINT20_BIT   4

#define PCINT21_DDR   DDRC
#define PCINT21_PORT  PORTC
#define PCINT21_PIN   PINC
#define PCINT21_BIT   5

#define PCINT22_DDR   DDRC
#define PCINT22_PORT  PORTC
#define PCINT22_PIN   PINC
#define PCINT22_BIT   6

#define PCINT23_DDR   DDRC
#define PCINT23_PORT  PORTC
#define PCINT23_PIN   PINC
#define PCINT23_BIT   7

#define ADC7_DDR   DDRA
#define ADC7_PORT  PORTA
#define ADC7_PIN   PINA
#define ADC7_BIT   7

#define PCINT7_DDR   DDRA
#define PCINT7_PORT  PORTA
#define PCINT7_PIN   PINA
#define PCINT7_BIT   7

#define ADC6_DDR   DDRA
#define ADC6_PORT  PORTA
#define ADC6_PIN   PINA
#define ADC6_BIT   6

#define PCINT6_DDR   DDRA
#define PCINT6_PORT  PORTA
#define PCINT6_PIN   PINA
#define PCINT6_BIT   6

#define ADC5_DDR   DDRA
#define ADC5_PORT  PORTA
#define ADC5_PIN   PINA
#define ADC5_BIT   5

#define PCINT5_DDR   DDRA
#define PCINT5_PORT  PORTA
#define PCINT5_PIN   PINA
#define PCINT5_BIT   5

#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   4

#define PCINT4_DDR   DDRA
#define PCINT4_PORT  PORTA
#define PCINT4_PIN   PINA
#define PCINT4_BIT   4

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   3

#define PCINT3_DDR   DDRA
#define PCINT3_PORT  PORTA
#define PCINT3_PIN   PINA
#define PCINT3_BIT   3

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define PCINT2_DDR   DDRA
#define PCINT2_PORT  PORTA
#define PCINT2_PIN   PINA
#define PCINT2_BIT   2

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define PCINT1_DDR   DDRA
#define PCINT1_PORT  PORTA
#define PCINT1_PIN   PINA
#define PCINT1_BIT   1

#define ADC0_DDR   DDRA
#define ADC0_PORT  PORTA
#define ADC0_PIN   PINA
#define ADC0_BIT   0

#define PCINT0_DDR   DDRA
#define PCINT0_PORT  PORTA
#define PCINT0_PIN   PINA
#define PCINT0_BIT   0

#define XCK_DDR   DDRB
#define XCK_PORT  PORTB
#define XCK_PIN   PINB
#define XCK_BIT   0

#define T0_DDR   DDRB
#define T0_PORT  PORTB
#define T0_PIN   PINB
#define T0_BIT   0

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define AIN0_DDR   DDRB
#define AIN0_PORT  PORTB
#define AIN0_PIN   PINB
#define AIN0_BIT   2

#define INT2_DDR   DDRB
#define INT2_PORT  PORTB
#define INT2_PIN   PINB
#define INT2_BIT   2

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define AIN1_DDR   DDRB
#define AIN1_PORT  PORTB
#define AIN1_PIN   PINB
#define AIN1_BIT   3

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   3

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   4

#define OC0B_DDR   DDRB
#define OC0B_PORT  PORTB
#define OC0B_PIN   PINB
#define OC0B_BIT   4

#define PCINT12_DDR   DDRB
#define PCINT12_PORT  PORTB
#define PCINT12_PIN   PINB
#define PCINT12_BIT   4

#endif /* _AVR_PIN_ATMEGA324PA_H_ */

