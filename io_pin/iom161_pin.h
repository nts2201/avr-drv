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

/* avr/../io_pin/iom161_pin.h - definitions for ATmega161 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom161_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA161_H_
#define _AVR_PIN_ATMEGA161_H_ 1


/* Device Pin Definitions */
#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   5

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   6

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   7

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

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   3

#define PD4_DDR   DDRD
#define PD4_PORT  PORTD
#define PD4_PIN   PIND
#define PD4_BIT   4

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

#define A8_DDR   DDRC
#define A8_PORT  PORTC
#define A8_PIN   PINC
#define A8_BIT   0

#define A9_DDR   DDRC
#define A9_PORT  PORTC
#define A9_PIN   PINC
#define A9_BIT   1

#define A10_DDR   DDRC
#define A10_PORT  PORTC
#define A10_PIN   PINC
#define A10_BIT   2

#define A11_DDR   DDRC
#define A11_PORT  PORTC
#define A11_PIN   PINC
#define A11_BIT   3

#define A12_DDR   DDRC
#define A12_PORT  PORTC
#define A12_PIN   PINC
#define A12_BIT   4

#define A13_DDR   DDRC
#define A13_PORT  PORTC
#define A13_PIN   PINC
#define A13_BIT   5

#define A14_DDR   DDRC
#define A14_PORT  PORTC
#define A14_PIN   PINC
#define A14_BIT   6

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

#define ICP/INT2_DDR   DDRE
#define ICP/INT2_PORT  PORTE
#define ICP/INT2_PIN   PINE
#define ICP/INT2_BIT   0

#define AD7_DDR   DDRA
#define AD7_PORT  PORTA
#define AD7_PIN   PINA
#define AD7_BIT   7

#define AD6_DDR   DDRA
#define AD6_PORT  PORTA
#define AD6_PIN   PINA
#define AD6_BIT   6

#define AD5_DDR   DDRA
#define AD5_PORT  PORTA
#define AD5_PIN   PINA
#define AD5_BIT   5

#define AD4_DDR   DDRA
#define AD4_PORT  PORTA
#define AD4_PIN   PINA
#define AD4_BIT   4

#define AD3_DDR   DDRA
#define AD3_PORT  PORTA
#define AD3_PIN   PINA
#define AD3_BIT   3

#define AD2_DDR   DDRA
#define AD2_PORT  PORTA
#define AD2_PIN   PINA
#define AD2_BIT   2

#define AD1_DDR   DDRA
#define AD1_PORT  PORTA
#define AD1_PIN   PINA
#define AD1_BIT   1

#define AD0_DDR   DDRA
#define AD0_PORT  PORTA
#define AD0_PIN   PINA
#define AD0_BIT   0

#define OC0/T0_DDR   DDRB
#define OC0/T0_PORT  PORTB
#define OC0/T0_PIN   PINB
#define OC0/T0_BIT   0

#define OC2/_DDR   DDRB
#define OC2/_PORT  PORTB
#define OC2/_PIN   PINB
#define OC2/_BIT   1

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

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   4

#endif /* _AVR_PIN_ATMEGA161_H_ */

