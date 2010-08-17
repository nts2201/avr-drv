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

#include "tmrcnt0.h"
#include "tmrcntCommon.h"

//Define Prescaler target register
#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0A
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (_BV(CS00))
#elif defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega128__)
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (_BV(CS00))
#elif defined(__AVR_ATmega644__)
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0B
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (_BV(CS00))
#else
#   warning "Device need verification"
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0A
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (_BV(CS00))
#endif

//Define Wave Generation Mode
#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
#   define WGM_0_1_REG    TCCR0A
#elif defined(__AVR_ATmega128__)
#   define WGM_0_1_REG    TCCR0
#elif defined(__AVR_ATmega8__)
//No WGM
#else
#   warning "Device need verification"
#   define WGM_0_1_REG    TCCR0A
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
void tmrcnt0_init(tmrcnt0_wgm_t wgm, tmrcnt0_clk_select_t prescale)
{
    /* Force timer to stop */
       CLK_SEL_REG &= ~CLK_SEL_REG_MASK;

    switch (wgm)
    {
    case tmrcnt0_wgm_normal_ff_imd_max:
        WGM_0_1_REG &= ~(_BV(WGM01) | _BV(WGM00));
        break;

    case tmrcnt0_wgm_pwm_phase_correct_ff_top_btm:
        WGM_0_1_REG &= ~_BV(WGM01);
        WGM_0_1_REG |= _BV(WGM00);
        break;

    case tmrcnt0_wgm_ctc_ocra_imd_max:
        WGM_0_1_REG |= _BV(WGM01);
        WGM_0_1_REG &= ~_BV(WGM00);
        break;

    case tmrcnt0_wgm_fast_pwm_ff_top_max:
        WGM_0_1_REG |= _BV(WGM01);
        WGM_0_1_REG |= _BV(WGM00);
        break;
    default:
        break;
    }

    //Clock prescaler
    CLK_SEL_REG |= (prescale<<CLK_SEL_REG_OFFSET);
}
#else
void tmrcnt0_init(tmrcnt0_clk_select_t prescale)
{
    /* Force timer to stop */
    CLK_SEL_REG &= ~CLK_SEL_REG_MASK;

    CLK_SEL_REG |= (prescale<<CLK_SEL_REG_OFFSET);
}
#endif

tmrcnt_get_timer(0, 8);
tmrcnt_set_timer(0, 8);

#if defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega128__)
tmrcnt_overflow_int_enable(0,);
tmrcnt_overflow_int_disable(0,);
tmrcnt_is_overflow_int_flag_set(0,);
#else
tmrcnt_overflow_int_enable(0, 0);
tmrcnt_overflow_int_disable(0, 0);
tmrcnt_is_overflow_int_flag_set(0, 0);
#endif


#if defined(__AVR_AT90can32__) \
|| defined(__AVR_AT90can64__) \
|| defined(__AVR_AT90can128__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)

tmrcnt_oc_set_pin_mode(0,A,a);

tmrcnt_oc_set_pin_as_ouput(0,A,a);

tmrcnt_oc_force_ouput_compare(0,A,a);

tmrcnt_get_oc(0,A,a,8);

tmrcnt_set_oc(0,A,a,8);

tmrcnt_oc_match_int_enable(0,A,a,TIMSK_SUFIX);

tmrcnt_oc_match_int_disable(0,A,a,TIMSK_SUFIX);

#   if defined(__AVR_ATmega640__) \
    || defined(__AVR_ATmega1280__) \
    || defined(__AVR_ATmega2560__)
tmrcnt_oc_set_pin_mode(0,B,b);
tmrcnt_oc_set_pin_as_ouput(0,B,b);
tmrcnt_oc_force_ouput_compare(0,B,b);
tmrcnt_get_oc(0,B,b,8);
tmrcnt_set_oc(0,B,b,8);
tmrcnt_oc_match_int_enable(0,B,b, TIMSK_SUFIX);
tmrcnt_oc_match_int_disable(0,B,b, TIMSK_SUFIX);
#   endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
#endif

#if defined(__AVR_ATmega128__)
tmrcnt_oc_set_pin_mode(0,,a);

tmrcnt_oc_set_pin_as_ouput(0,,a);

tmrcnt_oc_force_ouput_compare(0,,a);

tmrcnt_get_oc(0,,a,8);

tmrcnt_set_oc(0,,a,8);

tmrcnt_oc_match_int_enable(0,,a,);

tmrcnt_oc_match_int_disable(0,,a,);
#endif
