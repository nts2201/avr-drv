/* Copyright (c) 2008-2010 Frédéric Nadeau
   Copyright (c) 2008 François-Pierre Pépin
   Copyright (c) 2008 Sy Sech Vong
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

/*! \file can.c
 \brief API for Atmel CAN module.

 \author Frédéric Nadeau
 \author François-Pierre Pépin
 \author Sy Sech Vong

 \todo Translate comments in English.
 */
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>

#include "avr-drv-errno.h"
#include "can.h"

#define CAN_MIN_TQ                          8
#define CAN_MAX_TQ                          25

//TODO Removed ASSERTs

/************************************************/
/*     CAN General Control Register CANGCON     */
/************************************************/

void can_set_abort_request(void)
{
    CANGCON |= (1 << ABRQ);
}

void can_clear_abort_request(void)
{
    CANGCON &= ~(1 << ABRQ);
}

void can_set_overload_frame_request(void)
{
    CANGCON |= (1 << OVRQ);
}

void can_clear_overload_frame_request(void)
{
    CANGCON &= ~(1 << OVRQ);
}

void can_enable_time_trigger_communication(void)
{
    CANGCON |= (1 << TTC);
}

void can_disable_time_trigger_communication(void)
{
    CANGCON &= ~(1 << TTC);
}

void can_ttc_sync_on_last_bit_of_eof(void)
{
    CANGCON |= (1 << SYNTTC);
}

void can_ttc_sync_on_sof(void)
{
    CANGCON &= ~(1 << SYNTTC);
}

void can_enable_listening_mode(void)
{
    CANGCON |= (1 << LISTEN);
}

void can_disable_listening_mode(void)
{
    CANGCON &= ~(1 << LISTEN);
}

void can_set_enable_mode(void)
{
    CANGCON |= (1 << ENASTB);
}

void can_set_standby_mode(void)
{
    CANGCON &= ~(1 << ENASTB);
}

void can_request_reset(void)
{
    CANGCON |= (1 << SWRES);
}

/************************************************/
/*     CAN General Status Register CANGSTA      */
/************************************************/

_Bool can_is_overload_frame_flag_set(void)
{
    return bit_is_set(CANGSTA,OVFG) == 0 ? false:true;
}

_Bool can_is_transmitter_busy(void)
{
    return bit_is_set(CANGSTA,TXBSY) == 0 ? false:true;
}

_Bool can_is_receiver_busy(void)
{
    return bit_is_set(CANGSTA,RXBSY) == 0 ? false:true;
}

_Bool can_is_enabled(void)
{
    return bit_is_set(CANGSTA,ENFG) == 0 ? false:true;
}

_Bool can_is_bus_off(void)
{
    return bit_is_set(CANGSTA,BOFF) == 0 ? false:true;
}

_Bool can_is_error_passive_set(void)
{
    return bit_is_set(CANGSTA,ERRP) == 0 ? false:true;
}

/************************************************/
/*    CAN General Interrupt Register CANGIT     */
/************************************************/

_Bool can_is_general_interrupt_set(void)
{
    return bit_is_set(CANGIT,CANIT) == 0 ? false:true;
}

_Bool can_is_bus_off_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,BOFFIT) == 0 ? false:true;
}

void can_clear_bus_off_interrupt_flag(void)
{
    CANGIT |= (1 << BOFFIT);
}

_Bool can_is_overrun_can_timer_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,OVRTIM) == 0 ? false:true;
}

void can_clear_overrun_can_timer_interrupt_flag(void)
{
    CANGIT |= (1 << OVRTIM);
}

_Bool can_is_frame_buffer_reveive_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,BXOK) == 0 ? false:true;
}

void can_clear_frame_buffer_reveive_interrupt_flag(void)
{
    CANGIT |= (1 << BXOK);
}

_Bool can_is_stuff_error_general_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,SERG) == 0 ? false:true;
}

void can_clear_stuff_error_general_interrupt_flag(void)
{
    CANGIT |= (1 << SERG);
}

_Bool can_is_crc_error_general_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,CERG) == 0 ? false:true;
}

void can_clear_crc_error_general_interrupt_flag(void)
{
    CANGIT |= (1 << CERG);
}

_Bool can_is_form_error_general_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,FERG) == 0 ? false:true;
}

