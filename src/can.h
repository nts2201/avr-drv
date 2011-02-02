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

/*! \file can.h
 \brief API for Atmel CAN module.

 \author Frédéric Nadeau
 \author François-Pierre Pépin
 \author Sy Sech Vong

 \todo Translate comments in English.
 */

#ifndef CAN_H_
#define CAN_H_

#include <stdbool.h>
#include <stdint.h>

enum can_int_src_e//Interrupt source
{
	can_int_src_AERR_00 = 0x00,
	can_int_src_FERR_00,
	can_int_src_CERR_00,
	can_int_src_SERR_00,
	can_int_src_BERR_00,
	can_int_src_RXOK_00,
	can_int_src_TXOK_00,
	can_int_src_AERR_01 = 0x10,
	can_int_src_FERR_01,
	can_int_src_CERR_01,
	can_int_src_SERR_01,
	can_int_src_BERR_01,
	can_int_src_RXOK_01,
	can_int_src_TXOK_01,
	can_int_src_AERR_02 = 0x20,
	can_int_src_FERR_02,
	can_int_src_CERR_02,
	can_int_src_SERR_02,
	can_int_src_BERR_02,
	can_int_src_RXOK_02,
	can_int_src_TXOK_02,
	can_int_src_AERR_03 = 0x30,
	can_int_src_FERR_03,
	can_int_src_CERR_03,
	can_int_src_SERR_03,
	can_int_src_BERR_03,
	can_int_src_RXOK_03,
	can_int_src_TXOK_03,
	can_int_src_AERR_04 = 0x40,
	can_int_src_FERR_04,
	can_int_src_CERR_04,
	can_int_src_SERR_04,
	can_int_src_BERR_04,
	can_int_src_RXOK_04,
	can_int_src_TXOK_04,
	can_int_src_AERR_05 = 0x50,
	can_int_src_FERR_05,
	can_int_src_CERR_05,
	can_int_src_SERR_05,
	can_int_src_BERR_05,
	can_int_src_RXOK_05,
	can_int_src_TXOK_05,
	can_int_src_AERR_06 = 0x60,
	can_int_src_FERR_06,
	can_int_src_CERR_06,
	can_int_src_SERR_06,
	can_int_src_BERR_06,
	can_int_src_RXOK_06,
	can_int_src_TXOK_06,
	can_int_src_AERR_07 = 0x70,
	can_int_src_FERR_07,
	can_int_src_CERR_07,
	can_int_src_SERR_07,
	can_int_src_BERR_07,
	can_int_src_RXOK_07,
	can_int_src_TXOK_07,
	can_int_src_AERR_08 = 0x80,
	can_int_src_FERR_08,
	can_int_src_CERR_08,
	can_int_src_SERR_08,
	can_int_src_BERR_08,
	can_int_src_RXOK_08,
	can_int_src_TXOK_08,
	can_int_src_AERR_09 = 0x90,
	can_int_src_FERR_09,
	can_int_src_CERR_09,
	can_int_src_SERR_09,
	can_int_src_BERR_09,
	can_int_src_RXOK_09,
	can_int_src_TXOK_09,
	can_int_src_AERR_10 = 0xA0,
	can_int_src_FERR_10,
	can_int_src_CERR_10,
	can_int_src_SERR_10,
	can_int_src_BERR_10,
	can_int_src_RXOK_10,
	can_int_src_TXOK_10,
	can_int_src_AERR_11 = 0xB0,
	can_int_src_FERR_11,
	can_int_src_CERR_11,
	can_int_src_SERR_11,
	can_int_src_BERR_11,
	can_int_src_RXOK_11,
	can_int_src_TXOK_11,
	can_int_src_AERR_12 = 0xC0,
	can_int_src_FERR_12,
	can_int_src_CERR_12,
	can_int_src_SERR_12,
	can_int_src_BERR_12,
	can_int_src_RXOK_12,
	can_int_src_TXOK_12,
	can_int_src_AERR_13 = 0xD0,
	can_int_src_FERR_13,
	can_int_src_CERR_13,
	can_int_src_SERR_13,
	can_int_src_BERR_13,
	can_int_src_RXOK_13,
	can_int_src_TXOK_13,
	can_int_src_AERR_14 = 0xE0,
	can_int_src_FERR_14,
	can_int_src_CERR_14,
	can_int_src_SERR_14,
	can_int_src_BERR_14,
	can_int_src_RXOK_14,
	can_int_src_TXOK_14,
	can_int_src_BOFFI = 0xF0,
	can_int_src_AERG,
	can_int_src_FERG,
	can_int_src_CERG,
	can_int_src_SERG,
	can_int_src_BXOK,
	can_int_src_UNKNOWN = 0xFF,
};

