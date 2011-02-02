/* Copyright (c) 2008-2010 Frédéric Nadeau
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

/*! \file adc.h
 \brief Function definition for ADC module.

 \todo Add Bipolar input selection
 \todo Add Gain Select
 \todo Add High Speed selection ADHSM
 \todo ADNCDIS: ADC Noise Canceller Disable
 \todo ADSSEN: ADC Single Shot Enable on PSC’s synchronization signals
 \todo ADASCR: Analog to Digital Conversion on Amplified Channel Start Conversion Request Bit

 \author Frédéric Nadeau
 */
#ifndef ADC_H_
#define ADC_H_

#include <stdbool.h>
#include <stdint.h>
#include "adcDef.h"

#if !defined(__AVR_ATmega103__) \
|| defined(__DOXYGEN__)
/*! \fn void adc_select_vref(adc_voltage_ref_t ref)
 *  \brief Select voltage reference to be used by the ADC.
 *
 *  \note Not all device share same voltages references.
 *
 *  \note This function does nothing for ATmega103.
 *
 *  \param ref Voltage reference to be used.
 */
void adc_select_vref(adc_voltage_ref_t ref);
#else
#   define adc_select_vref(x)
#endif

/*! \fn void adc_select_input(adc_input_channel_t channel)
 *  \brief Select input channel of the ADC.
 *
 *  \note Not all device share same inputs channels.
 *
 *  \param channel Selected channel.
 */
void adc_select_input(adc_input_channel_t channel);

#if !defined(__AVR_ATtiny4__) \
&& !defined(__AVR_ATtiny5__) \
&& !defined(__AVR_ATtiny9__) \
&& !defined(__AVR_ATtiny10__) \
&& !defined(__AVR_ATmega103__) \
|| defined(__DOXYGEN__)
/*! \fn void adc_left_adjust(_Bool adjust)
 *  \brief Select how conversion result will be stored in register.
 *
 *  For 8-bits result, use:
 *  \li \c adc_left_adjust(true)
 *  \li #adc_read_high()
 *
 *	For 10-bits result, use:
 *  \li \c adc_left_adjust(false)
 *  \li #adc_read()
 *
 *  \param adjust Alignment of the result register.
 *
 *  \note Devices with 8-bits ADC do not support this function.
 */
void adc_left_adjust(_Bool adjust);
#endif

/*! \fn void adc_prescaler_selection(adc_prescaler_t prescaler)
 *  \brief Select ADC core clock prescaler.
 *
 *  \param prescaler Prescaler clock. See #adc_prescaler_t for option list.
 */
void adc_prescaler_selection(adc_prescaler_t prescaler);

/*! \fn void adc_enable(_Bool status)
 *  \brief Enable or disable ADC core.
 *
 *  \param status Status of the ADC core.
 */
void adc_enable(_Bool status);

/*! \fn void adc_interrupt_enable (_Bool intEn)
 *  \brief Enable or disable ADC core interrupt.
 *
 *  \warning Interrupt service routine are not provided by AVR-drv.
 *  You have to write your own.
 *
 *  \param intEn New interrupt status.
 */
void adc_interrupt_enable (_Bool intEn);

/*! \fn void adc_start_conversion(void)
 *  \brief Start a conversion.
 */
void adc_start_conversion(void);

#if !defined(__AVR_ATtiny4__) \
&& !defined(__AVR_ATtiny5__) \
&& !defined(__AVR_ATtiny9__) \
&& !defined(__AVR_ATtiny10__) \
|| defined(__DOXYGEN__)
/*! \fn uint16_t adc_read(void)
 *  \brief Read conversion result register.
 *
 *  \return Value in the conversion result register.
 *
 *  \note Devices with 8-bits ADC do not support this function.
 *  Use #adc_read_low instead.
 */
uint16_t adc_read(void);

/*! \fn uint8_t adc_read_high(void)
 *  \brief Read high byte of the conversion result register.
 *
 *  \return Value in the high byte of the conversion result register.
 *
 *  \note Devices with 8-bits ADC do not support this function.
 *  Use #adc_read_low instead.
 */
uint8_t adc_read_high(void);
#endif

