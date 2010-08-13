/* Copyright (c) 2010 Frédéric Nadeau
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

#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>

#include <io_pin/io_pin.h>

#include "tmrcnt2.h"

void tmrcnt2_init(tmrcnt2_wgm_t wgm, tmrcnt2_clk_select_t prescale)
{
  // Force timer to stop
  TCCR2B &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));

  switch (wgm)
    {
    case tmrcnt2_wgm_normal_ff_imd_max:
      TCCR2B &= ~(1 << WGM22);
      TCCR2A &= ~((1 << WGM21) | (1 << WGM20));
      break;

    case tmrcnt2_wgm_pwm_phase_correct_ff_top_btm:
      TCCR2B &= ~(1 << WGM22);
      TCCR2A &= ~(1 << WGM21);
      TCCR2A |=  (1 << WGM20);
      break;

    case tmrcnt2_wgm_ctc_ocra_imd_max:
      TCCR2B &= ~(1 << WGM22);
      TCCR2A |=  (1 << WGM21);
      TCCR2A &= ~(1 << WGM20);
      break;

    case tmrcnt2_wgm_fast_pwm_ff_top_max:
      TCCR2B &= ~(1 << WGM22);
      TCCR2A |=  (1 << WGM21);
      TCCR2A |=  (1 << WGM20);
      break;

    case tmrcnt2_wgm_pwm_phase_correct_ocra_top_btm:
      TCCR2B |=  (1 << WGM22);
      TCCR2A &= ~(1 << WGM21);
      TCCR2A |=  (1 << WGM20);
      break;

    case tmrcnt2_wgm_fast_pwm_ocra_top_top:
      TCCR2B |= (1 << WGM22);
      TCCR2A |= ((1 << WGM21) | (1 << WGM20));
      break;

    default:
      break;
    }

#if !(CS22 == (CS20 + 2) && CS21 == (CS20 + 1))
#   error "tmrcnt2_init needs to be rewritten for this device"
#endif
  TCCR2B |= (prescale << CS20);

}

void tmrcnt2_set_clk_source(tmrcnt2_clk_src_t source)
{
    ASSR &= ~((1 << EXCLK) | (1 << AS2));

    switch (source)
    {
    case tmrcnt2_clk_src_clkIO:
        break;

    case tmrcnt2_clk_src_ExtClk:
        ASSR |= (1 << EXCLK);
        break;

    case tmrcnt2_clk_src_ExtOsc:
        ASSR |= (1 << EXCLK) | (1 << AS2);
        break;

    default:
        break;
    }
}

void tmrcnt2_set_ouput_compare_pin_mode (tmrcnt2_ouput_compare_channel_t channel, uint8_t mode)
{
    switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
#if !(COM2A1 == (COM2A0 + 1))
#   error "tmrcnt2_init needs to be rewritten for this device"
#endif
        TCCR2A &= ~((1 << COM2A1) | (1 << COM2A0));
        TCCR2A |= (mode << COM2A0);
        break;

    case tmrcnt2_ouput_compare_channel_b:
#if !(COM2B1 == (COM2B0 + 1))
#   error "tmrcnt2_init needs to be rewritten for this device"
#endif
        TCCR2A &= ~((1 << COM2B1) | (1 << COM2B0));
        TCCR2A |= (mode << COM2B0);
        break;

    default:
        break;
    }
}


void tmrcnt2_set_ouput_compare_pin_as_ouput (tmrcnt2_ouput_compare_channel_t channel, _Bool isOutput)
{
    switch (channel)
    {
        case tmrcnt2_ouput_compare_channel_a:
            if(isOutput)
            {
                OC2A_DDR |= _BV(OC2A_BIT);
            }
            else
            {
                OC2A_DDR &= ~_BV(OC2A_BIT);
            }
        break;

        case tmrcnt2_ouput_compare_channel_b:
            if(isOutput)
            {
                OC2B_DDR |= _BV(OC2B_BIT);
            }
            else
            {
                OC2B_DDR &= ~_BV(OC2B_BIT);
            }
        break;

        default:
        break;
    }
}

void tmrcnt2_force_ouput_compare (tmrcnt2_ouput_compare_channel_t channel)
{
  switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
      TCCR2B |= (1 << FOC2A);
      break;

    case tmrcnt2_ouput_compare_channel_b:
      TCCR2B |= (1 << FOC2B);
      break;

    default:
      break;
    }
}

uint8_t tmrcnt2_get_timer(void)
{
    return TCNT2;
}

void tmrcnt2_set_timer(uint8_t value)
{
    TCNT2 = value;
}

uint8_t tmrcnt2_get_output_compare(tmrcnt2_ouput_compare_channel_t channel)
{
    uint8_t retVal = 0;

    switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
        retVal = OCR2A;
        break;

        case tmrcnt2_ouput_compare_channel_b:
        retVal = OCR2B;
        break;

    default:
        break;
    }
    return retVal;
}

void tmrcnt2_set_output_compare(tmrcnt2_ouput_compare_channel_t channel,
        uint8_t value)
{
    switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
        OCR2A = value;
        break;

        case tmrcnt2_ouput_compare_channel_b:
        OCR2B = value;
        break;

    default:
        break;
    }
}

void tmrcnt2_output_compare_match_int_enable(
        tmrcnt2_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
        TIMSK2 |= _BV(OCIE2A);
        break;

        case tmrcnt2_ouput_compare_channel_b:
        TIMSK2 |= _BV(OCIE2B);
        break;

    default:
        break;
    }
}

void tmrcnt2_output_compare_match_int_disable(
        tmrcnt2_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
        TIMSK2 &= ~_BV(OCIE2A);
        break;

        case tmrcnt2_ouput_compare_channel_b:
        TIMSK2 &= ~_BV(OCIE2B);
        break;

    default:
        break;
    }
}

_Bool tmrcnt2_is_output_compare_match_int_flag_set(tmrcnt2_ouput_compare_channel_t channel)
{
    _Bool retVal = false;
    switch (channel)
    {
    case tmrcnt2_ouput_compare_channel_a:
        retVal = bit_is_set(TIFR2,OCF2A) == 0 ? false:true;
        break;

        case tmrcnt2_ouput_compare_channel_b:
            retVal = bit_is_set(TIFR2,OCF2B) == 0 ? false:true;
        break;

    default:
        break;
    }
    return retVal;
}

void tmrcnt2_enable_overflow_int(void)
{
    TIMSK2 |= _BV(TOIE2);
}

void tmrcnt2_disable_overflow_int(void)
{
    TIMSK2 &= ~_BV(TOIE2);
}

_Bool tmrcnt2_is_overflow_int_flag_set(void)
{
    return bit_is_set(TIFR2,TOV2) == 0 ? false:true;
}


