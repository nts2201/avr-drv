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

/* avr/../io_pin/iom16m1_pin.h - definitions for ATmega16M1 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iom16m1_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATMEGA16M1_H_
#define _AVR_PIN_ATMEGA16M1_H_ 1


/* Device Pin Definitions */
#define PSCIN2_DDR   DDRD
#define PSCIN2_PORT  PORTD
#define PSCIN2_PIN   PIND
#define PSCIN2_BIT   2

#define OC1A_DDR   DDRD
#define OC1A_PORT  PORTD
#define OC1A_PIN   PIND
#define OC1A_BIT   2

#define MISO_A_DDR   DDRD
#define MISO_A_PORT  PORTD
#define MISO_A_PIN   PIND
#define MISO_A_BIT   2

#define PCINT18_DDR   DDRD
#define PCINT18_PORT  PORTD
#define PCINT18_PIN   PIND
#define PCINT18_BIT   2

#define TXD_DDR   DDRD
#define TXD_PORT  PORTD
#define TXD_PIN   PIND
#define TXD_BIT   3

#define TXLIN_DDR   DDRD
#define TXLIN_PORT  PORTD
#define TXLIN_PIN   PIND
#define TXLIN_BIT   3

#define OC0A_DDR   DDRD
#define OC0A_PORT  PORTD
#define OC0A_PIN   PIND
#define OC0A_BIT   3

#define SS_DDR   DDRD
#define SS_PORT  PORTD
#define SS_PIN   PIND
#define SS_BIT   3

#define MOSI_A_DDR   DDRD
#define MOSI_A_PORT  PORTD
#define MOSI_A_PIN   PIND
#define MOSI_A_BIT   3

#define PCINT19_DDR   DDRD
#define PCINT19_PORT  PORTD
#define PCINT19_PIN   PIND
#define PCINT19_BIT   3

#define PSCIN1_DDR   DDRC
#define PSCIN1_PORT  PORTC
#define PSCIN1_PIN   PINC
#define PSCIN1_BIT   1

#define OC1B_DDR   DDRC
#define OC1B_PORT  PORTC
#define OC1B_PIN   PINC
#define OC1B_BIT   1

#define SS_A_DDR   DDRC
#define SS_A_PORT  PORTC
#define SS_A_PIN   PINC
#define SS_A_BIT   1

#define PCINT9_DDR   DDRC
#define PCINT9_PORT  PORTC
#define PCINT9_PIN   PINC
#define PCINT9_BIT   1

#define T0_DDR   DDRC
#define T0_PORT  PORTC
#define T0_PIN   PINC
#define T0_BIT   2

#define TXCAN_DDR   DDRC
#define TXCAN_PORT  PORTC
#define TXCAN_PIN   PINC
#define TXCAN_BIT   2

#define PCINT10_DDR   DDRC
#define PCINT10_PORT  PORTC
#define PCINT10_PIN   PINC
#define PCINT10_BIT   2

#define RXCAN_DDR   DDRC
#define RXCAN_PORT  PORTC
#define RXCAN_PIN   PINC
#define RXCAN_BIT   3

#define ICP1B_DDR   DDRC
#define ICP1B_PORT  PORTC
#define ICP1B_PIN   PINC
#define ICP1B_BIT   3

#define PCINT11_DDR   DDRC
#define PCINT11_PORT  PORTC
#define PCINT11_PIN   PINC
#define PCINT11_BIT   3

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   0

#define PSCOUT2A_DDR   DDRB
#define PSCOUT2A_PORT  PORTB
#define PSCOUT2A_PIN   PINB
#define PSCOUT2A_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   1

#define PSCOUT2B_DDR   DDRB
#define PSCOUT2B_PORT  PORTB
#define PSCOUT2B_PIN   PINB
#define PSCOUT2B_BIT   1

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   1

#define OC0B_DDR   DDRE
#define OC0B_PORT  PORTE
#define OC0B_PIN   PINE
#define OC0B_BIT   1

#define PCINT25_DDR   DDRE
#define PCINT25_PORT  PORTE
#define PCINT25_PIN   PINE
#define PCINT25_BIT   1

#define ADC0_DDR   DDRE
#define ADC0_PORT  PORTE
#define ADC0_PIN   PINE
#define ADC0_BIT   2

#define PCINT26_DDR   DDRE
#define PCINT26_PORT  PORTE
#define PCINT26_PIN   PINE
#define PCINT26_BIT   2

