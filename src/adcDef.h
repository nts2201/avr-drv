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

/*! \file adcDef.h
 \brief This file declares \c typedef used by the ADC module.

 Not all part of the following \c enum are available to all devices.

 \author Frédéric Nadeau
 */
#ifndef ADCDEF_H_
#define ADCDEF_H_

/*! \ingroup drv_adc
 * List of available prescaler.
 */
enum adc_prescaler_e
{
    adc_prescaler_2 = 0, /*!< Oscillator clock divided by 2. */
    adc_prescaler_2_, /*!< Oscillator clock divided by 2. Alternate setting. */
    adc_prescaler_4, /*!< Oscillator clock divided by 4. */
    adc_prescaler_8, /*!< Oscillator clock divided by 8. */
    adc_prescaler_16, /*!< Oscillator clock divided by 16. */
    adc_prescaler_32,/*!< Oscillator clock divided by 32. */
    adc_prescaler_64,/*!< Oscillator clock divided by 64. */
    adc_prescaler_128,/*!< Oscillator clock divided by 128. */
};

/*! \ingroup drv_adc
 * List of available prescaler typedef.
 */
typedef enum adc_prescaler_e adc_prescaler_t;

#if defined(__DOXYGEN__)
/*! \ingroup drv_adc
 * List of available voltage reference.
 */
enum adc_voltage_ref_e
{
    adc_voltage_ref_aref, /*!< ADC use Aref PIN as voltage reference. */
    adc_voltage_ref_avcc_wcap, /*!< ADC use VCC as voltage reference with capacitor on AREF pin. */
    adc_voltage_ref_avcc_wocap, /*!< ADC use VCC as voltage reference without capacitor on AREF pin. */
    adc_voltage_ref_internal_1_1_wcap, /*!< ADC use internal 1.1 Voltage reference. */
    adc_voltage_ref_internal_2_56_wcap, /*!< ADC use internal 2.56 Voltage reference. */
    adc_voltage_ref_internal_2_56_wocap, /*!< ADC use internal 2.56 Voltage reference. */
};

/*! \ingroup drv_adc
 * List of available voltage reference typedef.
 *
 * Note that not all voltage references are available. Availability is determined
 * by the device used.
 * */
typedef enum adc_voltage_ref_e adc_voltage_ref_t;
#elif defined(__AVR_AT90PWM81__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0,
    adc_voltage_ref_avcc_wcap,
    adc_voltage_ref_internal_2_56_wcap,
    adc_voltage_ref_internal_2_56_wocap
}adc_voltage_ref_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90PWM1__) \
|| defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__)\
|| defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega32U4__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega163__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATmega8535__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0,
    adc_voltage_ref_avcc_wcap,
    adc_voltage_ref_internal_2_56_wcap = 3,
}adc_voltage_ref_t;
#elif  defined(__AVR_ATmega16M1__) \
|| defined (__AVR_ATmega32C1__) \
|| defined (__AVR_ATmega32M1__) \
|| defined (__AVR_ATmega64C1__) \
|| defined (__AVR_ATmega64M1__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_avcc_wocap = 1,
    adc_voltage_ref_internal_2_56_wocap = 3,
    adc_voltage_ref_aref,
    adc_voltage_ref_avcc_wcap,
    adc_voltage_ref_internal_2_56_wcap = 7,
}adc_voltage_ref_t;
#elif defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165A__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined (__AVR_ATmega169__) \
|| defined (__AVR_ATmega169A__) \
|| defined (__AVR_ATmega169P__) \
|| defined (__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325A__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__)\
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649A__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250A__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega6490A__) \
|| defined(__AVR_ATmega6490P__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0,
    adc_voltage_ref_avcc_wcap,
    adc_voltage_ref_internal_1_1_wcap = 3,
}adc_voltage_ref_t;
#elif defined(__AVR_ATmega128RFA1__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0,
    adc_voltage_ref_avcc_wcap,
    adc_voltage_ref_internal_1_5_wcap,
    adc_voltage_ref_internal_1_6_wcap
}adc_voltage_ref_t;
#elif defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__)\
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_aref = 0,
    adc_voltage_ref_avcc_wcap,
    adc_voltage_ref_internal_1_1_wcap,
    adc_voltage_ref_internal_2_56_wcap
}adc_voltage_ref_t;
#elif defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny43U__) \
|| defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny88__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_vcc_wocap,
    adc_voltage_ref_internal_1_1_wocap
}adc_voltage_ref_t;
#elif defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny84__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_vcc_wocap,
    adc_voltage_ref_aref,
    adc_voltage_ref_internal_1_1_wocap
}adc_voltage_ref_t;
#elif defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__) \
|| defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny261A__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461A__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861A__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_vcc_wocap,
    adc_voltage_ref_aref,
    adc_voltage_ref_internal_1_1_wocap,
    adc_voltage_ref_internal_2_56_wocap = 6,
    adc_voltage_ref_internal_2_56_wcap
}adc_voltage_ref_t;
#elif defined(__AVR_ATtiny26__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_avcc_wocap,
    adc_voltage_ref_aref,
    adc_voltage_ref_internal_2_56_w0cap,
    adc_voltage_ref_internal_2_56_wcap
}adc_voltage_ref_t;
#elif defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)
typedef enum adc_voltage_ref_e
{
    adc_voltage_ref_avcc_wocap,
    adc_voltage_ref_aref,
    adc_voltage_ref_internal_1_1_wocap,
    adc_voltage_ref_internal_2_56_wocap
}adc_voltage_ref_t;
#elif defined(__AVR_ATmega103__)
    //adc_voltage_ref_t not define for those device
