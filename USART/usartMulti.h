/*! \file usartSingle.h
 \brief Function declaration for device with a multiple USART.

 \author Frédéric Nadeau

 \warning Copyright (c) 2008 Frédéric Nadeau
 All rights reserved.


 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:\n
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.\n
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.\n
 3. The name of the author nor the names of its contributors may not
 be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef USARTMULTI_H_
#define USARTMULTI_H_

int usartmultisetbaudrate(Usart_portt port, uint32t baudrate);
int usartmultisetnumbit(Usart_portt port, Usart_numbitst numbit);
int usartmultisetparity(Usart_portt port, Usart_parityt partity);
int usartmultisetstopbit(Usart_portt port, Usart_stopbitt stopbit);
int usartmultisetmode(Usart_portt port, Usart_modet mode);

int usartmultienablerx(Usart_portt port, Bool enable);
int usartmultienabletx(Usart_portt port, Bool enable);

int usartmultiputc(Usart_portt port, char data);
int usartmultiputs(Usart_portt port, char data);
int usartmultigetc(Usart_portt port, char *data);

_bool usartmultiistx(Usartportt port);

int usartmultienablerxint(Usart_portt port, Bool enable);
int usartmultienabletxbufint(Usart_portt port, Bool enable);
int usartmultienabletxcmpint(Usart_portt port, Bool enable);

int usartmultiputcisr(Usart_portt port, char data);
int usartmultigetcisr(Usart_portt port, char *data);


#endif /* USARTMULTI_H_ */
