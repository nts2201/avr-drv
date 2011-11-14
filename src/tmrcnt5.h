/* Copyright (c) 2010-2011 Frédéric Nadeau
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

/*! \file tmrcnt5.h
 \defgroup drv_tmrcnt1 <tmrcnt1.h>: Timer/Counter 5
 \brief API for Atmel Timer/Counter 5.

 \author Frédéric Nadeau
 */

#ifndef TMR_CNT_5_H_
#define TMR_CNT_5_H_

#include <tmrcnt.h>

typedef enum tmrcnt5_clk_select_e
{
    tmrcnt5_clk_select_halted = 0,
    tmrcnt5_clk_select_clkio,
    tmrcnt5_clk_select_clkio_8,
    tmrcnt5_clk_select_clkio_64,
    tmrcnt5_clk_select_clkio_256,
    tmrcnt5_clk_select_clkio_1024,
    tmrcnt5_clk_select_ext_clk_falling_edge,
    tmrcnt5_clk_select_ext_clk_rising_edge,
} tmrcnt5_clk_select_t;

typedef enum tmrcnt5_wgm_e
{
    tmrcnt5_wgm_normal_ffff_imd_max = 0,
    tmrcnt5_wgm_pwm_phase_correct_8bit_00ff_top_btm,
    tmrcnt5_wgm_pwm_phase_correct_9bit_01ff_top_btm,
    tmrcnt5_wgm_pwm_phase_correct_10bit_03ff_top_btm,
    tmrcnt5_wgm_ctc_ocr5a_imd_max,
    tmrcnt5_wgm_fast_pwm_8bit_00ff_btm_top,
    tmrcnt5_wgm_fast_pwm_9bit_01ff_btm_top,
    tmrcnt5_wgm_fast_pwm_10bit_03ff_btm_top,
    tmrcnt5_wgm_pwm_phase_freq_correct_icr5_btm_btm,
    tmrcnt5_wgm_pwm_phase_freq_correct_ocr5a_btm_btm,
    tmrcnt5_wgm_pwm_phase_correct_icr5_top_btm,
    tmrcnt5_wgm_pwm_phase_correct_ocr5a_top_btm,
    tmrcnt5_wgm_ctc_icr5_imd_max,
    tmrcnt5_wgm_fast_pwm_icr5_top_top = 14,
    tmrcnt5_wgm_fast_pwm_ocr5a_top_top
} tmrcnt5_wgm_t;

void tmrcnt5_init (tmrcnt5_wgm_t mode, tmrcnt5_clk_select_t prescale);

uint16_t tmrcnt5_get_timer(void);
void tmrcnt5_set_timer(uint16_t);

void tmrcnt5_overflow_int_enable(void);
void tmrcnt5_overflow_int_disable(void);
_Bool tmrcnt5_is_overflow_int_flag_set(void);

void tmrcnt5_oca_set_pin_mode(tmrcnt_com_t mode);
void tmrcnt5_ocb_set_pin_mode(tmrcnt_com_t mode);
void tmrcnt5_occ_set_pin_mode(tmrcnt_com_t mode);

#if !defined(__AVR_ATmega128RFA1__)
void tmrcnt5_oca_set_pin_as_ouput(_Bool isOutput);
void tmrcnt5_ocb_set_pin_as_ouput(_Bool isOutput);
void tmrcnt5_occ_set_pin_as_ouput(_Bool isOutput);
#endif

void tmrcnt5_oca_force_ouput_compare(void);
void tmrcnt5_ocb_force_ouput_compare(void);
void tmrcnt5_occ_force_ouput_compare(void);

uint16_t tmrcnt5_get_oca(void);
uint16_t tmrcnt5_get_ocb(void);
uint16_t tmrcnt5_get_occ(void);

void tmrcnt5_set_oca(uint16_t value);
void tmrcnt5_set_ocb(uint16_t value);
void tmrcnt5_set_occ(uint16_t value);

uint16_t tmrcnt5_get_ic(void);

void tmrcnt5_ic_match_int_enable(void);
void tmrcnt5_ic_match_int_disable(void);

void tmrcnt5_oca_match_int_enable(void);
void tmrcnt5_ocb_match_int_enable(void);
void tmrcnt5_occ_match_int_enable(void);

void tmrcnt5_oca_match_int_disable(void);
void tmrcnt5_ocb_match_int_disable(void);
void tmrcnt5_occ_match_int_disable(void);

#endif /* TMR_CNT_5_H_ */