#else
#   error "adc_voltage_ref_t not defined for your device"
#endif

#if defined(__DOXYGEN__)
/*! \ingroup drv_adc
 * List of available trigger source.
 */
enum adc_trigger_source_e
{
    adc_trigger_source_free_running, /*!< ADC is in free running mode. */
    adc_trigger_source_analog_comparator, /*!< Start of conversion is triggered by the analog comparator. */
    adc_trigger_source_ext_int_request0, /*!< Start of conversion is triggered by the external request 0. */
    adc_trigger_source_timer_0_compare_match, /*!< Start of conversion is triggered by timer 0 compare match. */
    adc_trigger_source_timer_0_overflow, /*!< Start of conversion is triggered by timer 0 overflow. */
    adc_trigger_source_timer_1_compare_match_b, /*!< Start of conversion is triggered by timer 1 compare match B. */
    adc_trigger_source_timer_1_overflow, /*!< Start of conversion is triggered by timer 1 overflow. */
    adc_trigger_source_timer_1_capture_event, /*!< Start of conversion is triggered by timer 1 capture event. */
};

/*! \ingroup drv_adc
 * List of available trigger source typedef.
 */
typedef enum adc_trigger_source_e adc_trigger_source_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__)\
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165A__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325A__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649A__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250A__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega6490A__) \
|| defined(__AVR_ATmega6490P__) \
|| defined(__AVR_ATmega8535__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny84__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
} adc_trigger_source_t;
#elif defined(__AVR_AT90PWM1__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator_0,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_psc0asy_event,
    adc_trigger_source_psc2asy_event = 10,
    adc_trigger_source_analog_comparator_1,
    adc_trigger_source_analog_comparator_2
} adc_trigger_source_t;
#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator_0,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_psc0asy_event,
    adc_trigger_source_psc1asy_event,
    adc_trigger_source_psc2asy_event,
    adc_trigger_source_analog_comparator_1,
    adc_trigger_source_analog_comparator_2
} adc_trigger_source_t;
#elif defined(__AVR_AT90PWM81__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator_1,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_pscrasy_event,
    adc_trigger_source_psc2asy_event,
    adc_trigger_source_analog_comparator_2,
    adc_trigger_source_analog_comparator_3
} adc_trigger_source_t;
#elif defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega163__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATtiny15__) \
|| defined(__AVR_ATtiny26__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running
} adc_trigger_source_t;
#elif defined(__AVR_ATmega16M1__) \
|| defined (__AVR_ATmega32C1__) \
|| defined (__AVR_ATmega32M1__) \
|| defined (__AVR_ATmega64C1__) \
|| defined (__AVR_ATmega64M1__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_psc0asy_event,
    adc_trigger_source_psc1asy_event,
    adc_trigger_source_psc2asy_event,
    adc_trigger_source_analog_comparator_0,
    adc_trigger_source_analog_comparator_1,
    adc_trigger_source_analog_comparator_2,
    adc_trigger_source_analog_comparator_3
} adc_trigger_source_t;
#elif defined(__AVR_ATmega16M1__) \
|| defined (__AVR_ATmega32C1__) \
|| defined (__AVR_ATmega32M1__) \
|| defined (__AVR_ATmega64C1__) \
|| defined (__AVR_ATmega64M1__)\
|| defined (__AVR_ATmega16U4__) \
|| defined (__AVR_ATmega32U4__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_timer_4_overflow,
    adc_trigger_source_timer_4_compare_match_a,
    adc_trigger_source_timer_4_compare_match_b,
    adc_trigger_source_timer_4_compare_match_d
} adc_trigger_source_t;
#elif defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATtiny43U__) \
|| defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny88__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match_a,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_capture_event,
} adc_trigger_source_t;
#elif defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match_a,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_0_compare_match_b,
    adc_trigger_source_pin_change_interrupt_request
} adc_trigger_source_t;
#elif defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_1_compare_match_a,
    adc_trigger_source_timer_1_overflow,
    adc_trigger_source_timer_1_compare_match_b,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_watchdog_interrupt_request
} adc_trigger_source_t;
#elif defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny261A__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461A__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861A__)
typedef enum adc_trigger_source_e
{
    adc_trigger_source_free_running = 0,
    adc_trigger_source_analog_comparator,
    adc_trigger_source_ext_int_request0,
    adc_trigger_source_timer_0_compare_match_a,
    adc_trigger_source_timer_0_overflow,
    adc_trigger_source_timer_0_compare_match_b,
    adc_trigger_source_timer_1_capture_event,
    adc_trigger_source_watchdog_interrupt_request
} adc_trigger_source_t;
#elif defined(__AVR_ATmega103__)
    //adc_trigger_source_t not define for those device
