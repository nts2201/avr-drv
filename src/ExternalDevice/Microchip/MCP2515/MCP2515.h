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


/*! \file MCP2515.h
    \brief API to control the Microchip MCP2515 CAN controller. This CAN
    controller use the SPI link. For that reason, SPI initiation and data
    control should custom by the user.

     \author Sy Sech VONG
             Frédéric Nadeau
*/


#ifndef MCP2515_H_
#define MCP2515_H_

#include <stdint.h>

#define MCP2515_CANINT_MERR	0x80
#define MCP2515_CANINT_WAKI	0x40
#define MCP2515_CANINT_ERRI	0x20
#define MCP2515_CANINT_TX2I	0x10
#define MCP2515_CANINT_TX1I	0x08
#define MCP2515_CANINT_TX0I	0x04
#define MCP2515_CANINT_RX1I	0x02
#define MCP2515_CANINT_RX0I	0x01

/*! \struct mcp2515_can_frame_s
 *  Structure of a CANbus frame.
 */
typedef struct mcp2515_can_frame_s{
    uint32_t id;        /**< Standard or Extented ID*/
    uint8_t data[8];    /**< Data*/
    uint8_t dlc;        /**< Data Length Code*/
}mcp2515_can_frame_t;   /**< Typedef of #mcp2515_can_frame_s*/

typedef enum mcp2515_rx_e
{
	mcp2515_rx_0,
	mcp2515_rx_1
}mcp2515_rx_t;

typedef enum mcp2515_tx_e
{
	mcp2515_tx_0,
	mcp2515_tx_1,
	mcp2515_tx_2
}mcp2515_tx_t;

typedef enum mcp2515_op_mode_e
{
	mcp2515_op_mode_normal = 0,
	mcp2515_op_mode_sleep,
	mcp2515_op_mode_loopback,
	mcp2515_op_mode_listen,
	mcp2515_op_mode_config
}mcp2515_op_mode_t;

typedef enum mcp2515_rx_op_mode_e
{
	mcp2515_rx_op_mode_filter_any = 0,
	mcp2515_rx_op_mode_filter_standard,
	mcp2515_rx_op_mode_filter_extended,
	mcp2515_rx_op_mode_any
}mcp2515_rx_op_mode_t;

typedef enum mcp2515_rx_filter_mask_e
{
	mcp2515_rx_filter_mask_RXF0 = 0x00,
	mcp2515_rx_filter_mask_RXF1 = 0x04,
	mcp2515_rx_filter_mask_RXF2 = 0x08,
	mcp2515_rx_filter_mask_RXF3 = 0x10,
	mcp2515_rx_filter_mask_RXF4 = 0x14,
	mcp2515_rx_filter_mask_RXF5 = 0x18,
	mcp2515_rx_filter_mask_RXM0 = 0x20,
	mcp2515_rx_filter_mask_RXM1 = 0x24
}mcp2515_rx_filter_mask_t;


/*! \fn uint8_t mcp2515_reset(void)
 *  \brief Send the RESET command over SPI bus. It has the same effect as
 *  lowing the RESET pin of MCP2515.
 */
void mcp2515_reset(void);

/*! \fn uint8_t mcp2515_read_rx_buf(uint8_t nBuf, mcp2515_can_frame_t *canData)
 *  \brief Send the Read RX Buffer command over SPI bus. This reads the whole CAN frame.
 *  \param nBuf buffer of #MCP2515_RX_BUF_0 (buffer RX 0) or #MCP2515_RX_BUF_1 (buffer RX 1).
 *  \param canData is the address of mcp2515_can_frame_t type.
 */
void mcp2515_read_rx_buf(mcp2515_rx_t channel, mcp2515_can_frame_t *canData);

/*! \fn uint8_t mcp2515_load_tx_buf(uint8_t nBuf, mcp2515_can_frame_t *canData)
 *  \brief Send the Load TX Buffer command over SPI bus. This loads the whole CAN frame
 *   to the buffer.
 *  \param nBuf is buffer of #MCP2515_TX_BUF_0/1/2 (buffer TX 0,1 or 2).
 *  \param canData is the begin address of mcp2515_can_frame_t type.
 */
void mcp2515_load_tx_buf(uint8_t nBuf, mcp2515_can_frame_t *canData);

/*! \fn uint8_t mcp2515_rts(uint8_t nBuf)
 *  \brief Send the Request-To-Send (RTS) command over SPI bus. This sets a RTS to
 *   the TX buffer.
 *  \param nBuf is buffer of #MCP2515_TX_BUF_0/1/2 (buffer 0,1 or 2).
 */
void mcp2515_rts(uint8_t nBuf);

/*! \fn uint8_t mcp2515_read_rxtx_status(uint8_t* canRxTxStatus)
 *  \brief Send the Read Status command over SPI bus. This requests the CAN controller
 *   to give the RX/TX buffer status.
 *
 *   The return value points by canRxTxStatus will be as below:
 *   MSB<-|7|6|5|4|3|2|1|0|<-LSB
 *   bit7: CANINTF.TX2IF      bit3: CANINTF.TX0IF
 *   bit6: TXB2CNTRL.TXREQ    bit2: TXB0CNTRL.TXREQ
 *   bit5: CANINTF.TX1IF      bit1: CANINTFL.RX1IF
 *   bit4: TXB1CNTRL.TXREQ    bit0: CANINTF.RX0IF
 *  \param canRxTxStatus is the address of the status value to be saved.
 */
void mcp2515_read_rxtx_status(uint8_t* canRxTxStatus);

/*! \fn uint8_t mcp2515_rx_status(uint8_t* canRxStatus)
 *  \brief Send the RX Status command over SPI bus.
 *
 *  This requests the CAN controller
 *  to give the RX buffer status. It gives more information than
 *  MCP2515canReadRxTxStatus(). Please see the MCP2515.pdf p.67 for more information.
 *  \param canRxStatus is the address of the status value to be saved.
 */
void mcp2515_rx_status(uint8_t* canRxStatus);

void mcp2515_set_rx_filter_mask(mcp2515_rx_filter_mask_t regAddr, uint32_t canID);

int mcp2515_get_int_flag(void);
void mcp2515_clear_interrupt(void);

void mcp2515_set_op_mode(mcp2515_op_mode_t mode);

void mcp2515_set_rx_op_mode(mcp2515_rx_t channel, mcp2515_rx_op_mode_t mode);

void mcp2515_enable_rx_int(mcp2515_rx_t channel);
void mcp2515_enable_tx_int(mcp2515_tx_t channel);

/*************************************************************************************************/
/*! \fn int mcp2515_set_baudrate(uint32_t ulBaudrate, uint32_t ulMCP2515Clk, uint8_t ubSamplingTime, uint8_t ubTsjw)
 *  \brief Set CANBus baud rate.
 *
 *  \param ulBaudrate is the baudrate that you would like to run on the CAN bus.
 *  \param ulMCP2515Clk is the MCP2515's clock source frequency in Hz
 *  \param ubSamplingTime sampling time, range between 0 to 100. Best result at 75.
 *  \param ubTsjw Synchronization Jump Width for CAN bus sync. correction (1 to 4TQ).
 *************************************************************************************************/
int mcp2515_set_baudrate(uint32_t ulBaudrate, uint32_t ulMCP2515Clk, uint8_t ubSamplingTime, uint8_t ubTsjw);

#endif /*MCP2515_H_*/
