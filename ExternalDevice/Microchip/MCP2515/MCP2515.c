/* Copyright (c) 2007 Sy Sech VONG
   Copyright (c) 2008,2009,2011 Frédéric Nadeau

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

/*! \file MCP2515.c
    \brief API for Microchip MCP2515 CAN controller.

    This CAN controller use the SPI link. For that reason, SPI initiation and data
    control should custom by the user.

     \author Sy Sech VONG
             Frédéric Nadeau
 */

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "MCP2515define.h"
#include "MCP2515.h"

/*! \fn uint8_t mcp2515_spi_port_init(void)
 *  \brief	Provide the initiation of the SPI port to be use for the MCP2515 transmission.
 *
 *  This function should also initialize any IO required for the MCP2515.
 */
extern void mcp2515_spi_port_init(void);

/*! \fn void mcp2515_spi_select(void)
 *  \brief	This function shall drive the CS pin low.
 */
extern void mcp2515_spi_select(void);

/*! \fn void mcp2515_spi_unselect(void)
 *  \brief	This function shall drive the CS pin high.
 */
extern void mcp2515_spi_unselect(void);

/*! \fn uint8_t mcp2515_spi_transfer(uint8_t dataOut, uint8_t *dataIn)
 *  \brief Provide the transmission service on the SPI port to MCP2515.
 *  \param dataOut Data to be send.
 *  \param dataIn Pointer to 8 bits data space. Read value will be saved at specified address.
 */
extern void mcp2515_spi_transfer(uint8_t dataOut, uint8_t *dataIn);

/*! \fn uint8_t MCP2515canIDRead(uint32_t *canID)
 *  \brief Read the Std or Ext ID from the correct register.
 *
 *   This is use along with the bust method which meant that the "!CS" is
 *   already lowed ( by mcp2515_spi_select() )and the next address of the
 *   register must XXXnSIDH.
 *  \param canID is the address of the value Std or Ext ID with 29th bit = 0 for Std ID or
 *   29th bit = 1 for Ext ID. It returns the CAN ID locate in *canID provided.
 */
static void id_read(uint32_t *canID)
{
    uint8_t dataIn;
    uint32_t uwID = 0;

    mcp2515_spi_transfer(0, &dataIn);//read XXXnSIDH
    uwID = (((uint32_t)dataIn) << 21);
    mcp2515_spi_transfer(0, &dataIn);//read XXXnSIDL
    uwID |= ( ((uint32_t)(dataIn & 0xE0)) << 13);
    uwID |= ( ((uint32_t)(dataIn & 0x03)) << 16);

    if (dataIn & 0x08) //Ext. ID? (bit mask on bit3)
        uwID |= 0x20000000;

    mcp2515_spi_transfer(0, &dataIn);//read XXXnEID8
    uwID |= (((uint32_t)dataIn) << 8);
    mcp2515_spi_transfer(0, &dataIn);//read XXXnEID0
    uwID |= (uint32_t)dataIn;
    *canID = uwID;
}

/*! \fn uint8_t MCP2515canIDWrite(uint32_t canID)
 *  \brief Write the Std or Ext ID to the correct register.
 *
 *   This is use along with the bust method which meant that the "!CS" is
 *   already lowed ( by mcp2515_spi_select() )and the next address of the
 *   register must XXXnSIDH.
 *  \param canID is the Std or Ext ID with 29th bit = 0 for Std ID or 29th bit = 1 for Ext ID.
 */
static void id_write(uint32_t canID)
{
    uint8_t ubtempo = 0;

    mcp2515_spi_transfer((uint8_t) (canID >> 21), NULL);//send XXXnSIDH
    ubtempo = ( (uint8_t)(canID >> 13) ) & 0xE0;
    ubtempo |= ( (uint8_t)(canID >> 16) ) & 0x03;

    if (canID & 0x20000000)//Ext. ID?
        ubtempo |= 0x08;

    mcp2515_spi_transfer(ubtempo, NULL);//send XXXnSIDL
    mcp2515_spi_transfer((uint8_t) (canID >> 8), NULL);//Send XXXnEID8
    mcp2515_spi_transfer((uint8_t) canID, NULL);//Send XXXnEID0
}