#else
#   error "adc_trigger_source_t not defined for your device"
#endif

#if defined(__DOXYGEN__)
/*! \ingroup drv_adc
 * List of available input for ADC.
 */
enum adc_input_channel_e
{
    adc_input_channel_0, /*!< ADC use ADCpin 0. */
    adc_input_channel_1, /*!< ADC use ADCpin 1. */
    adc_input_channel_2, /*!< ADC use ADCpin 2. */
    adc_input_channel_3, /*!< ADC use ADCpin 3. */
    adc_input_channel_4, /*!< ADC use ADCpin 4. */
    adc_input_channel_5, /*!< ADC use ADCpin 5. */
    adc_input_channel_6, /*!< ADC use ADCpin 6. */
    adc_input_channel_7, /*!< ADC use ADCpin 7. */
    adc_input_channel_p0_n0_10x, /*!< ADC use differential input (pin0 - pin0) * 10. */
    adc_input_channel_p1_n0_10x, /*!< ADC use differential input (pin1 - pin0) * 10. */
    adc_input_channel_p0_n0_200x, /*!< ADC use differential input (pin0 - pin0) * 200. */
    adc_input_channel_p1_n0_200x, /*!< ADC use differential input (pin1 - pin0) * 200. */
    adc_input_channel_p2_n2_10x, /*!< ADC use differential input (pin2 - pin2) * 10. */
    adc_input_channel_p3_n2_10x, /*!< ADC use differential input (pin3 - pin2) * 10. */
    adc_input_channel_p2_n2_200x, /*!< ADC use differential input (pin2 - pin2) * 200. */
    adc_input_channel_p3_n2_200x, /*!< ADC use differential input (pin3 - pin2) * 200. */
    adc_input_channel_p0_n1_1x, /*!< ADC use differential input (pin0 - pin1) * 1. */
    adc_input_channel_p1_n1_1x, /*!< ADC use differential input (pin1 - pin1) * 1. */
    adc_input_channel_p2_n1_1x, /*!< ADC use differential input (pin2 - pin1) * 1. */
    adc_input_channel_p3_n1_1x, /*!< ADC use differential input (pin3 - pin1) * 1. */
    adc_input_channel_p4_n1_1x, /*!< ADC use differential input (pin4 - pin1) * 1. */
    adc_input_channel_p5_n1_1x, /*!< ADC use differential input (pin5 - pin1) * 1. */
    adc_input_channel_p6_n1_1x, /*!< ADC use differential input (pin6 - pin1) * 1. */
    adc_input_channel_p7_n1_1x, /*!< ADC use differential input (pin7 - pin1) * 1. */
    adc_input_channel_p0_n2_1x, /*!< ADC use differential input (pin0 - pin2) * 1. */
    adc_input_channel_p1_n2_1x, /*!< ADC use differential input (pin1 - pin2) * 1. */
    adc_input_channel_p2_n2_1x, /*!< ADC use differential input (pin2 - pin2) * 1. */
    adc_input_channel_p3_n2_1x, /*!< ADC use differential input (pin3 - pin2) * 1. */
    adc_input_channel_p4_n2_1x, /*!< ADC use differential input (pin4 - pin2) * 1. */
    adc_input_channel_p5_n2_1x, /*!< ADC use differential input (pin5 - pin2) * 1. */
    adc_input_channel_vbg, /*!< ADC use Vbg, Band gap(see documentation for per-device reference). */
    adc_input_channel_gnd, /*!< ADC use ground. */
    adc_input_channel_8, /*!< ADC use ADCpin 8. */
    adc_input_channel_9, /*!< ADC use ADCpin 9. */
    adc_input_channel_10, /*!< ADC use ADCpin 10. */
    adc_input_channel_11, /*!< ADC use ADCpin 11. */
    adc_input_channel_12, /*!< ADC use ADCpin 12. */
    adc_input_channel_13, /*!< ADC use ADCpin 13. */
    adc_input_channel_14, /*!< ADC use ADCpin 14. */
    adc_input_channel_15, /*!< ADC use ADCpin 15. */
    adc_input_channel_p8_n8_10x, /*!< ADC use differential input (pin8 - pin8) * 10. */
    adc_input_channel_p9_n8_10x, /*!< ADC use differential input (pin9 - pin8) * 10. */
    adc_input_channel_p8_n8_200x, /*!< ADC use differential input (pin8 - pin8) * 200. */
    adc_input_channel_p9_n8_200x, /*!< ADC use differential input (pin9 - pin8) * 200. */
    adc_input_channel_p10_n10_10x, /*!< ADC use differential input (pin10 - pin10) * 10. */
    adc_input_channel_p11_n10_10x, /*!< ADC use differential input (pin11 - pin10) * 10. */
    adc_input_channel_p10_n10_200x, /*!< ADC use differential input (pin10 - pin10) * 200. */
    adc_input_channel_p11_n10_200x, /*!< ADC use differential input (pin11 - pin10) * 200. */
    adc_input_channel_p8_n9_1x, /*!< ADC use differential input (pin8 - pin9) * 1. */
    adc_input_channel_p9_n9_1x, /*!< ADC use differential input (pin9 - pin9) * 1. */
    adc_input_channel_p10_n9_1x, /*!< ADC use differential input (pin10 - pin9) * 1. */
    adc_input_channel_p11_n9_1x, /*!< ADC use differential input (pin11 - pin9) * 1. */
    adc_input_channel_p12_n9_1x, /*!< ADC use differential input (pin12 - pin9) * 1. */
    adc_input_channel_p13_n9_1x, /*!< ADC use differential input (pin13 - pin9) * 1. */
    adc_input_channel_p14_n9_1x, /*!< ADC use differential input (pin14 - pin9) * 1. */
    adc_input_channel_p15_n9_1x, /*!< ADC use differential input (pin15 - pin9) * 1. */
    adc_input_channel_p8_n10_1x, /*!< ADC use differential input (pin8 - pin10) * 1. */
    adc_input_channel_p9_n10_1x, /*!< ADC use differential input (pin9 - pin10) * 1. */
    adc_input_channel_p10_n10_1x, /*!< ADC use differential input (pin10 - pin10) * 1. */
    adc_input_channel_p11_n10_1x, /*!< ADC use differential input (pin11 - pin10) * 1. */
    adc_input_channel_p12_n10_1x, /*!< ADC use differential input (pin12 - pin10) * 1. */
    adc_input_channel_p13_n10_1x, /*!< ADC use differential input (pin13 - pin10) * 1. */
};

