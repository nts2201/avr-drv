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

/* avr/../io_pin/iom162_pin.h - definitions for ATmega162 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom162_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA162_H_
#define _AVR_PIN_ATMEGA162_H_ 1


/* Device Pin Definitions */
#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   5

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   6

#define RXD0_DDR   DDRD
#define RXD0_PORT  PORTD
#define RXD0_PIN   PIND
#define RXD0_BIT   0

#define TXD0_DDR   DDRD
#define TXD0_PORT  PORTD
#define TXD0_PIN   PIND
#define TXD0_BIT   1

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   2

#define XCK1_DDR   DDRD
#define XCK1_PORT  PORTD
#define XCK1_PIN   PIND
#define XCK1_BIT   2

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   3

#define ICP3_DDR   DDRD
#define ICP3_PORT  PORTD
#define ICP3_PIN   PIND
#define ICP3_BIT   3

#define XCK0_DDR   DDRD
#define XCK0_PORT  PORTD
#define XCK0_PIN   PIND
#define XCK0_BIT   4

#define OC3A_DDR   DDRD
#define OC3A_PORT  PORTD
#define OC3A_PIN   PIND
#define OC3A_BIT   4

#define OC1A_DDR   DDRD
#define OC1A_PORT  PORTD
#define OC1A_PIN   PIND
#define OC1A_BIT   5

#define WR_DDR   DDRD
#define WR_PORT  PORTD
#define WR_PIN   PIND
#define WR_BIT   6

#define RD_DDR   DDRD
#define RD_PORT  PORTD
#define RD_PIN   PIND
#define RD_BIT   7

#define PCINT8_DDR   DDRC
#define PCINT8_PORT  PORTC
#define PCINT8_PIN   PINC
#define PCINT8_BIT   0

#define A8_DDR   DDRC
#define A8_PORT  PORTC
#define A8_PIN   PINC
#define A8_BIT   0

#define PCINT9_DDR   DDRC
#define PCINT9_PORT  PORTC
#define PCINT9_PIN   PINC
#define PCINT9_BIT   1

#define A9_DDR   DDRC
#define A9_PORT  PORTC
#define A9_PIN   PINC
#define A9_BIT   1

#define PCINT10_DDR   DDRC
#define PCINT10_PORT  PORTC
#define PCINT10_PIN   PINC
#define PCINT10_BIT   2

#define A10_DDR   DDRC
#define A10_PORT  PORTC
#define A10_PIN   PINC
#define A10_BIT   2

#define PCINT11_DDR   DDRC
#define PCINT11_PORT  PORTC
#define PCINT11_PIN   PINC
#define PCINT11_BIT   3

#define A11_DDR   DDRC
#define A11_PORT  PORTC
#define A11_PIN   PINC
#define A11_BIT   3

#define PCINT12_DDR   DDRC
#define PCINT12_PORT  PORTC
#define PCINT12_PIN   PINC
#define PCINT12_BIT   4

#define A12_DDR   DDRC
#define A12_PORT  PORTC
#define A12_PIN   PINC
#define A12_BIT   4

#define PCINT13_DDR   DDRC
#define PCINT13_PORT  PORTC
#define PCINT13_PIN   PINC
#define PCINT13_BIT   5

#define A13_DDR   DDRC
#define A13_PORT  PORTC
#define A13_PIN   PINC
#define A13_BIT   5

#define PCINT14_DDR   DDRC
#define PCINT14_PORT  PORTC
#define PCINT14_PIN   PINC
#define PCINT14_BIT   6

#define A14_DDR   DDRC
#define A14_PORT  PORTC
#define A14_PIN   PINC
#define A14_BIT   6

#define PCINT15_DDR   DDRC
#define PCINT15_PORT  PORTC
#define PCINT15_PIN   PINC
#define PCINT15_BIT   7

#define A15_DDR   DDRC
#define A15_PORT  PORTC
#define A15_PIN   PINC
#define A15_BIT   7

#define OC1B_DDR   DDRE
#define OC1B_PORT  PORTE
#define OC1B_PIN   PINE
#define OC1B_BIT   2