void can_clear_form_error_general_interrupt_flag(void)
{
    CANGIT |= (1 << FERG);
}

_Bool can_is_ack_error_general_interrupt_flag_set(void)
{
    return bit_is_set(CANGIT,AERG) == 0 ? false:true;
}

void can_clear_ack_error_general_interrupt_flag(void)
{
    CANGIT |= (1 << AERG);
}

/************************************************/
/* CAN General Interrupt Enable Register CANGIE */
/************************************************/

void can_all_interrupt_enable(_Bool enabled)
{
    if(enabled == true)
    {
        CANGIE |= _BV(ENIT);
    }
    else
    {
        CANGIE &= ~_BV(ENIT);
    }
}

void can_bus_off_interrupt_enable(_Bool enabled)
{
    if(enabled == true)
    {
        CANGIE |= _BV(ENBOFF);
    }
    else
    {
        CANGIE &= ~_BV(ENBOFF);
    }
}

void can_receive_interrupt_enable(_Bool enabled)
{
    if(enabled == true)
    {
        CANGIE |= _BV(ENRX);
    }
    else
    {
        CANGIE &= ~_BV(ENRX);
    }
}

_Bool can_is_receive_interrupt_enable(void)
{
    return bit_is_set(CANGIE,ENRX) == 0 ? false:true;
}

void can_transmit_interrupt_enable(_Bool enabled)
{
    if(enabled == true)
    {
        CANGIE |= _BV(ENTX);
    }
    else
    {
        CANGIE &= ~_BV(ENTX);
    }
}

_Bool can_is_transmit_interrupt_enable(void)
{
    return bit_is_set(CANGIE,ENTX) == 0 ? false:true;
}

void can_mob_errors_interrupt_enable(_Bool enabled)
{
    if(enabled == true)
    {
        CANGIE |= _BV(ENERR);
    }
    else
    {
        CANGIE &= ~_BV(ENERR);
    }
}

void can_frame_buffer_interrupt_enable(void)
{
    CANGIE |= (1 << ENBX);
}

void can_frame_buffer_interrupt_disable(void)
{
    CANGIE &= ~(1 << ENBX);
}

void can_general_errors_interrupt_enable(void)
{
    CANGIE |= (1 << ENERG);
}

void can_general_errors_interrupt_disable(void)
{
    CANGIE &= ~(1 << ENERG);
}

void can_can_timer_overrun_interrupt_enable(void)
{
    CANGIE |= (1 << ENOVRT);
}

void can_can_timer_overrun_interrupt_disable(void)
{
    CANGIE &= ~(1 << ENOVRT);
}

/************************************************/
/*        CAN Enable Mob Register CANENx        */
/************************************************/

_Bool can_is_mob_enabled(uint8_t ubMOb)
{
    _Bool bRetVal = false;

    if (ubMOb < 8)
    {
        bRetVal = (CANEN2 & (1 << ubMOb)) >> (ubMOb);
    }
    else if(ubMOb < 15)
    {
        ubMOb = ubMOb - 8;
        bRetVal = (CANEN1 & (1 << ubMOb)) >> (ubMOb);
    }
    return bRetVal;
}

/************************************************/
/*   CAN Enable Interrupt Mob Register CANIEx   */
/************************************************/

void can_interrupt_mob(uint8_t ubMOb, _Bool enabled)
{
    if (ubMOb < 8)
    {
        if (true == enabled)
        {
            CANIE2 |= (1 << ubMOb);
        }
        else
        {
            CANIE2 &= ~(1 << ubMOb);
        }

    }
    else if (ubMOb < 15)
    {
        ubMOb = ubMOb - 8;
        if(true == enabled)
        {
            CANIE1 |= (1 << ubMOb);
        }
        else
        {
            CANIE1 &= ~(1 << ubMOb);
        }
    }
}

/************************************************/
/*   CAN Status Interrupt MOb Register CANSITx  */
/************************************************/

/* It returns 1 if has interrupt, 0 else. */
_Bool can_is_status_interrupt_mob_flag_set(uint8_t ubMOb)
{
    _Bool bRetVal = false;

    if (ubMOb < 8)
    {
        bRetVal = (CANSIT2 & (1 << ubMOb)) == 0 ? false:true;
    }
    else if (ubMOb < 15)
    {
        ubMOb = ubMOb - 8;
        bRetVal = (CANSIT1 & (1 << ubMOb)) == 0 ? false:true;
    }
    return bRetVal;
}