/*! \fn void read(uint8_t regAddr, uint8_t *dataAddr)
 *  \brief Send the Read command over SPI bus. It can read any register
 *  byte accordingly of the address provided.
 *  \param regAddr is the register address of the MCP2515.
 *  \param dataAddr is the address of the data to be writed on.
 */
static void read(uint8_t regAddr, uint8_t *dataAddr)
{
    assert(dataAddr != 0);

    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_READ, NULL);
    mcp2515_spi_transfer(regAddr, NULL);
    mcp2515_spi_transfer(0, dataAddr);
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

/*! \fn void read_bust(uint8_t regAddr, uint8_t *dataAddr, uint8_t size)
 *  \brief Send the READ command over SPI bus. It can read any register
 *  byte accordingly of the address provided. It provides a burst read so please
 *  be careful on the read data that not overlap other MCP2515 registers's data.
 *  \param regAddr is the register address of the MCP2515.
 *  \param dataAddr is the address of the data to be saved.
 *  \param size is the data byte size to be read (n bytes).
 */
static void read_bust(uint8_t regAddr, uint8_t *dataAddr, uint8_t size)
{
    uint8_t i;

    assert((dataAddr != NULL) && (size != 0));

    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_READ, NULL);
    mcp2515_spi_transfer(regAddr, NULL);

    for (i=0; i <= size; i++)
        mcp2515_spi_transfer(0, dataAddr++);

    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

/*! \fn static void write(uint8_t regAddr, uint8_t data)
 *  \brief	Send the WRITE command over SPI bus. It can write any register
 *  byte accordingly of the address provided.
 *  \param	regAddr is the register address of the MCP2515.
 *  \param	data is the data to be send.
 */
static void write(uint8_t regAddr, uint8_t data)
{
    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_WRITE, NULL);
    mcp2515_spi_transfer(regAddr, NULL);
    mcp2515_spi_transfer(data, NULL);
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

/*! \fn void write_bust(uint8_t regAddr, uint8_t *dataAddr, uint8_t size)
 *  \brief Send the WRITE command over SPI bus. It can write any register
 *  byte accordingly of the address provided. It provides a bust write so please
 *  be careful on the write data that not overlap other MCP2515 registers's data.
 *  \param regAddr is the register address of the MCP2515.
 *  \param dataAddr is the begin address of the data byte to be send.
 *  \param size is the data byte size to be send (n bytes).
 */
static void write_bust(uint8_t regAddr, uint8_t *dataAddr, uint8_t size)
{
    uint8_t i;

    assert(dataAddr != NULL);

    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_WRITE, NULL);
    mcp2515_spi_transfer(regAddr, NULL);

    for (i=0; i < size; i++)
        mcp2515_spi_transfer(dataAddr[i], NULL);

    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

/*! \fn void bit_modify(uint8_t regAddr, uint8_t bitMask, uint8_t val)
 *  \brief Send the Bit Modify command over SPI bus.
 *
 *  This changes individual bit at
 *  the given register address. Not all registers can be changed that way.
 *  Please see the MCP2515.pdf p.61 and p.64 for more information.
 *  \param regAddr is the register address.
 *  \param bitMask is the bit mask.
 *  \param val is the value to be set.
 */
static void bit_modify(uint8_t regAddr, uint8_t bitMask, uint8_t val)
{
    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_BIT_MODIFY, NULL);
    mcp2515_spi_transfer(regAddr, NULL);
    mcp2515_spi_transfer(bitMask, NULL);
    mcp2515_spi_transfer(val, NULL);
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_reset(void)
{
    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_RESET, NULL);
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_read_rx_buf(mcp2515_rx_t channel, mcp2515_can_frame_t *canData)
{
    uint8_t i;

    assert(canData != NULL);


    mcp2515_spi_select();//Select the MCP2515 on the SPI bus

    switch (channel)
    {
        case mcp2515_rx_0:
        mcp2515_spi_transfer(MCP2515_READ_BUF_RXB0SIDH, NULL);
        break;
        case mcp2515_rx_1:
        mcp2515_spi_transfer(MCP2515_READ_BUF_RXB1SIDH, NULL);
        break;
        default:
        assert(0);
        //break;
    }
    id_read(&canData->id);

    mcp2515_spi_transfer(0, &canData->dlc);//read DLC
    canData->dlc &= 0x0F;
    for (i = 0; i < canData->dlc; i++)
    {
        mcp2515_spi_transfer(0, &canData->data[i]);
    }
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}