typedef enum can_int_src_e can_int_src_t;

enum can_mob_conf_e
{
    can_mob_conf_disable,
    can_mob_conf_enable_transmission,
    can_mob_conf_enable_reception,
    can_mob_conf_enable_frame_buffer_reception
};

typedef enum can_mob_conf_e can_mob_conf_t;

/*! \fn void can_set_abort_request(void)
 *  \brief Force all message boxes to be desactivated.
 *
 * All communication currently ongoing will terminate normally.
 *
 * Flags will not be reset.
 */
void can_set_abort_request(void);

/*! \fn void can_clear_abort_request(void)
 *  \brief After an #can_set_abort_request(), this command will reactivate
 *  message boxes.
 */
void can_clear_abort_request(void);

/*! \fn void can_set_overload_frame_request(void)
 *  \brief Force la transmission d'un message de surcharge imm�diatement
 * apr�s la prochaine reception.
 *
 * Le fanions ne se remet pas � z�ro de lui m�me.
 * Pas plus de deux message de surcharge successif ne devrait �tre transmis successivement.
 */
void can_set_overload_frame_request(void);

/*! \fn void can_clear_overload_frame_request(void)
 *  \brief Si une demande d'envois de message de surcharge fut plac� plust�t,
 * cette fonction permet ne plus transmettre de tel message.
 */
void can_clear_overload_frame_request(void);

/*! \fn void can_enable_time_trigger_communication(void)
 *  \brief Active la communication bas� sur le temps et non pas les �v�nements.
 */
void can_enable_time_trigger_communication(void);

/*! \fn void can_disable_time_trigger_communication(void)
 *  \brief D�sctive la communication bas�e sur le temps et
 * active donc la celle bas�e sur les �v�nements.
 */
void can_disable_time_trigger_communication(void);

/*! \fn void can_ttc_sync_on_last_bit_of_eof(void)
 *  \brief Force la synchronisation de TTC lors du dernier bit de EOF.
 * End Of Frame
 *
 * Seulement utilis� lorsqu'en mode TTC
 */
void can_ttc_sync_on_last_bit_of_eof(void);

/*! \fn void can_ttc_sync_on_sof(void)
 *  \brief Force la synchronisation de TTC lors de SOF.
 * Start Of Frame
 *
 * Seulement utilis� lorsqu'en mode TTC
 */
void can_ttc_sync_on_sof(void);

/*! \fn void can_enable_listening_mode(void)
 *  \brief Active le mode d'�coute. Tx est connect� vers l'ext�rieure ainsi que
 * sur Rx.
 */
void can_enable_listening_mode(void);

/*! \fn void can_disable_listening_mode(void)
 *  \brief D�sactive le mode d'�coute. Rx est connect� vers l'ext�rieure.
 */
void can_disable_listening_mode(void);

/*! \fn void can_set_enable_mode(void)
 *  \brief Le Module can sera activ� suite � la lecture de 11bit.
 *
 * Puisque l'effet de ce fanion n'est pas imm�diat, il vaut mieux lire le bit
 * ENFG du registre CANGSTA afin de connaitre le mode pr�sent d'op�ration.
 */
void can_set_enable_mode(void);

