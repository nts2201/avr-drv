/* Copyright (c) 2011 Frédéric Nadeau
   All rights reserved.

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

/*! \file usartBaudRate.h
 \brief Function definition for USART baud rate calculation.
 */

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
        uint8_t ubTol, usart_mode_t mode, uint16_t* puwUbrr);
