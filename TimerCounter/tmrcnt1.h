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

#ifndef TMR_CNT_1_H_
#define TMR_CNT_1_H_

#include <stdbool.h>

typedef enum tmrcnt1_clk_select_e
{
    tmrcnt1_clk_src_halted = 0,
    tmrcnt1_clk_src_clkio,
    tmrcnt1_clk_src_clkio_8,
    tmrcnt1_clk_src_clkio_64,
    tmrcnt1_clk_src_clkio_256,
    tmrcnt1_clk_src_clkio_1024,
    tmrcnt1_clk_src_ext_clk_falling_edge,
    tmrcnt1_clk_src_ext_clk_rising_edge,
} tmrcnt1_clk_select_t;

typedef enum tmrcnt1_wgm_e
{
    tmrcnt1_wgm_normal_ffff_imd_max = 0,
    tmrcnt1_wgm_pwm_phase_correct_8bit_00ff_top_btm,
    tmrcnt1_wgm_pwm_phase_correct_9bit_01ff_top_btm,
    tmrcnt1_wgm_pwm_phase_correct_10bit_03ff_top_btm,
    tmrcnt1_wgm_ctc_ocr5a_imd_max,
    tmrcnt1_wgm_fast_pwm_8bit_00ff_btm_top,
    tmrcnt1_wgm_fast_pwm_9bit_01ff_btm_top,
    tmrcnt1_wgm_fast_pwm_10bit_03ff_btm_top,
    tmrcnt1_wgm_pwm_phase_freq_correct_icr5_btm_btm,
    tmrcnt1_wgm_pwm_phase_freq_correct_ocr5a_btm_btm,
    tmrcnt1_wgm_pwm_phase_correct_icr5_top_btm,
    tmrcnt1_wgm_pwm_phase_correct_ocr5a_top_btm,
    tmrcnt1_wgm_ctc_icr5_imd_max,
    tmrcnt1_wgm_fast_pwm_icr5_top_top = 14,
    tmrcnt1_wgm_fast_pwm_ocr5a_top_top
} tmrcnt1_wgm_t;

typedef enum tmrcnt1_com_e
{
    tmrcnt1_com_port_disconnected = 0,
    tmrcnt1_com_normal_toggle_oc0a_compare_match = 1,
    tmrcnt1_com_ctc_toggle_oc0a_compare_match = 1,
    tmrcnt1_com_normal_clear_oc0a_compare_match = 2,
    tmrcnt1_com_pwm_phase_correct_clear_oc0a_upcounting_set_oc0a_downcounting = 2,
    tmrcnt1_com_ctc_clear_oc0a_compare_match = 2,
    tmrcnt1_com_fast_pwm_clear_oc0a_compare_match_set_oc0a_top = 2,
    tmrcnt1_com_normal_set_oc0a_compare_match = 3,
    tmrcnt1_com_pwm_phase_correct_set_oc0a_upcounting_clear_oc0a_downcounting = 3,
    tmrcnt1_com_ctc_set_oc0a_compare_match = 3,
    tmrcnt1_com_fast_pwm_set_oc0a_compare_match_clear_oc0a_top = 3,
} tmrcnt1_com_t;

void tmrcnt1_init (tmrcnt1_wgm_t mode, tmrcnt1_clk_select_t prescale);

uint16_t tmrcnt1_get_timer(void);
void tmrcnt1_set_timer(uint16_t);

void tmrcnt1_overflow_int_enable(void);
void tmrcnt1_overflow_int_disable(void);
_Bool tmrcnt1_is_overflow_int_flag_set(void);

void tmrcnt1_oca_set_pin_mode(tmrcnt1_com_t mode);
void tmrcnt1_ocb_set_pin_mode(tmrcnt1_com_t mode);
void tmrcnt1_occ_set_pin_mode(tmrcnt1_com_t mode);

void tmrcnt1_oca_set_pin_as_ouput(_Bool isOutput);
void tmrcnt1_ocb_set_pin_as_ouput(_Bool isOutput);
void tmrcnt1_occ_set_pin_as_ouput(_Bool isOutput);

void tmrcnt1_oca_force_ouput_compare(void);
void tmrcnt1_ocb_force_ouput_compare(void);
void tmrcnt1_occ_force_ouput_compare(void);

uint16_t tmrcnt1_get_oca(void);
uint16_t tmrcnt1_get_ocb(void);
uint16_t tmrcnt1_get_occ(void);

void tmrcnt1_set_oca(uint16_t value);
void tmrcnt1_set_ocb(uint16_t value);

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega128A__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
void tmrcnt1_set_occ(uint16_t value);
#endif

uint16_t tmrcnt1_get_ic(void);

void tmrcnt1_ic_match_int_enable(void);
void tmrcnt1_ic_match_int_disable(void);

void tmrcnt1_oca_match_int_enable(void);
void tmrcnt1_ocb_match_int_enable(void);

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega128A__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
void tmrcnt1_occ_match_int_enable(void);
#endif

void tmrcnt1_oca_match_int_disable(void);
void tmrcnt1_ocb_match_int_disable(void);

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega128A__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
void tmrcnt1_occ_match_int_disable(void);
#endif

#endif /* TMR_CNT_1_H_ */
