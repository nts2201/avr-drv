/* Copyright (c) 2010 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/** \file */
/** \defgroup drv_io_pin <io_pin/io_pin.h> AVR device-specific I/O PIN definition

\code
#include <io_pin/io_pin.h>
\endcode

This header file defines missing elements from AVR-libc's <avr/io.h>.
It gives port definitions(PORTx, DDRx, PINx) to pins alternate
functions.

\warning Headers are script generated from Atmel's XML which are known to
contains errors. Open an issue if you find anything wrong in io_pin headers.
The project keeps track of changes made to Atmel's XML in order to provide the
most accurate information. Atmel has been informed for most error found in their
XML and they are slow to react(XML are taken from AVR Studio releases, which is not
that often), if they react at all.

\code
#include <io_pin/io_pin.h>

void twi_enable_pullup(void)
{
    SDA_PORT |= _BV(SDA_BIT);
    SCL_PORT |= _BV(SCL_BIT);
}
\endcode


*/

#ifndef _AVR_IO_PIN_H_
#define _AVR_IO_PIN_H_ 1

#if defined (__AVR_AT90CAN128__)
#  include <io_pin/iocan128_pin.h>
#elif defined (__AVR_AT90CAN32__)
#  include <io_pin/iocan32_pin.h>
#elif defined (__AVR_AT90CAN64__)
#  include <io_pin/iocan64_pin.h>
#elif defined (__AVR_AT90PWM1__)
#  include <io_pin/io90pwm1_pin.h>
#elif defined (__AVR_AT90PWM2__)
#  include <io_pin/io90pwm2_pin.h>
#elif defined (__AVR_AT90PWM216__)
#  include <io_pin/io90pwm216_pin.h>
#elif defined (__AVR_AT90PWM2B__)
#  include <io_pin/io90pwm2b_pin.h>
#elif defined (__AVR_AT90PWM3__)
#  include <io_pin/io90pwm3_pin.h>
#elif defined (__AVR_AT90PWM316__)
#  include <io_pin/io90pwm316_pin.h>
#elif defined (__AVR_AT90PWM3B__)
#  include <io_pin/io90pwm3b_pin.h>
#elif defined (__AVR_AT90PWM81__)
#  include <io_pin/io90pwm81_pin.h>
#elif defined (__AVR_AT90USB1286__)
#  include <io_pin/iousb1286_pin.h>
#elif defined (__AVR_AT90USB1287__)
#  include <io_pin/iousb1287_pin.h>
#elif defined (__AVR_AT90USB162__)
#  include <io_pin/iousb162_pin.h>
#elif defined (__AVR_AT90USB646__)
#  include <io_pin/iousb646_pin.h>
#elif defined (__AVR_AT90USB647__)
#  include <io_pin/iousb647_pin.h>
#elif defined (__AVR_AT90USB82__)
#  include <io_pin/iousb82_pin.h>
#elif defined (__AVR_ATmega103__)
#  include <io_pin/iom103_pin.h>
#elif defined (__AVR_ATmega128__)
#  include <io_pin/iom128_pin.h>
#elif defined (__AVR_ATmega1280__)
#  include <io_pin/iom1280_pin.h>
#elif defined (__AVR_ATmega1281__)
#  include <io_pin/iom1281_pin.h>
#elif defined (__AVR_ATmega1284__)
#  include <io_pin/iom1284_pin.h>
#elif defined (__AVR_ATmega1284P__)
#  include <io_pin/iom1284p_pin.h>
#elif defined (__AVR_ATmega128A__)
#  include <io_pin/iom128a_pin.h>
#elif defined (__AVR_ATmega128RFA1__)
#  include <io_pin/iom128rfa1_pin.h>
#elif defined (__AVR_ATmega16__)
#  include <io_pin/iom16_pin.h>
#elif defined (__AVR_ATmega161__)
#  include <io_pin/iom161_pin.h>
#elif defined (__AVR_ATmega162__)
#  include <io_pin/iom162_pin.h>
#elif defined (__AVR_ATmega163__)
#  include <io_pin/iom163_pin.h>
#elif defined (__AVR_ATmega164A__)
#  include <io_pin/iom164a_pin.h>
#elif defined (__AVR_ATmega164P__)
#  include <io_pin/iom164p_pin.h>
#elif defined (__AVR_ATmega164PA__)
#  include <io_pin/iom164pa_pin.h>
#elif defined (__AVR_ATmega165__)
#  include <io_pin/iom165_pin.h>
#elif defined (__AVR_ATmega165P__)
#  include <io_pin/iom165p_pin.h>
#elif defined (__AVR_ATmega165PA__)
#  include <io_pin/iom165pa_pin.h>
#elif defined (__AVR_ATmega168__)
#  include <io_pin/iom168_pin.h>
#elif defined (__AVR_ATmega168A__)
#  include <io_pin/iom168a_pin.h>
#elif defined (__AVR_ATmega168P__)
#  include <io_pin/iom168p_pin.h>
#elif defined (__AVR_ATmega168PA__)
#  include <io_pin/iom168pa_pin.h>
#elif defined (__AVR_ATmega169__)
#  include <io_pin/iom169_pin.h>
#elif defined (__AVR_ATmega169P__)
#  include <io_pin/iom169p_pin.h>
#elif defined (__AVR_ATmega169PA__)
#  include <io_pin/iom169pa_pin.h>
#elif defined (__AVR_ATmega16A__)
#  include <io_pin/iom16a_pin.h>
#elif defined (__AVR_ATmega16HVA__)
#  include <io_pin/iom16hva_pin.h>
#elif defined (__AVR_ATmega16HVA2__)
#  include <io_pin/iom16hva2_pin.h>
#elif defined (__AVR_ATmega16HVB__)
#  include <io_pin/iom16hvb_pin.h>
#elif defined (__AVR_ATmega16M1__)
#  include <io_pin/iom16m1_pin.h>
#elif defined (__AVR_ATmega16U2__)
#  include <io_pin/iom16u2_pin.h>
#elif defined (__AVR_ATmega16U4__)
#  include <io_pin/iom16u4_pin.h>
#elif defined (__AVR_ATmega2560__)
#  include <io_pin/iom2560_pin.h>
#elif defined (__AVR_ATmega2561__)
#  include <io_pin/iom2561_pin.h>
#elif defined (__AVR_ATmega32__)
#  include <io_pin/iom32_pin.h>
#elif defined (__AVR_ATmega323__)
#  include <io_pin/iom323_pin.h>
#elif defined (__AVR_ATmega324A__)
#  include <io_pin/iom324a_pin.h>
#elif defined (__AVR_ATmega324P__)
#  include <io_pin/iom324p_pin.h>
#elif defined (__AVR_ATmega324PA__)
#  include <io_pin/iom324pa_pin.h>
#elif defined (__AVR_ATmega325__)
#  include <io_pin/iom325_pin.h>
#elif defined (__AVR_ATmega3250__)
#  include <io_pin/iom3250_pin.h>
#elif defined (__AVR_ATmega3250P__)
#  include <io_pin/iom3250p_pin.h>
#elif defined (__AVR_ATmega325P__)
#  include <io_pin/iom325p_pin.h>
#elif defined (__AVR_ATmega328__)
#  include <io_pin/iom328_pin.h>
#elif defined (__AVR_ATmega328P__)
#  include <io_pin/iom328p_pin.h>
#elif defined (__AVR_ATmega329__)
#  include <io_pin/iom329_pin.h>
#elif defined (__AVR_ATmega3290__)
#  include <io_pin/iom3290_pin.h>
#elif defined (__AVR_ATmega3290P__)
#  include <io_pin/iom3290p_pin.h>
#elif defined (__AVR_ATmega329P__)
#  include <io_pin/iom329p_pin.h>
#elif defined (__AVR_ATmega329PA__)
#  include <io_pin/iom329pa_pin.h>
#elif defined (__AVR_ATmega32A__)
#  include <io_pin/iom32a_pin.h>
#elif defined (__AVR_ATmega32C1__)
#  include <io_pin/iom32c1_pin.h>
#elif defined (__AVR_ATmega32HVB__)
#  include <io_pin/iom32hvb_pin.h>
#elif defined (__AVR_ATmega32M1__)
#  include <io_pin/iom32m1_pin.h>
#elif defined (__AVR_ATmega32U2__)
#  include <io_pin/iom32u2_pin.h>
#elif defined (__AVR_ATmega32U4__)
#  include <io_pin/iom32u4_pin.h>
#elif defined (__AVR_ATmega32U6__)
#  include <io_pin/iom32u6_pin.h>
#elif defined (__AVR_ATmega406__)
#  include <io_pin/iom406_pin.h>
#elif defined (__AVR_ATmega48__)
#  include <io_pin/iom48_pin.h>
#elif defined (__AVR_ATmega48A__)
#  include <io_pin/iom48a_pin.h>
#elif defined (__AVR_ATmega48P__)
#  include <io_pin/iom48p_pin.h>
#elif defined (__AVR_ATmega48PA__)
#  include <io_pin/iom48pa_pin.h>
#elif defined (__AVR_ATmega64__)
#  include <io_pin/iom64_pin.h>
#elif defined (__AVR_ATmega640__)
#  include <io_pin/iom640_pin.h>
#elif defined (__AVR_ATmega644__)
#  include <io_pin/iom644_pin.h>
#elif defined (__AVR_ATmega644A__)
#  include <io_pin/iom644a_pin.h>
#elif defined (__AVR_ATmega644P__)
#  include <io_pin/iom644p_pin.h>
#elif defined (__AVR_ATmega644PA__)
#  include <io_pin/iom644pa_pin.h>
#elif defined (__AVR_ATmega645__)
#  include <io_pin/iom645_pin.h>
#elif defined (__AVR_ATmega6450__)
#  include <io_pin/iom6450_pin.h>
#elif defined (__AVR_ATmega649__)
#  include <io_pin/iom649_pin.h>
#elif defined (__AVR_ATmega6490__)
#  include <io_pin/iom6490_pin.h>
#elif defined (__AVR_ATmega649P__)
#  include <io_pin/iom649p_pin.h>
#elif defined (__AVR_ATmega64A__)
#  include <io_pin/iom64a_pin.h>
#elif defined (__AVR_ATmega64C1__)
#  include <io_pin/iom64c1_pin.h>
#elif defined (__AVR_ATmega64HVE__)
#  include <io_pin/iom64hve_pin.h>
#elif defined (__AVR_ATmega64M1__)
#  include <io_pin/iom64m1_pin.h>
#elif defined (__AVR_ATmega8__)
#  include <io_pin/iom8_pin.h>
#elif defined (__AVR_ATmega8515__)
#  include <io_pin/iom8515_pin.h>
#elif defined (__AVR_ATmega8535__)
#  include <io_pin/iom8535_pin.h>
#elif defined (__AVR_ATmega88__)
#  include <io_pin/iom88_pin.h>
#elif defined (__AVR_ATmega88A__)
#  include <io_pin/iom88a_pin.h>
#elif defined (__AVR_ATmega88P__)
#  include <io_pin/iom88p_pin.h>
#elif defined (__AVR_ATmega88PA__)
#  include <io_pin/iom88pa_pin.h>
#elif defined (__AVR_ATmega8A__)
#  include <io_pin/iom8a_pin.h>
#elif defined (__AVR_ATmega8HVA__)
#  include <io_pin/iom8hva_pin.h>
#elif defined (__AVR_ATmega8U2__)
#  include <io_pin/iom8u2_pin.h>
#elif defined (__AVR_ATtiny10__)
#  include <io_pin/iotn10_pin.h>
#elif defined (__AVR_ATtiny11__)
#  include <io_pin/iotn11_pin.h>
#elif defined (__AVR_ATtiny12__)
#  include <io_pin/iotn12_pin.h>
#elif defined (__AVR_ATtiny13__)
#  include <io_pin/iotn13_pin.h>
#elif defined (__AVR_ATtiny13A__)
#  include <io_pin/iotn13a_pin.h>
#elif defined (__AVR_ATtiny15__)
#  include <io_pin/iotn15_pin.h>
#elif defined (__AVR_ATtiny167__)
#  include <io_pin/iotn167_pin.h>
#elif defined (__AVR_ATtiny20__)
#  include <io_pin/iotn20_pin.h>
#elif defined (__AVR_ATtiny22__)
#  include <io_pin/iotn22_pin.h>
#elif defined (__AVR_ATtiny2313__)
#  include <io_pin/iotn2313_pin.h>
#elif defined (__AVR_ATtiny2313A__)
#  include <io_pin/iotn2313a_pin.h>
#elif defined (__AVR_ATtiny24__)
#  include <io_pin/iotn24_pin.h>
#elif defined (__AVR_ATtiny24A__)
#  include <io_pin/iotn24a_pin.h>
#elif defined (__AVR_ATtiny25__)
#  include <io_pin/iotn25_pin.h>
#elif defined (__AVR_ATtiny26__)
#  include <io_pin/iotn26_pin.h>
#elif defined (__AVR_ATtiny261__)
#  include <io_pin/iotn261_pin.h>
#elif defined (__AVR_ATtiny261A__)
#  include <io_pin/iotn261a_pin.h>
#elif defined (__AVR_ATtiny28__)
#  include <io_pin/iotn28_pin.h>
#elif defined (__AVR_ATtiny4__)
#  include <io_pin/iotn4_pin.h>
#elif defined (__AVR_ATtiny40__)
#  include <io_pin/iotn40_pin.h>
#elif defined (__AVR_ATtiny4313__)
#  include <io_pin/iotn4313_pin.h>
#elif defined (__AVR_ATtiny43U__)
#  include <io_pin/iotn43u_pin.h>
#elif defined (__AVR_ATtiny44__)
#  include <io_pin/iotn44_pin.h>
#elif defined (__AVR_ATtiny44A__)
#  include <io_pin/iotn44a_pin.h>
#elif defined (__AVR_ATtiny45__)
#  include <io_pin/iotn45_pin.h>
#elif defined (__AVR_ATtiny461__)
#  include <io_pin/iotn461_pin.h>
#elif defined (__AVR_ATtiny461A__)
#  include <io_pin/iotn461a_pin.h>
#elif defined (__AVR_ATtiny48__)
#  include <io_pin/iotn48_pin.h>
#elif defined (__AVR_ATtiny5__)
#  include <io_pin/iotn5_pin.h>
#elif defined (__AVR_ATtiny84__)
#  include <io_pin/iotn84_pin.h>
#elif defined (__AVR_ATtiny85__)
#  include <io_pin/iotn85_pin.h>
#elif defined (__AVR_ATtiny861__)
#  include <io_pin/iotn861_pin.h>
#elif defined (__AVR_ATtiny861A__)
#  include <io_pin/iotn861a_pin.h>
#elif defined (__AVR_ATtiny87__)
#  include <io_pin/iotn87_pin.h>
#elif defined (__AVR_ATtiny88__)
#  include <io_pin/iotn88_pin.h>
#elif defined (__AVR_ATtiny9__)
#  include <io_pin/iotn9_pin.h>
#else
#  if !defined(__COMPILING_AVR_LIBC__)
#    warning "device type not defined"
#  endif
#endif
#endif /* _AVR_IO_PIN_H_ */

