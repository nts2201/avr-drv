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

#include "tmrcnt1.h"

void tmrcnt1_init(tmrcnt1_wgm_t mode, tmrcnt1_clk_select_t prescale)
{
    // Force timer to stop
    TCCR1B &= ~(_BV(CS12) | _BV(CS11) | _BV(CS10));

    switch (mode)
    {
    case tmrcnt1_wgm_normal_ffff_imd_max:
        TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
        TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_pwm_phase_correct_8bit_00ff_top_btm:
        TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
        TCCR1A &= ~_BV(WGM11);
        TCCR1A |= _BV(WGM10);
        break;

    case tmrcnt1_wgm_pwm_phase_correct_9bit_01ff_top_btm:
        TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
        TCCR1A |= _BV(WGM11);
        TCCR1A &= ~_BV(WGM10);
        break;

    case tmrcnt1_wgm_pwm_phase_correct_10bit_03ff_top_btm:
        TCCR1B &= ~(_BV(WGM13) | _BV(WGM12));
        TCCR1A |= (_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_ctc_ocr5a_imd_max:
        TCCR1B &= ~_BV(WGM13);
        TCCR1B |= _BV(WGM12);
        TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_fast_pwm_8bit_00ff_btm_top:
        TCCR1B &= ~_BV(WGM13);
        TCCR1B |= _BV(WGM12);
        TCCR1A &= ~_BV(WGM11);
        TCCR1A |= _BV(WGM10);
        break;

    case tmrcnt1_wgm_fast_pwm_9bit_01ff_btm_top:
        TCCR1B &= ~_BV(WGM13);
        TCCR1B |= _BV(WGM12);
        TCCR1A |= _BV(WGM11);
        TCCR1A &= ~_BV(WGM10);
        break;

    case tmrcnt1_wgm_fast_pwm_10bit_03ff_btm_top:
        TCCR1B &= ~_BV(WGM13);
        TCCR1B |= _BV(WGM12);
        TCCR1A |= (_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_pwm_phase_freq_correct_icr5_btm_btm:
        TCCR1B |= _BV(WGM13);
        TCCR1B &= ~_BV(WGM12);
        TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_pwm_phase_freq_correct_ocr5a_btm_btm:
        TCCR1B |= _BV(WGM13);
        TCCR1B &= ~_BV(WGM12);
        TCCR1A &= ~_BV(WGM11);
        TCCR1A |= _BV(WGM10);
        break;

    case tmrcnt1_wgm_pwm_phase_correct_icr5_top_btm:
        TCCR1B |= _BV(WGM13);
        TCCR1B &= ~_BV(WGM12);
        TCCR1A |= _BV(WGM11);
        TCCR1A &= ~_BV(WGM10);
        break;

    case tmrcnt1_wgm_pwm_phase_correct_ocr5a_top_btm:
        TCCR1B |= _BV(WGM13);
        TCCR1B &= ~_BV(WGM12);
        TCCR1A |= (_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_ctc_icr5_imd_max:
        TCCR1B |= (_BV(WGM13) | _BV(WGM12));
        TCCR1A &= ~(_BV(WGM11) | _BV(WGM10));
        break;

    case tmrcnt1_wgm_fast_pwm_icr5_top_top:
        TCCR1B |= (_BV(WGM13) | _BV(WGM12));
        TCCR1A |= _BV(WGM11);
        TCCR1A &= ~_BV(WGM10);
        break;

    case tmrcnt1_wgm_fast_pwm_ocr5a_top_top:
        TCCR1B |= (_BV(WGM13) | _BV(WGM12));
        TCCR1A |= (_BV(WGM11) | _BV(WGM10));
        break;

    default:
        break;
    }

#if !(CS12 == (CS10 + 2) && CS11 == (CS10 + 1))
#   error "tmrcnt1_init needs to be rewritten for this device"
#endif
    TCCR1B |= (prescale << CS10);
}

void tmrcnt1_set_ouput_compare_pin_mode(
        tmrcnt1_ouput_compare_channel_t channel, tmrcnt1_com_t mode)
{
    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        TCCR1A &= ~(_BV(COM1A1) | _BV(COM1A0));
        TCCR1A |= (mode << COM1A0);
        break;

    case tmrcnt1_ouput_compare_channel_b:
        TCCR1A &= ~(_BV(COM1B1) | _BV(COM1B0));
        TCCR1A |= (mode << COM1B0);
        break;

    case tmrcnt1_ouput_compare_channel_c:
        TCCR1A &= ~(_BV(COM1C1) | _BV(COM1C0));
        TCCR1A |= (mode << COM1C0);
        break;

    default:
        break;
    }
}

void tmrcnt1_set_ouput_compare_pin_as_ouput(
        tmrcnt1_ouput_compare_channel_t channel, _Bool isOutput)
{
    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        if (isOutput)
        {
            OC1A_DDR |= _BV(OC1A_BIT);
        }
        else
        {
            OC1A_DDR &= ~_BV(OC1A_BIT);
        }
        break;

    case tmrcnt1_ouput_compare_channel_b:
        if (isOutput)
        {
            OC1B_DDR |= _BV(OC1B_BIT);
        }
        else
        {
            OC1B_DDR &= ~_BV(OC1B_BIT);
        }
        break;

    case tmrcnt1_ouput_compare_channel_c:
        if (isOutput)
        {
            OC1C_DDR |= _BV(OC1C_BIT);
        }
        else
        {
            OC1C_DDR &= ~_BV(OC1C_BIT);
        }
        break;

    default:
        break;
    }
}

void tmrcnt1_force_ouput_compare(tmrcnt1_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        TCCR1C |= _BV(FOC1A);
        break;

    case tmrcnt1_ouput_compare_channel_b:
        TCCR1C |= _BV(FOC1B);
        break;

    case tmrcnt1_ouput_compare_channel_c:
        TCCR1C |= _BV(FOC1C);
        break;

    default:
        break;
    }
}