/************************************************/
/*     CAN Timer Control Register CANTCON       */
/************************************************/

void can_set_timer_control_register(uint8_t ubData)
{
    CANTCON = ubData;
}

uint8_t can_get_timer_control_register(void)
{
    return CANTCON;
}

/************************************************/
/*          CAN Timer Register CANTIMx          */
/************************************************/

uint16_t can_get_timer_register(void)
{
    uint16_t uwRetVal = CANTIMH;//Read High byte
    uwRetVal = uwRetVal << 8;//Allign high byte
    uwRetVal += CANTIML;//Add low byte
    return uwRetVal;
}

/************************************************/
/*      CAN TTC Timer Register CANTTCx          */
/************************************************/

uint16_t can_get_ttc_timer_register(void)
{
    uint16_t uwRetVal = CANTTCH;//Read High byte
    uwRetVal = uwRetVal << 8;//Allign high byte
    uwRetVal += CANTTCL;//Add low byte
    return uwRetVal;
}

/************************************************/
/*  CAN Transmit Error Counter Register CANTEC  */
/************************************************/

uint8_t can_get_transmit_error_counter(void)
{
    return CANTEC;
}

/************************************************/
/*  CAN Receive Error Counter Register CANREC   */
/************************************************/

uint8_t can_get_receive_error_counter(void)
{
    return CANTEC;
}

/************************************************/
/*  CAN Highest Priority MOb Register CANHPMOB  */
/************************************************/

uint8_t can_get_highest_priority_mob_number(void)
{
    uint8_t ubRetVal = CANHPMOB;
    ubRetVal &= ((1 << HPMOB3) | (1 << HPMOB2) | (1 << HPMOB1) | (1 << HPMOB0));
    ubRetVal = ubRetVal >> HPMOB0;
    return ubRetVal;
}

/************************************************/
/*        CAN Page MOb Register CANPAGE         */
/************************************************/

void can_set_mob_page(uint8_t ubData)
{
    assert(ubData < 15);
    CANPAGE &= _BV(AINC);//Remove current MOb and reset the index
    CANPAGE |= (ubData << MOBNB0);
}

uint8_t can_get_mob_page(void)
{
    uint8_t ubRetVal = CANPAGE;
    ubRetVal &= ((1 << MOBNB3) | (1 << MOBNB2) | (1 << MOBNB1) | (1 << MOBNB0));
    ubRetVal = ubRetVal >> MOBNB0;
    return ubRetVal;
}

void can_set_auto_increment(_Bool enabled)
{
    if(true == enabled)
    {
        CANPAGE |= _BV(AINC);
    }
    else
    {
        CANPAGE &= ~_BV(AINC);//Remove current info
    }
}

_Bool can_get_auto_increment(void)
{
    return bit_is_set(CANPAGE,AINC) == 0 ? false:true;
}

void can_set_fifo_can_data_index(uint8_t ubData)
{
    assert(ubData < 15);
    CANPAGE &= ~((1 << INDX2) | (1 << INDX1) | (1 << INDX0));//Remove current info
    CANPAGE |= (ubData << INDX0);
}

uint8_t can_get_fifo_can_data_index(void)
{
    uint8_t ubRetVal = CANPAGE;
    ubRetVal &= ((1 << INDX2) | (1 << INDX1) | (1 << INDX0));
    ubRetVal = ubRetVal >> INDX0;
    return ubRetVal;
}

/************************************************/
/*       CAN MOb Status Register CANSTMOB       */
/************************************************/

_Bool can_get_data_length_code_warning_flag(void)
{
    return bit_is_set(CANSTMOB,DLCW) == 0 ? false:true;
}

_Bool can_get_transmit_ok_flag(void)
{
    return bit_is_set(CANSTMOB,TXOK) == 0 ? false:true;
}

void can_clear_transmit_ok_flag(void)
{
    //CANSTMOB |= (1<<TXOK);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << TXOK);
}

_Bool can_get_receive_ok_flag(void)
{
    return bit_is_set(CANSTMOB,RXOK) == 0 ? false:true;
}

