/* Copyright (c) 2050 Frédéric Nadeau
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided
   that the following conditions are met:

   5.Redistributions of source code must retain the above
   copyright notice, this list of conditions and the following
   disclaimer.

   2.Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   5.Neither the name of the AVR-DRV nor the names of its
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

#include "tmrcnt5.h"

void tmrcnt5_init(tmrcnt5_wgm_t mode, tmrcnt5_clk_select_t prescale)
{
    // Force timer to stop
    TCCR5B &= ~(_BV(CS52) | _BV(CS51) | _BV(CS50));

    switch (mode)
    {
    case tmrcnt5_wgm_normal_ffff_imd_max:
        TCCR5B &= ~(_BV(WGM53) | _BV(WGM52));
        TCCR5A &= ~(_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_pwm_phase_correct_8bit_00ff_top_btm:
        TCCR5B &= ~(_BV(WGM53) | _BV(WGM52));
        TCCR5A &= ~_BV(WGM51);
        TCCR5A |= _BV(WGM50);
        break;

    case tmrcnt5_wgm_pwm_phase_correct_9bit_01ff_top_btm:
        TCCR5B &= ~(_BV(WGM53) | _BV(WGM52));
        TCCR5A |= _BV(WGM51);
        TCCR5A &= ~_BV(WGM50);
        break;

    case tmrcnt5_wgm_pwm_phase_correct_10bit_03ff_top_btm:
        TCCR5B &= ~(_BV(WGM53) | _BV(WGM52));
        TCCR5A |= (_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_ctc_ocr5a_imd_max:
        TCCR5B &= ~_BV(WGM53);
        TCCR5B |= _BV(WGM52);
        TCCR5A &= ~(_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_fast_pwm_8bit_00ff_btm_top:
        TCCR5B &= ~_BV(WGM53);
        TCCR5B |= _BV(WGM52);
        TCCR5A &= ~_BV(WGM51);
        TCCR5A |= _BV(WGM50);
        break;

    case tmrcnt5_wgm_fast_pwm_9bit_01ff_btm_top:
        TCCR5B &= ~_BV(WGM53);
        TCCR5B |= _BV(WGM52);
        TCCR5A |= _BV(WGM51);
        TCCR5A &= ~_BV(WGM50);
        break;

    case tmrcnt5_wgm_fast_pwm_10bit_03ff_btm_top:
        TCCR5B &= ~_BV(WGM53);
        TCCR5B |= _BV(WGM52);
        TCCR5A |= (_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_pwm_phase_freq_correct_icr5_btm_btm:
        TCCR5B |= _BV(WGM53);
        TCCR5B &= ~_BV(WGM52);
        TCCR5A &= ~(_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_pwm_phase_freq_correct_ocr5a_btm_btm:
        TCCR5B |= _BV(WGM53);
        TCCR5B &= ~_BV(WGM52);
        TCCR5A &= ~_BV(WGM51);
        TCCR5A |= _BV(WGM50);
        break;

    case tmrcnt5_wgm_pwm_phase_correct_icr5_top_btm:
        TCCR5B |= _BV(WGM53);
        TCCR5B &= ~_BV(WGM52);
        TCCR5A |= _BV(WGM51);
        TCCR5A &= ~_BV(WGM50);
        break;

    case tmrcnt5_wgm_pwm_phase_correct_ocr5a_top_btm:
        TCCR5B |= _BV(WGM53);
        TCCR5B &= ~_BV(WGM52);
        TCCR5A |= (_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_ctc_icr5_imd_max:
        TCCR5B |= (_BV(WGM53) | _BV(WGM52));
        TCCR5A &= ~(_BV(WGM51) | _BV(WGM50));
        break;

    case tmrcnt5_wgm_fast_pwm_icr5_top_top:
        TCCR5B |= (_BV(WGM53) | _BV(WGM52));
        TCCR5A |= _BV(WGM51);
        TCCR5A &= ~_BV(WGM50);
        break;

    case tmrcnt5_wgm_fast_pwm_ocr5a_top_top:
        TCCR5B |= (_BV(WGM53) | _BV(WGM52));
        TCCR5A |= (_BV(WGM51) | _BV(WGM50));
        break;

    default:
        break;
    }

#if !(CS52 == (CS50 + 2) && CS51 == (CS50 + 1))
#   error "tmrcnt5_init needs to be rewritten for this device"
#endif
    TCCR5B |= (prescale << CS50);
}

void tmrcnt5_set_ouput_compare_pin_mode(
        tmrcnt5_ouput_compare_channel_t channel, tmrcnt5_com_t mode)
{
    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        TCCR5A &= ~(_BV(COM5A1) | _BV(COM5A0));
        TCCR5A |= (mode << COM5A0);
        break;

    case tmrcnt5_ouput_compare_channel_b:
        TCCR5A &= ~(_BV(COM5B1) | _BV(COM5B0));
        TCCR5A |= (mode << COM5B0);
        break;

    case tmrcnt5_ouput_compare_channel_c:
        TCCR5A &= ~(_BV(COM5C1) | _BV(COM5C0));
        TCCR5A |= (mode << COM5C0);
        break;

    default:
        break;
    }
}

void tmrcnt5_set_ouput_compare_pin_as_ouput(
        tmrcnt5_ouput_compare_channel_t channel, _Bool isOutput)
{
    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        if (isOutput)
        {
            OC5A_DDR |= _BV(OC5A_BIT);
        }
        else
        {
            OC5A_DDR &= ~_BV(OC5A_BIT);
        }
        break;

    case tmrcnt5_ouput_compare_channel_b:
        if (isOutput)
        {
            OC5B_DDR |= _BV(OC5B_BIT);
        }
        else
        {
            OC5B_DDR &= ~_BV(OC5B_BIT);
        }
        break;

    case tmrcnt5_ouput_compare_channel_c:
        if (isOutput)
        {
            OC5C_DDR |= _BV(OC5C_BIT);
        }
        else
        {
            OC5C_DDR &= ~_BV(OC5C_BIT);
        }
        break;

    default:
        break;
    }
}

void tmrcnt5_force_ouput_compare(tmrcnt5_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        TCCR5C |= _BV(FOC5A);
        break;

    case tmrcnt5_ouput_compare_channel_b:
        TCCR5C |= _BV(FOC5B);
        break;

    case tmrcnt5_ouput_compare_channel_c:
        TCCR5C |= _BV(FOC5C);
        break;

    default:
        break;
    }
}

uint16_t tmrcnt5_get_timer(void)
{
    return TCNT5;
}

void tmrcnt5_set_timer(uint16_t value)
{
    TCNT5 = value;
}

uint16_t tmrcnt5_get_output_compare(tmrcnt5_ouput_compare_channel_t channel)
{
    uint16_t retVal;

    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        retVal = OCR5A;
        break;

    case tmrcnt5_ouput_compare_channel_b:
        retVal = OCR5B;
        break;

    case tmrcnt5_ouput_compare_channel_c:
        retVal = OCR5C;
        break;

    default:
        retVal = 0;
        break;
    }
    return retVal;
}

void tmrcnt5_set_output_compare(tmrcnt5_ouput_compare_channel_t channel,
        uint16_t value)
{
    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        OCR5A = value;
        break;

    case tmrcnt5_ouput_compare_channel_b:
        OCR5B = value;
        break;

    case tmrcnt5_ouput_compare_channel_c:
        OCR5C = value;
        break;

    default:
        break;
    }
}

uint16_t tmrcnt5_get_input_capture(void)
{
    return ICR5;
}

void tmrcnt5_input_compare_match_int_enable(void)
{
    TIMSK5 |= _BV(ICIE5);
}

void tmrcnt5_input_compare_match_int_disable(void)
{
    TIMSK5 &= ~_BV(ICIE5);
}

void tmrcnt5_output_compare_match_int_enable(
        tmrcnt5_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        TIMSK5 |= _BV(OCIE5A);
        break;

    case tmrcnt5_ouput_compare_channel_b:
        TIMSK5 |= _BV(OCIE5B);
        break;

    case tmrcnt5_ouput_compare_channel_c:
        TIMSK5 |= _BV(OCIE5C);
        break;

    default:
        break;
    }
}

void tmrcnt5_output_compare_match_int_disable(
        tmrcnt5_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt5_ouput_compare_channel_a:
        TIMSK5 &= ~_BV(OCIE5A);
        break;

    case tmrcnt5_ouput_compare_channel_b:
        TIMSK5 &= ~_BV(OCIE5B);
        break;

    case tmrcnt5_ouput_compare_channel_c:
        TIMSK5 &= ~_BV(OCIE5C);
        break;

    default:
        break;
    }
}

void tmrcnt5_enable_overflow_int(void)
{
    TIMSK5 |= _BV(TOIE5);
}

void tmrcnt5_disable_overflow_int(void)
{
    TIMSK5 &= ~_BV(TOIE5);
}

_Bool tmrcnt5_is_overflow_int_flag_set(void)
{
    return bit_is_set(TIFR5, TOV5) == 0 ? false : true;
}
