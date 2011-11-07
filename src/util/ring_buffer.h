/* Copyright (c) 2011 Frédéric Nadeau
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

/*! \file ring_buffer.h
 \defgroup util_ring_buffer <util/ring_buffer.h>: Ring Buffer
 \brief Ring buffer macro, also known as circular buffer.

 This is a very generic ring buffer that could fit most usage.

 Here is a little example tested on AT90CAN128.

 \code
	#include <util/ring_buffer.h>

	ring_buffer_constructor(int, 16, myRing);

	int main (void)
	{
		int pushValue = 18;
		int popValue;

		ring_buffer_myRing_push(pushValue);
		ring_buffer_myRing_pop(&popValue);

		return 0;
	}

 \endcode

 \author Frédéric Nadeau
 */
#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

/*! \ingroup util_ring_buffer
 Generic ring buffer constructor.
 This will generate code for a simple type ring buffer.
 \param type Storage type of variable kept in the ring buffer.
 Only simple type should be use here(int, char...), for complex type
 refer to #ring_buffer_memcpy_constructor.
 \param size Size of the ring buffer. Should be less than 65536.
 \param name Suffix that will be append to function name.
 */
#define ring_buffer_constructor(type, size, name) \
static uint16_t ring_buffer_##name##_head = 0; \
static uint16_t ring_buffer_##name##_tail = 0; \
static uint16_t ring_buffer_##name##_elements = 0; \
static type ring_buffer_##name##_array[ size ]; \
static void ring_buffer_##name##_push(type element)\
{\
	if(size != ring_buffer_##name##_elements)\
	{ \
		ring_buffer_##name##_elements++; \
		ring_buffer_##name##_array[ring_buffer_##name##_head] = element; \
		ring_buffer_##name##_head++; \
		ring_buffer_##name##_head %= size; \
	} \
}\
static void ring_buffer_##name##_pop(type *element)\
{\
	if(0 != ring_buffer_##name##_elements)\
	{ \
		ring_buffer_##name##_elements--; \
		*element = ring_buffer_##name##_array[ring_buffer_##name##_tail]; \
		ring_buffer_##name##_tail++; \
		ring_buffer_##name##_tail %= size; \
	} \
	else \
	{ \
		element = (void*) 0; \
	} \
}\

/*! \ingroup util_ring_buffer
 Generic ring buffer constructor for complex type.
 This will generate code for complex type ring buffer.
 \param type Storage type of variable kept in the ring buffer.
 Complex type such as structure should be use.
 \param size Size of the ring buffer. Should be less than 65536.
 \param name Suffix that will be append to function name.

 This ring buffer use memcpy to push and pop element in and out of
 the buffer. This make it ideal for, as example, CANbus messages.
 */
#define ring_buffer_memcpy_constructor(type, size, name) \
static uint16_t ring_buffer_##name##_head = 0; \
static uint16_t ring_buffer_##name##_tail = 0; \
static uint16_t ring_buffer_##name##_elements = 0; \
static type ring_buffer_##name##_array[ size ]; \
static void ring_buffer_##name##_push(const type *element)\
{\
	if(size != ring_buffer_##name##_elements)\
	{ \
		ring_buffer_##name##_elements++; \
		memcpy((void*)&ring_buffer_##name##_array[ring_buffer_##name##_head], (void*)element, sizeof(type)); \
		ring_buffer_##name##_head++; \
		ring_buffer_##name##_head %= size; \
	} \
}\
static void ring_buffer_##name##_pop(type *element)\
{\
	if(0 != ring_buffer_##name##_elements)\
	{ \
		ring_buffer_##name##_elements--; \
		memcpy((void*)element, (void*)&ring_buffer_##name##_array[ring_buffer_##name##_tail], sizeof(type)); \
		ring_buffer_##name##_tail++; \
		ring_buffer_##name##_tail %= size; \
	} \
	else \
	{ \
		element = (void*) 0; \
	} \
}\


#endif /* RING_BUFFER_H_ */
