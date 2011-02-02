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

/*! \file usart.c
 \brief At build time, this file will build the appropriate core.

 \author Frédéric Nadeau
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>

#include "avr-drv-errno.h"
#include "usart.h"
#include "io_pin/io_pin.h"

#include "usartBaudRate.c"

#define USART_RX_ERR_MASK   (_BV(PE) | _BV(DOR) | _BV(FE)) //0b0001 1100

#define write_to_ucsrc(ucsrc, value)    (ucsrc = value)

#if defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATmega8515__) \
|| defined(__AVR_ATmega8535__) \
|| defined(__AVR_ATtiny2313__) \
|| defined(__AVR_ATtiny2313A__) \
|| defined(__AVR_ATtiny4313__)
usart_port_t usart0 = {&UDR, &UCSRA, &UCSRB, &UCSRC, &UBRRH, &UBRRL, &XCK_DDR, XCK_BIT};

#   ifdef URSEL
#       undef write_to_ucsrc
#       define write_to_ucsrc(ucsrc, value)    (ucsrc = _BV(URSEL) | (value))
#   endif

//Some device define PE as UPE
#   if defined(UMSEL0) && !defined(UMSEL) && (UMSEL0 == 6)
#       define UMSEL   UMSEL0
#   endif

#elif defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__)  \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__)  \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega165PA__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__)  \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325P__)  \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__)  \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__) \
|| defined(__AVR_ATmega6490__)
usart_port_t usart0 = {&UDR0, &UCSR0A, &UCSR0B, &UCSR0C, &UBRR0H, &UBRR0L, &XCK_DDR, XCK_BIT};
#elif defined(__AVR_ATmega644__)
usart_port_t usart0 = {&UDR0, &UCSR0A, &UCSR0B, &UCSR0C, &UBRR0H, &UBRR0L, &XCK0_DDR, XCK0_BIT};
#elif defined(__AVR_AT90USB82__) \
|| defined(__AVR_AT90USB162__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega8U2__) \
|| defined(__AVR_ATmega16U2__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32U2__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__)
usart_port_t usart1 = {&UDR1, &UCSR1A, &UCSR1B, &UCSR1C, &UBRR1H, &UBRR1L, &XCK1_DDR, XCK1_BIT};
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega162__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega164PA__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
usart_port_t usart0 = {&UDR0, &UCSR0A, &UCSR0B, &UCSR0C, &UBRR0H, &UBRR0L, &XCK0_DDR, XCK0_BIT};
usart_port_t usart1 = {&UDR1, &UCSR1A, &UCSR1B, &UCSR1C, &UBRR1H, &UBRR1L, &XCK1_DDR, XCK1_BIT};
#   if defined(__AVR_ATmega640__) \
    || defined(__AVR_ATmega1280__) \
    || defined(__AVR_ATmega2560__)
usart_port_t usart2 = {&UDR2, &UCSR2A, &UCSR2B, &UCSR2C, &UBRR2H, &UBRR2L, &XCK2_DDR, XCK2_BIT};
usart_port_t usart3 = {&UDR3, &UCSR3A, &UCSR3B, &UCSR3C, &UBRR3H, &UBRR3L, &XCK3_DDR, XCK3_BIT};
#   endif
#else
#   error "Device not supported!"
#endif

//Define generic
/* USART Status Register A (generic) */
#   ifndef RXC
#       define    RXC          7
#   endif
#   ifndef TXC
#       define    TXC          6
#   endif
#   ifndef UDRE
#       define    UDRE         5
#   endif
#   ifndef FE
#       define    FE           4
#   endif
#   ifndef DOR
#       define    DOR          3
#   endif
#   ifndef UPE
#       define    UPE          2
#   endif
#   ifndef U2X
#       define    U2X          1
#   endif
#   ifndef MPCM
#       define    MPCM         0
#   endif

