/* Copyright (c) 2011 Frédéric Nadeau
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

/*! \file tmrcnt.h
 \defgroup drv_tmrcnt <tmrcnt.h>: Timer/Counter common definition
 \brief Common definition for multilple Atmel Timer/Counter.

 \author Frédéric Nadeau
 */

#ifndef __TMR_CNT_H__
#define __TMR_CNT_H__

#ifndef __DOXYGEN__
typedef enum tmrcnt_com_e
{
    tmrcnt_com_port_disconnected = 0,
    tmrcnt_com_normal_toggle_oc_compare_match = 1,
    tmrcnt_com_ctc_toggle_oc_compare_match = 1,
    tmrcnt_com_normal_clear_oc_compare_match = 2,
    tmrcnt_com_pwm_phase_correct_clear_oc_upcounting_set_oc_downcounting = 2,
    tmrcnt_com_ctc_clear_oc_compare_match = 2,
    tmrcnt_com_fast_pwm_clear_oc_compare_match_set_oc_top = 2,
    tmrcnt_com_normal_set_oc_compare_match = 3,
    tmrcnt_com_pwm_phase_correct_set_oc_upcounting_clear_oc_downcounting = 3,
    tmrcnt_com_ctc_set_oc_compare_match = 3,
    tmrcnt_com_fast_pwm_set_oc_compare_match_clear_oc_top = 3,
} tmrcnt_com_t;
#else

/*! \ingroup drv_tmrcnt
 * List of available Compare Output Mode for Timer/Counter.
 */
enum tmrcnt_com_e
{
    tmrcnt_com_port_disconnected = 0,
    tmrcnt_com_normal_toggle_oc_compare_match = 1,
    tmrcnt_com_ctc_toggle_oc_compare_match = 1,
    tmrcnt_com_normal_clear_oc_compare_match = 2,
    tmrcnt_com_pwm_phase_correct_clear_oc_upcounting_set_oc_downcounting = 2,
    tmrcnt_com_ctc_clear_oc_compare_match = 2,
    tmrcnt_com_fast_pwm_clear_oc_compare_match_set_oc_top = 2,
    tmrcnt_com_normal_set_oc_compare_match = 3,
    tmrcnt_com_pwm_phase_correct_set_oc_upcounting_clear_oc_downcounting = 3,
    tmrcnt_com_ctc_set_oc_compare_match = 3,
    tmrcnt_com_fast_pwm_set_oc_compare_match_clear_oc_top = 3,
};

/*! \ingroup drv_tmrcnt
 * Compare Output Mode typedef for Timer/Counter.
 */
typedef enum tmrcnt_com_e tmrcnt_com_t;
#endif
#endif
