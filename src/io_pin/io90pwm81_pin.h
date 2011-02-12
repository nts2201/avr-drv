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

/* avr/../io_pin/io90pwm81_pin.h - definitions for AT90PWM81 */

/* This file should only be included from <io_pin/io_pin.h>, never directly. */

#ifndef _AVR_IO_PIN_H_
#  error "Include <io_pin/io_pin.h> instead of this file."
#endif

#ifndef _AVR_IO_PINXXX_H_
#  define _AVR_IO_PINXXX_H_ "../io_pin/io90pwm81_pin.h"
#else
#  error "Attempt to include more than one <io_pin/io_pinXXX.h> file."
#endif


#ifndef _AVR_PIN_AT90PWM81_H_
#define _AVR_PIN_AT90PWM81_H_ 1


/* Device Pin Definitions */
#define AMP0_N_DDR   DDRD
#define AMP0_N_PORT  PORTD
#define AMP0_N_PIN   PIND
#define AMP0_N_BIT   5

#define ADC7_DDR   DDRD
#define ADC7_PORT  PORTD
#define ADC7_PIN   PIND
#define ADC7_BIT   5

#define AMP0_P_DDR   DDRD
#define AMP0_P_PORT  PORTD
#define AMP0_P_PIN   PIND
#define AMP0_P_BIT   6

#define ADC8_DDR   DDRB
#define ADC8_PORT  PORTB
#define ADC8_PIN   PINB
#define ADC8_BIT   6

#define ACMP2_DDR   DDRB
#define ACMP2_PORT  PORTB
#define ACMP2_PIN   PINB
#define ACMP2_BIT   6

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   6

#define ADC10_DDR   DDRD
#define ADC10_PORT  PORTD
#define ADC10_PIN   PIND
#define ADC10_BIT   7

#define PSCIN0A_DDR   DDRD
#define PSCIN0A_PORT  PORTD
#define PSCIN0A_PIN   PIND
#define PSCIN0A_BIT   7

#define ADC9_DDR   DDRB
#define ADC9_PORT  PORTB
#define ADC9_PIN   PINB
#define ADC9_BIT   7

#define ICP1_DDR   DDRB
#define ICP1_PORT  PORTB
#define ICP1_PIN   PINB
#define ICP1_BIT   7

#define PSCOUT22_DDR   DDRB
#define PSCOUT22_PORT  PORTB
#define PSCOUT22_PIN   PINB
#define PSCOUT22_BIT   7

#define ACMP2_OUT_DDR   DDRB
#define ACMP2_OUT_PORT  PORTB
#define ACMP2_OUT_PIN   PINB
#define ACMP2_OUT_BIT   0

#define PSCOUT23_DDR   DDRB
#define PSCOUT23_PORT  PORTB
#define PSCOUT23_PIN   PINB
#define PSCOUT23_BIT   0

#define OCD_DDR   DDRE
#define OCD_PORT  PORTE
#define OCD_PIN   PINE
#define OCD_BIT   0

#define INT2_DDR   DDRE
#define INT2_PORT  PORTE
#define INT2_PIN   PINE
#define INT2_BIT   0

#endif /* _AVR_PIN_AT90PWM81_H_ */

