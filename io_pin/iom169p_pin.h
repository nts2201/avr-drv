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

/* avr/../io_pin/iom169p_pin.h - definitions for ATmega169P */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom169p_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA169P_H_
#define _AVR_PIN_ATMEGA169P_H_ 1


/* Device Pin Definitions */
#define RXD_DDR   DDRE
#define RXD_PORT  PORTE
#define RXD_PIN   PINE
#define RXD_BIT   0

#define PCINT0_DDR   DDRE
#define PCINT0_PORT  PORTE
#define PCINT0_PIN   PINE
#define PCINT0_BIT   0

#define TXD_DDR   DDRE
#define TXD_PORT  PORTE
#define TXD_PIN   PINE
#define TXD_BIT   1

#define PCINT1_DDR   DDRE
#define PCINT1_PORT  PORTE
#define PCINT1_PIN   PINE
#define PCINT1_BIT   1

#define XCK_DDR   DDRE
#define XCK_PORT  PORTE
#define XCK_PIN   PINE
#define XCK_BIT   2

#define AIN0_DDR   DDRE
#define AIN0_PORT  PORTE
#define AIN0_PIN   PINE
#define AIN0_BIT   2

#define PCINT2_DDR   DDRE
#define PCINT2_PORT  PORTE
#define PCINT2_PIN   PINE
#define PCINT2_BIT   2

#define AIN1_DDR   DDRE
#define AIN1_PORT  PORTE
#define AIN1_PIN   PINE
#define AIN1_BIT   3

#define PCINT3_DDR   DDRE
#define PCINT3_PORT  PORTE
#define PCINT3_PIN   PINE
#define PCINT3_BIT   3

#define USCK_DDR   DDRE
#define USCK_PORT  PORTE
#define USCK_PIN   PINE
#define USCK_BIT   4

#define SCL_DDR   DDRE
#define SCL_PORT  PORTE
#define SCL_PIN   PINE
#define SCL_BIT   4

#define PCINT4_DDR   DDRE
#define PCINT4_PORT  PORTE
#define PCINT4_PIN   PINE
#define PCINT4_BIT   4

#define DI_DDR   DDRE
#define DI_PORT  PORTE
#define DI_PIN   PINE
#define DI_BIT   5

#define SDA_DDR   DDRE
#define SDA_PORT  PORTE
#define SDA_PIN   PINE
#define SDA_BIT   5

#define PCINT5_DDR   DDRE
#define PCINT5_PORT  PORTE
#define PCINT5_PIN   PINE
#define PCINT5_BIT   5

#define DO_DDR   DDRE
#define DO_PORT  PORTE
#define DO_PIN   PINE
#define DO_BIT   6

#define PCINT6_DDR   DDRE
#define PCINT6_PORT  PORTE
#define PCINT6_PIN   PINE
#define PCINT6_BIT   6

#define PCINT7_DDR   DDRE
#define PCINT7_PORT  PORTE
#define PCINT7_PIN   PINE
#define PCINT7_BIT   7

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   0

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   1

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   2

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   3

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define OC0_DDR   DDRB
#define OC0_PORT  PORTB
#define OC0_PIN   PINB
#define OC0_BIT   4

#define PCINT12_DDR   DDRB
#define PCINT12_PORT  PORTB
#define PCINT12_PIN   PINB
#define PCINT12_BIT   4

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   5

#define PCINT13_DDR   DDRB
#define PCINT13_PORT  PORTB
#define PCINT13_PIN   PINB
#define PCINT13_BIT   5

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   6

#define PCINT14_DDR   DDRB
#define PCINT14_PORT  PORTB
#define PCINT14_PIN   PINB
#define PCINT14_BIT   6

#define OC2_DDR   DDRB
#define OC2_PORT  PORTB
#define OC2_PIN   PINB
#define OC2_BIT   7

#define PCINT15_DDR   DDRB
#define PCINT15_PORT  PORTB
#define PCINT15_PIN   PINB
#define PCINT15_BIT   7

#define SEG24_DDR   DDRG
#define SEG24_PORT  PORTG
#define SEG24_PIN   PING
#define SEG24_BIT   3

#define T0_DDR   DDRG
#define T0_PORT  PORTG
#define T0_PIN   PING
#define T0_BIT   4

#define SEG23_DDR   DDRG
#define SEG23_PORT  PORTG
#define SEG23_PIN   PING
#define SEG23_BIT   4

#define ICP/SEG22_DDR   DDRD
#define ICP/SEG22_PORT  PORTD
#define ICP/SEG22_PIN   PIND
#define ICP/SEG22_BIT   0