void mcp2515_load_tx_buf(uint8_t nBuf, mcp2515_can_frame_t *canData)
{
    uint8_t i;

    assert(canData != NULL);

    switch (nBuf)
    {
    case MCP2515_TX_BUF_0:
        mcp2515_spi_select();//Select the MCP2515 on the SPI bus
        mcp2515_spi_transfer(MCP2515_LOAD_BUF_TXB0SIDH, NULL);
        break;
    case MCP2515_TX_BUF_1:
        mcp2515_spi_select();//Select the MCP2515 on the SPI bus
        mcp2515_spi_transfer(MCP2515_LOAD_BUF_TXB1SIDH, NULL);
        break;
    case MCP2515_TX_BUF_2:
        mcp2515_spi_select();//Select the MCP2515 on the SPI bus
        mcp2515_spi_transfer(MCP2515_LOAD_BUF_TXB2SIDH, NULL);
        break;
    default:
        assert(0);
        //break;
    }

    id_write(canData->id);
    mcp2515_spi_transfer(canData->dlc & 0x0F, NULL);
    for (i = 0; (i < canData->dlc) && (i < MCP2515_MAX_BYTE_CANFRM); i++)
    {
        mcp2515_spi_transfer(canData->data[i], NULL);
    }
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_rts(uint8_t nBuf)
{
    //uint8_t ubRetVal = SPI_OK;
    uint8_t dataIn;

    mcp2515_spi_select();//Select the MCP2515 on the SPI bus

    switch (nBuf)
    {
    case MCP2515_TX_BUF_0:
        mcp2515_spi_transfer(MCP2515_RTS_TXB0, &dataIn);
        break;
    case MCP2515_TX_BUF_1:
        mcp2515_spi_transfer(MCP2515_RTS_TXB1, &dataIn);
        break;
    case MCP2515_TX_BUF_2:
        mcp2515_spi_transfer(MCP2515_RTS_TXB2, &dataIn);
        break;
    default:
        assert(0);
        //break;
    }
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_read_rxtx_status(uint8_t* canRxTxStatus)
{
    assert(canRxTxStatus != NULL);

    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_READ_RXTX_STATUS, NULL);
    mcp2515_spi_transfer(0, canRxTxStatus);

    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_rx_status(uint8_t* canRxStatus)
{

    assert(canRxStatus != NULL);

    mcp2515_spi_select();//Select the MCP2515 on the SPI bus
    mcp2515_spi_transfer(MCP2515_READ_RXTX_STATUS, NULL);
    mcp2515_spi_transfer(0, canRxStatus);
    mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_clear_interrupt(void)
{
	mcp2515_spi_select();//Select the MCP2515 on the SPI bus
	mcp2515_spi_transfer(MCP2515_WRITE, NULL);
	mcp2515_spi_transfer(MCP2515_CANINTF, NULL);
	mcp2515_spi_transfer(0, NULL);
	mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus
}

void mcp2515_set_rx_filter_mask(mcp2515_rx_filter_mask_t regAddr, uint32_t canID)
{
	mcp2515_spi_select();//Select the MCP2515 on the SPI bus
	mcp2515_spi_transfer(MCP2515_WRITE, NULL);
	mcp2515_spi_transfer((uint8_t)regAddr, NULL);
	id_write(canID);
	mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus

}

int mcp2515_get_int_flag(void)
{
	uint8_t value;
	mcp2515_spi_select();//Select the MCP2515 on the SPI bus
	mcp2515_spi_transfer(MCP2515_READ, NULL);
	mcp2515_spi_transfer(MCP2515_CANINTF, NULL);
	mcp2515_spi_transfer(0, &value);
	mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus

	return (int)value;
}

void mcp2515_set_op_mode(mcp2515_op_mode_t mode)
{
	bit_modify(MCP2515_CANCTRL, 0xE0, mode<<5);
}

void mcp2515_set_rx_op_mode(mcp2515_rx_t channel, mcp2515_rx_op_mode_t mode)
{
	switch(channel)
	{
	case mcp2515_rx_0:
		bit_modify(MCP2515_RXB0CTRL, 0x60, mode<<5);
		break;
	case mcp2515_rx_1:
		bit_modify(MCP2515_RXB1CTRL, 0x60, mode<<5);
		break;
	default:
        assert(0);
		break;
	}
}

void mcp2515_enable_rx_int(mcp2515_rx_t channel)
{
	switch(channel)
	{
	case mcp2515_rx_0:
		bit_modify(MCP2515_CANINTE, 0x01, 0x01);
		break;
	case mcp2515_rx_1:
		bit_modify(MCP2515_CANINTE, 0x02, 0x02);
		break;
	default:
        assert(0);
		break;
	}
}

void mcp2515_enable_tx_int(mcp2515_tx_t channel)
{
	switch(channel)
	{
	case mcp2515_tx_0:
		bit_modify(MCP2515_CANINTE, 0x04, 0x04);
		break;
	case mcp2515_tx_1:
		bit_modify(MCP2515_CANINTE, 0x08, 0x08);
		break;
	case mcp2515_tx_2:
		bit_modify(MCP2515_CANINTE, 0x10, 0x10);
		break;
	default:
        assert(0);
		break;
	}
}

int mcp2515_set_baudrate(uint32_t ulBaudrate, uint32_t ulMCP2515Clk, uint8_t ubSamplingTime, uint8_t ubTsjw)
{
	static uint8_t ubDivider;
	static uint8_t ubTbit;
	static uint8_t ubTprs;
	static uint8_t ubTphs1;
	static uint8_t ubTphs2;
	static uint8_t ubBRP = 1;

	ubDivider = ulMCP2515Clk / ulBaudrate;

	ubTbit = ubDivider/2;
	while ( (ubTbit >= MCP2515_MAX_TQ) | (ubTbit <= MCP2515_MIN_TQ))
	{
		ubTbit = (ubTbit >> 1);
		ubBRP*=2;
	}

	ubTphs2 = (ubTbit * (100 - ubSamplingTime) / 100);
	ubTphs1 = 0;

	for(ubTprs = 8; ubTprs > 0; ubTprs--)
	{
		if((1 + ubTprs + ubTphs2 + ubTphs2) <= (ubTbit + 8 - ubTphs2)
						&& ((ubTbit - 1 - ubTprs - ubTphs2) >= ubTphs2))
		{
				ubTphs1 = ubTbit - 1 - ubTprs - ubTphs2;
				break;
		}
	}

	//SET ALL THE REGISTER OF THE MCP 2515 FOR THE DESIRED BAUD RATE
	mcp2515_spi_select();//Select the MCP2515 on the SPI bus
	mcp2515_spi_transfer(MCP2515_WRITE, NULL);
	mcp2515_spi_transfer(MCP2515_CNF3, NULL);
	mcp2515_spi_transfer(0x07 & (ubTphs2-1), NULL);//CF3
	mcp2515_spi_transfer((0x07 & (ubTprs-1))|(0x38 & ((ubTphs1-1)<<3))|(0x80), NULL);//CF2
	mcp2515_spi_transfer((0x03 & ((ubTsjw-1)<<6))|(0x20 & (ubBRP-1)), NULL);//CF1 : 1TQ for SJW and BRP = 5 for 1TQ = 12/F_CPU
	mcp2515_spi_unselect();//Unselect the MCP2515 on the SPI bus

	if (ubDivider == (ubBRP) * (ubTprs + ubTphs1 + ubTphs2 + 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