/*! \ingroup drv_adc
 * List of available input for ADC typedef.
 */
typedef enum adc_input_channel_e adc_input_channel_t;
#elif defined(__AVR_AT90PWM1__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_amp0 = 0x0B,
    adc_input_channel_vbg = 0x0E,
    adc_input_channel_gnd = 0x0F
} adc_input_channel_t;
#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_amp0,
    adc_input_channel_amp1,
    adc_input_channel_vbg = 0x0E,
    adc_input_channel_gnd = 0x0F
} adc_input_channel_t;
#elif defined(__AVR_AT90PWM81__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_amp0,
    adc_input_channel_temp_sensor,
    adc_input_channel_vcc_div_4,
    adc_input_channel_vbg,
    adc_input_channel_gnd
} adc_input_channel_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega64P__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined (__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega8535__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p0_n0_10x,
    adc_input_channel_p1_n0_10x,
    adc_input_channel_p0_n0_200x,
    adc_input_channel_p1_n0_200x,
    adc_input_channel_p2_n2_10x,
    adc_input_channel_p3_n2_10x,
    adc_input_channel_p2_n2_200x,
    adc_input_channel_p3_n2_200x,
    adc_input_channel_p0_n1_1x,
    adc_input_channel_p1_n1_1x,
    adc_input_channel_p2_n1_1x,
    adc_input_channel_p3_n1_1x,
    adc_input_channel_p4_n1_1x,
    adc_input_channel_p5_n1_1x,
    adc_input_channel_p6_n1_1x,
    adc_input_channel_p7_n1_1x,
    adc_input_channel_p0_n2_1x,
    adc_input_channel_p1_n2_1x,
    adc_input_channel_p2_n2_1x,
    adc_input_channel_p3_n2_1x,
    adc_input_channel_p4_n2_1x,
    adc_input_channel_p5_n2_1x,
    adc_input_channel_vbg,
    adc_input_channel_gnd
} adc_input_channel_t;
#elif defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega163__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325A__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250A__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_vbg = 0x0E,
    adc_input_channel_gnd = 0x0F
} adc_input_channel_t;
#elif defined(__AVR_ATmega16M1__) \
|| defined (__AVR_ATmega32C1__) \
|| defined (__AVR_ATmega32M1__) \
|| defined (__AVR_ATmega64C1__) \
|| defined (__AVR_ATmega64M1__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_temp_sensor,
    adc_input_channel_vcc_div_4,
    adc_input_channel_isrc,
    adc_input_channel_amp0,
    adc_input_channel_amp1,
    adc_input_channel_amp2,
    adc_input_channel_vbg,
    adc_input_channel_gnd
} adc_input_channel_t;
#elif defined(__AVR_ATmega16U4__) \
|| defined(__AVR_ATmega32U4__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_4 = 4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p1_n0_10x = 9,
    adc_input_channel_p1_n0_200x = 0x0A,
    adc_input_channel_p0_n1_1x = 0x10,
    adc_input_channel_p4_n1_1x = 0x14,
    adc_input_channel_vbg = 0x1E,
    adc_input_channel_gnd,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_11,
    adc_input_channel_12,
    adc_input_channel_13,
    adc_input_channel_p1_n0_40x,
    adc_input_channel_temp_sensor,
    adc_input_channel_p4_n0_10x,
    adc_input_channel_p5_n0_10x,
    adc_input_channel_p6_n0_10x,
    adc_input_channel_p7_n0_10x,
    adc_input_channel_p4_n1_10x,
    adc_input_channel_p5_n1_10x,
    adc_input_channel_p6_n1_10x,
    adc_input_channel_p7_n1_10x,
    adc_input_channel_p4_n0_40x,
    adc_input_channel_p5_n0_40x,
    adc_input_channel_p6_n0_40x,
    adc_input_channel_p7_n0_40x,
    adc_input_channel_p4_n1_40x,
    adc_input_channel_p5_n1_40x,
    adc_input_channel_p6_n1_40x,
    adc_input_channel_p7_n1_40x,
    adc_input_channel_p4_n0_200x,
    adc_input_channel_p5_n0_200x,
    adc_input_channel_p6_n0_200x,
    adc_input_channel_p7_n0_200x,
    adc_input_channel_p4_n1_200x,
    adc_input_channel_p5_n1_200x,
    adc_input_channel_p6_n1_200x,
    adc_input_channel_p7_n1_200x,
} adc_input_channel_t;
#elif defined(__AVR_ATmega103__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7
} adc_input_channel_t;
#elif defined(__AVR_ATmega128RFA1__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p0_n0_10x,
    adc_input_channel_p1_n0_10x,
    adc_input_channel_p0_n0_200x,
    adc_input_channel_p1_n0_200x,
    adc_input_channel_p2_n2_10x,
    adc_input_channel_p3_n2_10x,
    adc_input_channel_p2_n2_200x,
    adc_input_channel_p3_n2_200x,
    adc_input_channel_p0_n1_1x,
    adc_input_channel_p1_n1_1x,
    adc_input_channel_p2_n1_1x,
    adc_input_channel_p3_n1_1x,
    adc_input_channel_p4_n1_1x,
    adc_input_channel_p5_n1_1x,
    adc_input_channel_p6_n1_1x,
    adc_input_channel_p7_n1_1x,
    adc_input_channel_p0_n2_1x,
    adc_input_channel_p1_n2_1x,
    adc_input_channel_p2_n2_1x,
    adc_input_channel_p3_n2_1x,
    adc_input_channel_p4_n2_1x,
    adc_input_channel_p5_n2_1x,
    adc_input_channel_vbg,
    adc_input_channel_gnd,
    adc_input_channel_temp_sensor = 0x29,
    adc_input_channel_vdrtbbp = 0x34,
    adc_input_channel_vdrtbbn = 0x3D
} adc_input_channel_t;
#elif defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165A__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649A__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega6490A__) \
|| defined(__AVR_ATmega6490P__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p0_n1_1x = 0x10,
    adc_input_channel_p1_n1_1x,
    adc_input_channel_p2_n1_1x,
    adc_input_channel_p3_n1_1x,
    adc_input_channel_p4_n1_1x,
    adc_input_channel_p5_n1_1x,
    adc_input_channel_p6_n1_1x,
    adc_input_channel_p7_n1_1x,
    adc_input_channel_p0_n2_1x,
    adc_input_channel_p1_n2_1x,
    adc_input_channel_p2_n2_1x,
    adc_input_channel_p3_n2_1x,
    adc_input_channel_p4_n2_1x,
    adc_input_channel_p5_n2_1x,
    adc_input_channel_vbg,
    adc_input_channel_gnd
} adc_input_channel_t;
#elif defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_p0_n0_10x,
    adc_input_channel_p1_n0_10x,
    adc_input_channel_p0_n0_200x,
    adc_input_channel_p1_n0_200x,
    adc_input_channel_p2_n2_10x,
    adc_input_channel_p3_n2_10x,
    adc_input_channel_p2_n2_200x,
    adc_input_channel_p3_n2_200x,
    adc_input_channel_p0_n1_1x,
    adc_input_channel_p1_n1_1x,
    adc_input_channel_p2_n1_1x,
    adc_input_channel_p3_n1_1x,
    adc_input_channel_p4_n1_1x,
    adc_input_channel_p5_n1_1x,
    adc_input_channel_p6_n1_1x,
    adc_input_channel_p7_n1_1x,
    adc_input_channel_p0_n2_1x,
    adc_input_channel_p1_n2_1x,
    adc_input_channel_p2_n2_1x,
    adc_input_channel_p3_n2_1x,
    adc_input_channel_p4_n2_1x,
    adc_input_channel_p5_n2_1x,
    adc_input_channel_vbg,
    adc_input_channel_gnd,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    adc_input_channel_11,
    adc_input_channel_12,
    adc_input_channel_13,
    adc_input_channel_14,
    adc_input_channel_15,
    adc_input_channel_p8_n8_10x,
    adc_input_channel_p9_n8_10x,
    adc_input_channel_p8_n8_200x,
    adc_input_channel_p9_n8_200x,
    adc_input_channel_p10_n10_10x,
    adc_input_channel_p11_n10_10x,
    adc_input_channel_p10_n10_200x,
    adc_input_channel_p11_n10_200x,
    adc_input_channel_p8_n9_1x,
    adc_input_channel_p9_n9_1x,
    adc_input_channel_p10_n9_1x,
    adc_input_channel_p11_n9_1x,
    adc_input_channel_p12_n9_1x,
    adc_input_channel_p13_n9_1x,
    adc_input_channel_p14_n9_1x,
    adc_input_channel_p15_n9_1x,
    adc_input_channel_p8_n10_1x,
    adc_input_channel_p9_n10_1x,
    adc_input_channel_p10_n10_1x,
    adc_input_channel_p11_n10_1x,
    adc_input_channel_p12_n10_1x,
    adc_input_channel_p13_n10_1x,
    adc_input_channel_Reserved_1,
    adc_input_channel_Reserved_2,
} adc_input_channel_t;
#elif defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny10__) \
|| defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3
} adc_input_channel_t;
#elif defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny84__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7
    //\todo Add missing channel
} adc_input_channel_t;
#elif defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3
    //\todo Add missing channel
} adc_input_channel_t;
#elif defined(__AVR_ATtiny26__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    //\todo Add missing channel
} adc_input_channel_t;
#elif defined(__AVR_ATtiny43U__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3
    //\todo Add missing channel
} adc_input_channel_t;
#elif defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny88__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    //\todo Add missing channel
} adc_input_channel_t;
#elif defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    //\todo Add missing channel
} adc_input_channel_t;
#elif defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny261A__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461A__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861A__)
typedef enum adc_input_channel_e
{
    adc_input_channel_0 = 0,
    adc_input_channel_1,
    adc_input_channel_2,
    adc_input_channel_3,
    adc_input_channel_4,
    adc_input_channel_5,
    adc_input_channel_6,
    adc_input_channel_7,
    adc_input_channel_8,
    adc_input_channel_9,
    adc_input_channel_10,
    //\todo Add missing channel
} adc_input_channel_t;
#else
#   error "adc_input_channel_selection_t not coded for device"
#endif

