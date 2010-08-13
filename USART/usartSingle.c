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

/*! \file usartSingle.h
 \brief This is the core file for device with a single USART.

 \author Frédéric Nadeau
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

#include "avr-drv-errno.h"
#include "io_pin/io_pin.h"

extern int usart_baud_rate_get_ubrb(uint32_t uiBaudRate, uint32_t uiClk, uint8_t ubTol, usart_mode_t mode, uint16_t* puwUbrr);

#define USART_RX_ERR_MASK	0x1C //0b0001 1100 //TODO Check these value
#define USART_RX_CHAR_IN	0x80 //0b1000 0000

int usart_single_set_baud_rate(uint32_t baudRate) {

	uint16_t uwBaud;
	int result = usartBaudRateGetUBRR(baudRate, 2,USART_Mode_Async, &uwBaud);

	if(0 <= result)
	{
		UBRRH = uwBaud >> 8;
		UBRRL = uwBaud;

		if (1 == result) {
			UCSRC |= _BV(1<<U2X);
			result = 0;
		} else {
			UCSRC &= ~(_BV(1<<U2X));
		}
		result = 0;
	}
	else
	{}


	return result;
}

void usart_single_set_baud_rate_precalc(uint16_t ubrr, _Bool use2x)
{
#ifdef UBRR
    UBRR = ubrr;
#else
    UBRRH = (uint8_t)(ubrr >> 8);
    UBRRL = (uint8_t)ubrr;
#endif
    if(TRUE == use2x)
    {
        UCSRC |= _BV(1<<U2X);
    }
    else
    {
        UCSRC &= ~(_BV(1<<U2X));
    }
}

int usart_single_set_num_bit(USART_NumBits_t numBit) {
	uint8_t ubBit;
	switch (numBit) {
	case USART_NumBits_5:
		ubBit = 0x00;
		break;
	case USART_NumBits_6:
		ubBit = 0x01;
		break;
	case USART_NumBits_7:
		ubBit = 0x02;
		break;
	case USART_NumBits_8:
		ubBit = 0x03;
		break;
	case USART_NumBits_9:
		ubBit = 0x07;
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}
	UCSRC &= ~(_BV(UCSZ0) | _BV(UCSZ1) | _BV(UCSZ1));
	UCSRC |= (ubBit << UCSZ0);

	return 0;
}

int usart_single_set_parity(USART_Parity_t partity) {
	uint8_t ubParity;
	switch (partity) {
	case USART_Parity_None:
		ubParity = 0;
		break;
	case USART_Parity_Even:
		ubParity = 2;
		break;
	case USART_Parity_Odd:
		ubParity = 3;
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}
	UCSRC &= ~(_BV(UPM0) | _BV(UPM1));
	UCSRC = (ubParity << UPM0);

	return 0;
}

int usart_single_set_stop_bit(USART_StopBit_t stopBit) {
	switch (stopBit) {
	case USART_StopBit_1:
		UCSRC &= ~(_BV(USBS));
		break;
	case USART_StopBit_2:
		UCSRC |= _BV(USBS);
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}

	return 0;
}

int usart_single_set_mode(USART_Mode_t mode) {
	switch(mode)
	{
	case USART_Mode_Async:
		UCSRC &= ~(_BV(UMSEL));
		break;
	case USART_Mode_SyncMaster:
		UCSRC = _BV(UMSEL);
		XCK0_DDR |= _BV(XCK0_DDx);
		break;
	case USART_Mode_SyncSlave:
		UCSRC = _BV(UMSEL);
		XCK0_DDR &= ~(_BV(XCK0_DDx));
		break;
	default:
		errno = EINVAL;
		return -1;
		break;
	}
	return 0;
}

int usart_single_enable_rx(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(RXEN);
	} else {
		UCSRB &= ~_BV(RXEN);
	}

	return 0;
}

int usart_single_enable_tx(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(TXEN);
	} else {
		UCSRB &= ~_BV(TXEN);
	}

	return 0;
}

int usart_single_putc(char data) {
	if (false != (UCSRB & (1 << TXEN))) {
		while (!(UCSRA & (1 << UDRE)))
			;
		UDR = data;
		return 0;
	} else {
		errno = ETXDISABLED;
		return -1;
	}
}

int usart_single_getc(char* data) {
	int wRetVal = 0;
	uint8_t ubStatus = UCSRB;

	if ((ubStatus & (1 << RXEN)) == 0) {
		errno = ERXDISABLED;
		wRetVal = -1;
	} else {
		ubStatus = UCSRA;

		if ((ubStatus & USART_RX_CHAR_IN) != 0) {
			if ((ubStatus & USART_RX_ERR_MASK) != 0) {
				switch (ubStatus) {
				case 0x04:
					errno = ERXPARITY;
					wRetVal = -1;//USART_ERR_PARITY;
					break;
				case 0x08:
					errno = ERXOVERRUN;
					wRetVal = -1;//USART_ERR_OVERRUN;
					break;
				case 0x10:
					errno = ERXFRAM;
					wRetVal = -1;//USART_ERR_FRAME;
					break;
				default:
					errno = ERXMULTI;
					wRetVal = -1;//USART_ERR_RX_MULTI;
					break;
				}
			} else {
			}
			*data = UDR;
		} else {
			wRetVal = -1;//USART_ERR_RX_EMPTY;
		}
	}
	return wRetVal;
}

_Bool usart_single_is_tx(void) {
	if ((UCSRA & (1 << UDRE))) {
		return false;
	} else {
		return true;
	}
}

int usart_single_enable_rx_int(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(RXCIE);
	} else {
		UCSRB &= ~_BV(RXCIE);
	}

	return 0;
}

int usart_single_enable_tx_buf_int(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(UDRIE);
	} else {
		UCSRB &= ~_BV(UDRIE);
	}

	return 0;
}

int usart_single_enable_tx_cmp_int(_Bool enable) {
	if (true == enable) {
		UCSRB |= _BV(TXCIE);
	} else {
		UCSRB &= ~_BV(TXCIE);
	}

	return 0;
}

int usart_single_putcISR(char data) {
	UDR = data;

	return 0;
}

int usart_single_getcISR(char *data) {
	int wRetVal = 0;
	uint8_t ubStatus = 0x00;

	ubStatus = UCSRA;
	*data = UDR;

	if ((ubStatus & USART_RX_ERR_MASK) != 0) {
		switch (ubStatus) {
		case 0x04:
			errno = ERXPARITY;
			wRetVal = -1;//USART_ERR_PARITY;
			break;
		case 0x08:
			errno = ERXOVERRUN;
			wRetVal = -1;//USART_ERR_OVERRUN;
			break;
		case 0x10:
			errno = ERXFRAM;
			wRetVal = -1;//USART_ERR_FRAME;
			break;
		default:
			errno = ERXMULTI;
			wRetVal = -1;//USART_ERR_RX_MULTI;
			break;
		}
	} else {
	}

	return wRetVal;
}
