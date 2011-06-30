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

/*! \file tmrcnt2.h
 \brief API for Atmel Timer Counter 2.

 \author Frédéric Nadeau

 This module controls the Timer Counter 2. On most devices, if not all,
 this timer can be configured to use an asynchronous clock source.
 */

#ifndef TMR_CNT_2_H_
#define TMR_CNT_2_H_

#include <stdbool.h>

/*! List of clock source for Timer/Counter 2. */
enum tmrcnt2_clk_src_e
{
    tmrcnt2_clk_src_clkIO = 0, /*!< Timer/Counter 2 is driven by the main system I/O clock. */
    tmrcnt2_clk_src_ExtClk, /*!< Timer/Counter 2 uses an external clock source on pin TOSC1. */
    tmrcnt2_clk_src_ExtOsc /*!< Timer/Counter 2 uses a crystal clock source on pin TOSC1 and TOSC2. */
};

/*! List of clock source for Timer/Counter 2 typedef. */
typedef enum tmrcnt2_clk_src_e tmrcnt2_clk_src_t;

/*! List of available prescaler for Timer/Counter 2. */
enum tmrcnt2_clk_select_e
{
    tmrcnt2_clk_select_halted = 0, /* Timer/Counter 2 is halted. */
    tmrcnt2_clk_select_no_prescaler, /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>.*/
    tmrcnt2_clk_select_div_8, /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>/8.*/
    tmrcnt2_clk_select_div_32, /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>/32.*/
    tmrcnt2_clk_select_div_64, /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>/64.*/
    tmrcnt2_clk_select_div_128, /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>/128.*/
    tmrcnt2_clk_select_div_256, /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>/256.*/
    tmrcnt2_clk_select_div_1024 /* Timer/Counter 2 uses clock source clk<sub>T2S</sub>/1024.*/
};

/*! List of available prescaler for Timer/Counter 2 typedef. */
typedef enum tmrcnt2_clk_select_e tmrcnt2_clk_select_t

#if defined(__DOXYGEN__)
/*! List of waveform generation mode for Timer/Counter 2.
 *
 * The list is made up like this: tmrcnt2_wmg_WW_XX_YY_ZZ where
 * WW: mode: normal, pwm_phaze_correct, ctc, fast_pwm
 * XX: TOP
 * YY: Update of OCRx at
 * ZZ: TOV Flag set on: max=0xFF, btm=0x00
 *
 * \note Some modes are not available on some devices.
 * */
enum tmrcnt2_wgm_e
{
    tmrcnt2_wgm_normal_ff_imd_max = 0, /* Normal waveform with TOP at 0xFF, OCRx updated imediatly and TOV2 flag set at max.*/
    tmrcnt2_wgm_pwm_phase_correct_ff_top_btm, /* PWM phase correct waveform with TOP at 0xFF, OCRx updated at top and TOV2 flag set at bottom.*/
    tmrcnt2_wgm_ctc_ocr_imd_max, /* CTC waveform with TOP at OCR2x, OCRx updated imediatly and TOV2 flag set at max.*/
    tmrcnt2_wgm_fast_pwm_ff_top_max,
    tmrcnt2_wgm_pwm_phase_correct_ocr_top_btm,
    tmrcnt2_wgm_fast_pwm_ocr_top_top
} tmrcnt2_wgm_t;

/*! List of waveform generation mode for Timer/Counter 2 typedef. */
typedef enum tmrcnt2_wgm_e tmrcnt2_wgm_t;

#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__)
// Name are tmrcnt0_wgm_W_X_Y_Z
// W: mode: normal, pwm_phaze_correct, ctc, fast_pwm
// X: TOP
// Y: Update of OCRx at
// Z: TOV Flag set on: MAX=0xFF, Bottom=0x00
typedef enum tmrcnt2_wgm_e
{
    tmrcnt2_wgm_normal_ff_imd_max = 0,
    tmrcnt2_wgm_pwm_phase_correct_ff_top_btm,
    tmrcnt2_wgm_ctc_ocra_imd_max,
    tmrcnt2_wgm_fast_pwm_ff_top_max,
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
    tmrcnt2_wgm_pwm_phase_correct_ocra_top_btm = 5,
    tmrcnt2_wgm_fast_pwm_ocra_top_top = 7
#endif
} tmrcnt2_wgm_t;
#else
#	error "device not supported"
#endif
#endif

typedef enum tmrcnt2_com_e
{
    tmrcnt2_com_port_disconnected = 0,
    tmrcnt2_com_normal_toggle_oc2_compare_match = 1,
    tmrcnt2_com_ctc_toggle_oc2_compare_match = 1,
    tmrcnt2_com_normal_clear_oc2_compare_match = 2,
    tmrcnt2_com_pwm_phase_correct_clear_oc2_upcounting_set_oc0a_downcounting = 2,
    tmrcnt2_com_ctc_clear_oc2_compare_match = 2,
    tmrcnt2_com_fast_pwm_clear_oc2_compare_match_set_oc0a_top = 2,
    tmrcnt2_com_normal_set_oc2_compare_match = 3,
    tmrcnt2_com_pwm_phase_correct_set_oc2_upcounting_clear_oc0a_downcounting = 3,
    tmrcnt2_com_ctc_set_oc2_compare_match = 3,
    tmrcnt2_com_fast_pwm_set_oc2_compare_match_clear_oc0a_top = 3,
} tmrcnt2_com_t;

void tmrcnt2_init(tmrcnt2_wgm_t wgm, tmrcnt2_clk_select_t prescale);
void tmrcnt2_set_clk_source(tmrcnt2_clk_src_t source);

uint8_t tmrcnt2_get_timer(void);
void tmrcnt2_set_timer(uint8_t);

void tmrcnt2_overflow_int_enable(void);
void tmrcnt2_overflow_int_disable(void);
_Bool tmrcnt2_is_overflow_int_flag_set(void);

void tmrcnt2_oca_set_pin_mode(tmrcnt2_com_t mode);

#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
void tmrcnt2_ocb_set_pin_mode(tmrcnt2_com_t mode);
#endif

void tmrcnt2_oca_set_pin_as_ouput(_Bool isOutput);
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
void tmrcnt2_ocb_set_pin_as_ouput(_Bool isOutput);
#endif

void tmrcnt2_oca_force_ouput_compare(void);
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
void tmrcnt2_ocb_force_ouput_compare(void);
#endif

uint8_t tmrcnt2_get_oca(void);
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
uint8_t tmrcnt2_get_ocb(void);
#endif

void tmrcnt2_set_oca(uint8_t value);
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
void tmrcnt2_set_ocb(uint8_t value);
#endif

void tmrcnt2_oca_match_int_enable(void);
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
void tmrcnt2_ocb_match_int_enable(void);
#endif

void tmrcnt2_oca_match_int_disable(void);
#if defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__)
void tmrcnt2_ocb_match_int_disable(void);
#endif

#endif /*TMR_CNT_2_H_*/
