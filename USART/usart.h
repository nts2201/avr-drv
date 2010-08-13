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

#if defined(__DOXYGEN__)
typedef enum usart_port_e /*!< Enum of available port. */
{
    usart_port_0,       /*!< USART port 0. */
    usart_port_1,       /*!< USART port 1. */
    usart_port_2,       /*!< USART port 2. */
    usart_port_3,       /*!< USART port 3. */
}usart_port_t; /*!< Typedef of #usart_port_e. */
#else
typedef enum usart_port_e
{
    usart_port_0,
#if defined(__AVR_AT90CAN32__) \
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
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
    usart_port_1,
#endif
#if defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega2560__)
    usart_port_2,
    usart_port_3,
#endif
}usart_port_t;
#endif

typedef enum usart_bit_e /*!< Number of bits used by the USART module. */
{
    usart_bit_5,    /*!< USART use 5 bits. */
    usart_bit_6,    /*!< USART use 6 bits. */
    usart_bit_7,    /*!< USART use 7 bits. */
    usart_bit_8,    /*!< USART use 8 bits. */
    usart_bit_9,    /*!< USART use 9 bits. */
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

//External function
extern int usart_single_set_baud_rate(uint32_t baudRate);
extern void usart_single_set_baud_rate_precalc(uint16_t ubrr, _Bool use2x);
extern int usart_single_set_num_bit(usart_bit_t numBit);
extern int usart_single_set_parity(usart_parity_t partity);
extern int usart_single_set_stop_bit(usart_stop_bit_t stopBit);
extern int usart_single_set_mode(usart_mode_t mode);

extern int usart_single_enable_rx(_Bool enable);
extern int usart_single_enable_tx(_Bool enable);

extern int usart_single_putc(char data);
extern int usart_single_getc(char* data);

extern _Bool usart_single_is_tx(void);

extern int usart_single_enable_rx_int(_Bool enable);
extern int usart_single_enable_tx_buf_int(_Bool enable);
extern int usart_single_enable_tx_cmp_int(_Bool enable);

extern int usart_single_putcISR(char data);
extern int usart_single_getcISR(char *data);

//Map generic functions to external functions
#	define  usart_set_baud_rate(port, baud_rate) usart_single_set_baud_rate(baud_rate)
#   define  usart_set_baud_rate_precalc(port, ubrr, use2x) usart_single_set_baud_rate_precalc(ubrr, use2x)
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
#elif defined(__AVR_AT90CAN32__) \
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
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)

extern int usartmultisetbaudrate(usart_port_t port, uint32t baudrate);
extern int usartmultisetnumbit(usart_port_t port, usart_bit_t numbit);
extern int usartmultisetparity(usart_port_t port, usart_parity_t partity);
extern int usartmultisetstopbit(usart_port_t port, usart_stop_bit_t stopbit);
extern int usartmultisetmode(usart_port_t port, usart_mode_t mode);

extern int usartmultienablerx(usart_port_t port, _Bool enable);
extern int usartmultienabletx(usart_port_t port, _Bool enable);

extern int usartmultiputc(usart_port_t port, char data);
extern int usartmultiputs(usart_port_t port, char data);
extern int usartmultigetc(usart_port_t port, char *data);

extern _Bool usartmultiistx(usart_port_t port);

extern int usartmultienablerxint(usart_port_t port, _Bool enable);
extern int usartmultienabletxbufint(usart_port_t port, _Bool enable);
extern int usartmultienabletxcmpint(usart_port_t port, _Bool enable);

extern int usartmultiputcisr(usart_port_t port, char data);
extern int usartmultigetcisr(usart_port_t port, char *data);

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
#else
#   error "Device not supported!"
#endif

#endif /* USART_H_ */
