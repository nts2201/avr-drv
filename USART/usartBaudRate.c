/* Copyright (c) 2008, 2010 Frédéric Nadeau
   Copyright (c) 2007  Cliff Lawson
   Copyright (c) 2007  Carlos Lamas
   All rights reserved.

   Part of the following code is derived from setbaud.h found in avr-libc
   project ditributed under WinAVR20081205.

   The following copyright are included to respect the license of AVR-Libc.

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

/*! \file usartBaudRate.c
 \brief This file calculate value of baud rate register for the USART.
 */

#include "usartDef.h"
#include "xtal/xtal.h"

#include <stdbool.h>
#include <stdint.h>

static uint16_t get_UBRR(uint32_t uiBaudRate, uint8_t ubTol, uint8_t factor)
{
	//Get clock
	uint32_t uiClk = xtalGetClockFreq();
	return (((uiClk) + (factor>>1) * (uiBaudRate)) / (factor * (uiBaudRate)) - 1UL);
}

static _Bool check_Tol(uint32_t uiBaudRate, uint16_t uwUbrr, uint8_t ubTol, uint8_t factor)
{
	uint32_t uiClk = xtalGetClockFreq();
	if (100 * (uiClk) > (factor * ((uwUbrr) + 1)) * (100UL * (uiBaudRate) + (uiBaudRate)
			* ubTol)) {
		return false;
	} else if (100 * (uiClk) < (factor * ((uwUbrr) + 1)) * (100 * (uiBaudRate)
			- (uiBaudRate) * ubTol)) {
		return false;
	}

	return true;
}

int usart_baud_rate_get_UBRR(uint32_t uiBaudRate, uint8_t ubTol, USART_Mode_t mode, uint16_t* puwUbrr)
{
	uint32_t uiClk;
	uint16_t uwBaud;
	int retVal = 0;

	if(NULL == puwUbrr)
	{
		errno = EINVAL;
		return -1;
	}

	//Get clock
	uiClk = xtalGetClockFreq();

	switch(mode)
	{
	case USART_Mode_Async:
	{
		//Use equation found in util/setbaud.h
		uwBaud = getUBRR(uiBaudRate,ubTol,16);

		if(false == checkTol(uiBaudRate, uwBaud, ubTol, 16))
		{
			uwBaud = getUBRR(uiBaudRate,ubTol,8);
			if(false == checkTol(uiBaudRate, uwBaud, ubTol, 8))
			{
				errno = EBAUDRATE;
				return -1;
			}
			else
			{}
		}
		else
		{}
	}
		break;
	case USART_Mode_SyncMaster:
	case USART_Mode_SyncSlave:
	{
		//Use a modified version of equation found in util/setbaud.h
		uwBaud = getUBRR(uiBaudRate,ubTol,2);

		if(false == checkTol(uiBaudRate, uwBaud, ubTol, 2))
		{
			errno = EBAUDRATE;
			return -1;
		}
		else
		{}
	}
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}

	*puwUbrr = uwBaud;
	return retVal;
}
