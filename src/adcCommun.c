/* Copyright (c) 2008-2010 Frédéric Nadeau
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided
   that the following conditions are met:

   1.Redistributions of source code must retain the above
   copyright notice, this list of conditions and the following
   disclaimer.

   2.Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   3.Neither the name of the AVR-DRV nor the names of its
   contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

/*! \file adcCommun.c
 \brief This file contains common code for ADC.

 This file contains common function for all supported ADC.
 This file may eventually get modified as more AVR device get supported.

 \author Frédéric Nadeau
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

#include "adcDef.h"

//Those devices uses ADCSR rather than ADCSRA
#if defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega163__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATtiny26__)
#   define ADCSRA ADCSR
#endif

void adc_enable(_Bool status)
{
    if (status != false)
    {
        ADCSRA |= _BV(ADEN);
    }
    else
    {
        ADCSRA &= ~_BV(ADEN);
    }
}

void adc_interrupt_enable(_Bool intEn)
{
    if (intEn != false)
    {
        ADCSRA |= _BV(ADIE);
    }
    else
    {
        ADCSRA &= ~_BV(ADIE);
    }
}

#if !defined(__AVR_ATtiny5__) \
&& !defined(__AVR_ATtiny10__) \
&& !defined(__AVR_ATmega103__)
void adc_left_adjust(_Bool adjust)
{
    if (adjust != false)
    {
        ADMUX |= _BV(ADLAR);
    }
    else
    {
        ADMUX &= ~_BV(ADLAR);
    }
}
#endif

//This function assume that ADPS2 == (ADPS0 + 2) && ADPS1 == (ADPS0 + 1)
//It seems it is always the case
#if !(ADPS2 == (ADPS0 + 2) && ADPS1 == (ADPS0 + 1))
#	error "adc_prescaler_selection needs to be rewritten for this device"
#endif
void adc_prescaler_selection(adc_prescaler_t prescaler)
{
    ADCSRA &= ~(_BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0));
    ADCSRA |= prescaler << ADPS0;
}

//Device with 8bits ADC don't get 16bit read nor high byte read.
#if !defined(__AVR_ATtiny4__) \
&& !defined(__AVR_ATtiny5__) \
&& !defined(__AVR_ATtiny9__) \
&& !defined(__AVR_ATtiny10__)
uint16_t adc_read(void)
{
    return ADCW;
}

uint8_t adc_read_high(void)
{
    return ADCH;
}
#endif

uint8_t adc_read_low(void)
{
    return ADCL;
}

_Bool adcReadIntFlag(void)
{
    return (ADCSRA & _BV(ADIF)) == 0 ? false : true;
}

void adcClearIntFlag(void)
{
    //Write a logical 1 to clear the flag
    ADCSRA |= _BV(ADIF);
}

#if !defined(__AVR_ATmega103__)
#   if defined(REFS0) && defined(REFS1)
#       define ADC_REFS_MASK (_BV(REFS0) | _BV(REFS1))
#       define ADC_REFS0_IDX (REFS0)
#       if REFS1 != (REFS0 + 1)
#           error "REFS0 and REFS1 are not contiguous, device shall be coded separately"
#       endif
#   elif defined(REFS0)
#       define ADC_REFS_MASK (_BV(REFS0))
#       define ADC_REFS0_IDX (REFS0)
#   elif defined(REFS)
#       define ADC_REFS_MASK (_BV(REFS))
#       define ADC_REFS0_IDX (REFS)
#   else
#       error "Error finding REFS mask for your device"
#   endif


void adc_select_vref(adc_voltage_ref_t ref)
{
#   if defined(__AVR_ATtiny25__) \
        || defined(__AVR_ATtiny45__) \
        || defined(__AVR_ATtiny85__)
    ADMUX &= ~(ADC_REFS_MASK);
    ADMUX |= (ref & 0x03) << ADC_REFS0_IDX;
    if(ref & 0x04)
    {
        ADMUX |= _BV(REFS2);
    }
    else
    {
        ADMUX &= ~_BV(REFS2);
    }
#   elif defined(__AVR_ATtiny261__) \
        || defined(__AVR_ATtiny261A__) \
        || defined(__AVR_ATtiny461__) \
        || defined(__AVR_ATtiny461A__) \
        || defined(__AVR_ATtiny861__) \
        || defined(__AVR_ATtiny861A__)
    ADMUX &= ~(ADC_REFS_MASK);
    ADMUX |= (ref & 0x03) << ADC_REFS0_IDX;
    if(ref & 0x04)
    {
        ADCSRB |= _BV(REFS2);
    }
    else
    {
        ADCSRB &= ~_BV(REFS2);
    }
#   elif defined (__AVR_ATmega16M1__) \
        || defined (__AVR_ATmega32C1__) \
        || defined (__AVR_ATmega32M1__) \
        || defined (__AVR_ATmega64C1__) \
        || defined (__AVR_ATmega64M1__)
    ADMUX &= ~(ADC_REFS_MASK);
    ADMUX |= (ref & 0x03) << ADC_REFS0_IDX;
    ADCSRB &= ~_BV(ISRCEN);
    if(ref & 0x04)
    {
        ADCSRB |= _BV(AREFEN);
    }
    else
    {
        ADCSRB &= ~_BV(AREFEN);
    }
#   elif defined (__AVR_ATtiny87__) \
        || defined (__AVR_ATtiny167__)
    ADMUX &= ~(ADC_REFS_MASK);
    ADMUX |= (ref & 0x03) << ADC_REFS0_IDX;
    if(ref & 0x04)
    {
        AMISCR |= _BV(AREFEN);
    }
    else
    {
        AMISCR &= ~_BV(AREFEN);
    }
#   else
    ADMUX &= ~(ADC_REFS_MASK);
    ADMUX |= ref << ADC_REFS0_IDX;
#   endif

}
#endif

void adc_start_conversion(void)
{
    ADCSRA |= _BV(ADSC);
}