/* USART Control Register B (generic) */
#   ifndef RXCIE
#       define    RXCIE        7
#   endif
#   ifndef TXCIE
#       define    TXCIE        6
#   endif
#   ifndef UDRIE
#       define    UDRIE        5
#   endif
#   ifndef RXEN
#       define    RXEN         4
#   endif
#   ifndef TXEN
#       define    TXEN         3
#   endif
#   ifndef UCSZ2
#       define    UCSZ2        2
#   endif
#   ifndef RXB8
#       define    RXB8         1
#   endif
#   ifndef TXB8
#       define    TXB8         0
#   endif

/* USART Register C (generic) */
#   ifndef UMSEL
#       define    UMSEL        6
#   endif
#   ifndef UPM1
#       define    UPM1         5
#   endif
#   ifndef UPM0
#       define    UPM0         4
#   endif
#   ifndef USBS
#       define    USBS         3
#   endif
#   ifndef UCSZ1
#       define    UCSZ1        2
#   endif
#   ifndef UCSZ0
        #define    UCSZ0        1
#   endif
#   ifndef UCPOL
#       define    UCPOL        0
#   endif

//Some device define PE as UPE
#   if defined(UPE) && !defined(PE) && (UPE == 2)
#       define PE   UPE
#   endif

int usart_init(usart_port_t* port, uint32_t ulBaudrate, uint32_t uiClk, usart_bit_t bit,
        usart_parity_t parity, usart_stop_bit_t stopBit, usart_mode_t mode)
{
    int wRetVal;

    wRetVal = usart_set_baud_rate(port, ulBaudrate, uiClk, mode);
    if (0 == wRetVal)
    {
        usart_set_mode(port, mode);
        usart_set_num_bit(port, bit);
        usart_set_parity(port, parity);
        usart_set_stop_bit(port, stopBit);
    }
    else
    {
    }

    return wRetVal;
}

int usart_set_baud_rate(usart_port_t* port, uint32_t ulBaudrate, uint32_t uiClk, usart_mode_t mode)
{

    uint16_t uwBaud;
    int result = usart_baud_rate_get_ubrb(ulBaudrate, uiClk, 2, mode,
            &uwBaud);

    if (0 <= result)
    {
        *port->ubrrh = uwBaud >> 8;
        *port->ubrrl = uwBaud;

        if (1 == result)
        {
            *port->ucsra |= _BV(1 << U2X);
            result = 0;
        }
        else
        {
            *port->ucsra &= ~(_BV(1 << U2X));
        }
        result = 0;
    }
    else
    {
    }

    return result;
}

void usart_set_baud_rate_precalc(usart_port_t* port, uint16_t uwBaud, _Bool use2x)
{
    *port->ubrrh = uwBaud >> 8;
    *port->ubrrl = uwBaud;
    if (true == use2x)
    {
        *port->ucsra |= _BV(1 << U2X);
    }
    else
    {
        *port->ucsra &= ~(_BV(1 << U2X));
    }
}

void usart_set_num_bit(usart_port_t* port, usart_bit_t numBit)
{
    switch(numBit)
    {
    case usart_bit_5:
    case usart_bit_6:
    case usart_bit_7:
    case usart_bit_8:
        write_to_ucsrc(*port->ucsrc, *port->ucsrc & ~(_BV(UCSZ0) | _BV(UCSZ1)));
        write_to_ucsrc(*port->ucsrc, *port->ucsrc | (numBit << UCSZ0));
        *port->ucsrb &= ~_BV(UCSZ2);
        break;
    case usart_bit_9:
        write_to_ucsrc(*port->ucsrc, *port->ucsrc | (_BV(UCSZ0) | _BV(UCSZ1)));
        *port->ucsrb |= _BV(UCSZ2);
        break;
    default:
        break;
    }
}

