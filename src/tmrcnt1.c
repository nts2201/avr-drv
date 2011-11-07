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

#include "tmrcnt1.h"
#include "tmrcntCommon.h"

#if defined(TICIE1) && !defined(ICIE1)
#	define ICIE1	TICIE1
#endif

tmrcnt_init_15wgm(1);

tmrcnt_get_timer(1, 16);
tmrcnt_set_timer(1, 16);

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
tmrcnt_overflow_int_enable(1,);
tmrcnt_overflow_int_disable(1,);
tmrcnt_is_overflow_int_flag_set(1,);
#else
tmrcnt_overflow_int_enable(1, 0);
tmrcnt_overflow_int_disable(1, 0);
tmrcnt_is_overflow_int_flag_set(1, 0);
#endif

tmrcnt_oc_set_pin_mode(1,A,a);
tmrcnt_oc_set_pin_mode(1,B,b);

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
tmrcnt_oc_set_pin_mode(1,C,c);
#endif

tmrcnt_oc_set_pin_as_ouput(1,A,a);
tmrcnt_oc_set_pin_as_ouput(1,B,b);

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
tmrcnt_oc_set_pin_as_ouput(1,C,c);
#endif

tmrcnt_oc_force_ouput_compare(1,A,a);
tmrcnt_oc_force_ouput_compare(1,B,b);

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
tmrcnt_oc_force_ouput_compare(1,C,c);
#endif

tmrcnt_get_oc(1,A,a,16);
tmrcnt_get_oc(1,B,b,16);

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
tmrcnt_get_oc(1,C,c,16);
#endif

tmrcnt_set_oc(1,A,a,16);
tmrcnt_set_oc(1,B,b,16);

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
tmrcnt_set_oc(1,C,c,16);
#endif

tmrcnt_get_ic(1, 16);

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
tmrcnt_ic_match_int_enable(1,);
tmrcnt_ic_match_int_disable(1,);

tmrcnt_oc_match_int_enable(1,A,a,);
tmrcnt_oc_match_int_enable(1,B,b,);
#else
tmrcnt_ic_match_int_enable(1,1);
tmrcnt_ic_match_int_disable(1,1);

tmrcnt_oc_match_int_enable(1,A,a,1);
tmrcnt_oc_match_int_enable(1,B,b,1);
#endif

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
tmrcnt_oc_match_int_enable(1,C,c,1);
#endif

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
tmrcnt_oc_match_int_disable(1,A,a,);
tmrcnt_oc_match_int_disable(1,B,b,);
#else
tmrcnt_oc_match_int_disable(1,A,a,1);
tmrcnt_oc_match_int_disable(1,B,b,1);
#endif

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
tmrcnt_oc_match_int_disable(1,C,c,1);
#endif
