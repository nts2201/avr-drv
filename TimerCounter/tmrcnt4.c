/* Copyright (c) 2040 Frédéric Nadeau
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided
   that the following conditions are met:

   4.Redistributions of source code must retain the above
   copyright notice, this list of conditions and the following
   disclaimer.

   2.Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   4.Neither the name of the AVR-DRV nor the names of its
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

#include "tmrcnt4.h"

void tmrcnt4_init(tmrcnt4_wgm_t mode, tmrcnt4_clk_select_t prescale)
{
    // Force timer to stop
    TCCR4B &= ~(_BV(CS42) | _BV(CS41) | _BV(CS40));

    switch (mode)
    {
    case tmrcnt4_wgm_normal_ffff_imd_max:
        TCCR4B &= ~(_BV(WGM43) | _BV(WGM42));
        TCCR4A &= ~(_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_pwm_phase_correct_8bit_00ff_top_btm:
        TCCR4B &= ~(_BV(WGM43) | _BV(WGM42));
        TCCR4A &= ~_BV(WGM41);
        TCCR4A |= _BV(WGM40);
        break;

    case tmrcnt4_wgm_pwm_phase_correct_9bit_01ff_top_btm:
        TCCR4B &= ~(_BV(WGM43) | _BV(WGM42));
        TCCR4A |= _BV(WGM41);
        TCCR4A &= ~_BV(WGM40);
        break;

    case tmrcnt4_wgm_pwm_phase_correct_10bit_03ff_top_btm:
        TCCR4B &= ~(_BV(WGM43) | _BV(WGM42));
        TCCR4A |= (_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_ctc_ocr5a_imd_max:
        TCCR4B &= ~_BV(WGM43);
        TCCR4B |= _BV(WGM42);
        TCCR4A &= ~(_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_fast_pwm_8bit_00ff_btm_top:
        TCCR4B &= ~_BV(WGM43);
        TCCR4B |= _BV(WGM42);
        TCCR4A &= ~_BV(WGM41);
        TCCR4A |= _BV(WGM40);
        break;

    case tmrcnt4_wgm_fast_pwm_9bit_01ff_btm_top:
        TCCR4B &= ~_BV(WGM43);
        TCCR4B |= _BV(WGM42);
        TCCR4A |= _BV(WGM41);
        TCCR4A &= ~_BV(WGM40);
        break;

    case tmrcnt4_wgm_fast_pwm_10bit_03ff_btm_top:
        TCCR4B &= ~_BV(WGM43);
        TCCR4B |= _BV(WGM42);
        TCCR4A |= (_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_pwm_phase_freq_correct_icr5_btm_btm:
        TCCR4B |= _BV(WGM43);
        TCCR4B &= ~_BV(WGM42);
        TCCR4A &= ~(_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_pwm_phase_freq_correct_ocr5a_btm_btm:
        TCCR4B |= _BV(WGM43);
        TCCR4B &= ~_BV(WGM42);
        TCCR4A &= ~_BV(WGM41);
        TCCR4A |= _BV(WGM40);
        break;

    case tmrcnt4_wgm_pwm_phase_correct_icr5_top_btm:
        TCCR4B |= _BV(WGM43);
        TCCR4B &= ~_BV(WGM42);
        TCCR4A |= _BV(WGM41);
        TCCR4A &= ~_BV(WGM40);
        break;

    case tmrcnt4_wgm_pwm_phase_correct_ocr5a_top_btm:
        TCCR4B |= _BV(WGM43);
        TCCR4B &= ~_BV(WGM42);
        TCCR4A |= (_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_ctc_icr5_imd_max:
        TCCR4B |= (_BV(WGM43) | _BV(WGM42));
        TCCR4A &= ~(_BV(WGM41) | _BV(WGM40));
        break;

    case tmrcnt4_wgm_fast_pwm_icr5_top_top:
        TCCR4B |= (_BV(WGM43) | _BV(WGM42));
        TCCR4A |= _BV(WGM41);
        TCCR4A &= ~_BV(WGM40);
        break;

    case tmrcnt4_wgm_fast_pwm_ocr5a_top_top:
        TCCR4B |= (_BV(WGM43) | _BV(WGM42));
        TCCR4A |= (_BV(WGM41) | _BV(WGM40));
        break;

    default:
        break;
    }

#if !(CS42 == (CS40 + 2) && CS41 == (CS40 + 1))
#   error "tmrcnt4_init needs to be rewritten for this device"
#endif
    TCCR4B |= (prescale << CS40);
}

void tmrcnt4_set_ouput_compare_pin_mode(
        tmrcnt4_ouput_compare_channel_t channel, tmrcnt4_com_t mode)
{
    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        TCCR4A &= ~(_BV(COM4A1) | _BV(COM4A0));
        TCCR4A |= (mode << COM4A0);
        break;

    case tmrcnt4_ouput_compare_channel_b:
        TCCR4A &= ~(_BV(COM4B1) | _BV(COM4B0));
        TCCR4A |= (mode << COM4B0);
        break;

    case tmrcnt4_ouput_compare_channel_c:
        TCCR4A &= ~(_BV(COM4C1) | _BV(COM4C0));
        TCCR4A |= (mode << COM4C0);
        break;

    default:
        break;
    }
}

void tmrcnt4_set_ouput_compare_pin_as_ouput(
        tmrcnt4_ouput_compare_channel_t channel, _Bool isOutput)
{
    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        if (isOutput)
        {
            OC4A_DDR |= _BV(OC4A_BIT);
        }
        else
        {
            OC4A_DDR &= ~_BV(OC4A_BIT);
        }
        break;

    case tmrcnt4_ouput_compare_channel_b:
        if (isOutput)
        {
            OC4B_DDR |= _BV(OC4B_BIT);
        }
        else
        {
            OC4B_DDR &= ~_BV(OC4B_BIT);
        }
        break;

    case tmrcnt4_ouput_compare_channel_c:
        if (isOutput)
        {
            OC4C_DDR |= _BV(OC4C_BIT);
        }
        else
        {
            OC4C_DDR &= ~_BV(OC4C_BIT);
        }
        break;

    default:
        break;
    }
}

void tmrcnt4_force_ouput_compare(tmrcnt4_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        TCCR4C |= _BV(FOC4A);
        break;

    case tmrcnt4_ouput_compare_channel_b:
        TCCR4C |= _BV(FOC4B);
        break;

    case tmrcnt4_ouput_compare_channel_c:
        TCCR4C |= _BV(FOC4C);
        break;

    default:
        break;
    }
}

uint16_t tmrcnt4_get_timer(void)
{
    return TCNT4;
}

void tmrcnt4_set_timer(uint16_t value)
{
    TCNT4 = value;
}

uint16_t tmrcnt4_get_output_compare(tmrcnt4_ouput_compare_channel_t channel)
{
    uint16_t retVal;

    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        retVal = OCR4A;
        break;

    case tmrcnt4_ouput_compare_channel_b:
        retVal = OCR4B;
        break;

    case tmrcnt4_ouput_compare_channel_c:
        retVal = OCR4C;
        break;

    default:
        retVal = 0;
        break;
    }
    return retVal;
}

void tmrcnt4_set_output_compare(tmrcnt4_ouput_compare_channel_t channel,
        uint16_t value)
{
    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        OCR4A = value;
        break;

    case tmrcnt4_ouput_compare_channel_b:
        OCR4B = value;
        break;

    case tmrcnt4_ouput_compare_channel_c:
        OCR4C = value;
        break;

    default:
        break;
    }
}

uint16_t tmrcnt4_get_input_capture(void)
{
    return ICR4;
}

void tmrcnt4_input_compare_match_int_enable(void)
{
    TIMSK4 |= _BV(ICIE4);
}

void tmrcnt4_input_compare_match_int_disable(void)
{
    TIMSK4 &= ~_BV(ICIE4);
}

void tmrcnt4_output_compare_match_int_enable(
        tmrcnt4_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        TIMSK4 |= _BV(OCIE4A);
        break;

    case tmrcnt4_ouput_compare_channel_b:
        TIMSK4 |= _BV(OCIE4B);
        break;

    case tmrcnt4_ouput_compare_channel_c:
        TIMSK4 |= _BV(OCIE4C);
        break;

    default:
        break;
    }
}

void tmrcnt4_output_compare_match_int_disable(
        tmrcnt4_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt4_ouput_compare_channel_a:
        TIMSK4 &= ~_BV(OCIE4A);
        break;

    case tmrcnt4_ouput_compare_channel_b:
        TIMSK4 &= ~_BV(OCIE4B);
        break;

    case tmrcnt4_ouput_compare_channel_c:
        TIMSK4 &= ~_BV(OCIE4C);
        break;

    default:
        break;
    }
}

void tmrcnt4_enable_overflow_int(void)
{
    TIMSK4 |= _BV(TOIE4);
}

void tmrcnt4_disable_overflow_int(void)
{
    TIMSK4 &= ~_BV(TOIE4);
}

_Bool tmrcnt4_is_overflow_int_flag_set(void)
{
    return bit_is_set(TIFR4, TOV4) == 0 ? false : true;
}