uint16_t tmrcnt1_get_timer(void)
{
    return TCNT1;
}

void tmrcnt1_set_timer(uint16_t value)
{
    TCNT1 = value;
}

uint16_t tmrcnt1_get_output_compare(tmrcnt1_ouput_compare_channel_t channel)
{
    uint16_t retVal;

    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        retVal = OCR1A;
        break;

    case tmrcnt1_ouput_compare_channel_b:
        retVal = OCR1B;
        break;

    case tmrcnt1_ouput_compare_channel_c:
        retVal = OCR1C;
        break;

    default:
        retVal = 0;
        break;
    }
    return retVal;
}

void tmrcnt1_set_output_compare(tmrcnt1_ouput_compare_channel_t channel,
        uint16_t value)
{
    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        OCR1A = value;
        break;

    case tmrcnt1_ouput_compare_channel_b:
        OCR1B = value;
        break;

    case tmrcnt1_ouput_compare_channel_c:
        OCR1C = value;
        break;

    default:
        break;
    }
}

uint16_t tmrcnt1_get_input_capture(void)
{
    return ICR1;
}

void tmrcnt1_input_compare_match_int_enable(void)
{
    TIMSK1 |= _BV(ICIE1);
}

void tmrcnt1_input_compare_match_int_disable(void)
{
    TIMSK1 &= ~_BV(ICIE1);
}

void tmrcnt1_output_compare_match_int_enable(
        tmrcnt1_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        TIMSK1 |= _BV(OCIE1A);
        break;

    case tmrcnt1_ouput_compare_channel_b:
        TIMSK1 |= _BV(OCIE1B);
        break;

    case tmrcnt1_ouput_compare_channel_c:
        TIMSK1 |= _BV(OCIE1C);
        break;

    default:
        break;
    }
}

void tmrcnt1_output_compare_match_int_disable(
        tmrcnt1_ouput_compare_channel_t channel)
{
    switch (channel)
    {
    case tmrcnt1_ouput_compare_channel_a:
        TIMSK1 &= ~_BV(OCIE1A);
        break;

    case tmrcnt1_ouput_compare_channel_b:
        TIMSK1 &= ~_BV(OCIE1B);
        break;

    case tmrcnt1_ouput_compare_channel_c:
        TIMSK1 &= ~_BV(OCIE1C);
        break;

    default:
        break;
    }
}

void tmrcnt1_enable_overflow_int(void)
{
    TIMSK1 |= _BV(TOIE1);
}

void tmrcnt1_disable_overflow_int(void)
{
    TIMSK1 &= ~_BV(TOIE1);
}

_Bool tmrcnt1_is_overflow_int_flag_set(void)
{
    return bit_is_set(TIFR1, TOV1) == 0 ? false : true;
}
