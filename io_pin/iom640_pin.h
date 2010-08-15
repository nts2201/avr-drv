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

/* avr/../io_pin/iom640_pin.h - definitions for ATmega640 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom640_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA640_H_
#define _AVR_PIN_ATMEGA640_H_ 1


/* Device Pin Definitions */
#define OC0B_DDR   DDRG
#define OC0B_PORT  PORTG
#define OC0B_PIN   PING
#define OC0B_BIT   5

#define RXD0_DDR   DDRE
#define RXD0_PORT  PORTE
#define RXD0_PIN   PINE
#define RXD0_BIT   0

#define PCINT8_DDR   DDRE
#define PCINT8_PORT  PORTE
#define PCINT8_PIN   PINE
#define PCINT8_BIT   0

#define TXD0_DDR   DDRE
#define TXD0_PORT  PORTE
#define TXD0_PIN   PINE
#define TXD0_BIT   1

#define XCK_DDR   DDRE
#define XCK_PORT  PORTE
#define XCK_PIN   PINE
#define XCK_BIT   2

#define AIN0_DDR   DDRE
#define AIN0_PORT  PORTE
#define AIN0_PIN   PINE
#define AIN0_BIT   2

#define OC3A_DDR   DDRE
#define OC3A_PORT  PORTE
#define OC3A_PIN   PINE
#define OC3A_BIT   3

#define AIN1_DDR   DDRE
#define AIN1_PORT  PORTE
#define AIN1_PIN   PINE
#define AIN1_BIT   3

#define OC3B_DDR   DDRE
#define OC3B_PORT  PORTE
#define OC3B_PIN   PINE
#define OC3B_BIT   4

#define INT4_DDR   DDRE
#define INT4_PORT  PORTE
#define INT4_PIN   PINE
#define INT4_BIT   4

#define OC3C_DDR   DDRE
#define OC3C_PORT  PORTE
#define OC3C_PIN   PINE
#define OC3C_BIT   5

#define INT5_DDR   DDRE
#define INT5_PORT  PORTE
#define INT5_PIN   PINE
#define INT5_BIT   5

#define INT6_DDR   DDRE
#define INT6_PORT  PORTE
#define INT6_PIN   PINE
#define INT6_BIT   6

#define ICP3_DDR   DDRE
#define ICP3_PORT  PORTE
#define ICP3_PIN   PINE
#define ICP3_BIT   7

#define INT7_DDR   DDRE
#define INT7_PORT  PORTE
#define INT7_PIN   PINE
#define INT7_BIT   7

#define RXD2_DDR   DDRH
#define RXD2_PORT  PORTH
#define RXD2_PIN   PINH
#define RXD2_BIT   0

#define TXD2_DDR   DDRH
#define TXD2_PORT  PORTH
#define TXD2_PIN   PINH
#define TXD2_BIT   1

#define XCK2_DDR   DDRH
#define XCK2_PORT  PORTH
#define XCK2_PIN   PINH
#define XCK2_BIT   2

#define OC4A_DDR   DDRH
#define OC4A_PORT  PORTH
#define OC4A_PIN   PINH
#define OC4A_BIT   3

#define OC4B_DDR   DDRH
#define OC4B_PORT  PORTH
#define OC4B_PIN   PINH
#define OC4B_BIT   4

#define OC4C_DDR   DDRH
#define OC4C_PORT  PORTH
#define OC4C_PIN   PINH
#define OC4C_BIT   5

#define OC2B_DDR   DDRH
#define OC2B_PORT  PORTH
#define OC2B_PIN   PINH
#define OC2B_BIT   6

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   1

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

#define OC2A_DDR   DDRB
#define OC2A_PORT  PORTB
#define OC2A_PIN   PINB
#define OC2A_BIT   4

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   5

#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   6

#define PCINT6_DDR   DDRB
#define PCINT6_PORT  PORTB
#define PCINT6_PIN   PINB
#define PCINT6_BIT   6

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   7

#define OC1C_DDR   DDRB
#define OC1C_PORT  PORTB
#define OC1C_PIN   PINB
#define OC1C_BIT   7

#define PCINT7_DDR   DDRB
#define PCINT7_PORT  PORTB
#define PCINT7_PIN   PINB
#define PCINT7_BIT   7

#define ICP4_DDR   DDRL
#define ICP4_PORT  PORTL
#define ICP4_PIN   PINL
#define ICP4_BIT   0

#define ICP5_DDR   DDRL
#define ICP5_PORT  PORTL
#define ICP5_PIN   PINL
#define ICP5_BIT   1

#define OC5A_DDR   DDRL
#define OC5A_PORT  PORTL
#define OC5A_PIN   PINL
#define OC5A_BIT   3

#define OC5B_DDR   DDRL
#define OC5B_PORT  PORTL
#define OC5B_PIN   PINL
#define OC5B_BIT   4

#define OC5C_DDR   DDRL
#define OC5C_PORT  PORTL
#define OC5C_PIN   PINL
#define OC5C_BIT   5

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

#define ICP1_DDR   DDRD
#define ICP1_PORT  PORTD
#define ICP1_PIN   PIND
#define ICP1_BIT   4

#define XCK1_DDR   DDRD
#define XCK1_PORT  PORTD
#define XCK1_PIN   PIND
#define XCK1_BIT   5

