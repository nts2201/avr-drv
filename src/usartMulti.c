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

/*! \file usartMulti.h
 \brief This is the core file for device with multiple USART.

 \author Frédéric Nadeau
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>

#include "avr-drv-errno.h"
#include "io_pin/io_pin.h"

typedef struct usart_multi_port_s
{
    volatile uint8_t *data;
    volatile uint8_t *ucsra;
    volatile uint8_t *ucsrb;
    volatile uint8_t *ucsrc;
    volatile uint16_t *ubrr;
}usart_multi_port_t;

static usart_multi_port_t gPort[] = {
        {UDR0, UCSRA0, UCSRB0, UCSRC0, UBRR0},
        {UDR1, UCSRA1, UCSRB1, UCSRC1, UBRR1}
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        ,
        {UDR2, UCSRA2, UCSRB2, UCSRC2, UBRR2},
        {UDR3, UCSRA3, UCSRB3, UCSRC3, UBRR3}
#endif

};

extern int usart_baud_rate_get_ubrb(uint32_t uiBaudRate, uint32_t uiClk,
        uint8_t ubTol, usart_mode_t mode, uint16_t* puwUbrr);

#define USART_RX_ERR_MASK   (_BV(PE) | _BV(DOR) | _BV(FE)) //0b0001 1100

int usart_multi_init(usart_port_t port, uint32_t ulBaudRate, uint32_t uiClk, usart_bit_t bit,
        usart_parity_t parity, usart_stop_bit_t stopBit, usart_mode_t mode)
{
    int wRetVal = USART_OK;

    wRetVal = usart_multi_set_baud_rate(port, ulBaudRate, uiClk, mode);
    if (0 == wRetVal)
    {
        usart_multi_set_mode(port, mode);
        usart_multi_set_num_bit(port, bit);
        usart_multi_set_parity(port, parity);
        usart_multi_set_stop_bit(port, stopBit);
    }
    else
    {
    }

    return wRetVal;
}

uint8_t USARTsetBit(uint8_t ubUSART,uint8_t ubDataBit, uint8_t ubParity,uint8_t ubSstopBit)
{
    uint8_t ubRetVal = USART_OK;
    uint8_t bit_u08 = 0;
    uint8_t par_u08 = 0;
    uint8_t stop_u08 = 0;

    switch(ubDataBit)
    {
        case USART_DATA_BIT_5: bit_u08 = 0x00; break;
        case USART_DATA_BIT_6: bit_u08 = 0x01; break;
        case USART_DATA_BIT_7: bit_u08 = 0x02; break;
        case USART_DATA_BIT_8: bit_u08 = 0x03; break;
        case USART_DATA_BIT_9: bit_u08 = 0x07; break;
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    switch(ubParity)
    {
        case USART_PARITY_NONE: par_u08 = 0; break;
        case USART_PARITY_EVEN: par_u08 = 2; break;
        case USART_PARITY_ODD:  par_u08 = 3; break;
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    switch(ubSstopBit)
    {
        case USART_1_STOP_BIT: stop_u08 = 0; break;
        case USART_2_STOP_BIT: stop_u08 = 1; break;
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    if(ubRetVal == USART_OK)
    {
        switch (ubUSART)
        {
        case USART_PORT_0:
            UCSR0C = (stop_u08 << USBS0) | (bit_u08 << UCSZ00) | (par_u08 << UPM00);
            break;
        case USART_PORT_1:
            UCSR1C = (stop_u08 << USBS1) | (bit_u08 << UCSZ10)| (par_u08 << UPM10);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2C = (stop_u08 << USBS1) | (bit_u08 << UCSZ10)| (par_u08 << UPM10);
            break;
        case USART_PORT_3:
            UCSR3C = (stop_u08 << USBS1) | (bit_u08 << UCSZ10)| (par_u08 << UPM10);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
        }
    }

    return ubRetVal;
}

uint8_t USARTsetBaud(uint8_t ubUSART, uint32_t ulBaudRate)
{
    uint8_t ubRetVal = USART_OK;
    uint16_t uiBaudRate = 0;
#if defined (__AVR_ATmega128__)
    if((XDIV & 0x80) != 0)
    {
        uiBaudRate =
            (uint16_t) ((OSCCLK / (129 - (XDIV & 0x7F))) /
                   (ulBaudRate * 16l)) - 1;
    }
    else
#elif defined (__AVR_AT90CAN128__) || defined (__AVR_ATmega640__) || defined (__AVR_ATmega1280__)|| defined (__AVR_ATmega1281__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega2561__)
    if(CLKPR & (1<<CLKPCE) )
    {
        switch(CLKPR)
        {
            case 0x80: uiBaudRate = (uint16_t)F_CPU; break;
            case 0x81: uiBaudRate = (uint16_t)(F_CPU>>1); break;
            case 0x82: uiBaudRate = (uint16_t)(F_CPU>>2); break;
            case 0x83: uiBaudRate = (uint16_t)(F_CPU>>3); break;
            case 0x84: uiBaudRate = (uint16_t)(F_CPU>>4); break;
            case 0x85: uiBaudRate = (uint16_t)(F_CPU>>5); break;
            case 0x86: uiBaudRate = (uint16_t)(F_CPU>>6); break;
            case 0x87: uiBaudRate = (uint16_t)(F_CPU>>7); break;
            case 0x88: uiBaudRate = (uint16_t)(F_CPU>>8); break;
            default: break;
        }
    }
    else
#endif
    {
        uiBaudRate = F_CPU / (ulBaudRate * 16l) - 1;
    }

    switch (ubUSART)
    {
        case USART_PORT_0:
            UBRR0H = uiBaudRate >> 8;
            UBRR0L = uiBaudRate & 0xFF;
            break;
        case USART_PORT_1:
            UBRR1H = uiBaudRate >> 8;
            UBRR1L = uiBaudRate & 0xFF;
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UBRR2H = uiBaudRate >> 8;
            UBRR2L = uiBaudRate & 0xFF;
            break;
        case USART_PORT_3:
            UBRR3H = uiBaudRate >> 8;
            UBRR3L = uiBaudRate & 0xFF;
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }
    return ubRetVal;
}

uint8_t USARTenableRx(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;
    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B |= (1 << RXEN0);
            break;
        case USART_PORT_1:
            UCSR1B |= (1 << RXEN1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B |= (1 << RXEN2);
            break;
        case USART_PORT_3:
            UCSR3B |= (1 << RXEN3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }
    return ubRetVal;
}

uint8_t USARTenableTx(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B |= (1 << TXEN0);
            break;
        case USART_PORT_1:
            UCSR1B |= (1 << TXEN1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B |= (1 << TXEN2);
            break;
        case USART_PORT_3:
            UCSR3B |= (1 << TXEN3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTdisableRx(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B &= ~(1 << RXEN0);
            break;
        case USART_PORT_1:
            UCSR1B &= ~(1 << RXEN1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B &= ~(1 << RXEN2);
            break;
        case USART_PORT_3:
            UCSR3B &= ~(1 << RXEN3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTdisableTx(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B &= ~(1 << TXEN0);
            break;
        case USART_PORT_1:
            UCSR1B &= ~(1 << TXEN1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B &= ~(1 << TXEN2);
            break;
        case USART_PORT_3:
            UCSR3B &= ~(1 << TXEN3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTenableRxInt(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            if(USARTrxCmpISR[0] != NULL)
            {
                UCSR0B |= (1 << RXCIE0);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
        case USART_PORT_1:
            if(USARTrxCmpISR[1] != NULL)
            {
                UCSR1B |= (1 << RXCIE1);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            if(USARTrxCmpISR[2] != NULL)
            {
                UCSR2B |= (1 << RXCIE2);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
        case USART_PORT_3:
            if(USARTrxCmpISR[3] != NULL)
            {
                UCSR3B |= (1 << RXCIE3);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTenableTxBufInt(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            if(USARTtxBufEmptyISR[0] != NULL)
            {
                UCSR0B |= (1 << UDRIE0);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
        case USART_PORT_1:
            if(USARTtxBufEmptyISR[1] != NULL)
            {
                UCSR1B |= (1 << UDRIE1);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            if(USARTrxCmpISR[2] != NULL)
            {
                UCSR2B |= (1 << UDRIE2);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
        case USART_PORT_3:
            if(USARTrxCmpISR[3] != NULL)
            {
                UCSR3B |= (1 << UDRIE3);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTenableTxCmpInt(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            if(USARTtxCmpISR[0] != NULL)
            {
                UCSR0B |= (1 << TXCIE0);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
        case USART_PORT_1:
            if(USARTtxCmpISR[1] != NULL)
            {
                UCSR1B |= (1 << TXCIE1);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            if(USARTrxCmpISR[2] != NULL)
            {
                UCSR2B |= (1 << TXCIE2);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
        case USART_PORT_3:
            if(USARTrxCmpISR[3] != NULL)
            {
                UCSR3B |= (1 << TXCIE3);
            }
            else
            {
                ubRetVal = USART_ERR_INT_FCT;
            }
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTdisableRxInt(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B &= ~(1 << RXCIE0);
            break;
        case USART_PORT_1:
            UCSR1B &= ~(1 << RXCIE1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B &= ~(1 << RXCIE2);
            break;
        case USART_PORT_3:
            UCSR3B &= ~(1 << RXCIE3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTdisableTxBufInt(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B &= ~(1 << UDRIE0);
            break;
        case USART_PORT_1:
            UCSR1B &= ~(1 << UDRIE1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B &= ~(1 << UDRIE2);
            break;
        case USART_PORT_3:
            UCSR3B &= ~(1 << UDRIE3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTdisableTxCmpInt(uint8_t ubUSART)
{
    uint8_t ubRetVal = USART_OK;

    switch (ubUSART)
    {
        case USART_PORT_0:
            UCSR0B &= ~(1 << TXCIE0);
            break;
        case USART_PORT_1:
            UCSR1B &= ~(1 << TXCIE1);
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            UCSR2B &= ~(1 << TXCIE2);
            break;
        case USART_PORT_3:
            UCSR3B &= ~(1 << TXCIE3);
            break;
#endif
        default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    return ubRetVal;
}

uint8_t USARTputc(uint8_t ubUSART, uint8_t ubData)
{
    uint8_t ubRetVal;
    switch (ubUSART)
    {
    case USART_PORT_0:
        if((UCSR0B & (1 << TXEN0)) != 0)
        {
            while( (UCSR0A & (1 << UDRE0)) == 0 )
                ;
            UDR0 = ubData;
            ubRetVal = USART_OK;
        }
        else
        {
            ubRetVal = USART_TX_DISABLED;
        }
        break;
    case USART_PORT_1:
        if((UCSR1B & (1 << TXEN1)) != 0)
        {
            while( (UCSR1A & (1 << UDRE1)) == 0 )
                ;
            UDR1 = ubData;
            ubRetVal = USART_OK;
        }
        else
        {
            ubRetVal = USART_TX_DISABLED;
        }
        break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
        if((UCSR2B & (1 << TXEN2)) != 0)
        {
            while( (UCSR2A & (1 << UDRE2)) == 0 )
            {;}
            UDR2 = ubData;
            ubRetVal = USART_OK;
        }
        else
        {
            ubRetVal = USART_TX_DISABLED;
        }
            break;
        case USART_PORT_3:
        if((UCSR3B & (1 << TXEN3)) != 0)
        {
            while( (UCSR3A & (1 << UDRE3)) == 0 )
            {;}
            UDR3 = ubData;
            ubRetVal = USART_OK;
        }
        else
        {
            ubRetVal = USART_TX_DISABLED;
        }
            break;
#endif
    default:
        ubRetVal = USART_ERR_USART;
        break;
    }
    return ubRetVal;
}

uint8_t USARTputs(uint8_t ubUSART, uint8_t *data_str)
{
    uint8_t ubRetVal = USART_OK;

    if(data_str != NULL)
    {
        while(*data_str)
        {
            ubRetVal = USARTputc(ubUSART, *data_str++);
            if(ubRetVal != 0)
            {
                break;
            }
            else
            {
            }
        }
    }
    else
    {
        ubRetVal = USART_ERR_ARG;
    }
    return ubRetVal;
}

uint8_t USARTgetc(uint8_t ubUSART, uint8_t *pubData)
{
    uint8_t ubRetVal;
    uint8_t ubStatus;

    switch (ubUSART)
    {
        case USART_PORT_0:
            ubStatus = UCSR0B;
            break;
        case USART_PORT_1:
            ubStatus = UCSR1B;
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            ubStatus = UCSR2B;
            break;
        case USART_PORT_3:
            ubStatus = UCSR3B;
            break;
#endif
        default:
            ubStatus = 0x00;
            break;
    }

    if( (ubStatus & (1<<RXEN0)) == 0)
    {
        ubRetVal = USART_RX_DISABLED;
    }else
    {
        switch (ubUSART)
        {
            case USART_PORT_0:
                ubStatus = UCSR0A;
                break;
            case USART_PORT_1:
                ubStatus = UCSR1A;
                break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
            case USART_PORT_2:
                ubStatus = UCSR2A;
                break;
            case USART_PORT_3:
                ubStatus = UCSR3A;
                break;
#endif
            default:
                ubStatus = 0x00;
                break;
        }

        if( (ubStatus & USART_RX_CHAR_IN) != 0)
        {
            if( (ubStatus & USART_RX_ERR_MASK) != 0)
            {
                switch(ubStatus)
                {
                case 0x04:  ubRetVal = USART_ERR_PARITY; break;
                case 0x08:  ubRetVal = USART_ERR_OVERRUN; break;
                case 0x10:  ubRetVal = USART_ERR_FRAME; break;
                default:    ubRetVal = USART_ERR_RX_MULTI; break;
                }
            }else
            {
                ubRetVal = USART_OK;
            }

            switch (ubUSART)
            {
                case USART_PORT_0:
                    *pubData = UDR0;
                    break;
                case USART_PORT_1:
                    *pubData = UDR1;
                    break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
                case USART_PORT_2:
                    *pubData = UDR2;
                    break;
                case USART_PORT_3:
                    *pubData = UDR3;
                    break;
#endif
            }
        }else
        {
            ubRetVal = USART_ERR_RX_EMPTY;
        }
    }
    return ubRetVal;
}


void USARTputcISR(uint8_t ubUSART, uint8_t ubData)
{
    switch (ubUSART)
    {
    case 0x00:
        UDR0 = ubData;
        break;
    case 0x01:
        UDR1 = ubData;
        break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
    case USART_PORT_2:
        UDR2 = ubData;
        break;
    case USART_PORT_3:
        UDR3 = ubData;
        break;
#endif
    default:
        break;
    }
}

uint8_t USARTgetcISR(uint8_t ubUSART, uint8_t * pubData)
{
    uint8_t ubRetVal = USART_OK;
    uint8_t ubStatus = 0x00;

    switch(ubUSART)
    {
        case USART_PORT_0:
            ubStatus = UCSR0A;
            *pubData = UDR0;
            break;
        case USART_PORT_1:
            ubStatus = UCSR1A;
            *pubData = UDR1;
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            ubStatus = UCSR2A;
            *pubData = UDR2;
            break;
        case USART_PORT_3:
            ubStatus = UCSR3A;
            *pubData = UDR3;
            break;
#endif
            default:
            ubRetVal = USART_ERR_ARG;
            break;
    }

    if( (ubRetVal == USART_OK) && ((ubStatus & USART_RX_ERR_MASK) != 0) )
    {
        switch(ubStatus)
        {
            case 0x04:
                ubRetVal = USART_ERR_PARITY;
                break;
            case 0x08:
                ubRetVal = USART_ERR_OVERRUN;
                break;
            case 0x10:
                ubRetVal = USART_ERR_FRAME;
                break;
            default:
                ubRetVal = USART_ERR_RX_MULTI;
                break;
        }
    }
    else
    {}

    return ubRetVal;
}

uint8_t USARTisTxBufferEmpty(uint8_t ubUSART)
{
    uint8_t ubRetVal = 1;
    switch(ubUSART)
    {
        case 0x00:
            if ( (UCSR0A & (1<<UDRE0)) == 0 )
            {
                ubRetVal = 0;
            }
            break;
        case 0x01:
            if ((UCSR1A & (1<<UDRE1)) == 0 )
            {
                ubRetVal = 0;
            }
            break;
#if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__) || defined (__AVR_ATmega640__)
        case USART_PORT_2:
            if ((UCSR2A & (1<<UDRE2)) == 0 )
            {
                ubRetVal = 0;
            }
            break;
        case USART_PORT_3:
            if ((UCSR3A & (1<<UDRE3)) == 0 )
            {
                ubRetVal = 0;
            }
            break;
#endif
            default:
            ubRetVal = 0;
            break;
    }
    return ubRetVal;
}

