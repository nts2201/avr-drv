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

/* avr/../io_pin/iotn13a_pin.h - definitions for ATtiny13A */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn13a_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATTINY13A_H_
#define _AVR_PIN_ATTINY13A_H_ 1


/* Device Pin Definitions */
#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define ADC0_DDR   DDRB
#define ADC0_PORT  PORTB
#define ADC0_PIN   PINB
#define ADC0_BIT   5

#define PCINT3_DDR   DDRB
#define PCINT3_PORT  PORTB
#define PCINT3_PIN   PINB
#define PCINT3_BIT   3

#define ADC3_DDR   DDRB
#define ADC3_PORT  PORTB
#define ADC3_PIN   PINB
#define ADC3_BIT   3

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define ADC2_DDR   DDRB
#define ADC2_PORT  PORTB
#define ADC2_PIN   PINB
#define ADC2_BIT   4

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   0

#define AIN0_DDR   DDRB
#define AIN0_PORT  PORTB
#define AIN0_PIN   PINB
#define AIN0_BIT   0

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   0

#define TXD_DDR   DDRB
#define TXD_PORT  PORTB
#define TXD_PIN   PINB
#define TXD_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   1

#define INT0_DDR   DDRB
#define INT0_PORT  PORTB
#define INT0_PIN   PINB
#define INT0_BIT   1

#define AIN1_DDR   DDRB
#define AIN1_PORT  PORTB
#define AIN1_PIN   PINB
#define AIN1_BIT   1

#define OC0B_DDR   DDRB
#define OC0B_PORT  PORTB
#define OC0B_PIN   PINB
#define OC0B_BIT   1

#define INT0_DDR   DDRB
#define INT0_PORT  PORTB
#define INT0_PIN   PINB
#define INT0_BIT   1

#define RXD_DDR   DDRB
#define RXD_PORT  PORTB
#define RXD_PIN   PINB
#define RXD_BIT   1

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   1

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   2

#define ADC1_DDR   DDRB
#define ADC1_PORT  PORTB
#define ADC1_PIN   PINB
#define ADC1_BIT   2

#define T0_DDR   DDRB
#define T0_PORT  PORTB
#define T0_PIN   PINB
#define T0_BIT   2

#define PCINT2_DDR   DDRB
#define PCINT2_PORT  PORTB
#define PCINT2_PIN   PINB
#define PCINT2_BIT   2

#endif /* _AVR_PIN_ATTINY13A_H_ */

