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

#include <avr/io.h>
#include <avr/interrupt.h>

#include "twi.h"
#include "io_pin/io_pin.h"

// Standard I2C bit rates are:
// 100KHz for slow speed
// 400KHz for high speed

#define TWCR_TWINT_MASK 0x7F
#define TWCR_CMD_MASK 0x0F

// functions
void twi_init(uint32_t clkio)
{
	// set pull-up resistors on I2C bus pins
    SCL_DDR |= _BV(SCL_PIN);
    SDA_DDR |= _BV(SDA_PIN);

	// set i2c bit rate to 100KHz
	twi_set_bitrate(clkio, 100);
	// enable TWI (two-wire interface)
	TWCR |= (1<<TWEN);
}

void twi_set_bitrate(uint32_t clkio, uint8_t uwBitrateKHz)
{

	if((clkio/1000/(16+2*0xFF)) <= uwBitrateKHz)
	{
		TWBR = ((clkio/1000/uwBitrateKHz - 16)/(2));
		TWSR &= ~(_BV(TWPS1) | _BV(TWPS0));
	}
	else if((clkio/1000/(16+2*0xFF*4)) <= uwBitrateKHz)
	{
		TWBR = ((clkio/1000/uwBitrateKHz - 16)/(2*4));
		TWSR &= ~(_BV(TWPS1));
		TWSR |= _BV(TWPS0);
	}
	else if((clkio/1000/(16+2*0xFF*16)) <= uwBitrateKHz)
	{
		TWBR = ((clkio/1000/uwBitrateKHz - 16)/(2*16));
		TWSR &= ~(_BV(TWPS0));
		TWSR |= _BV(TWPS1);
	}
	else if((clkio/1000/(16+2*0xFF*64)) <= uwBitrateKHz)
	{
		TWBR = ((clkio/1000/uwBitrateKHz - 16)/(2*64));
		TWSR |= _BV(TWPS0) | _BV(TWPS1);
	}
	else
	{
		asm("break");
	}

}

void twi_set_slave_address( void )
{
	uint8_t ubAddress = (0x01)<<1;
	TWAR = ubAddress&0xFE;
}

void twi_enable_slave_addressing( void )
{
	TWCR |= _BV(TWEA);
}

void twi_enable_int(void)
{
	TWCR |= TWCR_TWINT_MASK & (1<<TWIE);
}

void twi_disable_int(void)
{
	TWCR &= TWCR_TWINT_MASK & (~(1<<TWIE));
}

void twi_send_start(void)
{
	// send start condition
	//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT)|BV(TWSTA));
	//TWCR |= (1<<TWINT)|(1<<TWSTA);
	TWCR = (TWCR & TWCR_CMD_MASK) |  (1<<TWINT)|(1<<TWSTA);
}

void twi_send_stop(void)
{
	// transmit stop condition
	// leave with TWEA on for slave receiving
	//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT)|BV(TWEA)|BV(TWSTO));
	//TWCR |= (1<<TWINT)|(1<<TWSTO)|(1<<TWEA);
	TWCR = (TWCR & TWCR_CMD_MASK) |   (1<<TWINT)|(1<<TWSTO)|(1<<TWEA);
}

void twi_wait_completion(void)
{
	// wait for i2c interface to complete operation;
	loop_until_bit_is_set(TWCR,TWINT);
}

void twi_send_byte(uint8_t ubData)
{
	// save data to the TWDR
	//outb(TWDR, data);
	TWDR = ubData;
	// begin send
	//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT));
	//TWCR |= (1<<TWINT);
	TWCR = (TWCR & TWCR_CMD_MASK) |  (1<<TWINT);
}

void twi_receive_byte(uint8_t ubAck)
{
	// begin receive over i2c
	if( ubAck != 0 )
	{
		// ackFlag = TRUE: ACK the recevied data
		//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT)|BV(TWEA));
		//TWCR |= (1<<TWINT)|(TWEA);
		TWCR = (TWCR & TWCR_CMD_MASK) |  (1<<TWINT)|(1<<TWEA);
	}
	else
	{
		// ackFlag = FALSE: NACK the recevied data
		//outb(TWCR, (inb(TWCR)&TWCR_CMD_MASK)|BV(TWINT));
		//TWCR |= (1<<TWINT);
		TWCR = (TWCR & TWCR_CMD_MASK) |  (1<<TWINT);
	}
}

uint8_t twi_get_received_byte(void)
{
	// retrieve received data byte from i2c TWDR
	return( TWDR );
}

uint8_t twi_get_status(void)
{
	// retrieve current i2c status from i2c TWSR
	return( TW_STATUS );
}