void can_clear_receive_ok_flag(void)
{
    //CANSTMOB |= (1<<RXOK);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << RXOK);
}

_Bool can_get_bit_error_flag(void)
{
    return bit_is_set(CANSTMOB,BERR) == 0 ? false:true;
}

void can_clear_bit_error_flag(void)
{
    //CANSTMOB |= (1 << BERR);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << BERR);
}

_Bool can_get_stuff_error_flag(void)
{
    return bit_is_set(CANSTMOB,SERR) == 0 ? false:true;
}

void can_clear_stuff_error_flag(void)
{
    //CANSTMOB |= (1 << SERR);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << SERR);
}

_Bool can_get_crc_error_flag(void)
{
    return bit_is_set(CANSTMOB,CERR) == 0 ? false:true;
}

void can_clear_crc_error_flag(void)
{
    //CANSTMOB |= (1 << CERR);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << CERR);
}

_Bool can_get_form_error_flag(void)
{
    return bit_is_set(CANSTMOB,FERR) == 0 ? false:true;
}

void can_clear_form_error_flag(void)
{
    //CANSTMOB |= (1 << FERR);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << FERR);
}

_Bool can_get_acknowledgement_error_flag(void)
{
    return bit_is_set(CANSTMOB,AERR) == 0 ? false:true;
}

void can_clear_acknowledgement_error_flag(void)
{
    //CANSTMOB |= (1 << AERR);
    //Must be read-modify-write rather than the usual write 1 to clear.
    CANSTMOB &= ~(1 << AERR);
}

/************************************************/
/*   CAN MOb Control and DLC register CANCDMOB  */
/************************************************/

void can_set_configuration_of_mob(can_mob_conf_t conf)
{
    CANCDMOB &= ~((1 << CONMOB1) | (1 << CONMOB0));//Remove current info
    CANCDMOB |= (conf << CONMOB0);
}

void can_set_reply_ready_flag(_Bool isReady)
{
    if(true == isReady)
    {
        CANCDMOB |= (1 << RPLV);
    }
    else
    {
        CANCDMOB &= ~(1 << RPLV);
    }
}

void can_set_identifier_extention_2a(void)
{
    CANCDMOB &= ~(1 << IDE);
}

void can_set_identifier_extention_2b(void)
{
    CANCDMOB |= (1 << IDE);
}

_Bool can_is_identifier_extention_2b(void)
{
    return bit_is_set(CANCDMOB,IDE) == 0 ? false:true;
}

void can_set_data_length_code(uint8_t ubData)
{
    assert(ubData < 9);
    CANCDMOB &= ~((1 << DLC3) | (1 << DLC2) | (1 << DLC1) | (1 << DLC0));//Remove current info
    //CANCDMOB |= (ubData<<DLC0);
    CANCDMOB |= ubData;
}

uint8_t can_get_data_length_code(void)
{
    uint8_t ubRetVal = CANCDMOB;
    ubRetVal &= (1 << DLC3) | (1 << DLC2) | (1 << DLC1) | (1 << DLC0);
    ubRetVal = ubRetVal >> DLC0;
    return ubRetVal;
}

/************************************************/
/*      CAN Identifier Tag Register CANIDTx     */
/************************************************/

void can_set_identifier_tag_v2a(uint16_t uwData)
{
    CANIDT1 = (uint8_t) (uwData >> 3);
    CANIDT2 = (uint8_t) (uwData << 5);
}

uint16_t can_get_identifier_tag_v2a(void)
{
    uint16_t uwRetVal = CANIDT1;//Read High byte
    uwRetVal = uwRetVal << 3;//Allign high byte
    uwRetVal += (CANIDT2 >> 5);//Add low byte
    return uwRetVal;
}

void can_set_identifier_tag_v2b(uint32_t ulData)
{
    CANIDT1 = (uint8_t) (ulData >> 21);
    CANIDT2 = (uint8_t) (ulData >> 13);
    CANIDT3 = (uint8_t) (ulData >> 5);
    CANIDT4 &= ~((1 << IDT4) | (1 << IDT3) | (1 << IDT2) | (1 << IDT1) | (1
            << IDT0));
    CANIDT4 |= (uint8_t) (ulData << 3);
}

