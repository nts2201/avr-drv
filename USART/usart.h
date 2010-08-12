/* Copyright (c) 2008, 2010 Frédéric Nadeau
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

/*! \file usart.h
 \brief Function definition for USART module.

 \author Frédéric Nadeau
 */
#ifndef USART_H_
#define USART_H_

#include "usartCoreSelection.h"
#include "usartDef.h"

#if USART_NUM_PORT == 1
#	include "usartSingle.h"
#	define  usart_set_baud_rate(port, baud_rate) usart_single_set_baud_rate(baud_rate)
#	define  usart_set_num_bit(port, num_bit) usart_single_set_num_bit(num_bit)
#	define  usart_set_parity(port, partity) usart_single_set_parity(partity)
#	define  usart_set_stop_bit(port, stop_bit) usart_single_set_stop_bit(stop_bit)
#	define  usart_set_mode(port, mode) usart_single_set_mode(mode)

#	define  usart_enable_rx(port, enable) usart_single_enable_rx(enable)
#	define  usart_enable_tx(port, enable) usart_single_enable_tx(enable)

#	define  usart_putc(port, data) usart_single_putc(data)
#	define  usart_puts(port, data) usart_single_puts(data)
#	define  usart_getc(port, data) usart_single_getc(data)

#	define  usart_is_tx(port) usart_single_is_tx()

#	define  usart_enable_rx_int(port, enable) usart_single_enable_rx_int(enable)
#	define  usart_enable_tx_buf_int(port, enable) usart_single_enable_tx_buf_int(enable)
#	define  usart_enable_tx_cmp_int(port, enable) usart_single_enable_tx_cmp_int(enable)

#	define  usart_putcISR(port, data) usart_single_putcISR(data)
#	define  usart_getcISR(port, data) usart_single_getcISR(data)
#else
#	include "usartMulti.h"
#	define  usart_set_baud_rate(port, baudRate) usart_multi_set_baud_rate(port, baudRate)
#	define  usart_set_num_bit(port, numBit) usart_multi_set_num_bit(port, numBit)
#	define  usart_set_parity(port, partity) usart_multi_set_parity(port, partity)
#	define  usart_set_stop_bit(port, stopBit) usart_multi_set_stop_bit(port, stopBit)
#	define  usart_set_mode(port, mode) usart_multi_set_mode(port, mode)

#	define  usart_enable_rx(port, enable) usart_multi_enable_rx(port, enable)
#	define  usart_enable_tx(port, enable) usart_multi_enable_tx(port, enable)

#	define  usart_putc(port, data) usart_multi_putc(port, data)
#	define  usart_puts(port, data) usart_multi_puts(port, data)
#	define  usart_getc(port, data) usart_multi_getc(port, data)

#	define  usart_is_tx(port) usart_multi_is_tx(port)

#	define  usart_enable_rx_int(port, enable) usart_multi_enable_rx_int(port, enable)
#	define  usart_enable_tx_buf_int(port, enable) usart_multi_enable_tx_buf_int(port, enable)
#	define  usart_enable_tx_cmp_int(port, enable) usart_multi_enable_tx_cmp_int(port, enable)

#	define  usart_putcISR(port, data) usart_multi_putcISR(port, data)
#	define  usart_getcISR(port, data) usart_multi_getcISR(port, data)
#endif

#endif /* USART_H_ */
