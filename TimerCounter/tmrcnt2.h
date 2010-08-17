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

#ifndef TMR_CNT_2_H_
#define TMR_CNT_2_H_

#include <stdbool.h>

typedef enum tmrcnt2_clk_src_e
{
    tmrcnt2_clk_src_clkIO = 0,
    tmrcnt2_clk_src_ExtClk,
    tmrcnt2_clk_src_ExtOsc
} tmrcnt2_clk_src_t;

typedef enum tmrcnt2_clk_select_e
{
    tmrcnt2_clk_src_halted = 0,
    tmrcnt2_clk_src_clkio,
    tmrcnt2_clk_src_clkio_8,
    tmrcnt2_clk_src_clkio_32,
    tmrcnt2_clk_src_clkio_64,
    tmrcnt2_clk_src_clkio_128,
    tmrcnt2_clk_src_clkio_256,
    tmrcnt2_clk_src_clkio_1024
} tmrcnt2_clk_select_t;


typedef enum tmrcnt2_wgm_e
{
    tmrcnt2_wgm_normal_ff_imd_max = 0,
    tmrcnt2_wgm_pwm_phase_correct_ff_top_btm,
    tmrcnt2_wgm_ctc_ocra_imd_max,
    tmrcnt2_wgm_fast_pwm_ff_top_max,
    tmrcnt2_wgm_pwm_phase_correct_ocra_top_btm = 5,
    tmrcnt2_wgm_fast_pwm_ocra_top_top = 7
} tmrcnt2_wgm_t;

typedef enum tmrcnt2_com_e
{
    tmrcnt2_com_port_disconnected = 0,
    tmrcnt2_com_normal_toggle_oc0a_compare_match = 1,
    tmrcnt2_com_ctc_toggle_oc0a_compare_match = 1,
    tmrcnt2_com_normal_clear_oc0a_compare_match = 2,
    tmrcnt2_com_pwm_phase_correct_clear_oc0a_upcounting_set_oc0a_downcounting = 2,
    tmrcnt2_com_ctc_clear_oc0a_compare_match = 2,
    tmrcnt2_com_fast_pwm_clear_oc0a_compare_match_set_oc0a_top = 2,
    tmrcnt2_com_normal_set_oc0a_compare_match = 3,
    tmrcnt2_com_pwm_phase_correct_set_oc0a_upcounting_clear_oc0a_downcounting = 3,
    tmrcnt2_com_ctc_set_oc0a_compare_match = 3,
    tmrcnt2_com_fast_pwm_set_oc0a_compare_match_clear_oc0a_top = 3,
} tmrcnt2_com_t;

void tmrcnt2_init(tmrcnt2_wgm_t wgm, tmrcnt2_clk_select_t prescale);
void tmrcnt2_set_clk_source(tmrcnt2_clk_src_t source);

uint8_t tmrcnt2_get_timer(void);
void tmrcnt2_set_timer(uint8_t);

void tmrcnt2_overflow_int_enable(void);
void tmrcnt2_overflow_int_disable(void);
_Bool tmrcnt2_is_overflow_int_flag_set(void);

void tmrcnt2_oca_set_pin_mode(tmrcnt2_com_t mode);
void tmrcnt2_ocb_set_pin_mode(tmrcnt2_com_t mode);

void tmrcnt2_oca_set_pin_as_ouput(_Bool isOutput);
void tmrcnt2_ocb_set_pin_as_ouput(_Bool isOutput);

void tmrcnt2_oca_force_ouput_compare(void);
void tmrcnt2_ocb_force_ouput_compare(void);

uint8_t tmrcnt2_get_oca(void);
uint8_t tmrcnt2_get_ocb(void);

void tmrcnt2_set_oca(uint8_t value);
void tmrcnt2_set_ocb(uint8_t value);

void tmrcnt2_oca_match_int_enable(void);
void tmrcnt2_ocb_match_int_enable(void);

void tmrcnt2_oca_match_int_disable(void);
void tmrcnt2_ocb_match_int_disable(void);

#endif /*TMR_CNT_2_H_*/
