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
#include <avr/io.h>

#include "extint.h"

#ifdef EICRB
void extint_set_sense_control(extint_sense_ctrl_t senseCtrl, uint8_t pin)
{

    switch (pin)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        EICRA &= ~(0x03 << (pin << 1));//Erase current state
        EICRA |= (senseCtrl << (pin << 1));
        break;

    case 4:
    case 5:
    case 6:
    case 7:
        EICRB &= ~(0x03 << ((pin & 0x03) << 1));//Erase current state
        EICRB |= (senseCtrl << ((pin & 0x03) << 1));
        break;

    default:
        break;
    }
}
#else
void extint_set_sense_control(extint_sense_ctrl_t senseCtrl, uint8_t pin)
{
    EICRA &= ~(0x03 << (pin << 1));//Erase current state
    EICRA |= (senseCtrl << (pin << 1));
}
#endif

void extint_int_enable(uint8_t pin)
{
    EIMSK |= (1 << pin);
}

void extint_int_disable(uint8_t pin)
{
    EIMSK &= ~(1 << pin);
}
