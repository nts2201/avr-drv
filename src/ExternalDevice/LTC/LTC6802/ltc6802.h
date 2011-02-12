/* Copyright (c) 2011 Frédéric Nadeau
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

/*! \file ltc6802.h
 \brief API for the LTC6802 multicell battery stack monitor.

 \author Frédéric Nadeau
 */
#ifndef LTC6802_H_
#define LTC6802_H_

#include <stdbool.h>
#include <stdint.h>

//! Operation codes used by the SPI driver.
typedef enum ltc6802_op_e {
	ltc6802_op_stcvad = 0x10,
	ltc6802_op_stowad = 0x20,
	ltc6802_op_sttmpad = 0x30,
	ltc6802_op_pladc = 0x40,
	ltc6802_op_plint = 0x50,
	ltc6802_op_stcvdc = 0x60,
	ltc6802_op_stowdc = 0x70
} ltc6802_op_t;

//! Registers codes used by the SPI driver.
typedef enum ltc6802_cmd_e {
	ltc6802_cmd_wrcfg = 0x01,
	ltc6802_cmd_rdcfg,
	ltc6802_cmd_rdcv = 0x04,
	ltc6802_cmd_rdflg = 0x06,
	ltc6802_cmd_rdtmp = 0x08,
} ltc6802_cmd_t;

typedef struct ltc6802_conf_s
{
	uint8_t ltc6802_conf_cfgr0;
	uint8_t ltc6802_conf_cfgr1;
	uint8_t ltc6802_conf_cfgr2;
	uint8_t ltc6802_conf_cfgr3;
	uint8_t ltc6802_conf_cfgr4;
	uint8_t ltc6802_conf_cfgr5;
}ltc6802_conf_t;

typedef struct ltc6802_voltage_s
{
	uint8_t ltc6802_read_cvr00;
	uint8_t ltc6802_read_cvr01;
	uint8_t ltc6802_read_cvr02;
	uint8_t ltc6802_read_cvr03;
	uint8_t ltc6802_read_cvr04;
	uint8_t ltc6802_read_cvr05;
	uint8_t ltc6802_read_cvr06;
	uint8_t ltc6802_read_cvr07;
	uint8_t ltc6802_read_cvr08;
	uint8_t ltc6802_read_cvr09;
	uint8_t ltc6802_read_cvr10;
	uint8_t ltc6802_read_cvr11;
	uint8_t ltc6802_read_cvr12;
	uint8_t ltc6802_read_cvr13;
	uint8_t ltc6802_read_cvr14;
	uint8_t ltc6802_read_cvr15;
	uint8_t ltc6802_read_cvr16;
	uint8_t ltc6802_read_cvr17;
	uint8_t ltc6802_read_pec;
}ltc6802_voltage_t;

typedef struct ltc6802_temperature_s
{
	uint8_t ltc6802_temperature_tmpr0;
	uint8_t ltc6802_temperature_tmpr1;
	uint8_t ltc6802_temperature_tmpr2;
	uint8_t ltc6802_temperature_tmpr3;
	uint8_t ltc6802_temperature_tmpr4;
	uint8_t ltc6802_temperature_pec;
}ltc6802_temperature_t;