#define ADC1_DDR   DDRD
#define ADC1_PORT  PORTD
#define ADC1_PIN   PIND
#define ADC1_BIT   4

#define RXD_DDR   DDRD
#define RXD_PORT  PORTD
#define RXD_PIN   PIND
#define RXD_BIT   4

#define RXLIN_DDR   DDRD
#define RXLIN_PORT  PORTD
#define RXLIN_PIN   PIND
#define RXLIN_BIT   4

#define ICP1A_DDR   DDRD
#define ICP1A_PORT  PORTD
#define ICP1A_PIN   PIND
#define ICP1A_BIT   4

#define SCK_A_DDR   DDRD
#define SCK_A_PORT  PORTD
#define SCK_A_PIN   PIND
#define SCK_A_BIT   4

#define PCINT20_DDR   DDRD
#define PCINT20_PORT  PORTD
#define PCINT20_PIN   PIND
#define PCINT20_BIT   4

#define ADC2_DDR   DDRD
#define ADC2_PORT  PORTD
#define ADC2_PIN   PIND
#define ADC2_BIT   5

#define ACMP2_DDR   DDRD
#define ACMP2_PORT  PORTD
#define ACMP2_PIN   PIND
#define ACMP2_BIT   5

#define PCINT21_DDR   DDRD
#define PCINT21_PORT  PORTD
#define PCINT21_PIN   PIND
#define PCINT21_BIT   5

#define ADC3_DDR   DDRD
#define ADC3_PORT  PORTD
#define ADC3_PIN   PIND
#define ADC3_BIT   6

#define ACMPN2_DDR   DDRD
#define ACMPN2_PORT  PORTD
#define ACMPN2_PIN   PIND
#define ACMPN2_BIT   6

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   6

#define PCINT22_DDR   DDRD
#define PCINT22_PORT  PORTD
#define PCINT22_PIN   PIND
#define PCINT22_BIT   6

#define ACMP0_DDR   DDRD
#define ACMP0_PORT  PORTD
#define ACMP0_PIN   PIND
#define ACMP0_BIT   7

#define PCINT23_DDR   DDRD
#define PCINT23_PORT  PORTD
#define PCINT23_PIN   PIND
#define PCINT23_BIT   7

#define ADC5_DDR   DDRB
#define ADC5_PORT  PORTB
#define ADC5_PIN   PINB
#define ADC5_BIT   2

#define INT1_DDR   DDRB
#define INT1_PORT  PORTB
#define INT1_PIN   PINB
#define INT1_BIT   2

#define ACMPN0_DDR   DDRB
#define ACMPN0_PORT  PORTB
#define ACMPN0_PIN   PINB
#define ACMPN0_BIT   2

#define PCINT2_DDR   DDRB
#define PCINT2_PORT  PORTB
#define PCINT2_PIN   PINB
#define PCINT2_BIT   2

#define ADC8_DDR   DDRC
#define ADC8_PORT  PORTC
#define ADC8_PIN   PINC
#define ADC8_BIT   4

#define AMP1_N_DDR   DDRC
#define AMP1_N_PORT  PORTC
#define AMP1_N_PIN   PINC
#define AMP1_N_BIT   4

#define ACMPN3_DDR   DDRC
#define ACMPN3_PORT  PORTC
#define ACMPN3_PIN   PINC
#define ACMPN3_BIT   4

#define PCINT12_DDR   DDRC
#define PCINT12_PORT  PORTC
#define PCINT12_PIN   PINC
#define PCINT12_BIT   4

#define ADC9_DDR   DDRC
#define ADC9_PORT  PORTC
#define ADC9_PIN   PINC
#define ADC9_BIT   5

#define AMP1_P_DDR   DDRC
#define AMP1_P_PORT  PORTC
#define AMP1_P_PIN   PINC
#define AMP1_P_BIT   5

#define ACMP3_DDR   DDRC
#define ACMP3_PORT  PORTC
#define ACMP3_PIN   PINC
#define ACMP3_BIT   5

#define PCINT13_DDR   DDRC
#define PCINT13_PORT  PORTC
#define PCINT13_PIN   PINC
#define PCINT13_BIT   5

#define ADC10_DDR   DDRC
#define ADC10_PORT  PORTC
#define ADC10_PIN   PINC
#define ADC10_BIT   6

#define ACMP1_DDR   DDRC
#define ACMP1_PORT  PORTC
#define ACMP1_PIN   PINC
#define ACMP1_BIT   6

