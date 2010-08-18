/* Copyright (c) 2009-2010 Frédéric Nadeau
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

/*! \file spi.c
 \brief Code for SPI module.

 \author Frédéric Nadeau
 */

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>

#include "avr-drv-errno.h"
#include "spi.h"
#include "io_pin/io_pin.h" //\TODO If avr-libc accept pin description, change me.

void spi_enable(void)
{
    SPCR |= _BV(SPE);
}

void spi_disable(void)
{
    SPCR &= ~_BV(SPE);
}

void spi_int_enable(void)
{
    SPCR |= (1 << SPIE);
}

void spi_int_disable(void)
{
    SPCR &= ~(1 << SPIE);
}

void spi_init(_Bool isMsb, spi_op_mode_t opMode, spi_mode_t mode,
        spi_prescaler_t scaler)
{
    spi_set_msb_lsb(isMsb);
    spi_set_operation_mode(opMode);
    spi_set_prescaler(scaler);
    spi_set_mode(mode);
    spi_enable();
}

void spi_set_operation_mode(spi_op_mode_t mode)
{
    switch (mode)
    {
    case spi_op_mode_single_master:
        SCK_PORT |= (1 << SCK_BIT); // set SCK hi
        //MOSI & SCK as output
        SCK_DDR |= (1 << SCK_BIT);
        MOSI_DDR |= (1 << MOSI_BIT);
        SS_DDR |= (1 << SS_BIT); // SS as output, will prevent fallback to slave
        SPCR |= (1 << MSTR);
        break;
    case spi_op_mode_multi_mMaster:
        SCK_PORT |= (1 << SCK_BIT); // set SCK hi
        //MOSI & SCK as output
        SCK_DDR |= (1 << SCK_BIT);
        MOSI_DDR |= (1 << MOSI_BIT);
        SS_DDR &= ~_BV(SS_BIT); // SS as input
        SS_PORT |= _BV(SS_BIT); // Activate pull-up on SS
        SPCR |= (1 << MSTR);
        break;
    case spi_op_mode_slave:
        SS_DDR &= ~_BV(SS_BIT); // SS as input
        SS_PORT |= _BV(SS_BIT); // Activate pull-up on SS
        MISO_DDR |= (1 << MISO_BIT); //set MISO as output
        SPCR &= ~(1 << MSTR);
        break;
    default:
        break;
    }
}

void spi_set_mode(spi_mode_t mode)
{
    switch (mode)
    {
    case spi_mode_0:
        SPCR &= ~((1 << CPOL) | (1 << CPHA));
        break;
    case spi_mode_1:
        SPCR &= ~(1 << CPOL);
        SPCR |= (1 << CPHA);
        break;
    case spi_mode_2:
        SPCR |= (1 << CPOL);
        SPCR &= ~(1 << CPHA);
        break;
    case spi_mode_3:
        SPCR |= ((1 << CPOL) | (1 << CPHA));
        break;
    default:
        break;
    }
}

void spi_set_msb_lsb(_Bool isMsb)
{
    if (false == isMsb)
    {
        SPCR |= (1 << DORD);
    }
    else
    {
        SPCR &= ~(1 << DORD);
    }
}

void spi_set_prescaler(spi_prescaler_t scaler)
{
    switch (scaler)
    {
    case spi_prescaler_4:
        SPCR &= ~((1 << SPR1) | (1 << SPR0));
        SPSR &= ~(1 << SPI2X);
        break;
    case spi_prescaler_16:
        SPCR |= (1 << SPR0);
        SPCR &= ~(1 << SPR1);
        SPSR &= ~(1 << SPI2X);
        break;
    case spi_prescaler_64:
        SPCR &= ~(1 << SPR0);
        SPCR |= (1 << SPR1);
        SPSR &= ~(1 << SPI2X);
        break;
    case spi_prescaler_128:
        SPCR |= ((1 << SPR1) | (1 << SPR0));
        SPSR &= ~(1 << SPI2X);
        break;
    case spi_prescaler_2:
        SPCR &= ~((1 << SPR1) | (1 << SPR0));
        SPSR |= (1 << SPI2X);
        break;
    case spi_prescaler_8:
        SPCR |= (1 << SPR0);
        SPCR &= ~(1 << SPR1);
        SPSR |= (1 << SPI2X);
        break;
    case spi_prescaler_32:
        SPCR &= ~(1 << SPR0);
        SPCR |= (1 << SPR1);
        SPSR |= (1 << SPI2X);
        break;
        /*		case SPI_OSCCLK_DIV64:
         SPCR |= ((1 << SPR1) | (1 << SPR0));
         SPSR |= (1 << SPI2X);
         break;
         */
    default:
        break;
    }
}

void spi_transfer(uint8_t ubDataOut, uint8_t *pubDataIn)
{
    SPDR = ubDataOut;

    loop_until_bit_is_set(SPSR, SPIF);

    if (pubDataIn != (void*) 0)
    {
        *pubDataIn = SPDR;
    }
    else
    {
        uint8_t tmp;
        tmp = SPDR;
    }
}

void spi_transferISR(uint8_t ubDataOut, uint8_t *pubDataIn)
{
    uint8_t ubDataTmp = SPDR;
    SPDR = ubDataOut;
    if (pubDataIn != (void*) 0)
    {
        *pubDataIn = ubDataTmp;
    }
}