/*! \fn void can_set_standby_mode(void)
 *  \brief La communication en cours se terminera comme pr�vue et le cannal CAN
 * sera suspendu(le bit CONMOB de chaque MOb ne changera pas).  Le transmetteur
 * permet donc la reception de donn�s.  Les registres de reception sont disponible
 * pour le CPU.
 *
 * Puisque l'effet de ce fanion n'est pas imm�diat, il vaut mieux lire le bit
 * ENFG du registre CANGSTA afin de connaitre le mode pr�sent d'op�ration.
 */
void can_set_standby_mode(void);

/*! \fn void can_request_reset(void)
 *  \brief Permet au module CAN de faire une remise � z�ro du processeur.
 */
void can_request_reset(void);

/*! \fn _Bool can_is_overload_frame_flag_set(void)
 *  \brief Lit le fanion OVFG
 *  \return false Si aucune trame de surcharge est n'envoy�.
 *          true Si une trame de surcharge est en cour de transmission.
 */
_Bool can_is_overload_frame_flag_set(void);

/*! \fn _Bool can_is_transmitter_busy(void)
 *  \brief Lit le fanion TXBSY
 *  \return false Si le transmetteur est inactif.
 *          true Si le transmetteur est occup�.
 */
_Bool can_is_transmitter_busy(void);

/*! \fn _Bool can_is_receiver_busy(void)
 *  \brief Lit le fanion RXBSY
 *  \return false Si le r�cepteur est inactif.
 *          true Si le r�cepteur est occup�.
 */
_Bool can_is_receiver_busy(void);

/*! \fn _Bool can_is_enabled(void)
 *  \brief Lit le fanion ENFG.
 *  \return false Si le controleur est inactif.
 *          true Si le controleur est actif.
 */
_Bool can_is_enabled(void);

/*! \fn _Bool can_is_bus_off(void)
 *  \brief Lit le fanion BOFF.
 *  \return false Si le bus n'est pas en mode Off.
 *          true Si le bus est en mode Off.
 */
_Bool can_is_bus_off(void);

/*! \fn _Bool can_is_error_passive_set(void)
 *  \brief Lit le fanion ERRP.
 *  \return false Si le bus n'est pas en mode "Error passive".
 *          true Si le bus est en mode "Error passive".
 */
_Bool can_is_error_passive_set(void);

/*! \fn _Bool can_is_general_interrupt_set(void)
 *  \brief Indique si un fanion d'int�ruption est actif.
 *  \return 0 Si aucune int�ruption n'est en attente.
 *          1 Si une int�ruption est en attente.
 */
_Bool can_is_general_interrupt_set(void);

_Bool can_is_bus_off_interrupt_flag_set(void);
void can_clear_bus_off_interrupt_flag(void);
_Bool can_is_overrun_can_timer_interrupt_flag_set(void);
void can_clear_overrun_can_timer_interrupt_flag(void);
_Bool can_is_frame_buffer_reveive_interrupt_flag_set(void);
void can_clear_frame_buffer_reveive_interrupt_flag(void);
_Bool can_is_stuff_error_general_interrupt_flag_set(void);
void can_clear_stuff_error_general_interrupt_flag(void);
_Bool can_is_crc_error_general_interrupt_flag_set(void);
void can_clear_crc_error_general_interrupt_flag(void);
_Bool can_is_form_error_general_interrupt_flag_set(void);
void can_clear_form_error_general_interrupt_flag(void);
_Bool can_is_ack_error_general_interrupt_flag_set(void);
void can_clear_ack_error_general_interrupt_flag(void);

