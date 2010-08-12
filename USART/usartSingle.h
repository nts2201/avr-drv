/*! \file usartSingle.h
 \brief Function declaration for device with a single USART.

 \author Frédéric Nadeau

 \warning Copyright (c) 2008 Frédéric Nadeau
 All rights reserved.


 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:\n
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.\n
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.\n
 3. The name of the author nor the names of its contributors may not
 be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef USARTSINGLE_H_
#define USARTSINGLE_H_

#include <stdint.h>

int usart_single_set_baud_rate(uint32_t baudRate);
int usart_single_set_num_bit(USART_NumBits_t numBit);
int usart_single_set_parity(USART_Parity_t partity);
int usart_single_set_stop_bit(USART_StopBit_t stopBit);
int usart_single_set_mode(USART_Mode_t mode);

int usart_single_enable_rx(_Bool enable);
int usart_single_enable_tx(_Bool enable);

int usart_single_putc(char data);
int usart_single_getc(char* data);

_Bool usart_single_is_tx(void);

int usart_single_enable_rx_int(_Bool enable);
int usart_single_enable_tx_buf_int(_Bool enable);
int usart_single_enable_tx_cmp_int(_Bool enable);

int usart_single_putcISR(char data);
int usart_single_getcISR(char *data);

#endif /* USARTSINGLE_H_ */
