/* Copyright (c) 2030 Frédéric Nadeau
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided
   that the following conditions are met:

   3.Redistributions of source code must retain the above
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

#include "tmrcnt3.h"

void tmrcnt3_init(tmrcnt3_wgm_t mode, tmrcnt3_clk_select_t prescale)
{
    // Force timer to stop
    TCCR3B &= ~(_BV(CS32) | _BV(CS31) | _BV(CS30));

    switch (mode)
    {
    case tmrcnt3_wgm_normal_ffff_imd_max:
        TCCR3B &= ~(_BV(WGM33) | _BV(WGM32));
        TCCR3A &= ~(_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_pwm_phase_correct_8bit_00ff_top_btm:
        TCCR3B &= ~(_BV(WGM33) | _BV(WGM32));
        TCCR3A &= ~_BV(WGM31);
        TCCR3A |= _BV(WGM30);
        break;

    case tmrcnt3_wgm_pwm_phase_correct_9bit_01ff_top_btm:
        TCCR3B &= ~(_BV(WGM33) | _BV(WGM32));
        TCCR3A |= _BV(WGM31);
        TCCR3A &= ~_BV(WGM30);
        break;

    case tmrcnt3_wgm_pwm_phase_correct_10bit_03ff_top_btm:
        TCCR3B &= ~(_BV(WGM33) | _BV(WGM32));
        TCCR3A |= (_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_ctc_ocr5a_imd_max:
        TCCR3B &= ~_BV(WGM33);
        TCCR3B |= _BV(WGM32);
        TCCR3A &= ~(_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_fast_pwm_8bit_00ff_btm_top:
        TCCR3B &= ~_BV(WGM33);
        TCCR3B |= _BV(WGM32);
        TCCR3A &= ~_BV(WGM31);
        TCCR3A |= _BV(WGM30);
        break;

    case tmrcnt3_wgm_fast_pwm_9bit_01ff_btm_top:
        TCCR3B &= ~_BV(WGM33);
        TCCR3B |= _BV(WGM32);
        TCCR3A |= _BV(WGM31);
        TCCR3A &= ~_BV(WGM30);
        break;

    case tmrcnt3_wgm_fast_pwm_10bit_03ff_btm_top:
        TCCR3B &= ~_BV(WGM33);
        TCCR3B |= _BV(WGM32);
        TCCR3A |= (_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_pwm_phase_freq_correct_icr5_btm_btm:
        TCCR3B |= _BV(WGM33);
        TCCR3B &= ~_BV(WGM32);
        TCCR3A &= ~(_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_pwm_phase_freq_correct_ocr5a_btm_btm:
        TCCR3B |= _BV(WGM33);
        TCCR3B &= ~_BV(WGM32);
        TCCR3A &= ~_BV(WGM31);
        TCCR3A |= _BV(WGM30);
        break;

    case tmrcnt3_wgm_pwm_phase_correct_icr5_top_btm:
        TCCR3B |= _BV(WGM33);
        TCCR3B &= ~_BV(WGM32);
        TCCR3A |= _BV(WGM31);
        TCCR3A &= ~_BV(WGM30);
        break;

    case tmrcnt3_wgm_pwm_phase_correct_ocr5a_top_btm:
        TCCR3B |= _BV(WGM33);
        TCCR3B &= ~_BV(WGM32);
        TCCR3A |= (_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_ctc_icr5_imd_max:
        TCCR3B |= (_BV(WGM33) | _BV(WGM32));
        TCCR3A &= ~(_BV(WGM31) | _BV(WGM30));
        break;

    case tmrcnt3_wgm_fast_pwm_icr5_top_top:
        TCCR3B |= (_BV(WGM33) | _BV(WGM32));
        TCCR3A |= _BV(WGM31);
        TCCR3A &= ~_BV(WGM30);
        break;

    case tmrcnt3_wgm_fast_pwm_ocr5a_top_top:
        TCCR3B |= (_BV(WGM33) | _BV(WGM32));
        TCCR3A |= (_BV(WGM31) | _BV(WGM30));
        break;

    default:
        break;
    }

#if !(CS32 == (CS30 + 2) && CS31 == (CS30 + 1))
#   error "tmrcnt3_init needs to be rewritten for this device"
#endif
    TCCR3B |= (prescale << CS30);
}

void tmrcnt3_set_ouput_compare_pin_mode(
        tmrcnt3_ouput_compare_channel_t channel, tmrcnt3_com_t mode)
{
    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        TCCR3A &= ~(_BV(COM3A1) | _BV(COM3A0));
        TCCR3A |= (mode << COM3A0);
        break;

    case tmrcnt3_ouput_compare_channel_b:
        TCCR3A &= ~(_BV(COM3B1) | _BV(COM3B0));
        TCCR3A |= (mode << COM3B0);
        break;

    case tmrcnt3_ouput_compare_channel_c:
        TCCR3A &= ~(_BV(COM3C1) | _BV(COM3C0));
        TCCR3A |= (mode << COM3C0);
        break;

    default:
        break;
    }
}

void tmrcnt3_set_ouput_compare_pin_as_ouput(
        tmrcnt3_ouput_compare_channel_t channel, _Bool isOutput)
{
    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        if (isOutput)
        {
            OC3A_DDR |= _BV(OC3A_BIT);
        }
        else
        {
            OC3A_DDR &= ~_BV(OC3A_BIT);
        }
        break;

    case tmrcnt3_ouput_compare_channel_b:
        if (isOutput)
        {
            OC3B_DDR |= _BV(OC3B_BIT);
        }
        else
        {
            OC3B_DDR &= ~_BV(OC3B_BIT);
        }
        break;

    case tmrcnt3_ouput_compare_channel_c:
        if (isOutput)
        {
            OC3C_DDR |= _BV(OC3C_BIT);
        }
        else
        {
            OC3C_DDR &= ~_BV(OC3C_BIT);
        }
        break;

    default:
        break;
    }
}

void tmrcnt3_force_ouput_compare(tmrcnt3_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        TCCR3C |= _BV(FOC3A);
        break;

    case tmrcnt3_ouput_compare_channel_b:
        TCCR3C |= _BV(FOC3B);
        break;

    case tmrcnt3_ouput_compare_channel_c:
        TCCR3C |= _BV(FOC3C);
        break;

    default:
        break;
    }
}

uint16_t tmrcnt3_get_timer(void)
{
    return TCNT3;
}

void tmrcnt3_set_timer(uint16_t value)
{
    TCNT3 = value;
}

uint16_t tmrcnt3_get_output_compare(tmrcnt3_ouput_compare_channel_t channel)
{
    uint16_t retVal;

    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        retVal = OCR3A;
        break;

    case tmrcnt3_ouput_compare_channel_b:
        retVal = OCR3B;
        break;

    case tmrcnt3_ouput_compare_channel_c:
        retVal = OCR3C;
        break;

    default:
        retVal = 0;
        break;
    }
    return retVal;
}

void tmrcnt3_set_output_compare(tmrcnt3_ouput_compare_channel_t channel,
        uint16_t value)
{
    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        OCR3A = value;
        break;

    case tmrcnt3_ouput_compare_channel_b:
        OCR3B = value;
        break;

    case tmrcnt3_ouput_compare_channel_c:
        OCR3C = value;
        break;

    default:
        break;
    }
}

uint16_t tmrcnt3_get_input_capture(void)
{
    return ICR3;
}

void tmrcnt3_input_compare_match_int_enable(void)
{
    TIMSK3 |= _BV(ICIE3);
}

void tmrcnt3_input_compare_match_int_disable(void)
{
    TIMSK3 &= ~_BV(ICIE3);
}

void tmrcnt3_output_compare_match_int_enable(
        tmrcnt3_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        TIMSK3 |= _BV(OCIE3A);
        break;

    case tmrcnt3_ouput_compare_channel_b:
        TIMSK3 |= _BV(OCIE3B);
        break;

    case tmrcnt3_ouput_compare_channel_c:
        TIMSK3 |= _BV(OCIE3C);
        break;

    default:
        break;
    }
}

void tmrcnt3_output_compare_match_int_disable(
        tmrcnt3_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt3_ouput_compare_channel_a:
        TIMSK3 &= ~_BV(OCIE3A);
        break;

    case tmrcnt3_ouput_compare_channel_b:
        TIMSK3 &= ~_BV(OCIE3B);
        break;

    case tmrcnt3_ouput_compare_channel_c:
        TIMSK3 &= ~_BV(OCIE3C);
        break;

    default:
        break;
    }
}

void tmrcnt3_enable_overflow_int(void)
{
    TIMSK3 |= _BV(TOIE3);
}

void tmrcnt3_disable_overflow_int(void)
{
    TIMSK3 &= ~_BV(TOIE3);
}

_Bool tmrcnt3_is_overflow_int_flag_set(void)
{
    return bit_is_set(TIFR3, TOV3) == 0 ? false : true;
}
