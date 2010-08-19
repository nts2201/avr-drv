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

/* avr/../io_pin/iotn26_pin.h - definitions for ATtiny26 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn26_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATTINY26_H_
#define _AVR_PIN_ATTINY26_H_ 1


/* Device Pin Definitions */
#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   0

#define DI_DDR   DDRB
#define DI_PORT  PORTB
#define DI_PIN   PINB
#define DI_BIT   0

#define SDA_DDR   DDRB
#define SDA_PORT  PORTB
#define SDA_PIN   PINB
#define SDA_BIT   0

#define INV_OC1A_DDR   DDRB
#define INV_OC1A_PORT  PORTB
#define INV_OC1A_PIN   PINB
#define INV_OC1A_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   1

#define DO_DDR   DDRB
#define DO_PORT  PORTB
#define DO_PIN   PINB
#define DO_BIT   1

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   1

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   1

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   2

#define SCL_DDR   DDRB
#define SCL_PORT  PORTB
#define SCL_PIN   PINB
#define SCL_BIT   2

#define INV_OC1B_DDR   DDRB
#define INV_OC1B_PORT  PORTB
#define INV_OC1B_PIN   PINB
#define INV_OC1B_BIT   2

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   2

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   3

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   3

#define ADC7_DDR   DDRB
#define ADC7_PORT  PORTB
#define ADC7_PIN   PINB
#define ADC7_BIT   4

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   4

#define ADC8_DDR   DDRB
#define ADC8_PORT  PORTB
#define ADC8_PIN   PINB
#define ADC8_BIT   5

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   5

#define ADC9_DDR   DDRB
#define ADC9_PORT  PORTB
#define ADC9_PIN   PINB
#define ADC9_BIT   6

#define INT0_DDR   DDRB
#define INT0_PORT  PORTB
#define INT0_PIN   PINB
#define INT0_BIT   6

#define T0_DDR   DDRB
#define T0_PORT  PORTB
#define T0_PIN   PINB
#define T0_BIT   6

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   6

#define ADC10_DDR   DDRB
#define ADC10_PORT  PORTB
#define ADC10_PIN   PINB
#define ADC10_BIT   7

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   7

#define ADC6_DDR   DDRA
#define ADC6_PORT  PORTA
#define ADC6_PIN   PINA
#define ADC6_BIT   7

#define AIN1_DDR   DDRA
#define AIN1_PORT  PORTA
#define AIN1_PIN   PINA
#define AIN1_BIT   7

#define ADC5_DDR   DDRA
#define ADC5_PORT  PORTA
#define ADC5_PIN   PINA
#define ADC5_BIT   6

#define AIN0_DDR   DDRA
#define AIN0_PORT  PORTA
#define AIN0_PIN   PINA
#define AIN0_BIT   6

#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   5

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   4

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define ADC0_DDR   DDRA
#define ADC0_PORT  PORTA
#define ADC0_PIN   PINA
#define ADC0_BIT   0

#endif /* _AVR_PIN_ATTINY26_H_ */

