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

/*! \file twi.h
 \defgroup drv_twi <spi.h>: Two Wire Interface
 \brief API for Atmel TWI module.

 \author Frédéric Nadeau
 */

#ifndef TWI_H_
#define TWI_H_

void twi_init(uint32_t clkio, uint8_t uwBitrateKHz);
void twi_set_bitrate(uint32_t clkio, uint8_t uwBitrateKHz);
void twi_enable_pullup(void);
void twi_set_slave_address( void );
void twi_enable_slave_addressing( void );

void twi_enable_int(void);
void twi_disable_int(void);

void twi_send_start(void);
void twi_send_stop(void);
void twi_wait_completion(void);
void twi_send_byte(uint8_t ubData);
void twi_receive_byte(uint8_t ubAck);
uint8_t twi_get_received_byte(void);
uint8_t twi_get_status(void);



#endif /*TWI_H_*/
