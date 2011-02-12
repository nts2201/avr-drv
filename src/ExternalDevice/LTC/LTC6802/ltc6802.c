/* Copyright (c) 2011 Frédéric Nadeau
   Copyright (c) 2006 Dave Hylands     <dhylands@gmail.com>

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

/*! \file ltc6802.c
 \brief Driver for the LTC6802 multicell battery stack monitor.

 This module is aimed to be portable across any device with
 SPI port. Some external functions are required.

 This module is based on the LTC6802-1 datasheet available
 at http://cds.linear.com/docs/Datasheet/68021fa.pdf
 at time of writing.

 \author Frédéric Nadeau
 */
#include <stdbool.h>
#include <stddef.h>
#include "ltc6802.h"

extern void ltc6802_spi_transfer(uint8_t ubDataOut, uint8_t *pubDataIn);
extern void ltc6802_clear_cs(void);
extern void ltc6802_set_cs(void);

static uint8_t _numDevice = 0; //Nombre de LTC6802 en daisy-chain

//This function comes from the robostix project. It uses BSD licenses and has
//been acknowledged in the file header.
static uint8_t crc8_ccitt_update(uint8_t inCrc, uint8_t inData)
{
	uint8_t i, data;

	data = inCrc ^ inData;

	for (i = 0; i < 8; i++)
	{
		if ((data & 0x80) != 0)
		{
			data <<= 1;
			data ^= 0x07;
		}
		else
		{
			data <<= 1;
		}
	}

	return data;
}

void ltc6802_init(uint8_t numDevice)
{
	//TODO check against maximum device chain
	_numDevice = numDevice;
}

void ltc6802_write_config(ltc6802_conf_t *cfg)
{
	uint8_t i, j;
	ltc6802_clear_cs();//Select chip

	//Send write configuration command
	ltc6802_spi_transfer(ltc6802_cmd_wrcfg, NULL);

	//For all LTC chips...
	for(i = 0; i < _numDevice; i++)
	{
		uint8_t *ptr = (uint8_t*)&cfg[i];//make conf strcut byte addressable
		//send whole configuration table
		for(j = 0; j < sizeof(ltc6802_conf_t); j++)
		{
			ltc6802_spi_transfer(ptr[j], NULL);
		}
	}

	ltc6802_set_cs();//Unselect chip
}

void ltc6802_read_config(ltc6802_conf_t *cfg)
{
	uint8_t i, j;
	ltc6802_clear_cs();//Select chip

	//Send write configuration command
	ltc6802_spi_transfer(ltc6802_cmd_rdcfg, NULL);

	//For all LTC chips...
	for(i = 0; i < _numDevice; i++)
	{
		uint8_t *ptr = (uint8_t*)&cfg[i];//make conf strcut byte addressable
		//send whole configuration table
		for(j = 0; j < sizeof(ltc6802_conf_t); j++)
		{
			ltc6802_spi_transfer(0xFF, &ptr[j]);
		}
	}

	ltc6802_set_cs();//Unselect chip
}

_Bool ltc6802_read_voltage(ltc6802_voltage_t *vtg)
{
	uint8_t i, j;
	uint8_t crcdata = 0;
	_Bool result = true;
	ltc6802_clear_cs();//Select chip

	//Send write configuration command
	ltc6802_spi_transfer(ltc6802_cmd_rdcv, NULL);

	//For all LTC chips...
	for(i = 0; i < _numDevice; i++)
	{
		uint8_t *ptr = (uint8_t*)&vtg[i];//make struct byte addressable
		//send whole configuration table
		for(j = 0; j < sizeof(ltc6802_voltage_t); j++)
		{
			ltc6802_spi_transfer(0xFF, &ptr[j]);
			crcdata = crc8_ccitt_update(crcdata,ptr[j]);
		}
		if(crcdata != 0)
		{
			result = false;
		}
	}

	ltc6802_set_cs();//Unselect chip

	return result;
}

_Bool ltc6802_read_temperature(ltc6802_temperature_t *tmp)
{
	uint8_t i, j;
	uint8_t crcdata = 0;
	_Bool result = true;
	ltc6802_clear_cs();//Select chip

	//Send write configuration command
	ltc6802_spi_transfer(ltc6802_cmd_rdtmp, NULL);

	//For all LTC chips...
	for(i = 0; i < _numDevice; i++)
	{
		uint8_t *ptr = (uint8_t*)&tmp[i];//make struct byte addressable
		//send whole configuration table
		for(j = 0; j < sizeof(ltc6802_temperature_t); j++)
		{
			ltc6802_spi_transfer(0xFF, &ptr[j]);
			crcdata = crc8_ccitt_update(crcdata,ptr[j]);
		}
		if(crcdata != 0)
		{
			result = false;
		}
	}

	ltc6802_set_cs();//Unselect chip

	return result;
}

void ltc6802_pool_cmd(ltc6802_pool_cmd_t cmd, _Bool poll)
{
	ltc6802_clear_cs();//Select chip

	//Send a broadcast command
	ltc6802_spi_transfer((uint8_t)cmd, NULL);

	//Poll if nescessary
	if(true == poll)
	{
		uint8_t status;
		uint16_t deadLock = 0;
		do
		{
			ltc6802_spi_transfer(0xFF, &status);
			deadLock++;
		}while((0x00 == status) && (10000 > deadLock));//for device running at 20Mhz SPI
	}

	ltc6802_set_cs();//Unselect chip
}
