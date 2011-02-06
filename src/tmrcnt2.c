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

#include "tmrcnt2.h"
#include "tmrcntCommon.h"


tmrcnt_init_7(2, TCCR2B, ((1 << CS22) | (1 << CS21) | (1 << CS20)), CS20, TCCR2A, TCCR2B);


void tmrcnt2_set_clk_source(tmrcnt2_clk_src_t source)
{
    ASSR &= ~(_BV(EXCLK) | _BV(AS2));

    switch (source)
    {
    case tmrcnt2_clk_src_clkIO:
        break;

    case tmrcnt2_clk_src_ExtClk:
        ASSR |= _BV(EXCLK);
        break;

    case tmrcnt2_clk_src_ExtOsc:
        ASSR |= _BV(EXCLK);
        ASSR |= _BV(AS2);
        break;

    default:
        break;
    }
}

tmrcnt_get_timer(2, 8);
tmrcnt_set_timer(2, 8);

tmrcnt_overflow_int_enable(2, 2);
tmrcnt_overflow_int_disable(2, 2);
tmrcnt_is_overflow_int_flag_set(2, 2);

tmrcnt_oc_set_pin_mode(2,A,a);
tmrcnt_oc_set_pin_mode(2,B,b);

tmrcnt_oc_set_pin_as_ouput(2,A,a);
tmrcnt_oc_set_pin_as_ouput(2,B,b);

tmrcnt_oc_force_ouput_compare(2,A,a);
tmrcnt_oc_force_ouput_compare(2,B,b);

tmrcnt_get_oc(2,A,a,8);
tmrcnt_get_oc(2,B,b,8);

tmrcnt_set_oc(2,A,a,8);
tmrcnt_set_oc(2,B,b,8);

tmrcnt_oc_match_int_enable(2,A,a,2);
tmrcnt_oc_match_int_enable(2,B,b,2);

tmrcnt_oc_match_int_disable(2,A,a,2);
tmrcnt_oc_match_int_disable(2,B,b,2);

