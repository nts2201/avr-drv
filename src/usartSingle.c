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

extern int usart_baud_rate_get_ubrb(uint32_t uiBaudRate, uint32_t uiClk,
        uint8_t ubTol, usart_mode_t mode, uint16_t* puwUbrr);

#define USART_RX_ERR_MASK   (_BV(PE) | _BV(DOR) | _BV(FE)) //0b0001 1100

int usart_single_init(uint32_t ulBaudRate, uint32_t uiClk, usart_bit_t bit,
        usart_parity_t parity, usart_stop_bit_t stopBit, usart_mode_t mode)
{
    int wRetVal = USART_OK;

    wRetVal = usart_single_set_baud_rate(ulBaudRate, uiClk, mode);
    if (0 == wRetVal)
    {
        usart_single_set_mode(mode);
        usart_single_set_num_bit(bit);
        usart_single_set_parity(parity);
        usart_single_set_stop_bit(stopBit);
    }
    else
    {
    }

    return wRetVal;
}

int usart_single_set_baud_rate(uint32_t baudRate, uint32_t uiClk, usart_mode_t mode)
{

    uint16_t uwBaud;
    int result = usart_baud_rate_get_ubrb(baudRate, uiClk, 2, mode,
            &uwBaud);

    if (0 <= result)
    {
        UBRRH = uwBaud >> 8;
        UBRRL = uwBaud;

        if (1 == result)
        {
            UCSRC |= _BV(1 << U2X);
            result = 0;
        }
        else
        {
            UCSRC &= ~(_BV(1 << U2X));
        }
        result = 0;
    }
    else
    {
    }

    return result;
}

void usart_single_set_baud_rate_precalc(uint16_t ubrr, _Bool use2x)
{
#ifdef UBRR
    UBRR = ubrr;
#else
    UBRRH = (uint8_t) (ubrr >> 8);
    UBRRL = (uint8_t) ubrr;
#endif
    if (TRUE == use2x)
    {
        UCSRC |= _BV(1 << U2X);
    }
    else
    {
        UCSRC &= ~(_BV(1 << U2X));
    }
}

void usart_single_set_num_bit(usart_bit_t numBit)
{
    UCSRC &= ~(_BV(UCSZ0) | _BV(UCSZ1) | _BV(UCSZ1));
    UCSRC |= (numBit << UCSZ0);
}

void usart_single_set_parity(usart_parity_t partity)
{
    UCSRC &= ~(_BV(UPM0) | _BV(UPM1));
    UCSRC = (partity << UPM0);
}

void usart_single_set_stop_bit(usart_stop_bit_t stopBit)
{

    if (usart_stop_bit_1 == stopBit)
    {
        UCSRC &= ~(_BV(USBS));
    }
    else
    {
        UCSRC |= _BV(USBS);
    }
}

void usart_single_set_mode(usart_mode_t mode)
{
    switch (mode)
    {
    case usart_mode_async:
        UCSRC &= ~(_BV(UMSEL));
        break;
    case usart_mode_sync_master:
        UCSRC = _BV(UMSEL);
        XCK_DDR |= _BV(XCK_BIT);
        break;
    case usart_mode_sync_slave:
        UCSRC = _BV(UMSEL);
        XCK_DDR &= ~(_BV(XCK_BIT));
        break;
    default:
        break;
    }
}

void usart_single_enable_rx(_Bool enable)
{
    if (true == enable)
    {
        UCSRB |= _BV(RXEN);
    }
    else
    {
        UCSRB &= ~_BV(RXEN);
    }
}

void usart_single_enable_tx(_Bool enable)
{
    if (true == enable)
    {
        UCSRB |= _BV(TXEN);
    }
    else
    {
        UCSRB &= ~_BV(TXEN);
    }
}

int usart_single_putc(char data)
{
    //Check if TX is enabled so that we don't loop infinitely
    if (false != (UCSRB & _BV(TXEN)))
    {
        loop_while_bit_is_clear(UCSRA, UDRE);
        UDR = data;
        return 0;
    }
    else
    {
        avr_drv_errno = ETXDISABLED;
        return -1;
    }
}

int usart_single_getc(char* data)
{
    int wRetVal;
    uint8_t ubStatus = UCSRB;

    if ((ubStatus & _BV(RXEN)) == 0)
    {
        avr_drv_errno = ERXDISABLED;
        wRetVal = -1;
    }
    else
    {
        ubStatus = UCSRA;

        if ((ubStatus & _BV(RCX)) != 0)
        {
            if ((ubStatus & USART_RX_ERR_MASK) != 0)
            {
                switch (ubStatus)
                {
                case _BV(PE):
                    avr_drv_errno = ERXPARITY;
                    wRetVal = -1;//USART_ERR_PARITY;
                    break;
                case _BV(DOR):
                    avr_drv_errno = ERXOVERRUN;
                    wRetVal = -1;//USART_ERR_OVERRUN;
                    break;
                case _BV(FE):
                    avr_drv_errno = ERXFRAM;
                    wRetVal = -1;//USART_ERR_FRAME;
                    break;
                default:
                    avr_drv_errno = ERXMULTI;
                    wRetVal = -1;//USART_ERR_RX_MULTI;
                    break;
                }
            }
            else
            {
            }
            *data = UDR;
            wRetVal = 1;
        }
        else
        {
            wRetVal = 0;//USART_ERR_RX_EMPTY;
        }
    }
    return wRetVal;
}

void usart_single_enable_rx_int(_Bool enable)
{
    if (true == enable)
    {
        UCSRB |= _BV(RXCIE);
    }
    else
    {
        UCSRB &= ~_BV(RXCIE);
    }
}

void usart_single_enable_tx_buf_int(_Bool enable)
{
    if (true == enable)
    {
        UCSRB |= _BV(UDRIE);
    }
    else
    {
        UCSRB &= ~_BV(UDRIE);
    }
}

void usart_single_enable_tx_cmp_int(_Bool enable)
{
    if (true == enable)
    {
        UCSRB |= _BV(TXCIE);
    }
    else
    {
        UCSRB &= ~_BV(TXCIE);
    }
}

void usart_single_putcISR(char data)
{
    UDR = data;
}

int usart_single_getcISR(char *data)
{
    int wRetVal = 1;
    uint8_t ubStatus = 0x00;

    ubStatus = UCSRA;
    *data = UDR;

    if ((ubStatus & USART_RX_ERR_MASK) != 0)
    {
        switch (ubStatus)
        {
        case _BV(PE):
            avr_drv_errno = ERXPARITY;
            wRetVal = -1;//USART_ERR_PARITY;
            break;
        case _BV(DOR):
            avr_drv_errno = ERXOVERRUN;
            wRetVal = -1;//USART_ERR_OVERRUN;
            break;
        case _BV(FE):
            avr_drv_errno = ERXFRAM;
            wRetVal = -1;//USART_ERR_FRAME;
            break;
        default:
            avr_drv_errno = ERXMULTI;
            wRetVal = -1;//USART_ERR_RX_MULTI;
            break;
        }
    }
    else
    {
    }

    return wRetVal;
}