#if defined(__DOXYGEN__)
/*! \ingroup drv_adc
 * List of digital input channel.
 *
 * Not all device are equipped with a Digital Input Disable Register.
 * Also, not all device share the same number of input.
 */
enum adc_digital_channel_e
{
    adc_digital_channel_0,    /*!< Digital input on pin0. */
    adc_digital_channel_1,    /*!< Digital input on pin1. */
    adc_digital_channel_2,    /*!< Digital input on pin2. */
    adc_digital_channel_3,    /*!< Digital input on pin3. */
    adc_digital_channel_4,    /*!< Digital input on pin4. */
    adc_digital_channel_5,    /*!< Digital input on pin5. */
    adc_digital_channel_6,    /*!< Digital input on pin6. */
    adc_digital_channel_7,    /*!< Digital input on pin7. */
    adc_digital_channel_8,    /*!< Digital input on pin8. */
    adc_digital_channel_9,    /*!< Digital input on pin9. */
    adc_digital_channel_10,   /*!< Digital input on pin10. */
    adc_digital_channel_11,   /*!< Digital input on pin11. */
    adc_digital_channel_12,   /*!< Digital input on pin12. */
    adc_digital_channel_13,   /*!< Digital input on pin13. */
    adc_digital_channel_14,   /*!< Digital input on pin14. */
    adc_digital_channel_15,   /*!< Digital input on pin15. */
    adc_digital_channel_amp0nd,
    adc_digital_channel_amp0pd,
    adc_digital_channel_amp1nd,
    adc_digital_channel_amp1pd,
    adc_digital_channel_amp2nd,
    adc_digital_channel_amp2pd,
    adc_digital_channel_aref, /*!< Digital input on pin AREF. */

};

