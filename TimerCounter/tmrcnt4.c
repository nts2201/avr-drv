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

#include "tmrcnt4.h"
#include "tmrcntCommon.h"

tmrcnt_init_15wgm(4);

tmrcnt_get_timer(4, 16);
tmrcnt_set_timer(4, 16);

tmrcnt_overflow_int_enable(4, 4);
tmrcnt_overflow_int_disable(4, 4);
tmrcnt_is_overflow_int_flag_set(4, 4);

#if !defined(__AVR_ATmega1281__) \
&& !defined(__AVR_ATmega2561__)

tmrcnt_oc_set_pin_mode(4,A,a);
tmrcnt_oc_set_pin_mode(4,B,b);
tmrcnt_oc_set_pin_mode(4,C,c);

#if !defined(__AVR_ATmega128RFA1__)
tmrcnt_oc_set_pin_as_ouput(4,A,a);
tmrcnt_oc_set_pin_as_ouput(4,B,b);
tmrcnt_oc_set_pin_as_ouput(4,C,c);
#endif

tmrcnt_oc_force_ouput_compare(4,A,a);
tmrcnt_oc_force_ouput_compare(4,B,b);
tmrcnt_oc_force_ouput_compare(4,C,c);

tmrcnt_get_oc(4,A,a,16);
tmrcnt_get_oc(4,B,b,16);
tmrcnt_get_oc(4,C,c,16);

tmrcnt_set_oc(4,A,a,16);
tmrcnt_set_oc(4,B,b,16);
tmrcnt_set_oc(4,C,c,16);

tmrcnt_get_ic(4, 16);

tmrcnt_ic_match_int_enable(4,4);
tmrcnt_ic_match_int_disable(4,4);

tmrcnt_oc_match_int_enable(4,A,a,4);
tmrcnt_oc_match_int_enable(4,B,b,4);
tmrcnt_oc_match_int_enable(4,C,c,4);

tmrcnt_oc_match_int_disable(4,A,a,4);
tmrcnt_oc_match_int_disable(4,B,b,4);
tmrcnt_oc_match_int_disable(4,C,c,4);

#endif