#define PCINT14_DDR   DDRC
#define PCINT14_PORT  PORTC
#define PCINT14_PIN   PINC
#define PCINT14_BIT   6

#define AMP0_N_DDR   DDRB
#define AMP0_N_PORT  PORTB
#define AMP0_N_PIN   PINB
#define AMP0_N_BIT   3

#define PCINT3_DDR   DDRB
#define PCINT3_PORT  PORTB
#define PCINT3_PIN   PINB
#define PCINT3_BIT   3

#define AMP0_P_DDR   DDRB
#define AMP0_P_PORT  PORTB
#define AMP0_P_PIN   PINB
#define AMP0_P_BIT   4

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define D2A_DDR   DDRC
#define D2A_PORT  PORTC
#define D2A_PIN   PINC
#define D2A_BIT   7

#define AMP2_P_DDR   DDRC
#define AMP2_P_PORT  PORTC
#define AMP2_P_PIN   PINC
#define AMP2_P_BIT   7

#define PCINT15_DDR   DDRC
#define PCINT15_PORT  PORTC
#define PCINT15_PIN   PINC
#define PCINT15_BIT   7

#define ADC6_DDR   DDRB
#define ADC6_PORT  PORTB
#define ADC6_PIN   PINB
#define ADC6_BIT   5

#define INT2_DDR   DDRB
#define INT2_PORT  PORTB
#define INT2_PIN   PINB
#define INT2_BIT   5

#define ACMPN1_DDR   DDRB
#define ACMPN1_PORT  PORTB
#define ACMPN1_PIN   PINB
#define ACMPN1_BIT   5

#define AMP2_N_DDR   DDRB
#define AMP2_N_PORT  PORTB
#define AMP2_N_PIN   PINB
#define AMP2_N_BIT   5

#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define ADC7_DDR   DDRB
#define ADC7_PORT  PORTB
#define ADC7_PIN   PINB
#define ADC7_BIT   6

#define PSCOUT1B_DDR   DDRB
#define PSCOUT1B_PORT  PORTB
#define PSCOUT1B_PIN   PINB
#define PSCOUT1B_BIT   6

#define PCINT6_DDR   DDRB
#define PCINT6_PORT  PORTB
#define PCINT6_PIN   PINB
#define PCINT6_BIT   6

#define ADC4_DDR   DDRB
#define ADC4_PORT  PORTB
#define ADC4_PIN   PINB
#define ADC4_BIT   7

#define PSCOUT0B_DDR   DDRB
#define PSCOUT0B_PORT  PORTB
#define PSCOUT0B_PIN   PINB
#define PSCOUT0B_BIT   7

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   7

#define PCINT7_DDR   DDRB
#define PCINT7_PORT  PORTB
#define PCINT7_PIN   PINB
#define PCINT7_BIT   7

#define PSCOUT0A_DDR   DDRD
#define PSCOUT0A_PORT  PORTD
#define PSCOUT0A_PIN   PIND
#define PSCOUT0A_BIT   0

#define PCINT16_DDR   DDRD
#define PCINT16_PORT  PORTD
#define PCINT16_PIN   PIND
#define PCINT16_BIT   0

#define INT3_DDR   DDRC
#define INT3_PORT  PORTC
#define INT3_PIN   PINC
#define INT3_BIT   0

#define PSCOUT1A_DDR   DDRC
#define PSCOUT1A_PORT  PORTC
#define PSCOUT1A_PIN   PINC
#define PSCOUT1A_BIT   0

#define PCINT8_DDR   DDRC
#define PCINT8_PORT  PORTC
#define PCINT8_PIN   PINC
#define PCINT8_BIT   0

#define OCD_DDR   DDRE
#define OCD_PORT  PORTE
#define OCD_PIN   PINE
#define OCD_BIT   0

#define PCINT24_DDR   DDRE
#define PCINT24_PORT  PORTE
#define PCINT24_PIN   PINE
#define PCINT24_BIT   0

#define PSCIN0_DDR   DDRD
#define PSCIN0_PORT  PORTD
#define PSCIN0_PIN   PIND
#define PSCIN0_BIT   1

#define CLK0_DDR   DDRD
#define CLK0_PORT  PORTD
#define CLK0_PIN   PIND
#define CLK0_BIT   1

#define PCINT17_DDR   DDRD
#define PCINT17_PORT  PORTD
#define PCINT17_PIN   PIND
#define PCINT17_BIT   1

#endif /* _AVR_PIN_ATMEGA16M1_H_ */