#define T0_DDR   DDRD
#define T0_PORT  PORTD
#define T0_PIN   PIND
#define T0_BIT   7

#define WR_DDR   DDRG
#define WR_PORT  PORTG
#define WR_PIN   PING
#define WR_BIT   0

#define RD_DDR   DDRG
#define RD_PORT  PORTG
#define RD_PIN   PING
#define RD_BIT   1

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

#define RXD3_DDR   DDRJ
#define RXD3_PORT  PORTJ
#define RXD3_PIN   PINJ
#define RXD3_BIT   0

#define PCINT9_DDR   DDRJ
#define PCINT9_PORT  PORTJ
#define PCINT9_PIN   PINJ
#define PCINT9_BIT   0

#define TXD3_DDR   DDRJ
#define TXD3_PORT  PORTJ
#define TXD3_PIN   PINJ
#define TXD3_BIT   1

#define PCINT10_DDR   DDRJ
#define PCINT10_PORT  PORTJ
#define PCINT10_PIN   PINJ
#define PCINT10_BIT   1

#define XCK3_DDR   DDRJ
#define XCK3_PORT  PORTJ
#define XCK3_PIN   PINJ
#define XCK3_BIT   2

#define PCINT11_DDR   DDRJ
#define PCINT11_PORT  PORTJ
#define PCINT11_PIN   PINJ
#define PCINT11_BIT   2

#define PCINT12_DDR   DDRJ
#define PCINT12_PORT  PORTJ
#define PCINT12_PIN   PINJ
#define PCINT12_BIT   3

#define PCINT13_DDR   DDRJ
#define PCINT13_PORT  PORTJ
#define PCINT13_PIN   PINJ
#define PCINT13_BIT   4

#define PCINT14_DDR   DDRJ
#define PCINT14_PORT  PORTJ
#define PCINT14_PIN   PINJ
#define PCINT14_BIT   5

#define PCINT15_DDR   DDRJ
#define PCINT15_PORT  PORTJ
#define PCINT15_PIN   PINJ
#define PCINT15_BIT   6

#define ALE_DDR   DDRG
#define ALE_PORT  PORTG
#define ALE_PIN   PING
#define ALE_BIT   2

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

#define ADC15_DDR   DDRK
#define ADC15_PORT  PORTK
#define ADC15_PIN   PINK
#define ADC15_BIT   7

#define PCINT23_DDR   DDRK
#define PCINT23_PORT  PORTK
#define PCINT23_PIN   PINK
#define PCINT23_BIT   7

#define ADC14_DDR   DDRK
#define ADC14_PORT  PORTK
#define ADC14_PIN   PINK
#define ADC14_BIT   6

#define PCINT22_DDR   DDRK
#define PCINT22_PORT  PORTK
#define PCINT22_PIN   PINK
#define PCINT22_BIT   6

#define ADC13_DDR   DDRK
#define ADC13_PORT  PORTK
#define ADC13_PIN   PINK
#define ADC13_BIT   5

#define PCINT21_DDR   DDRK
#define PCINT21_PORT  PORTK
#define PCINT21_PIN   PINK
#define PCINT21_BIT   5

#define ADC12_DDR   DDRK
#define ADC12_PORT  PORTK
#define ADC12_PIN   PINK
#define ADC12_BIT   4

#define PCINT20_DDR   DDRK
#define PCINT20_PORT  PORTK
#define PCINT20_PIN   PINK
#define PCINT20_BIT   4

#define ADC11_DDR   DDRK
#define ADC11_PORT  PORTK
#define ADC11_PIN   PINK
#define ADC11_BIT   3

#define PCINT19_DDR   DDRK
#define PCINT19_PORT  PORTK
#define PCINT19_PIN   PINK
#define PCINT19_BIT   3

#define ADC10_DDR   DDRK
#define ADC10_PORT  PORTK
#define ADC10_PIN   PINK
#define ADC10_BIT   2

#define PCINT18_DDR   DDRK
#define PCINT18_PORT  PORTK
#define PCINT18_PIN   PINK
#define PCINT18_BIT   2

#define ADC9_DDR   DDRK
#define ADC9_PORT  PORTK
#define ADC9_PIN   PINK
#define ADC9_BIT   1

#define PCINT17_DDR   DDRK
#define PCINT17_PORT  PORTK
#define PCINT17_PIN   PINK
#define PCINT17_BIT   1

#define ADC8_DDR   DDRK
#define ADC8_PORT  PORTK
#define ADC8_PIN   PINK
#define ADC8_BIT   0

#define PCINT16_DDR   DDRK
#define PCINT16_PORT  PORTK
#define PCINT16_PIN   PINK
#define PCINT16_BIT   0

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

#define ADC3_DDR   DDRF
#define ADC3_PORT  PORTF
#define ADC3_PIN   PINF
#define ADC3_BIT   3

#define ADC2_DDR   DDRF
#define ADC2_PORT  PORTF
#define ADC2_PIN   PINF
#define ADC2_BIT   2

#define ADC1_DDR   DDRF
#define ADC1_PORT  PORTF
#define ADC1_PIN   PINF
#define ADC1_BIT   1

#define ADC0_DDR   DDRF
#define ADC0_PORT  PORTF
#define ADC0_PIN   PINF
#define ADC0_BIT   0

#endif /* _AVR_PIN_ATMEGA640_H_ */

