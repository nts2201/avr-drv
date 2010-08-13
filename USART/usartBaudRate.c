/* Copyright (c) 2008, 2010 Frédéric Nadeau
   Copyright (c) 2007  Cliff Lawson
   Copyright (c) 2007  Carlos Lamas
   All rights reserved.

   Part of the following code is derived from setbaud.h found in avr-libc
   project ditributed under WinAVR20081205.

   The following copyright are included to respect the license of AVR-Libc.

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

/*! \file usartBaudRate.c
 \brief This file calculate value of baud rate register for the USART.
 */

#include <stdbool.h>
#include <stdint.h>

#include "usartDef.h"
#include "avr-drv-errno.h"

static uint16_t get_ubrb(uint32_t uiBaudRate, uint32_t uiClk, uint8_t ubTol,
        uint8_t factor)
{
    return (((uiClk) + (factor >> 1) * (uiBaudRate)) / (factor * (uiBaudRate))
            - 1UL);
}

static _Bool check_Tol(uint32_t uiBaudRate, uint32_t uiClk, uint16_t uwUbrr,
        uint8_t ubTol, uint8_t factor)
{
    if (100 * (uiClk) > (factor * ((uwUbrr) + 1)) * (100UL * (uiBaudRate)
            + (uiBaudRate) * ubTol))
    {
        return false;
    }
    else if (100 * (uiClk) < (factor * ((uwUbrr) + 1)) * (100 * (uiBaudRate)
            - (uiBaudRate) * ubTol))
    {
        return false;
    }

    return true;
}

/*! \fn int usart_baud_rate_get_ubrb(uint32_t uiBaudRate, uint32_t uiClk, uint8_t ubTol, usart_mode_t mode, uint16_t* puwUbrr)
 *  \brief  Compute value for UBRR.
 *
 *  \param  uiBaudRate Desired baud rate.
 *  \param  uiClk Clock frequency in Hz.
 *  \param  ubTol Mismatch tolerance. 2 should be use, witch mean 2%.
 *  \param  mode Whether it is Asyn or Sync USART mode.
 *  \param  puwUbrr Pointer to where UBRR value will be saved.
 *  \return On success, value can be 0 or 1. If value is 0, X2 mode shall be desactivated and if
 *          it is 1, it shall be activated. Value -1 indicate that an error occurred.
 *          See \c errno for detail on error.\n
 *          #EINVAL Invalid argument was provided.\n
 *          #EBAUDRATE Desired baud rate can not be achieved.
 */
int usart_baud_rate_get_ubrb(uint32_t uiBaudRate, uint32_t uiClk,
        uint8_t ubTol, usart_mode_t mode, uint16_t* puwUbrr)
{
    int retVal = 0;
    uint16_t uwBaud;

    if (NULL == puwUbrr)
    {
        avr_drv_errno = EINVAL;
        return -1;
    }

    switch (mode)
    {
    case usart_mode_async:
    {
        //Use equation found in util/setbaud.h
        uwBaud = get_ubrb(uiBaudRate, ubTol, 16);

        if (false == checkTol(uiBaudRate, uwBaud, ubTol, 16))
        {
            uwBaud = get_ubrb(uiBaudRate, ubTol, 8);
            if (false == check_Tol(uiBaudRate, uwBaud, ubTol, 8))
            {
                avr_drv_errno = EBAUDRATE;
                return -1;
            }
            else
            {
                retVal = 1;
            }
        }
        else
        {
        }
    }
        break;
    case usart_mode_sync_master:
    case usart_mode_sync_slave:
    {
        //Use a modified version of equation found in util/setbaud.h
        uwBaud = get_ubrb(uiBaudRate, ubTol, 2);

        if (false == checkTol(uiBaudRate, uwBaud, ubTol, 2))
        {
            avr_drv_errno = EBAUDRATE;
            return -1;
        }
        else
        {
        }
    }
        break;
    default:
        avr_drv_errno = EINVAL;
        return -1;
        break;
    }

    *puwUbrr = uwBaud;
    return 0;
}
