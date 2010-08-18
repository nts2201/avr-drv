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

/*! \file spi.h
 \brief API for Atmel SPI module.

 \author Frédéric Nadeau
 */
#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>


typedef enum spi_op_mode_e
{
    spi_op_mode_single_master = 0, /*!< SPI act as a single master on bus.
     Chip Select pin will be configured as output to prevent fallback to
     slave mode.*/
    spi_op_mode_multi_mMaster, /*!< SPI is configured as master but can fall back
     as slave if Chip Select pin is driven low. */
    spi_op_mode_slave, /*! SPI is configured as slave and will become active when
     Chip select is driven low. */
} spi_op_mode_t;

typedef enum spi_mode_e
{
    spi_mode_0 = 0, /*!< CPOL = 0, CPHA = 0 */
    spi_mode_1, /*!< CPOL = 0, CPHA = 1 */
    spi_mode_2, /*!< CPOL = 1, CPHA = 0 */
    spi_mode_3 /*!< CPOL = 1, CPHA = 1 */
} spi_mode_t;

typedef enum spi_prescaler_e
{
    spi_prescaler_2 = 0,/*!< OSCCLK/2 */
    spi_prescaler_4, /*!< OSCCLK/4 */
    spi_prescaler_8, /*!< OSCCLK/8 */
    spi_prescaler_16, /*!< OSCCLK/16 */
    spi_prescaler_32, /*!< OSCCLK/32 */
    spi_prescaler_64, /*!< OSCCLK/64 */
    spi_prescaler_128 /*!< OSCCLK/128 */
} spi_prescaler_t;

/*! \fn void spi_enable(void)
 *  \brief Enable SPI block.
 */
void spi_enable(void);

/*! \fn void spi_disable(void)
 *  \brief Disable SPI block.
 */
void spi_disable(void);

/*! \fn void spi_int_enable(void)
 *  \brief Enable interrupt for SPI block.
 */
void spi_int_enable(void);

/*! \fn void spi_int_disable(void)
 *  \brief Disable interrupt for SPI block.
 */
void spi_int_disable(void);

/*! \fn void spi_init(_Bool isMsb, spi_op_mode_t masterSlaveMode, spi_mode_t mode, spi_prescaler_t scaler)
 *  \brief  Configure the SPI port.
 *
 *  \param  isMsb \c true if MSB fist, \c false for LSB first.
 *  \param  masterSlaveMode use #spi_op_mode_t to select operation mode.
 *  \param  mode Use #spi_mode_t to select
 *  \param  scaler Use #spi_prescaler_t to select clock prescaler.
 */
void spi_init(_Bool isMsb, spi_op_mode_t masterSlaveMode, spi_mode_t mode, spi_prescaler_t scaler);

/*! \fn void spi_set_operation_mode(spi_op_mode_t mode)
 *  \brief Configure SPI in Slave or Master operation mode.
 *
 *  \param  mode use #spi_op_mode_t to select master or slave mode.
 */
void spi_set_operation_mode(spi_op_mode_t mode);

/*! \fn void spi_set_mode(spi_mode_t mode)
 *  \brief Configure SPI operation mode.
 *
 *  \param  mode use #spi_mode_t, see Atmel documentation.
 */
void spi_set_mode(spi_mode_t mode);

/*! \fn void spiSetMsbLsb(_Bool isMsb)
 *  \brief Configure data order
 *
 * Use to see data spi_set_msb_lsb in Big Endian or Little Endian
 *  \param  isMsb true is sending MSB fist, false if sending LSB first.
 */
void spi_set_msb_lsb(_Bool isMsb);

/*! \fn void spi_set_prescaler(spi_prescaler_t scaler)
 *  \brief Configure SPI clock to be use in Master mode.
 *
 *  \param  scaler Division factor, use #spi_prescaler_t to select clock source.
 */
void spi_set_prescaler(spi_prescaler_t scaler);

/*! \fn void spi_transfer(uint8_t ubDataOut, uint8_t *pubDataIn)
 *  \brief  Send byte over SPI bus.
 *  \param  ubDataOut Data to be send.
 *  \param  pubDataIn Pointer to 8 bit data space.  Red value will be saved at specified address.
 */
void spi_transfer(uint8_t ubDataOut, uint8_t *pubDataIn);

/*! \fn void spi_transferISR(uint8_t ubDataOut, uint8_t *pubDataIn)
 *  \brief Start a new byte transfer and get last byte in, use only in ISR function.
 *  \param ubDataOut Data to be send.
 *  \param  pubDataIn Pointer to 8 bit data space.
 *          Read value will be saved at specified address.
 *          If address is \c (void*) \c 0, received data will be discarded.
 */
void spi_transferISR(uint8_t ubDataOut, uint8_t *pubDataIn);

#endif /*SPI_H_*/
