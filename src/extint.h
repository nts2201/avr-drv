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
/*! \file extint.h
 \brief Function definition for External Interrupt module.

 \todo Add support for device with fewer than 8 external interrupt
 \todo Validate any edge capability for other devices

 \author Frédéric Nadeau
 */
#ifndef __EXTINT_H_
#define __EXTINT_H_

#if defined(__DOXYGEN__)
/*! List of external interrupt sense control.
 *
 * Some device do not implement all possibility.
 * */
enum extint_sense_ctrl_e
{
    extint_sense_ctrl_lowLevel, /*!< Low level on INT0 pin generates an interrupt request. */
    extint_sense_ctrl_anyEdge, /*!< Any level change on INT0 pin generates an interrupt request. */
    extint_sense_ctrl_fallingEdge, /*!< Change from 1 to 0 on INT0 pin generates an interrupt request. */
    extint_sense_ctrl_risingEdge /*!< Change from 0 to 1 on INT0 pin generates an interrupt request. */
};

/*! List of external interrupt sense control typedef. */
typedef extint_sense_ctrl_e extint_sense_ctrl_t;
#else
typedef enum extint_sense_ctrl_e
{
    extint_sense_ctrl_lowLevel = 0,
#if defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
    extint_sense_ctrl_anyEdge,
#endif
    extint_sense_ctrl_fallingEdge = 2,
    extint_sense_ctrl_risingEdge
}extint_sense_ctrl_t;
#endif

void extint_set_sense_control(extint_sense_ctrl_t senseCtrl, uint8_t pin);

void extint_int_enable(uint8_t pin);
void extint_int_disable(uint8_t pin);

#endif /*__EXTINT_H_*/
