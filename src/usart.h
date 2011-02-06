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
 \brief Function and type definitions for USART module.

 \author Frédéric Nadeau
 */
#ifndef USART_H_
#define USART_H_

typedef struct usart_port_s
{
    volatile uint8_t *udr;
    volatile uint8_t *ucsra;
    volatile uint8_t *ucsrb;
    volatile uint8_t *ucsrc;
    volatile uint8_t *ubrrh;
    volatile uint8_t *ubrrl;
    volatile uint8_t *xck_ddr;
    uint8_t xck_bit;
}usart_port_t;



#if defined(__DOXYGEN__)
//TODO do doxygen
#else
extern usart_port_t usart0;
#   define usart   usart0
#   if defined(__AVR_AT90CAN32__) \
    || defined(__AVR_AT90CAN64__) \
    || defined(__AVR_AT90CAN128__) \
    || defined(__AVR_AT90USB82__) \
    || defined(__AVR_AT90USB162__) \
    || defined(__AVR_AT90USB646__) \
    || defined(__AVR_AT90USB647__) \
    || defined(__AVR_AT90USB1286__) \
    || defined(__AVR_AT90USB1287__)\
    || defined(__AVR_ATmega8U2__) \
    || defined(__AVR_ATmega16U2__) \
    || defined(__AVR_ATmega16U4__) \
    || defined(__AVR_ATmega32U2__) \
    || defined(__AVR_ATmega32U4__) \
    || defined(__AVR_ATmega32U6__) \
    || defined(__AVR_ATmega64__) \
    || defined(__AVR_ATmega128__) \
    || defined(__AVR_ATmega128RFA1__) \
    || defined(__AVR_ATmega162__) \
    || defined(__AVR_ATmega324A__) \
    || defined(__AVR_ATmega324P__) \
    || defined(__AVR_ATmega324PA__)\
    || defined(__AVR_ATmega640__) \
    || defined(__AVR_ATmega644__) \
    || defined(__AVR_ATmega644A__) \
    || defined(__AVR_ATmega644P__) \
    || defined(__AVR_ATmega644PA__) \
    || defined(__AVR_ATmega1280__) \
    || defined(__AVR_ATmega1281__) \
    || defined(__AVR_ATmega1284__) \
    || defined(__AVR_ATmega2560__) \
    || defined(__AVR_ATmega2561__)
extern usart_port_t usart1;
#       if defined(__AVR_ATmega640__) \
        || defined(__AVR_ATmega1280__) \
        || defined(__AVR_ATmega2560__)
extern usart_port_t usart3;
extern usart_port_t usart4;
#       endif
#   endif
#endif

typedef enum usart_bit_e /*!< Number of bits used by the USART module. */
{
    usart_bit_5 = 0,    /*!< USART use 5 bits. */
    usart_bit_6,    /*!< USART use 6 bits. */
    usart_bit_7,    /*!< USART use 7 bits. */
    usart_bit_8,    /*!< USART use 8 bits. */
    usart_bit_9 = 7,    /*!< USART use 9 bits. */
}usart_bit_t; /*!< Typedef of #usart_bit_e. */

typedef enum usart_parity_e /*!< Parity bit that will be added to frame. */
{
    usart_parity_None = 0, /*!< No parity bit. */
    usart_parity_Even = 2, /*!< Use even parity bit. */
    usart_parity_Odd = 3 /*!< Use odd parity bit. */
}usart_parity_t; /*!< Typedef for #usart_parity_e. */

typedef enum usart_stop_bit_e /*!< How many stop bit will be added to frame. */
{
    usart_stop_bit_1 = 0, /*!< Add one stop bit. */
    usart_stop_bit_2, /*!< Add two stop bit. */
}usart_stop_bit_t; /*!< Typedef for #usart_stop_bit_e. */

typedef enum usart_mode_e /*!< Mode into witch USART will be configured. */
{
    usart_mode_async, /*!< Asynchronous, Most likely what you need. */
    usart_mode_sync_master, /*!< Synchronous mode. We are the clock source. */
    usart_mode_sync_slave, /*!< Synchronous mode. Clock source must be provided. */
}usart_mode_t;/*!< Typedef for #usart_mode_e. */

int usart_init(usart_port_t* port, uint32_t ulBaudRate, uint32_t uiClk, usart_bit_t bit,
        usart_parity_t parity, usart_stop_bit_t stopBit, usart_mode_t mode);
int usart_set_baud_rate(usart_port_t* port, uint32_t ulBaudrate, uint32_t uiClk, usart_mode_t mode);
void usart_set_num_bit(usart_port_t* port, usart_bit_t numbit);
void usart_set_parity(usart_port_t* port, usart_parity_t partity);
void usart_set_stop_bit(usart_port_t* port, usart_stop_bit_t stopbit);
void usart_set_mode(usart_port_t* port, usart_mode_t mode);

void usart_enable_rx(usart_port_t* port, _Bool enable);
void usart_enable_tx(usart_port_t* port, _Bool enable);

int usart_putc(usart_port_t* port, char data);
int usart_getc(usart_port_t* port, char *data);

void usart_enable_rx_int(usart_port_t* port, _Bool enable);
void usart_enable_tx_buf_int(usart_port_t* port, _Bool enable);
void usart_enable_tx_cmp_int(usart_port_t* port, _Bool enable);

void usart_putc_isr(usart_port_t* port, char data);
int usart_getc_isr(usart_port_t* port, char *data);

#endif /* USART_H_ */
