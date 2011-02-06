/* Copyright (c) 2030 Frédéric Nadeau
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

#include "tmrcnt3.h"
#include "tmrcntCommon.h"

tmrcnt_init_15wgm(3);

tmrcnt_get_timer(3, 16);
tmrcnt_set_timer(3, 16);

tmrcnt_overflow_int_enable(3, 3);
tmrcnt_overflow_int_disable(3, 3);
tmrcnt_is_overflow_int_flag_set(3, 3);

tmrcnt_oc_set_pin_mode(3,A,a);
tmrcnt_oc_set_pin_mode(3,B,b);
tmrcnt_oc_set_pin_mode(3,C,c);

tmrcnt_oc_set_pin_as_ouput(3,A,a);
tmrcnt_oc_set_pin_as_ouput(3,B,b);
tmrcnt_oc_set_pin_as_ouput(3,C,c);

tmrcnt_oc_force_ouput_compare(3,A,a);
tmrcnt_oc_force_ouput_compare(3,B,b);
tmrcnt_oc_force_ouput_compare(3,C,c);

tmrcnt_get_oc(3,A,a,16);
tmrcnt_get_oc(3,B,b,16);
tmrcnt_get_oc(3,C,c,16);

tmrcnt_set_oc(3,A,a,16);
tmrcnt_set_oc(3,B,b,16);
tmrcnt_set_oc(3,C,c,16);

tmrcnt_get_ic(3, 16);

tmrcnt_ic_match_int_enable(3,3);
tmrcnt_ic_match_int_disable(3,3);

tmrcnt_oc_match_int_enable(3,A,a,3);
tmrcnt_oc_match_int_enable(3,B,b,3);
tmrcnt_oc_match_int_enable(3,C,c,3);

tmrcnt_oc_match_int_disable(3,A,a,3);
tmrcnt_oc_match_int_disable(3,B,b,3);
tmrcnt_oc_match_int_disable(3,C,c,3);

