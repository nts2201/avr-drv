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

/* avr/../io_pin/iotn24a_pin.h - definitions for ATtiny24A */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/iotn24a_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_ATTINY24A_H_
#define _AVR_PIN_ATTINY24A_H_ 1


/* Device Pin Definitions */
#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   4

#define USCK_DDR   DDRA
#define USCK_PORT  PORTA
#define USCK_PIN   PINA
#define USCK_BIT   4

#define SCL_DDR   DDRA
#define SCL_PORT  PORTA
#define SCL_PIN   PINA
#define SCL_BIT   4

#define PCINT4_DDR   DDRA
#define PCINT4_PORT  PORTA
#define PCINT4_PIN   PINA
#define PCINT4_BIT   4

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   3

#define T0_DDR   DDRA
#define T0_PORT  PORTA
#define T0_PIN   PINA
#define T0_BIT   3

#define PCINT3_DDR   DDRA
#define PCINT3_PORT  PORTA
#define PCINT3_PIN   PINA
#define PCINT3_BIT   3

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define AIN1_DDR   DDRA
#define AIN1_PORT  PORTA
#define AIN1_PIN   PINA
#define AIN1_BIT   2

#define PCINT2_DDR   DDRA
#define PCINT2_PORT  PORTA
#define PCINT2_PIN   PINA
#define PCINT2_BIT   2

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define AIN0_DDR   DDRA
#define AIN0_PORT  PORTA
#define AIN0_PIN   PINA
#define AIN0_BIT   1

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

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define INT0_DDR   DDRB
#define INT0_PORT  PORTB
#define INT0_PIN   PINB
#define INT0_BIT   2

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   2

#define CKOUT_DDR   DDRB
#define CKOUT_PORT  PORTB
#define CKOUT_PIN   PINB
#define CKOUT_BIT   2

#define PCINT7_DDR   DDRA
#define PCINT7_PORT  PORTA
#define PCINT7_PIN   PINA
#define PCINT7_BIT   7

#define ICP1_DDR   DDRA
#define ICP1_PORT  PORTA
#define ICP1_PIN   PINA
#define ICP1_BIT   7

#define OC0B_DDR   DDRA
#define OC0B_PORT  PORTA
#define OC0B_PIN   PINA
#define OC0B_BIT   7

#define ADC7_DDR   DDRA
#define ADC7_PORT  PORTA
#define ADC7_PIN   PINA
#define ADC7_BIT   7

#define PCINT6_DDR   DDRA
#define PCINT6_PORT  PORTA
#define PCINT6_PIN   PINA
#define PCINT6_BIT   6

#define OC1A_DDR   DDRA
#define OC1A_PORT  PORTA
#define OC1A_PIN   PINA
#define OC1A_BIT   6

#define DI_DDR   DDRA
#define DI_PORT  PORTA
#define DI_PIN   PINA
#define DI_BIT   6

#define SDA_DDR   DDRA
#define SDA_PORT  PORTA
#define SDA_PIN   PINA
#define SDA_BIT   6

#define MOSI_DDR   DDRA
#define MOSI_PORT  PORTA
#define MOSI_PIN   PINA
#define MOSI_BIT   6

#define ADC6_DDR   DDRA
#define ADC6_PORT  PORTA
#define ADC6_PIN   PINA
#define ADC6_BIT   6

#define ADC5_DDR   DDRA
#define ADC5_PORT  PORTA
#define ADC5_PIN   PINA
#define ADC5_BIT   5

#define DO_DDR   DDRA
#define DO_PORT  PORTA
#define DO_PIN   PINA
#define DO_BIT   5

#define MISO_DDR   DDRA
#define MISO_PORT  PORTA
#define MISO_PIN   PINA
#define MISO_BIT   5

#define OC1B_DDR   DDRA
#define OC1B_PORT  PORTA
#define OC1B_PIN   PINA
#define OC1B_BIT   5

#define PCINT5_DDR   DDRA
#define PCINT5_PORT  PORTA
#define PCINT5_PIN   PINA
#define PCINT5_BIT   5

#endif /* _AVR_PIN_ATTINY24A_H_ */

