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

#ifndef TMR_CNT_0_H_
#define TMR_CNT_0_H_

#include <stdbool.h>

typedef enum tmrcnt0_clk_select_e
{
    tmrcnt0_clk_src_halted = 0,
    tmrcnt0_clk_src_clkio,
    tmrcnt0_clk_src_clkio_8,
    tmrcnt0_clk_src_clkio_64,
    tmrcnt0_clk_src_clkio_256,
    tmrcnt0_clk_src_clkio_1024,
    tmrcnt0_clk_src_ext_clk_falling_edge,
    tmrcnt0_clk_src_ext_clk_rising_edge,
} tmrcnt0_clk_select_t;

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega2560__)
// Name are tmrcnt0_wgm_W_X_Y_Z
// W: mode: normal, pwm_phaze_correct, ctc, fast_pwm
// X: TOP
// Y: Update of OCRx at
// Z: TOV Flag set on: MAX=0xFF, Bottom=0x00
typedef enum tmrcnt0_wgm_e
{
    tmrcnt0_wgm_normal_ff_imd_max = 0,
    tmrcnt0_wgm_pwm_phase_correct_ff_top_btm,
    tmrcnt0_wgm_ctc_ocra_imd_max,
    tmrcnt0_wgm_fast_pwm_ff_top_max,
#if defined(__AVR_AT90PWM1__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
    tmrcnt0_wgm_pwm_phase_correct_ocra_top_btm = 5,
    tmrcnt0_wgm_fast_pwm_ocra_top_top = 7
#endif
} tmrcnt0_wgm_t;

typedef enum tmrcnt0_com_e
{
    tmrcnt0_com_port_disconnected = 0,
    tmrcnt0_com_normal_toggle_oc0a_compare_match = 1,
    tmrcnt0_com_ctc_toggle_oc0a_compare_match = 1,
    tmrcnt0_com_normal_clear_oc0a_compare_match = 2,
    tmrcnt0_com_pwm_phase_correct_clear_oc0a_upcounting_set_oc0a_downcounting = 2,
    tmrcnt0_com_ctc_clear_oc0a_compare_match = 2,
    tmrcnt0_com_fast_pwm_clear_oc0a_compare_match_set_oc0a_top = 2,
    tmrcnt0_com_normal_set_oc0a_compare_match = 3,
    tmrcnt0_com_pwm_phase_correct_set_oc0a_upcounting_clear_oc0a_downcounting = 3,
    tmrcnt0_com_ctc_set_oc0a_compare_match = 3,
    tmrcnt0_com_fast_pwm_set_oc0a_compare_match_clear_oc0a_top = 3,
} tmrcnt0_com_t;
#endif

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
void tmrcnt0_init(tmrcnt0_wgm_t wgm, tmrcnt0_clk_select_t prescale);
#else
void tmrcnt0_init(tmrcnt0_clk_select_t prescale);
#endif


uint8_t tmrcnt0_get_timer(void);
void tmrcnt0_set_timer(uint8_t);

void tmrcnt0_overflow_int_enable(void);
void tmrcnt0_overflow_int_disable(void);
_Bool tmrcnt0_is_overflow_int_flag_set(void);

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)

void tmrcnt0_oca_set_pin_mode(tmrcnt0_com_t mode);
void tmrcnt0_ocb_set_pin_mode(tmrcnt0_com_t mode);

void tmrcnt0_oca_set_pin_as_ouput(_Bool isOutput);
void tmrcnt0_ocb_set_pin_as_ouput(_Bool isOutput);

void tmrcnt0_oca_force_ouput_compare(void);
void tmrcnt0_ocb_force_ouput_compare(void);

uint8_t tmrcnt0_get_oca(void);
uint8_t tmrcnt0_get_ocb(void);

void tmrcnt0_set_oca(uint8_t value);
void tmrcnt0_set_ocb(uint8_t value);

void tmrcnt0_oca_match_int_enable(void);
void tmrcnt0_ocb_match_int_enable(void);

void tmrcnt0_oca_match_int_disable(void);
void tmrcnt0_ocb_match_int_disable(void);

#endif

#endif//TMR_CNT_0_H_