/*! \fn uint8_t adc_read_low(void)
 *  \brief Read low byte of the conversion result register.
 *
 *  \return Value in the low byte of the conversion result register.
 */
uint8_t adc_read_low(void);

#if !defined(__AVR_ATmega8__) \
&& !defined(__AVR_ATmega103__) \
&& !defined(__AVR_ATmega128__) \
&& !defined(__AVR_ATmega163__) \
&& !defined(__AVR_ATmega323__) \
&& !defined(__AVR_ATtiny15__) \
&& !defined(__AVR_ATtiny26__) \
|| defined(__DOXYGEN__)
/*! \fn void adc_set_trigger_source (adc_trigger_source_t trigger)
 *  \brief Set the auto trigger source.
 *
 *  \note Not all device have the trigger source.
 *  For devices like \c ATmega8 and \c ATmega128, this function does nothing.
 *  The function has been left for these device only for API compatibility.
 *  It should be used with #adc_trigger_source_free_running.
 *
 *  \param trigger Trigger source. See #adc_trigger_source_t for option list.
 */
void adc_set_trigger_source (adc_trigger_source_t trigger);
#else
#   define adc_set_trigger_source(x)
#endif

#if !defined(__AVR_ATmega103__) \
|| defined(__DOXYGEN__)
/*! \fn void adc_trigger_enable(_Bool trigEn)
 *  \brief Enable or disable the auto trigger.
 *
 *  \note For devices like \c ATmega8 and \c ATmega128,
 *  this function enable the free running mode.
 *
 *  \note For devices like \c ATmega103,
 *  this function does nothing.
 *
 *  \param trigEn Trigger enable/disable.
 */
void adc_trigger_enable(_Bool trigEn);
#else
#   define adc_trigger_enable(x)
#endif

#if defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM2b__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90PWM3b__) \
|| defined(__AVR_AT90PWM81__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_ATmega1284p__) \
|| defined(__AVR_ATmega128rfa1__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165p__) \
|| defined(__AVR_ATmega168p__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169pa__) \
|| defined(__AVR_ATmega169p__) \
|| defined(__AVR_ATmega16hva2__) \
|| defined(__AVR_ATmega16hvb__) \
|| defined(__AVR_ATmega16m1__) \
|| defined(__AVR_ATmega16u4__) \
|| defined(__AVR_ATmega324pa__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega328p__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega32c1__) \
|| defined(__AVR_ATmega32hvb__) \
|| defined(__AVR_ATmega32m1__) \
|| defined(__AVR_ATmega32u4__) \
|| defined(__AVR_ATmega32u6__) \
|| defined(__AVR_ATmega406__) \
|| defined(__AVR_ATmega48p__) \
|| defined(__AVR_ATmega644pa__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649p__) \
|| defined(__AVR_ATmega64c1__) \
|| defined(__AVR_ATmega64hve__) \
|| defined(__AVR_ATmega64m1__) \
|| defined(__AVR_ATmega88pa__) \
|| defined(__AVR_ATmega88p__) \
|| defined(__AVR_ATtiny10__) \
|| defined(__AVR_ATtiny13a__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny167__) \
|| defined(__AVR_ATtiny20__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24a__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny261a__) \
|| defined(__AVR_ATtiny40__) \
|| defined(__AVR_ATtiny43u__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44a__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461a__) \
|| defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny4__) \
|| defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861a__) \
|| defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny88__) \
|| defined(__AVR_ATtiny9__)  \
|| defined(__DOXYGEN__)

/*! \fn void adc_digital_input_disable(adc_digital_channel_t chanList)
 *  \brief Disable digital input for selected channel.
 *
 *  \note Devices that do not support this feature will not have
 *  access to this function. It should be considered during device migration.
 *
 *  \param chanList List of channel that will have digital input disabled.
 */
void adc_digital_input_disable(adc_digital_channel_t chanList);

/*! \fn void adc_digital_input_enable(adc_digital_channel_t chanList)
 *  \brief Enable digital input for selected channel.
 *
 *  \note Devices that do not support this feature will not have
 *  access to this function. It should be considered during device migration.
 *
 *  \param chanList List of channel that will have digital input enabled.
 */
void adc_digital_input_enable(adc_digital_channel_t chanList);
#endif

#endif /*ADC_H_*/