#define INT0/SEG21_DDR   DDRD
#define INT0/SEG21_PORT  PORTD
#define INT0/SEG21_PIN   PIND
#define INT0/SEG21_BIT   1

#define SEG20_DDR   DDRD
#define SEG20_PORT  PORTD
#define SEG20_PIN   PIND
#define SEG20_BIT   2

#define SEG19_DDR   DDRD
#define SEG19_PORT  PORTD
#define SEG19_PIN   PIND
#define SEG19_BIT   3

#define SEG18_DDR   DDRD
#define SEG18_PORT  PORTD
#define SEG18_PIN   PIND
#define SEG18_BIT   4

#define SEG17_DDR   DDRD
#define SEG17_PORT  PORTD
#define SEG17_PIN   PIND
#define SEG17_BIT   5

#define SEG16_DDR   DDRD
#define SEG16_PORT  PORTD
#define SEG16_PIN   PIND
#define SEG16_BIT   6

#define SEG15_DDR   DDRD
#define SEG15_PORT  PORTD
#define SEG15_PIN   PIND
#define SEG15_BIT   7

#define SEG14_DDR   DDRG
#define SEG14_PORT  PORTG
#define SEG14_PIN   PING
#define SEG14_BIT   0

#define SEG13_DDR   DDRG
#define SEG13_PORT  PORTG
#define SEG13_PIN   PING
#define SEG13_BIT   1

#define SEG12_DDR   DDRC
#define SEG12_PORT  PORTC
#define SEG12_PIN   PINC
#define SEG12_BIT   0

#define SEG11_DDR   DDRC
#define SEG11_PORT  PORTC
#define SEG11_PIN   PINC
#define SEG11_BIT   1

#define SEG10_DDR   DDRC
#define SEG10_PORT  PORTC
#define SEG10_PIN   PINC
#define SEG10_BIT   2

#define SEG9_DDR   DDRC
#define SEG9_PORT  PORTC
#define SEG9_PIN   PINC
#define SEG9_BIT   3

#define SEG8_DDR   DDRC
#define SEG8_PORT  PORTC
#define SEG8_PIN   PINC
#define SEG8_BIT   4

#define SEG7_DDR   DDRC
#define SEG7_PORT  PORTC
#define SEG7_PIN   PINC
#define SEG7_BIT   5

#define SEG6_DDR   DDRC
#define SEG6_PORT  PORTC
#define SEG6_PIN   PINC
#define SEG6_BIT   6

#define SEG5_DDR   DDRC
#define SEG5_PORT  PORTC
#define SEG5_PIN   PINC
#define SEG5_BIT   7

#define SEG4_DDR   DDRG
#define SEG4_PORT  PORTG
#define SEG4_PIN   PING
#define SEG4_BIT   2

#define SEG3_DDR   DDRA
#define SEG3_PORT  PORTA
#define SEG3_PIN   PINA
#define SEG3_BIT   7

#define SEG2_DDR   DDRA
#define SEG2_PORT  PORTA
#define SEG2_PIN   PINA
#define SEG2_BIT   6

#define SEG1_DDR   DDRA
#define SEG1_PORT  PORTA
#define SEG1_PIN   PINA
#define SEG1_BIT   5

#define SEG0_DDR   DDRA
#define SEG0_PORT  PORTA
#define SEG0_PIN   PINA
#define SEG0_BIT   4

#define COM3_DDR   DDRA
#define COM3_PORT  PORTA
#define COM3_PIN   PINA
#define COM3_BIT   3

#define COM2_DDR   DDRA
#define COM2_PORT  PORTA
#define COM2_PIN   PINA
#define COM2_BIT   2

#define COM1_DDR   DDRA
#define COM1_PORT  PORTA
#define COM1_PIN   PINA
#define COM1_BIT   1

#define COM0_DDR   DDRA
#define COM0_PORT  PORTA
#define COM0_PIN   PINA
#define COM0_BIT   0

#define ADC7_DDR   DDRF
#define ADC7_PORT  PORTF
#define ADC7_PIN   PINF
#define ADC7_BIT   7

#define ADC6_DDR   DDRF
#define ADC6_PORT  PORTF
#define ADC6_PIN   PINF
#define ADC6_BIT   6

#define TD0_DDR   DDRF
#define TD0_PORT  PORTF
#define TD0_PIN   PINF
#define TD0_BIT   6

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

#endif /* _AVR_PIN_ATMEGA169P_H_ */

