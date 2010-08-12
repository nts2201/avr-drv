/*! \file usartDef.h
 \brief This file declares \c typedef used by the USART module.

 Not all part of the following \c enum are available to all devices.

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


#ifndef USARTDEF_H_
#define USARTDEF_H_

#include "usartCoreSelection.h"

#if defined(__DOXYGEN__)
typedef enum usart_port_e /*!< Enum of available port. */
{
    usart_port_0,		/*!< USART port 0. */
	usart_port_1,		/*!< USART port 1. */
	usart_port_2,		/*!< USART port 2. */
	usart_port_3,		/*!< USART port 3. */
}usart_port_t; /*!< Typedef of #usart_port_e. */
#else
typedef enum usart_port_e
{
    usart_port_0,
#if USART_NUM_PORT > 1
    usart_port_1,
#elif USART_NUM_PORT == 4
    usart_port_2,
    usart_port_3,
#endif
}usart_port_t;
#endif

typedef enum usart_bit_e /*!< Number of bits used by the USART module. */
{
    usart_bit_5,	/*!< USART use 5 bits. */
	usart_bit_6,	/*!< USART use 6 bits. */
	usart_bit_7,	/*!< USART use 7 bits. */
	usart_bit_8,	/*!< USART use 8 bits. */
	usart_bit_9,	/*!< USART use 9 bits. */
}usart_bit_t; /*!< Typedef of #usart_bit_e. */

typedef enum usart_parity_e /*!< Parity bit that will be added to frame. */
{
    usart_parity_None, /*!< No parity bit. */
	usart_parity_Even, /*!< Use even parity bit. */
	usart_parity_Odd /*!< Use odd parity bit. */
}usart_parity_t; /*!< Typedef for #usart_parity_e. */

typedef enum usart_stop_bit_e /*!< How many stop bit will be added to frame. */
{
    usart_stop_bit_1, /*!< Add one stop bit. */
    usart_stop_bit_2, /*!< Add two stop bit. */
}usart_stop_bit_t; /*!< Typedef for #usart_stop_bit_e. */

typedef enum usart_mode_e /*!< Mode into witch USART will be configured. */
{
    usart_mode_async, /*!< Asynchronous, Most likely what you need. */
    usart_mode_sync_master, /*!< Synchronous mode. We are the clock source. */
    usart_mode_sync_slave, /*!< Synchronous mode. Clock source must be provided. */
}usart_mode_t;/*!< Typedef for #usart_mode_e. */

#endif /* USARTDEF_H_ */
