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

/* avr/../io_pin/io90pwm216_pin.h - definitions for AT90PWM216 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/io90pwm216_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_AT90PWM216_H_
#define _AVR_PIN_AT90PWM216_H_ 1


/* Device Pin Definitions */
#define PSCOUT00_DDR   DDRD
#define PSCOUT00_PORT  PORTD
#define PSCOUT00_PIN   PIND
#define PSCOUT00_BIT   0

#define XCK_DDR   DDRD
#define XCK_PORT  PORTD
#define XCK_PIN   PIND
#define XCK_BIT   0

#define SSA_DDR   DDRD
#define SSA_PORT  PORTD
#define SSA_PIN   PIND
#define SSA_BIT   0

#define OCD_DDR   DDRE
#define OCD_PORT  PORTE
#define OCD_PIN   PINE
#define OCD_BIT   0

#define PSCIN0_DDR   DDRD
#define PSCIN0_PORT  PORTD
#define PSCIN0_PIN   PIND
#define PSCIN0_BIT   1

#define CLK0_DDR   DDRD
#define CLK0_PORT  PORTD
#define CLK0_PIN   PIND
#define CLK0_BIT   1

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

#define TXD_DDR   DDRD
#define TXD_PORT  PORTD
#define TXD_PIN   PIND
#define TXD_BIT   3

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

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   0

#define PSCOUT20_DDR   DDRB
#define PSCOUT20_PORT  PORTB
#define PSCOUT20_PIN   PINB
#define PSCOUT20_BIT   0

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   1

#define PSCOUT21_DDR   DDRB
#define PSCOUT21_PORT  PORTB
#define PSCOUT21_PIN   PINB
#define PSCOUT21_BIT   1

#define OC0B_DDR   DDRE
#define OC0B_PORT  PORTE
#define OC0B_PIN   PINE
#define OC0B_BIT   1

#define ADC0_DDR   DDRE
#define ADC0_PORT  PORTE
#define ADC0_PIN   PINE
#define ADC0_BIT   2

#define ADC1_DDR   DDRD
#define ADC1_PORT  PORTD
#define ADC1_PIN   PIND
#define ADC1_BIT   4

#define RXD_DDR   DDRD
#define RXD_PORT  PORTD
#define RXD_PIN   PIND
#define RXD_BIT   4

#define ICP1_DDR   DDRD
#define ICP1_PORT  PORTD
#define ICP1_PIN   PIND
#define ICP1_BIT   4

#define SCK_A_DDR   DDRD
#define SCK_A_PORT  PORTD
#define SCK_A_PIN   PIND
#define SCK_A_BIT   4

#define ADC2_DDR   DDRD
#define ADC2_PORT  PORTD
#define ADC2_PIN   PIND
#define ADC2_BIT   5

#define ACMP2_DDR   DDRD
#define ACMP2_PORT  PORTD
#define ACMP2_PIN   PIND
#define ACMP2_BIT   5

#define ADC3_DDR   DDRD
#define ADC3_PORT  PORTD
#define ADC3_PIN   PIND
#define ADC3_BIT   6

#define ACMPM_DDR   DDRD
#define ACMPM_PORT  PORTD
#define ACMPM_PIN   PIND
#define ACMPM_BIT   6

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   6

#define ACMP0_DDR   DDRD
#define ACMP0_PORT  PORTD
#define ACMP0_PIN   PIND
#define ACMP0_BIT   7

#define ADC5_DDR   DDRB
#define ADC5_PORT  PORTB
#define ADC5_PIN   PINB
#define ADC5_BIT   2

#define INT1_DDR   DDRB
#define INT1_PORT  PORTB
#define INT1_PIN   PINB
#define INT1_BIT   2

#define AMP0_N_DDR   DDRB
#define AMP0_N_PORT  PORTB
#define AMP0_N_PIN   PINB
#define AMP0_N_BIT   3

#define AMP0_P_DDR   DDRB
#define AMP0_P_PORT  PORTB
#define AMP0_P_PIN   PINB
#define AMP0_P_BIT   4

#define ADC6_DDR   DDRB
#define ADC6_PORT  PORTB
#define ADC6_PIN   PINB
#define ADC6_BIT   5

#define INT2_DDR   DDRB
#define INT2_PORT  PORTB
#define INT2_PIN   PINB
#define INT2_BIT   5

#define ADC7_DDR   DDRB
#define ADC7_PORT  PORTB
#define ADC7_PIN   PINB
#define ADC7_BIT   6

#define PSCOUT11_DDR   DDRB
#define PSCOUT11_PORT  PORTB
#define PSCOUT11_PIN   PINB
#define PSCOUT11_BIT   6

#define ICP1B_DDR   DDRB
#define ICP1B_PORT  PORTB
#define ICP1B_PIN   PINB
#define ICP1B_BIT   6

#define ADC4_DDR   DDRB
#define ADC4_PORT  PORTB
#define ADC4_PIN   PINB
#define ADC4_BIT   7

#define PSCOUT01_DDR   DDRB
#define PSCOUT01_PORT  PORTB
#define PSCOUT01_PIN   PINB
#define PSCOUT01_BIT   7

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   7

#endif /* _AVR_PIN_AT90PWM216_H_ */

