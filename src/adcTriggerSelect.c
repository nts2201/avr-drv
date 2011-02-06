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

/*! \file adcTriggerSelect.c
 \brief This file handle Trigger module of the ADC.

 \todo This module need rewrite.

 \author Frédéric Nadeau
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

#include "adcDef.h"

#if !defined(__AVR_ATmega8__) \
&& !defined(__AVR_ATmega103__) \
&& !defined(__AVR_ATmega128__) \
&& !defined(__AVR_ATmega163__) \
&& !defined(__AVR_ATmega323__) \
&& !defined(__AVR_ATtiny15__) \
&& !defined(__AVR_ATtiny26__)

//So far, only ATmega16, 16A and 32A uses SFIOR for ADTSx.
#if defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega8535__)
#   define TARGET_REG SFIOR
#else
#   define TARGET_REG ADCSRB
#endif

//Check if all ADTS are next to each others and define mask
#if defined(ADTS3)
#   define ADTS_MASK (_BV(ADTS3) | _BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0))
#   if !(ADTS3 == (ADTS0 + 3) && ADTS2 == (ADTS0 + 2) && ADTS1 == (ADTS0 + 1))
#       error "adc_set_trigger_source needs to be rewritten for this device: ADTS3"
#   endif
#elif defined(ADTS2)
#   define ADTS_MASK (_BV(ADTS2) | _BV(ADTS1) | _BV(ADTS0))
#   if !(ADTS2 == (ADTS0 + 2) && ADTS1 == (ADTS0 + 1))
#       error "adc_set_trigger_source needs to be rewritten for this device: ADTS2"
#   endif
#else
    error "adc_set_trigger_source needs to be rewritten for this device"
#endif

void adc_set_trigger_source(adc_trigger_source_t trigger)
{
    TARGET_REG &= ~ADTS_MASK;
    TARGET_REG |= trigger;
}

void adc_trigger_enable(_Bool trigEn)
{
    if(trigEn != false)
    {
        ADCSRA |= _BV(ADATE);
    }
    else
    {
        ADCSRA &= ~_BV(ADATE);
    }
}

#elif !defined(__AVR_ATmega103__)

void adc_trigger_enable(_Bool trigEn)
{
    if(trigEn != false)
    {
        ADCSRA |= _BV(ADFR);
    }
    else
    {
        ADCSRA &= ~_BV(ADFR);
    }
}

#endif