typedef enum ltc6802_pool_cmd_e
{
	ltc6802_pool_cmd_stcvad_all_cell		= 0x10,
	ltc6802_pool_cmd_stcvad_cell_1,
	ltc6802_pool_cmd_stcvad_cell_2,
	ltc6802_pool_cmd_stcvad_cell_3,
	ltc6802_pool_cmd_stcvad_cell_4,
	ltc6802_pool_cmd_stcvad_cell_5,
	ltc6802_pool_cmd_stcvad_cell_6,
	ltc6802_pool_cmd_stcvad_cell_7,
	ltc6802_pool_cmd_stcvad_cell_8,
	ltc6802_pool_cmd_stcvad_cell_9,
	ltc6802_pool_cmd_stcvad_cell_10,
	ltc6802_pool_cmd_stcvad_cell_11,
	ltc6802_pool_cmd_stcvad_cell_12,
	ltc6802_pool_cmd_stcvad_self_test_1 = 0x1E,
	ltc6802_pool_cmd_stcvad_self_test_2,
	ltc6802_pool_cmd_stowad_all_cell		= 0x20,
	ltc6802_pool_cmd_stowad_cell_1,
	ltc6802_pool_cmd_stowad_cell_2,
	ltc6802_pool_cmd_stowad_cell_3,
	ltc6802_pool_cmd_stowad_cell_4,
	ltc6802_pool_cmd_stowad_cell_5,
	ltc6802_pool_cmd_stowad_cell_6,
	ltc6802_pool_cmd_stowad_cell_7,
	ltc6802_pool_cmd_stowad_cell_8,
	ltc6802_pool_cmd_stowad_cell_9,
	ltc6802_pool_cmd_stowad_cell_10,
	ltc6802_pool_cmd_stowad_cell_11,
	ltc6802_pool_cmd_stowad_cell_12,
	ltc6802_pool_cmd_stowad_self_test_1 = 0x2E,
	ltc6802_pool_cmd_stowad_self_test_2,
	ltc6802_pool_cmd_sttmpad_all = 0x30,
	ltc6802_pool_cmd_sttmpad_ext_temp_1,
	ltc6802_pool_cmd_sttmpad_ext_temp_2,
	ltc6802_pool_cmd_sttmpad_int_temp,
	ltc6802_pool_cmd_sttmpad_self_test_1 = 0x3E,
	ltc6802_pool_cmd_sttmpad_self_test_2,
	ltc6802_pool_cmd_stcvdc_all_cell		= 0x60,
	ltc6802_pool_cmd_stcvdc_cell_1,
	ltc6802_pool_cmd_stcvdc_cell_2,
	ltc6802_pool_cmd_stcvdc_cell_3,
	ltc6802_pool_cmd_stcvdc_cell_4,
	ltc6802_pool_cmd_stcvdc_cell_5,
	ltc6802_pool_cmd_stcvdc_cell_6,
	ltc6802_pool_cmd_stcvdc_cell_7,
	ltc6802_pool_cmd_stcvdc_cell_8,
	ltc6802_pool_cmd_stcvdc_cell_9,
	ltc6802_pool_cmd_stcvdc_cell_10,
	ltc6802_pool_cmd_stcvdc_cell_11,
	ltc6802_pool_cmd_stcvdc_cell_12,
	ltc6802_pool_cmd_stcvdc_self_test_1 = 0x6E,
	ltc6802_pool_cmd_stcvdc_self_test_2,
	ltc6802_pool_cmd_stowdc_all_cell		= 0x70,
	ltc6802_pool_cmd_stowdc_cell_1,
	ltc6802_pool_cmd_stowdc_cell_2,
	ltc6802_pool_cmd_stowdc_cell_3,
	ltc6802_pool_cmd_stowdc_cell_4,
	ltc6802_pool_cmd_stowdc_cell_5,
	ltc6802_pool_cmd_stowdc_cell_6,
	ltc6802_pool_cmd_stowdc_cell_7,
	ltc6802_pool_cmd_stowdc_cell_8,
	ltc6802_pool_cmd_stowdc_cell_9,
	ltc6802_pool_cmd_stowdc_cell_10,
	ltc6802_pool_cmd_stowdc_cell_11,
	ltc6802_pool_cmd_stowdc_cell_12,
	ltc6802_pool_cmd_stowdc_self_test_1 = 0x7E,
	ltc6802_pool_cmd_stowdc_self_test_2
}ltc6802_pool_cmd_t;

void ltc6802_init(uint8_t numDevice);

void ltc6802_write_config(ltc6802_conf_t *cfg);
void ltc6802_read_config(ltc6802_conf_t *cfg);

_Bool ltc6802_read_voltage(ltc6802_voltage_t *vtg);
_Bool ltc6802_read_temperature(ltc6802_temperature_t *tmp);

void ltc6802_start(void);
void ltc6802_pool_cmd(ltc6802_pool_cmd_t cmd, _Bool poll);

#endif /* SPC1000_H_ */
