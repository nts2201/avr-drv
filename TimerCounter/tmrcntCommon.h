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

#ifndef __TMR_CNT_COMMON_H__
#define __TMR_CNT_COMMON_H__

#define tmrcnt_init_15wgm(id); void tmrcnt##id##_init(tmrcnt##id##_wgm_t mode, tmrcnt##id##_clk_select_t prescale) \
{ \
        /*Force timer to stop*/ \
    TCCR##id##B &= ~(_BV(CS##id##2) | _BV(CS##id##1) | _BV(CS##id##0)); \
 \
    switch (mode) \
    { \
    case tmrcnt##id##_wgm_normal_ffff_imd_max: \
        TCCR##id##B &= ~(_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A &= ~(_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_correct_8bit_00ff_top_btm: \
        TCCR##id##B &= ~(_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A &= ~_BV(WGM##id##1); \
        TCCR##id##A |= _BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_correct_9bit_01ff_top_btm: \
        TCCR##id##B &= ~(_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A |= _BV(WGM##id##1); \
        TCCR##id##A &= ~_BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_correct_10bit_03ff_top_btm: \
        TCCR##id##B &= ~(_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A |= (_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_ctc_ocr5a_imd_max: \
        TCCR##id##B &= ~_BV(WGM##id##3); \
        TCCR##id##B |= _BV(WGM##id##2); \
        TCCR##id##A &= ~(_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_fast_pwm_8bit_00ff_btm_top: \
        TCCR##id##B &= ~_BV(WGM##id##3); \
        TCCR##id##B |= _BV(WGM##id##2); \
        TCCR##id##A &= ~_BV(WGM##id##1); \
        TCCR##id##A |= _BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_fast_pwm_9bit_01ff_btm_top: \
        TCCR##id##B &= ~_BV(WGM##id##3); \
        TCCR##id##B |= _BV(WGM##id##2); \
        TCCR##id##A |= _BV(WGM##id##1); \
        TCCR##id##A &= ~_BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_fast_pwm_10bit_03ff_btm_top: \
        TCCR##id##B &= ~_BV(WGM##id##3); \
        TCCR##id##B |= _BV(WGM##id##2); \
        TCCR##id##A |= (_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_freq_correct_icr5_btm_btm: \
        TCCR##id##B |= _BV(WGM##id##3); \
        TCCR##id##B &= ~_BV(WGM##id##2); \
        TCCR##id##A &= ~(_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_freq_correct_ocr5a_btm_btm: \
        TCCR##id##B |= _BV(WGM##id##3); \
        TCCR##id##B &= ~_BV(WGM##id##2); \
        TCCR##id##A &= ~_BV(WGM##id##1); \
        TCCR##id##A |= _BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_correct_icr5_top_btm: \
        TCCR##id##B |= _BV(WGM##id##3); \
        TCCR##id##B &= ~_BV(WGM##id##2); \
        TCCR##id##A |= _BV(WGM##id##1); \
        TCCR##id##A &= ~_BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_pwm_phase_correct_ocr5a_top_btm: \
        TCCR##id##B |= _BV(WGM##id##3); \
        TCCR##id##B &= ~_BV(WGM##id##2); \
        TCCR##id##A |= (_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_ctc_icr5_imd_max: \
        TCCR##id##B |= (_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A &= ~(_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    case tmrcnt##id##_wgm_fast_pwm_icr5_top_top: \
        TCCR##id##B |= (_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A |= _BV(WGM##id##1); \
        TCCR##id##A &= ~_BV(WGM##id##0); \
        break; \
 \
    case tmrcnt##id##_wgm_fast_pwm_ocr5a_top_top: \
        TCCR##id##B |= (_BV(WGM##id##3) | _BV(WGM##id##2)); \
        TCCR##id##A |= (_BV(WGM##id##1) | _BV(WGM##id##0)); \
        break; \
 \
    default: \
        break; \
    } \
 \
    TCCR##id##B |= (prescale << CS##id##0); \
}

#define tmrcnt_get_timer(id, size); uint##size##_t tmrcnt##id##_get_timer(void) \
{ \
    return (TCNT##id); \
}

#define tmrcnt_set_timer(id, size); void tmrcnt##id##_set_timer(uint##size##_t value) \
{ \
    TCNT##id = value; \
}

#define tmrcnt_overflow_int_enable(id, regSufix); void tmrcnt##id##_overflow_int_enable(void) \
{ \
    TIMSK##regSufix |= _BV(TOIE##id); \
}

#define tmrcnt_overflow_int_disable(id, regSufix); void tmrcnt##id##_overflow_int_disable(void) \
{ \
    TIMSK##regSufix &= ~_BV(TOIE##id); \
}

#define tmrcnt_is_overflow_int_flag_set(id, regSufix); _Bool tmrcnt##id##_is_overflow_int_flag_set(void) \
{ \
    return bit_is_set(TIFR##regSufix, TOV##id) == 0 ? false : true; \
}

#define tmrcnt_oc_set_pin_mode(id, LTR, ltr); void tmrcnt##id##_oc##ltr##_set_pin_mode(tmrcnt##id##_com_t mode) \
{ \
    TCCR##id##LTR &= ~(_BV(COM##id##LTR##1) | _BV(COM##id##LTR##0)); \
    TCCR##id##LTR |= (mode << COM##id##LTR##0); \
}

#define tmrcnt_oc_set_pin_as_ouput(id, LTR, ltr); void tmrcnt##id##_oc##ltr##_set_pin_as_ouput(_Bool isOutput) \
{ \
    if (true == isOutput) \
    { \
        OC##id##LTR##_DDR |= _BV(OC##id##LTR##_BIT); \
    } \
    else \
    { \
        OC##id##LTR##_DDR &= ~_BV(OC##id##LTR##_BIT); \
    } \
}

#define tmrcnt_oc_force_ouput_compare(id, LTR, ltr); void tmrcnt##id##_oc##ltr##_force_ouput_compare(void) \
{ \
    TCCR##id##LTR |= _BV(FOC##id##LTR); \
}

#define tmrcnt_get_oc(id, LTR, ltr, size); uint##size##_t tmrcnt##id##_get_oc##ltr (void) \
{ \
    return (OCR##id##LTR); \
}

#define tmrcnt_set_oc(id, LTR, ltr, size); void tmrcnt##id##_set_oc##ltr (uint##size##_t value) \
{ \
    OCR##id##LTR = value; \
}

#define tmrcnt_get_ic(id, size); uint##size##_t tmrcnt##id##_get_ic(void) \
{ \
    return ICR##id; \
}

#define tmrcnt_ic_match_int_enable(id, regSufix); void tmrcnt##id##_ic_match_int_enable(void) \
{ \
    TIMSK##regSufix |= _BV(ICIE##id); \
}

#define tmrcnt_ic_match_int_disable(id, regSufix); void tmrcnt##id##_ic_match_int_disable(void) \
{ \
    TIMSK##regSufix &= ~_BV(ICIE##id); \
}

#define tmrcnt_oc_match_int_enable(id, LTR, ltr, regSufix); void tmrcnt##id##_oc##ltr##_match_int_enable(void) \
{ \
    TIMSK##regSufix |= _BV(OCIE##id##LTR); \
}

#define tmrcnt_oc_match_int_disable(id, LTR, ltr, regSufix); void tmrcnt##id##_oc##ltr##_match_int_disable(void) \
{ \
    TIMSK##regSufix &= ~_BV(OCIE##id##LTR); \
}

#endif//__TMR_CNT_COMMON_H__

