/* Copyright (c) 2010 Frédéric Nadeau
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

/*! \file adis16209.c
 \brief Driver for the Analog Device ADIS16209 High Accuracy,
        Dual-Axis Digital Inclinometer and Accelerometer

 This module is aimed to be portable across any device with
 SPI port. Some external functions are required.

 This module is based on the ADIS16209 datasheet revision B available
 at http://www.analog.com/static/imported-files/data_sheets/ADIS16209.pdf
 at time of writing.

 \author Frédéric Nadeau
 */
#include <stdint.h>
#include <stdlib.h>

extern void adis16209_chip_select_set(void);
extern void adis16209_chip_select_clear(void);
extern void adis16209_spi_transfer(uint8_t ubDataOut, uint8_t *pubDataIn);

enum adis16209_reg_e /*!< Register map. */
{
	adis16209_reg_endurance  = 0x0000, /*!< Diagnostics, flash write counter (16-bit binary) */
	adis16209_reg_supply_out = 0x0002, /*!< Output, power supply */
	adis16209_reg_xaccl_out  = 0x0004, /*!< Output, x-axis acceleration */
	adis16209_reg_yaccl_out  = 0x0006, /*!< Output, y-axis acceleration */
	adis16209_reg_aux_adc    = 0x0008, /*!< Output, auxiliary ADC */
	adis16209_reg_temp_out   = 0x000A, /*!< Output, temperature */
	adis16209_reg_xincl_out  = 0x000C, /*!< Output, ±90° x-axis inclination */
	adis16209_reg_yincl_out  = 0x000E, /*!< Output, ±90° y-axis inclination */
	adis16209_reg_rot_out    = 0x0010, /*!< Output, ±180° vertical rotational position */
	adis16209_reg_xaccl_null = 0x0012, /*!< Calibration, x-axis acceleration offset null */
	adis16209_reg_yaccl_null = 0x0014, /*!< Calibration, y-axis acceleration offset null */
	adis16209_reg_xincl_null = 0x0016, /*!< Calibration, x-axis inclination offset null */
	adis16209_reg_yincl_null = 0x0018, /*!< Calibration, y-axis inclination offset null */
	adis16209_reg_rot_null   = 0x001A, /*!< Calibration, vertical rotation offset null */
	adis16209_reg_alm_mag1   = 0x0020, /*!< Alarm 1, amplitude threshold */
	adis16209_reg_alm_mag2   = 0x0022, /*!< Alarm 2, amplitude threshold */
	adis16209_reg_alm_smpl1  = 0x0024, /*!< Alarm 1, sample period */
	adis16209_reg_alm_smpl2  = 0x0026, /*!< Alarm 2, sample period */
	adis16209_reg_alm_ctrl   = 0x0028, /*!< Alarm, source control register */
	adis16209_reg_aux_dac    = 0x0030, /*!< Auxiliary DAC data */
	adis16209_reg_gpio_ctrl  = 0x0032, /*!< Operation, digital I/O configuration and data */
	adis16209_reg_msc_ctrl   = 0x0034, /*!< Operation, data-ready and self-test control */
	adis16209_reg_smpl_prd   = 0x0036, /*!< Operation, sample rate configuration */
	adis16209_reg_avg_cnt    = 0x0038, /*!< Operation, filter configuration */
	adis16209_reg_slp_cnt    = 0x003A, /*!< Operation, sleep mode control */
	adis16209_reg_status     = 0x003C, /*!< Diagnostics, system status register */
	adis16209_reg_command    = 0x003E  /*!< Operation, system command register */
};

uint16_t adis16209_get_status(void)
{
	uint8_t statusHigh;
	uint8_t statusLow;

	adis16209_chip_select_clear();

	adis16209_spi_transfer(adis16209_reg_status, &statusHigh);
	adis16209_spi_transfer(adis16209_reg_status+1, &statusLow);

	adis16209_chip_select_set();

	return (uint16_t)(statusHigh<<8) | statusLow;
}

void adis16209_get_accl(int16_t* x, int16_t* y)
{
	static uint8_t regHigh;
	static uint8_t regLow;

	adis16209_chip_select_clear();
	adis16209_spi_transfer(adis16209_reg_xaccl_out, NULL);
	adis16209_spi_transfer(0xFF, NULL);
	adis16209_chip_select_set();

	OSTimeDlyHMSM(0,0,0,1);

	adis16209_chip_select_clear();
	adis16209_spi_transfer(adis16209_reg_xincl_out, &regHigh);
	adis16209_spi_transfer(0xFF, &regLow);
	adis16209_chip_select_set();
	regHigh &= 0x3F;
	if((regHigh & 0x20) != 0)
	{
		regHigh |= 0xC0;
	}
	*x = (int16_t)(regHigh<<8) | regLow;

	OSTimeDlyHMSM(0,0,0,1);

	adis16209_chip_select_clear();
	adis16209_spi_transfer(adis16209_reg_xincl_out, &regHigh);
	adis16209_spi_transfer(0xFF, &regLow);
	adis16209_chip_select_set();
	regHigh &= 0x3F;
	if((regHigh & 0x20) != 0)
	{
		regHigh |= 0xC0;
	}
	*y = (int16_t)(regHigh<<8) | regLow;
}