void usart_set_parity(usart_port_t* port, usart_parity_t partity)
{
    write_to_ucsrc(*port->ucsrc, *port->ucsrc & ~(_BV(UPM0) | _BV(UPM1)));
    write_to_ucsrc(*port->ucsrc, *port->ucsrc | (partity << UPM0));
}

void usart_set_stop_bit(usart_port_t* port, usart_stop_bit_t stopBit)
{

    if (usart_stop_bit_1 == stopBit)
    {
        write_to_ucsrc(*port->ucsrc, *port->ucsrc & ~(_BV(USBS)));
    }
    else
    {
        write_to_ucsrc(*port->ucsrc, *port->ucsrc | _BV(USBS));
    }
}

void usart_set_mode(usart_port_t* port, usart_mode_t mode)
{
    switch (mode)
    {
    case usart_mode_async:
        write_to_ucsrc(*port->ucsrc, *port->ucsrc & ~(_BV(UMSEL)));
        break;
    case usart_mode_sync_master:
        write_to_ucsrc(*port->ucsrc, *port->ucsrc | _BV(UMSEL));
        *port->xck_ddr |= _BV(port->xck_bit);
        break;
    case usart_mode_sync_slave:
        write_to_ucsrc(*port->ucsrc, *port->ucsrc | _BV(UMSEL));
        *port->xck_ddr &= ~(_BV(port->xck_bit));
        break;
    default:
        break;
    }
}

void usart_enable_rx(usart_port_t* port, _Bool enable)
{
    if (true == enable)
    {
        *port->ucsrb |= _BV(RXEN);
    }
    else
    {
        *port->ucsrb &= ~_BV(RXEN);
    }
}

void usart_enable_tx(usart_port_t* port, _Bool enable)
{
    if (true == enable)
    {
        *port->ucsrb |= _BV(TXEN);
    }
    else
    {
        *port->ucsrb &= ~_BV(TXEN);
    }
}

int usart_putc(usart_port_t* port, char data)
{
    //Check if TX is enabled so that we don't loop infinitely
    if (false != (*port->ucsrb & _BV(TXEN)))
    {
        loop_until_bit_is_set(*port->ucsra, UDRE);
        *port->udr = data;
        return 0;
    }
    else
    {
        avr_drv_errno = ETXDISABLED;
        return -1;
    }
}

int usart_getc(usart_port_t* port, char* data)
{
    int wRetVal;
    uint8_t ubStatus = *port->ucsrb;

    if ((ubStatus & _BV(RXEN)) == 0)
    {
        avr_drv_errno = ERXDISABLED;
        wRetVal = -1;
    }
    else
    {
        ubStatus = *port->ucsra;

        if ((ubStatus & _BV(RXC)) != 0)
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
            *data = *port->udr;
            wRetVal = 1;
        }
        else
        {
            wRetVal = 0;//USART_ERR_RX_EMPTY;
        }
    }
    return wRetVal;
}

void usart_enable_rx_int(usart_port_t* port, _Bool enable)
{
    if (true == enable)
    {
        *port->ucsrb |= _BV(RXCIE);
    }
    else
    {
        *port->ucsrb &= ~_BV(RXCIE);
    }
}

void usart_enable_tx_buf_int(usart_port_t* port, _Bool enable)
{
    if (true == enable)
    {
        *port->ucsrb |= _BV(UDRE);
    }
    else
    {
        *port->ucsrb &= ~_BV(UDRE);
    }
}

void usart_enable_tx_cmp_int(usart_port_t* port, _Bool enable)
{
    if (true == enable)
    {
        *port->ucsrb |= _BV(TXCIE);
    }
    else
    {
        *port->ucsrb &= ~_BV(TXCIE);
    }
}

void usart_putc_isr(usart_port_t* port, char data)
{
    *port->udr = data;
}

int usart_getc_isr(usart_port_t* port, char *data)
{
    int wRetVal = 1;
    uint8_t ubStatus = 0x00;

    ubStatus = *port->ucsra;
    *data = *port->udr;

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
