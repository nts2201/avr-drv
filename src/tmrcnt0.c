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

#include <stdbool.h>
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
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6490__)
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0A
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (CS00)

#elif defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega8535__)
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (CS00)

#elif defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__)\
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16M1__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega64C1__) \
|| defined(__AVR_ATmega64M1__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega128RFA1__) \
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
|| defined(__AVR_ATmega406__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny43U__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__)
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0B
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (CS00)

#else
#   warning "Device need verification"
#   if ((CS02 != CS00 + 2) && (CS01 != CS00 +1))
#       error "Verify header file for CS0x"
#   endif
#   define CLK_SEL_REG    TCCR0A
#   define CLK_SEL_REG_MASK (_BV(CS02) | _BV(CS01) | _BV(CS00))
#   define CLK_SEL_REG_OFFSET (CS00)
#endif

//Define Wave Generation Mode
#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)
#   define WGM_0_1_REG    TCCR0A

#elif defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16M1__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega64C1__) \
|| defined(__AVR_ATmega64M1__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega128RFA1__) \
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
|| defined(__AVR_ATmega406__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny43U__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__)
#   define WGM_0_1_REG    TCCR0A
#   define WGM_2_REG      TCCR0B

#elif defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega8535__)
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
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega8535__) \
|| defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)

tmrcnt_init_3(0, CLK_SEL_REG, CLK_SEL_REG_MASK, CLK_SEL_REG_OFFSET, WGM_0_1_REG);

#elif defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16M1__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega64C1__) \
|| defined(__AVR_ATmega64M1__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega128RFA1__) \
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
|| defined(__AVR_ATmega406__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny43U__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__)
tmrcnt_init_7(0, CLK_SEL_REG, CLK_SEL_REG_MASK, CLK_SEL_REG_OFFSET, WGM_0_1_REG, WGM_2_REG);
#elif defined(__AVR_ATmega8__)
void tmrcnt0_init(tmrcnt0_clk_src_t prescale)
{
    /* Force timer to stop */
    CLK_SEL_REG &= ~CLK_SEL_REG_MASK;

    CLK_SEL_REG |= (prescale<<CLK_SEL_REG_OFFSET);
}
#else
#	error "Device need verirication"
#endif

tmrcnt_get_timer(0, 8);
tmrcnt_set_timer(0, 8);

#if defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega8535__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__)
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
|| defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16M1__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega64C1__) \
|| defined(__AVR_ATmega64M1__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega406__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny43U__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)

tmrcnt_oc_set_pin_mode(0,A,a);

tmrcnt_oc_set_pin_as_ouput(0,A,a);

tmrcnt_oc_force_ouput_compare(0,A,a);

tmrcnt_get_oc(0,A,a,8);

tmrcnt_set_oc(0,A,a,8);

tmrcnt_oc_match_int_enable(0,A,a,0);

tmrcnt_oc_match_int_disable(0,A,a,0);

#   if defined(__AVR_AT90PWM1__) \
    || defined(__AVR_AT90PWM2__) \
    || defined(__AVR_AT90PWM2B__) \
    || defined(__AVR_AT90PWM3__) \
    || defined(__AVR_AT90PWM3B__) \
    || defined(__AVR_AT90PWM216__) \
    || defined(__AVR_AT90PWM316__) \
    || defined(__AVR_AT90USB82__) \
    || defined(__AVR_AT90USB162__) \
    || defined(__AVR_AT90USB646__) \
    || defined(__AVR_AT90USB647__) \
    || defined(__AVR_AT90USB1286__) \
    || defined(__AVR_AT90USB1287__) \
    || defined(__AVR_ATmega8U2__) \
    || defined(__AVR_ATmega16M1__) \
    || defined(__AVR_ATmega16U2__) \
    || defined(__AVR_ATmega16U4__) \
    || defined(__AVR_ATmega32C1__) \
    || defined(__AVR_ATmega32M1__) \
    || defined(__AVR_ATmega32U2__) \
    || defined(__AVR_ATmega32U4__) \
    || defined(__AVR_ATmega32U6__) \
    || defined(__AVR_ATmega48__) \
    || defined(__AVR_ATmega48A__) \
    || defined(__AVR_ATmega48P__) \
    || defined(__AVR_ATmega64C1__) \
    || defined(__AVR_ATmega64M1__) \
    || defined(__AVR_ATmega88__) \
    || defined(__AVR_ATmega88A__) \
    || defined(__AVR_ATmega88P__) \
    || defined(__AVR_ATmega88PA__) \
    || defined(__AVR_ATmega128RFA1__) \
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
    || defined(__AVR_ATmega406__) \
    || defined(__AVR_ATmega640__) \
    || defined(__AVR_ATmega644__) \
    || defined(__AVR_ATmega644A__) \
    || defined(__AVR_ATmega644P__) \
    || defined(__AVR_ATmega644PA__) \
    || defined(__AVR_ATmega1280__) \
    || defined(__AVR_ATmega1284P__) \
    || defined(__AVR_ATmega2560__) \
    || defined(__AVR_ATtiny13__) \
    || defined(__AVR_ATtiny13A__) \
    || defined(__AVR_ATtiny24__) \
    || defined(__AVR_ATtiny24A__) \
    || defined(__AVR_ATtiny43U__) \
    || defined(__AVR_ATtiny44__) \
    || defined(__AVR_ATtiny44A__) \
    || defined(__AVR_ATtiny84__)
tmrcnt_oc_set_pin_mode(0,B,b);
tmrcnt_oc_set_pin_as_ouput(0,B,b);
tmrcnt_oc_force_ouput_compare(0,B,b);
tmrcnt_get_oc(0,B,b,8);
tmrcnt_set_oc(0,B,b,8);
tmrcnt_oc_match_int_enable(0,B,b,0);
tmrcnt_oc_match_int_disable(0,B,b,0);
#   endif /* defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) */
#endif

#if  defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__)
tmrcnt_oc_set_pin_mode(0,A,a);
tmrcnt_oc_set_pin_as_ouput(0,A,a);
tmrcnt_oc_force_ouput_compare(0,A,a);
tmrcnt_get_oc(0,A,a,8);
tmrcnt_set_oc(0,A,a,8);
tmrcnt_oc_match_int_enable(0,A,a,);
tmrcnt_oc_match_int_disable(0,A,a,);
tmrcnt_oc_set_pin_mode(0,B,b);
tmrcnt_oc_set_pin_as_ouput(0,B,b);
tmrcnt_oc_force_ouput_compare(0,B,b);
tmrcnt_get_oc(0,B,b,8);
tmrcnt_set_oc(0,B,b,8);
tmrcnt_oc_match_int_enable(0,B,b,);
tmrcnt_oc_match_int_disable(0,B,b,);
#endif

#if defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega8535__)
tmrcnt_oc_set_pin_mode(0,,a);

tmrcnt_oc_set_pin_as_ouput(0,,a);

tmrcnt_oc_force_ouput_compare(0,,a);

tmrcnt_get_oc(0,,a,8);

tmrcnt_set_oc(0,,a,8);

tmrcnt_oc_match_int_enable(0,,a,);

tmrcnt_oc_match_int_disable(0,,a,);
#endif