uint32_t can_get_identifier_tag_v2b(void)
{
    uint32_t ulRetVal = ((uint32_t) CANIDT1 << 21);
    ulRetVal |= (((uint32_t) CANIDT2) << 13);
    ulRetVal |= (((uint32_t) CANIDT3) << 5);
    ulRetVal |= (uint32_t) (CANIDT4 >> 3);
    return ulRetVal;
}

void can_set_remote_transmission_request_tag(_Bool enabled)
{
    if(true == enabled)
    {
        CANIDT4 |= (1 << RTRTAG);
    }
    else
    {
        CANIDT4 &= ~(1 << RTRTAG);
    }
}

_Bool can_is_remote_transmission_request_tag_set(void)
{
    return bit_is_set(CANIDT4,RTRTAG) == 0 ? false:true;
}

void can_set_reserved_bit_0_tag(_Bool isSet)
{
    if(true == isSet)
    {
        CANIDT4 |= (1 << RB0TAG);
    }
    else
    {
        CANIDT4 &= ~(1 << RB0TAG);
    }
}

_Bool can_is_reserved_bit_0_tag_set(void)
{
    return bit_is_set(CANIDT4,RB0TAG) == 0 ? false:true;
}

void can_set_reserved_bit_1_tag(_Bool isSet)
{
    if(true == isSet)
    {
        CANIDT4 |= (1 << RB1TAG);
    }
    else
    {
        CANIDT4 &= ~(1 << RB1TAG);
    }
}

_Bool can_is_reserved_bit_1_tag_set(void)
{
    return bit_is_set(CANIDT4,RB1TAG) == 0 ? false:true;
}

/************************************************/
/*  CAN Identifier Mask Tag Register CANIDMx    */
/************************************************/

void can_set_identifier_mask_v2a(uint16_t uwData)
{
    CANIDM1 = (uint8_t) (uwData >> 3);
    CANIDM2 = (uint8_t) (uwData << 5);
}

void can_set_identifier_mask_v2b(uint32_t ulData)
{
    CANIDM1 = (uint8_t) (ulData >> 21);
    CANIDM2 = (uint8_t) (ulData >> 13);
    CANIDM3 = (uint8_t) (ulData >> 5);
    CANIDM4 &= ~((1 << IDMSK4) | (1 << IDMSK3) | (1 << IDMSK2) | (1 << IDMSK1)
            | (1 << IDMSK0));
    CANIDM4 |= (uint8_t) (ulData << 3);
}

void can_set_remote_transmission_request_mask_flag(_Bool isSet)
{
    if(true == isSet)
    {
        CANIDM4 |= (1 << RTRMSK);
    }
    else
    {
        CANIDM4 &= ~(1 << RTRMSK);
    }
}

void can_set_identifier_extension_mask_flag(_Bool isSet)
{
    if(true == isSet)
    {
        CANIDM4 |= (1 << IDEMSK);
    }
    else
    {
        CANIDM4 &= ~(1 << IDEMSK);
    }
}

/************************************************/
/*       CAN Time Stamp Registers CANSTMx       */
/************************************************/

uint16_t can_get_time_stamp(void)
{
    return CANSTM;
}

/***************************************************************************************
 * Donn�es de Message Object (Mob)
 ***************************************************************************************/

uint8_t can_get_data_mob(void)
{
    return CANMSG;
}

void can_set_data_mob(uint8_t ubData)
{
    CANMSG = ubData;
}

void can_clear_mob(void)
{
    CANSTMOB = 0;
    CANCDMOB = 0;
    CANIDT = 0;
    CANIDM = 0;
    CANSTM = 0;
}

void can_clear_all_mob(void)
{
    uint8_t i;
    for (i = 0; i < 15; i++)
    {
        can_set_mob_page(i);
        can_clear_mob();
    }
}

uint8_t can_get_free_mob_number(uint8_t *ubFreeMOb)
{
    uint8_t ubCurrentMOb;
    uint8_t ubRetVal = false;

    ubCurrentMOb = CANPAGE;//Save current value
    for (*ubFreeMOb = 0; *ubFreeMOb < 15; (*ubFreeMOb)++)
    {
        can_set_mob_page(*ubFreeMOb);
        if ((CANCDMOB & 0xC0) == 0x00) //! Disable configuration
        {
            ubRetVal = true;
            break;
        }
    }
    CANPAGE = ubCurrentMOb;//Restore page
    return ubRetVal;
}

