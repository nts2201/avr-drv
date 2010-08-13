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

#include "avr-drv-errno.h"
#include "spi.h"
#include "spiDef.h"
#include "io_pin/io_pin.h" //\TODO If avr-libc accept pin description, change me.
void spi_enable(_Bool isEnable)
{
    if (false == isEnable)
    {
        SPCR |= _BV(SPE);
    }
    else
    {
        SPCR &= ~_BV(SPE);
    }
}

void spi_enable_int(_Bool isEnable)
{
    if (true == isEnable)
    {
        SPCR |= (1 << SPIE);
    }
    else
    {
        SPCR &= ~(1 << SPIE);
    }
}

int spi_init(_Bool isMsb, SPI_MasterSlave_t masterSlaveMode, SPI_Mode_t mode,
        SPI_Prescaler_t scaler)
{
    spiSetMsbLsb(isMsb);
    if (0 != spiSetMasterSlave(masterSlaveMode))
    {
        return -1;
    }
    if (0 != spiSetPrescaler(scaler))
    {
        return -1;
    }
    if (0 != spiSetMode(mode))
    {
        return -1;
    }

    spiEnable(true);

    return 0;
}

int spi_set_master_slave(SPI_MasterSlave_t mode)
{
    switch (mode)
    {
    case SPI_SingleMaster:
        PORT_SCK |= (1 << SCK_IDX); // set SCK hi
        //MOSI & SCK as output
        DDR_SCK |= (1 << SCK_IDX);
        DDR_MOSI |= (1 << MOSI_IDX);
        DDR_SS |= (1 << SS_IDX); // SS as output, will prevent fallback to slave
        SPCR |= (1 << MSTR);
        break;
    case SPI_MultiMaster:
        PORT_SCK |= (1 << SCK_IDX); // set SCK hi
        //MOSI & SCK as output
        DDR_SCK |= (1 << SCK_IDX);
        DDR_MOSI |= (1 << MOSI_IDX);
        DDR_SS &= ~_BV(SS_IDX); // SS as input
        PORT_SS |= _BV(SS_IDX); // Activate pull-up on SS
        SPCR |= (1 << MSTR);
        break;
    case SPI_Slave:
        DDR_SS &= ~_BV(SS_IDX); // SS as input
        PORT_SS |= _BV(SS_IDX); // Activate pull-up on SS
        DDR_MISO |= (1 << MISO_IDX); //set MISO as output
        SPCR &= ~(1 << MSTR);
        break;
    default:
        errno = EINVAL;
        return -1;
        break;
    }

    return 0;
}

int spi_set_mode(SPI_Mode_t mode)
{
    switch (mode)
    {
    case SPI_Mode_0:
        SPCR &= ~((1 << CPOL) | (1 << CPHA));
        break;
    case SPI_Mode_1:
        SPCR &= ~(1 << CPOL);
        SPCR |= (1 << CPHA);
        break;
    case SPI_Mode_2:
        SPCR |= (1 << CPOL);
        SPCR &= ~(1 << CPHA);
        break;
    case SPI_Mode_3:
        SPCR |= ((1 << CPOL) | (1 << CPHA));
        break;
    default:
        errno = EINVAL;
        return -1;
        break;
    }

    return 0;
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

int spi_set_prescaler(SPI_Prescaler_t scaler)
{
    switch (scaler)
    {
    case SPI_OSCCLK_DIV4:
        SPCR &= ~((1 << SPR1) | (1 << SPR0));
        SPSR &= ~(1 << SPI2X);
        break;
    case SPI_OSCCLK_DIV16:
        SPCR |= (1 << SPR0);
        SPCR &= ~(1 << SPR1);
        SPSR &= ~(1 << SPI2X);
        break;
    case SPI_OSCCLK_DIV64:
        SPCR &= ~(1 << SPR0);
        SPCR |= (1 << SPR1);
        SPSR &= ~(1 << SPI2X);
        break;
    case SPI_OSCCLK_DIV128:
        SPCR |= ((1 << SPR1) | (1 << SPR0));
        SPSR &= ~(1 << SPI2X);
        break;
    case SPI_OSCCLK_DIV2:
        SPCR &= ~((1 << SPR1) | (1 << SPR0));
        SPSR |= (1 << SPI2X);
        break;
    case SPI_OSCCLK_DIV8:
        SPCR |= (1 << SPR0);
        SPCR &= ~(1 << SPR1);
        SPSR |= (1 << SPI2X);
        break;
    case SPI_OSCCLK_DIV32:
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
        errno = EINVAL;
        return -1;
        break;
    }
    return 0;
}

void spi_transfer(uint8_t ubDataOut, uint8_t *pubDataIn)
{
    SPDR = ubDataOut;

    loop_while_bit_is_clear(SPSR, SPIF);

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