#define ALE_DDR   DDRE
#define ALE_PORT  PORTE
#define ALE_PIN   PINE
#define ALE_BIT   1

#define ICP1_DDR   DDRE
#define ICP1_PORT  PORTE
#define ICP1_PIN   PINE
#define ICP1_BIT   0

#define INT2_DDR   DDRE
#define INT2_PORT  PORTE
#define INT2_PIN   PINE
#define INT2_BIT   0

#define PCINT7_DDR   DDRA
#define PCINT7_PORT  PORTA
#define PCINT7_PIN   PINA
#define PCINT7_BIT   7

#define AD7_DDR   DDRA
#define AD7_PORT  PORTA
#define AD7_PIN   PINA
#define AD7_BIT   7

#define PCINT6_DDR   DDRA
#define PCINT6_PORT  PORTA
#define PCINT6_PIN   PINA
#define PCINT6_BIT   6

#define AD6_DDR   DDRA
#define AD6_PORT  PORTA
#define AD6_PIN   PINA
#define AD6_BIT   6

#define PCINT5_DDR   DDRA
#define PCINT5_PORT  PORTA
#define PCINT5_PIN   PINA
#define PCINT5_BIT   5

#define AD5_DDR   DDRA
#define AD5_PORT  PORTA
#define AD5_PIN   PINA
#define AD5_BIT   5

#define PCINT4_DDR   DDRA
#define PCINT4_PORT  PORTA
#define PCINT4_PIN   PINA
#define PCINT4_BIT   4

#define AD4_DDR   DDRA
#define AD4_PORT  PORTA
#define AD4_PIN   PINA
#define AD4_BIT   4

#define PCINT3_DDR   DDRA
#define PCINT3_PORT  PORTA
#define PCINT3_PIN   PINA
#define PCINT3_BIT   3

#define AD3_DDR   DDRA
#define AD3_PORT  PORTA
#define AD3_PIN   PINA
#define AD3_BIT   3

#define PCINT2_DDR   DDRA
#define PCINT2_PORT  PORTA
#define PCINT2_PIN   PINA
#define PCINT2_BIT   2

#define AD2_DDR   DDRA
#define AD2_PORT  PORTA
#define AD2_PIN   PINA
#define AD2_BIT   2

#define PCINT1_DDR   DDRA
#define PCINT1_PORT  PORTA
#define PCINT1_PIN   PINA
#define PCINT1_BIT   1

#define AD1_DDR   DDRA
#define AD1_PORT  PORTA
#define AD1_PIN   PINA
#define AD1_BIT   1

#define PCINT0_DDR   DDRA
#define PCINT0_PORT  PORTA
#define PCINT0_PIN   PINA
#define PCINT0_BIT   0

#define AD0_DDR   DDRA
#define AD0_PORT  PORTA
#define AD0_PIN   PINA
#define AD0_BIT   0

#define OC0_DDR   DDRB
#define OC0_PORT  PORTB
#define OC0_PIN   PINB
#define OC0_BIT   0

#define T0_DDR   DDRB
#define T0_PORT  PORTB
#define T0_PIN   PINB
#define T0_BIT   0

#define OC2_DDR   DDRB
#define OC2_PORT  PORTB
#define OC2_PIN   PINB
#define OC2_BIT   1

#define RXD1_DDR   DDRB
#define RXD1_PORT  PORTB
#define RXD1_PIN   PINB
#define RXD1_BIT   2

#define AIN0_DDR   DDRB
#define AIN0_PORT  PORTB
#define AIN0_PIN   PINB
#define AIN0_BIT   2

#define TXD1_DDR   DDRB
#define TXD1_PORT  PORTB
#define TXD1_PIN   PINB
#define TXD1_BIT   3

#define AIN1_DDR   DDRB
#define AIN1_PORT  PORTB
#define AIN1_PIN   PINB
#define AIN1_BIT   3

#define OC3B_DDR   DDRB
#define OC3B_PORT  PORTB
#define OC3B_PIN   PINB
#define OC3B_BIT   4

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   4

#endif /* _AVR_PIN_ATMEGA162_H_ */