void can_all_interrupt_enable(_Bool enabled);
void can_bus_off_interrupt_enable(_Bool enabled);
void can_receive_interrupt_enable(_Bool enabled);
_Bool can_is_receive_interrupt_enable(void);
void can_transmit_interrupt_enable(_Bool enabled);
_Bool can_is_transmit_interrupt_enable(void);
void can_mob_errors_interrupt_enable(_Bool enabled);
void can_frame_buffer_interrupt_enable(void);
void can_frame_buffer_interrupt_disable(void);
void can_general_errors_interrupt_enable(void);
void can_general_errors_interrupt_disable(void);
void can_can_timer_overrun_interrupt_enable(void);
void can_can_timer_overrun_interrupt_disable(void);
_Bool can_is_mob_enabled(uint8_t ubMOb);
void can_interrupt_mob(uint8_t ubMOb, _Bool enabled);
_Bool can_is_status_interrupt_mob_flag_set(uint8_t ubMOb);
void can_set_timer_control_register(uint8_t ubData);
uint8_t can_get_timer_control_register(void);
uint16_t can_get_timer_register(void);
uint16_t can_get_ttc_timer_register(void);
uint8_t can_get_transmit_error_counter(void);
uint8_t can_get_receive_error_counter(void);
uint8_t can_get_highest_priority_mob_number(void);
void can_set_mob_page(uint8_t ubData);
uint8_t can_get_mob_page(void);
void can_set_auto_increment(_Bool enabled);
_Bool can_get_auto_increment(void);
void can_set_fifo_can_data_index(uint8_t ubData);
uint8_t can_get_fifo_can_data_index(void);
_Bool can_get_data_length_code_warning_flag(void);
_Bool can_get_transmit_ok_flag(void);
void can_clear_transmit_ok_flag(void);
_Bool can_get_receive_ok_flag(void);
void can_clear_receive_ok_flag(void);
_Bool can_get_bit_error_flag(void);
void can_clear_bit_error_flag(void);
_Bool can_get_stuff_error_flag(void);
void can_clear_stuff_error_flag(void);
_Bool can_get_crc_error_flag(void);
void can_clear_crc_error_flag(void);
_Bool can_get_form_error_flag(void);
void can_clear_form_error_flag(void);
_Bool can_get_acknowledgement_error_flag(void);
void can_clear_acknowledgement_error_flag(void);
void can_set_configuration_of_mob(can_mob_conf_t conf);
void can_set_reply_ready_flag(_Bool isReady);
void can_set_identifier_extention_2a(void);
void can_set_identifier_extention_2b(void);
_Bool can_is_identifier_extention_2b(void);
void can_set_data_length_code(uint8_t ubData);
uint8_t can_get_data_length_code(void);
void can_set_identifier_tag_v2a(uint16_t uwData);
uint16_t can_get_identifier_tag_v2a(void);
void can_set_identifier_tag_v2b(uint32_t ulData);
uint32_t can_get_identifier_tag_v2b(void);
void can_set_remote_transmission_request_tag(_Bool enabled);
_Bool can_is_remote_transmission_request_tag_set(void);
void can_set_reserved_bit_0_tag(_Bool isSet);
_Bool can_is_reserved_bit_0_tag_set(void);
void can_set_reserved_bit_1_tag(_Bool isSet);
_Bool can_is_reserved_bit_1_tag_set(void);
void can_set_identifier_mask_v2a(uint16_t uwData);
void can_set_identifier_mask_v2b(uint32_t ulData);
void can_set_remote_transmission_request_mask_flag(_Bool isSet);
void can_set_identifier_extension_mask_flag(_Bool isSet);
uint16_t can_get_time_stamp(void);
uint8_t can_get_data_mob(void);
void can_set_data_mob(uint8_t ubData);
void can_clear_mob(void);
void can_clear_all_mob(void);
uint8_t can_get_free_mob_number(uint8_t *ubFreeMOb);

/***************************************************************************************
 * Vitesse de CAN Bus
 ***************************************************************************************/
int can_set_baud_rate(uint32_t ulBaudrate, uint32_t ulClkFreq,
        uint8_t ubSamplingRate, uint8_t ubTsjw);

void can_set_baud_rate_precalc(uint8_t canbt1, uint8_t canbt2, uint8_t canbt3);

/*! \fn can_int_src_t can_get_int_src(void)
 *  \brief Return interrupt source.
 *  \return Source of interrupt, see #can_int_src_t.
 *
 *  \warning This function cannot be used in polling mode. Should be called in a ISR.
 */
can_int_src_t can_get_int_src(void);

#endif /*CAN_H_*/