/*! \ingroup drv_adc
 * List of digital input channel typedef.
 */
typedef enum adc_digital_channel_e adc_digital_channel_t;
#elif defined(__AVR_AT90PWM1__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_amp0nd = 0x0800,
    adc_digital_channel_amp0pd = 0x1000,
}adc_digital_channel_t;
#elif defined(__AVR_AT90PWM2__) \
|| defined(__AVR_AT90PWM2B__) \
|| defined(__AVR_AT90PWM3__) \
|| defined(__AVR_AT90PWM3B__) \
|| defined(__AVR_AT90PWM216__) \
|| defined(__AVR_AT90PWM316__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel_amp1nd = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel_amp1pd = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel_amp0nd = 0x0800,
    adc_digital_channel_amp0pd = 0x1000,
}adc_digital_channel_t;
#elif defined(__AVR_AT90PWM81__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_7 = 0x0040,
    adc_digital_channel_amp0nd = 0x0040,
    adc_digital_channel_8 = 0x0080,
    adc_digital_channel_9 = 0x0100,
    adc_digital_channel_10 = 0x0200,
    adc_digital_channel_amp0pd = 0x0400
}adc_digital_channel_t;
#elif defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) \
|| defined(__AVR_AT90CAN128__) \
|| defined(__AVR_AT90USB646__) \
|| defined(__AVR_AT90USB647__) \
|| defined(__AVR_AT90USB1286__) \
|| defined(__AVR_AT90USB1287__) \
|| defined(__AVR_ATmega32U6__) \
|| defined(__AVR_ATmega128RFA1__) \
|| defined(__AVR_ATmega164A__) \
|| defined(__AVR_ATmega164P__) \
|| defined(__AVR_ATmega165__) \
|| defined(__AVR_ATmega165A__) \
|| defined(__AVR_ATmega165P__) \
|| defined(__AVR_ATmega169__) \
|| defined(__AVR_ATmega169A__) \
|| defined(__AVR_ATmega169P__) \
|| defined(__AVR_ATmega169PA__) \
|| defined(__AVR_ATmega324A__) \
|| defined(__AVR_ATmega324P__) \
|| defined(__AVR_ATmega324PA__) \
|| defined(__AVR_ATmega325__) \
|| defined(__AVR_ATmega325A__) \
|| defined(__AVR_ATmega325P__) \
|| defined(__AVR_ATmega329__) \
|| defined(__AVR_ATmega329P__) \
|| defined(__AVR_ATmega329PA__) \
|| defined(__AVR_ATmega644__) \
|| defined(__AVR_ATmega644A__) \
|| defined(__AVR_ATmega644P__) \
|| defined(__AVR_ATmega644PA__) \
|| defined(__AVR_ATmega645__) \
|| defined(__AVR_ATmega645A__) \
|| defined(__AVR_ATmega645P__) \
|| defined(__AVR_ATmega649__) \
|| defined(__AVR_ATmega649A__) \
|| defined(__AVR_ATmega649P__) \
|| defined(__AVR_ATmega1284__) \
|| defined(__AVR_ATmega1284P__) \
|| defined(__AVR_ATmega3250__) \
|| defined(__AVR_ATmega3250A__) \
|| defined(__AVR_ATmega3250P__) \
|| defined(__AVR_ATmega3290__) \
|| defined(__AVR_ATmega3290P__) \
|| defined(__AVR_ATmega6450__) \
|| defined(__AVR_ATmega6450A__) \
|| defined(__AVR_ATmega6450P__) \
|| defined(__AVR_ATmega6490__) \
|| defined(__AVR_ATmega6490A__) \
|| defined(__AVR_ATmega6490P__) \
|| defined(__AVR_ATtiny24__) \
|| defined(__AVR_ATtiny24A__) \
|| defined(__AVR_ATtiny44__) \
|| defined(__AVR_ATtiny44A__) \
|| defined(__AVR_ATtiny48__) \
|| defined(__AVR_ATtiny84__) \
|| defined(__AVR_ATtiny88__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080
}adc_digital_channel_t;
#elif defined(__AVR_ATmega16M1__) \
|| defined(__AVR_ATmega32C1__) \
|| defined(__AVR_ATmega32M1__) \
|| defined(__AVR_ATmega64C1__) \
|| defined(__AVR_ATmega64M1__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_amp2nd = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel_amp1nd = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel_amp1pd = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel_amp0nd = 0x0800,
    adc_digital_channel_amp0pd = 0x1000,
    adc_digital_channel_amp2pd = 0x4000
}adc_digital_channel_t;
#elif defined (__AVR_ATmega16U4__) \
|| defined (__AVR_ATmega32U4__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel_11 = 0x0800,
    adc_digital_channel_12 = 0x1000,
    adc_digital_channel_13 = 0x2000
}adc_digital_channel_t;
#elif defined(__AVR_ATmega48__) \
|| defined(__AVR_ATmega48A__) \
|| defined(__AVR_ATmega48P__) \
|| defined(__AVR_ATmega48PA__) \
|| defined(__AVR_ATmega88__) \
|| defined(__AVR_ATmega88A__) \
|| defined(__AVR_ATmega88P__) \
|| defined(__AVR_ATmega88PA__) \
|| defined(__AVR_ATmega168__) \
|| defined(__AVR_ATmega168A__) \
|| defined(__AVR_ATmega168P__) \
|| defined(__AVR_ATmega168PA__) \
|| defined(__AVR_ATmega328__) \
|| defined(__AVR_ATmega328P__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x01,
    adc_digital_channel_1 = 0x02,
    adc_digital_channel_2 = 0x04,
    adc_digital_channel_3 = 0x08,
    adc_digital_channel_4 = 0x10,
    adc_digital_channel_5 = 0x20,
}adc_digital_channel_t;
#elif defined(__AVR_ATmega640__) \
|| defined(__AVR_ATmega1280__) \
|| defined(__AVR_ATmega1281__) \
|| defined(__AVR_ATmega2560__) \
|| defined(__AVR_ATmega2561__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x0100,
    adc_digital_channel_9 = 0x0200,
    adc_digital_channel_10 = 0x0400,
    adc_digital_channel_11 = 0x0800,
    adc_digital_channel_12 = 0x1000,
    adc_digital_channel_13 = 0x2000,
    adc_digital_channel_14 = 0x4000,
    adc_digital_channel_15 = 0x8000
}adc_digital_channel_t;
#elif defined(__AVR_ATtiny5__) \
|| defined(__AVR_ATtiny10__) \
|| defined(__AVR_ATtiny43U__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x01,
    adc_digital_channel_1 = 0x02,
    adc_digital_channel_2 = 0x04,
    adc_digital_channel_3 = 0x08
}adc_digital_channel_t;
#elif defined(__AVR_ATtiny13__) \
|| defined(__AVR_ATtiny13A__) \
|| defined(__AVR_ATtiny25__) \
|| defined(__AVR_ATtiny45__) \
|| defined(__AVR_ATtiny85__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x20,
    adc_digital_channel_1 = 0x04,
    adc_digital_channel_2 = 0x80,
    adc_digital_channel_3 = 0x08
}adc_digital_channel_t;
#elif defined(__AVR_ATtiny87__) \
|| defined(__AVR_ATtiny167__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_3 = 0x0008,
    adc_digital_channel_4 = 0x0010,
    adc_digital_channel_5 = 0x0020,
    adc_digital_channel_6 = 0x0040,
    adc_digital_channel_7 = 0x0080,
    adc_digital_channel_8 = 0x1000,
    adc_digital_channel_9 = 0x2000,
    adc_digital_channel_10 = 0x4000
}adc_digital_channel_t;
#elif defined(__AVR_ATtiny261__) \
|| defined(__AVR_ATtiny261A__) \
|| defined(__AVR_ATtiny461__) \
|| defined(__AVR_ATtiny461A__) \
|| defined(__AVR_ATtiny861__) \
|| defined(__AVR_ATtiny861A__)
typedef enum adc_digital_channel_e
{
    adc_digital_channel_0 = 0x0001,
    adc_digital_channel_1 = 0x0002,
    adc_digital_channel_2 = 0x0004,
    adc_digital_channel_aref = 0x0008,
    adc_digital_channel_3 = 0x0010,
    adc_digital_channel_4 = 0x0020,
    adc_digital_channel_5 = 0x0040,
    adc_digital_channel_6 = 0x0080,
    adc_digital_channel_7 = 0x1000,
    adc_digital_channel_8 = 0x2000,
    adc_digital_channel_9 = 0x4000,
    adc_digital_channel_10 = 0x8000
}adc_digital_channel_t;
#elif defined(__AVR_ATmega8__) \
|| defined(__AVR_ATmega16__) \
|| defined(__AVR_ATmega16A__) \
|| defined(__AVR_ATmega32__) \
|| defined(__AVR_ATmega32A__) \
|| defined(__AVR_ATmega64__) \
|| defined(__AVR_ATmega64A__) \
|| defined(__AVR_ATmega103__) \
|| defined(__AVR_ATmega128__) \
|| defined(__AVR_ATmega163__) \
|| defined(__AVR_ATmega323__) \
|| defined(__AVR_ATmega8535__) \
|| defined(__AVR_ATtiny26__)
    //No Digital Input Disable Register for these devices
#else
#   error "adc_digital_channel_t not defined for your device"
#endif

#endif /*ADCDEF_H_*/
