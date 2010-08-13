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

#include <util/twi.h>

__attribute__((weak)) void twi_ext_start(void)
{
	twi_send_stop();
}

__attribute__((weak)) void twi_ext_repeated_start(void)
{
	twi_send_stop();
}

__attribute__((weak)) void twi_ext_master_tx_slave_ack_address(void)
{
	twi_send_stop();
}

__attribute__((weak)) void twi_ext_master_tx_slave_nack_address(void)
{
	twi_send_stop();
}

__attribute__((weak)) void twi_master_tx_slave_ack_data(void)
{
	twi_send_stop();
}

__attribute__((weak)) void twi_master_tx_slave_nack_data(void)
{
	twi_send_stop();
}

__attribute__((weak)) void twi_master_tx_rx_arbitration_lost(void)
{
	twi_receive_byte(false);
}

__attribute__((weak)) void twi_master_rx_slave_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_master_rx_slave_nack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_master_rx_slave_ack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_master_rx_slave_nack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_arb_lost_slave_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_general_call_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_arb_lost_slave_general_call_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_rx_ack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_rx_nack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_rx_general_call_ack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void tw_slave_rx_general_call_nack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_rx_stop(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_tx_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_arb_lost_slave_tx_ack_address(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_tx_ack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_tx_nack_data(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_slave_tx_last_data_ack_received(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_no_info(void)
{
	asm volatile("nop"::);
}

__attribute__((weak)) void twi_bus_error(void)
{
	asm volatile("nop"::);
	twi_send_stop();
}

//! I2C (TWI) interrupt service routine
void twi_isr(void)
{
	// read status bits
	uint8_t ubStatus = TW_STATUS;

	switch(ubStatus)
	{
	// Master General
	case TW_START:						// 0x08: Sent start condition
		twi_ext_start();
		break;
	case TW_REP_START:					// 0x10: Sent repeated start condition
		twi_ext_repeated_start();
		break;

	// Master Transmitter & Receiver status codes
	case TW_MT_SLA_ACK:					// 0x18: Slave address acknowledged
		twi_ext_master_tx_slave_ack_address();
		break;
	case TW_MT_SLA_NACK:				// 0x20: Slave address not acknowledged
		twi_ext_master_tx_slave_nack_address();
		break;
	case TW_MT_DATA_ACK:				// 0x28: Data acknowledged
		twi_master_tx_slave_ack_data();
		break;
	case TW_MT_DATA_NACK:				// 0x30: Data not acknowledged
		twi_master_tx_slave_nack_data();
		break;
	case TW_MT_ARB_LOST:				// 0x38: Bus arbitration lost
	//case TW_MR_ARB_LOST:				// 0x38: Bus arbitration lost
		twi_master_tx_rx_arbitration_lost();
		break;
	case TW_MR_SLA_ACK:					// 0x40: Slave address acknowledged
		twi_master_rx_slave_ack_address();
		break;
	case TW_MR_SLA_NACK:				// 0x48: Slave address not acknowledged
		twi_master_rx_slave_nack_address();
		break;
	case TW_MR_DATA_ACK:				// 0x50: Data acknowledged
		twi_master_rx_slave_ack_data();
		break;
	case TW_MR_DATA_NACK:				// 0x58: Data received, NACK reply issued
		twi_master_rx_slave_nack_data();
		break;

	////Status code for slave receiver mode.
	case TW_SR_SLA_ACK:					// 0x60: own SLA+W has been received, ACK has been returned
		twi_slave_ack_address();
		break;
	case TW_SR_ARB_LOST_SLA_ACK:		// 0x68: own SLA+W has been received, ACK has been returned
		twi_arb_lost_slave_ack_address();
		break;
	case TW_SR_GCALL_ACK:				// 0x70:     GCA+W has been received, ACK has been returned
		twi_slave_general_call_ack_address();
		break;
	case TW_SR_ARB_LOST_GCALL_ACK:		// 0x78:     GCA+W has been received, ACK has been returned
		twi_arb_lost_slave_general_call_ack_address();
		break;
	case TW_SR_DATA_ACK:				// 0x80: data byte has been received, ACK has been returned
		twi_slave_rx_ack_data();
		break;
	case TW_SR_DATA_NACK:				// 0x88: data byte has been received, NACK has been returned
		twi_slave_rx_nack_data();
		break;
	case TW_SR_GCALL_DATA_ACK:			// 0x90: data byte has been received, ACK has been returned
		twi_slave_rx_general_call_ack_data();
		break;
	case TW_SR_GCALL_DATA_NACK:			// 0x98: data byte has been received, NACK has been returned
		tw_slave_rx_general_call_nack_data();
		break;
	case TW_SR_STOP:					// 0xA0: STOP or REPEATED START has been received while addressed as slave
		twi_slave_rx_stop();
		break;

	////Status codes for slave transmitter mode.

	////Le master signales qu'il veut recevoir du data.
	case TW_ST_SLA_ACK:					// 0xA8: own SLA+R has been received, ACK has been returned
		twi_slave_tx_ack_address();
		break;

	case TW_ST_ARB_LOST_SLA_ACK:		// 0xB0:     GCA+R has been received, ACK has been returned
		twi_arb_lost_slave_tx_ack_address();
		break;

	////Feedback que le data transmit (en tant que slave) a ete recu.
	case TW_ST_DATA_ACK:				// 0xB8: data byte has been transmitted, ACK has been received
		twi_slave_tx_ack_data();
		break;
	case TW_ST_DATA_NACK:				// 0xC0: data byte has been transmitted, NACK has been received
		twi_slave_tx_nack_data();
		break;
	case TW_ST_LAST_DATA:				// 0xC8:
		twi_slave_tx_last_data_ack_received();
		break;

	case TW_NO_INFO:					// 0xF8: No relevant state information
		twi_no_info();
		break;
	case TW_BUS_ERROR:					// 0x00: Bus error due to illegal start or stop condition
		twi_bus_error();
		break;
	}
}