int can_set_baud_rate(uint32_t ulBaudrate, uint32_t ulClkFreq,
        uint8_t ubSamplingRate, uint8_t ubTsjw)
{
    uint8_t ubDivider;
    uint8_t ubTbit;
    uint8_t ubTprs;
    uint8_t ubTphs1;
    uint8_t ubTphs2;
    uint8_t ubBRP = 1;

    ubDivider = ulClkFreq / ulBaudrate; /* Trouve le diviseur total de la fréquence du Can */

    ubTbit = ubDivider;
    while ((ubTbit >= CAN_MAX_TQ) | (ubTbit <= CAN_MIN_TQ))
    {
        ubTbit = (ubTbit >> 1);
        ubBRP *= 2;
    }

    ubTphs2 = (ubTbit * (100 - ubSamplingRate) / 100);
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

    if (1 == ubBRP)
    {
        ubTphs1 = ubTphs2 + 1;
        ubTphs2 -= 1;
    }

    if (ubDivider == (ubBRP) * (ubTprs + ubTphs1 + ubTphs2 + 1))
    {
    	CANBT1 = ((ubBRP-1) << BRP0);
		CANBT2 = ((ubTprs-1) << PRS0) | ((ubTsjw-1) << SJW0);
		CANBT3 = ((ubTphs2-1) << PHS20) | ((ubTphs1-1) << PHS10) | (1 << SMP);
        return 0;
    }
    else
    {
        avr_drv_errno = EBAUDRATE;
        return -1;
    }
}

void can_set_baud_rate_precalc(uint8_t canbt1, uint8_t canbt2, uint8_t canbt3)
{
    CANBT1 = canbt1;
    CANBT2 = canbt2;
    CANBT3 = canbt3;
}

can_int_src_t can_get_int_src(void)
{
    if (bit_is_set(CANGIE, ENIT))//Interrupt are enabled
    {
        uint16_t canie;
        //uint16_t cansit;
        uint8_t i;

        canie = ((uint16_t) CANIE1) << 8;
        canie |= (uint16_t) CANIE2;

        //cansit = CANSIT;

        canie &= CANSIT;

        if (canie != 0)
        {
            //Seek interrupt source
            for (i = 0; i < 15; i++)
            {
                if (canie & (1 << i))
                    break;
            }

            can_set_mob_page(i); // Select MOb

            if (bit_is_set(CANGIE, ENRX) && bit_is_set(CANSTMOB, RXOK))
            {
                return 0x10 * i + can_int_src_RXOK_00;
            }

            if (bit_is_set(CANGIE, ENTX) && bit_is_set(CANSTMOB, TXOK))
            {
                return 0x10 * i + can_int_src_TXOK_00;
            }

            if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, AERR))
            {
                return 0x10 * i + can_int_src_AERR_00;
            }

            if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, FERR))
            {
                return 0x10 * i + can_int_src_FERR_00;
            }

            if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, CERR))
            {
                return 0x10 * i + can_int_src_CERR_00;
            }

            if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, SERR))
            {
                return 0x10 * i + can_int_src_SERR_00;
            }

            if (bit_is_set(CANGIE, ENERR) && bit_is_set(CANSTMOB, BERR))
            {
                return 0x10 * i + can_int_src_BERR_00;
            }
        }

        //Bus off interrupt enabled
        if (bit_is_set(CANGIE, ENBOFF) && bit_is_set(CANGIT, BOFFIT))
        {
            return can_int_src_BOFFI;
        }

        //Stuff error General
        if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, SERG))
        {
            return can_int_src_SERG;
        }

        //CAN error General
        if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, CERG))
        {
            return can_int_src_CERG;
        }

        //Frame error General
        if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, FERG))
        {
            return can_int_src_FERG;
        }

        //Ack error General
        if (bit_is_set(CANGIE, ENERG) && bit_is_set(CANGIT, AERG))
        {
            return can_int_src_AERG;
        }

        //Frame Buffer Receive Interrupt
        if (bit_is_set(CANGIE, ENBX) && bit_is_set(CANGIT, BXOK))
        {
            return can_int_src_BXOK;
        }

    }

    return can_int_src_UNKNOWN;
}
