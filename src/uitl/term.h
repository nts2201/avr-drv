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

/*! \file term.h
 \defgroup util_term <util/term.h>: Terminal emulation
 \brief Provide a set of macro for terminal emulation.

 This module highly depends on external functions. This should allow
 easy port to other platform as well as transmission medium(UART, TWI, ...).

 In contrast to Procyon AVRlib, this does not use program space string.
 I find that the use, for example, rprintfProgStrM("\x1B[2J"); is highly
 inefficient. Just to send 3 char, you then need to read those from flash
 and then send them with no real benefit in term of code size.

 Atmel version of terminal(ported to GCC by Martin THOMAS
 http://gandalf.arubi.uni-kl.de/avr_projects/ ) was not licensed under BSD terms
 and thus I had to rewrite it. This version implement more terminal function without
 the use of string. I think that for small string ("\e[?2h") there is no real benefit
 to use a string iterator (while(*str != '\0') over sending all char separately.

 \author Frédéric Nadeau

 \todo Implement char reception decoding.
 */

#ifndef TERM_H_
#define TERM_H_

extern void term_putc(char);

/*! \ingroup util_term
 List of possible colour both for foreground and background.
 */
enum term_colour_e
{
	term_colour_black = '0',
	term_colour_red,
	term_colour_green,
	term_colour_yellow,
	term_colour_blue,
	term_colour_magenta,
	term_colour_cyan,
	term_colour_white
};

/*! \ingroup util_term
 List of possible terminal mode.
 */
enum term_mode_e
{
	term_mode_reset_mode = '0', /*!< Reset terminal mode.*/
	term_mode_bright,
	term_mode_dim,
	term_mode_underscore,
	term_mode_blink,
	term_mode_reverse,
	term_mode_hidden
};

/*! \ingroup util_term
    Convert number in base 10 digits.

    This is a stripped version of itoa() that do not require
    buffer. It will only convert number within the 0 to 255 range.
    This limits the terminal window size to 255 by 255.
*/
static __inline__ void
term_itoa(uint8_t digit)
{
	if(digit >= 100)
	{
		term_putc(digit / 100);
		digit %= 100;
	}
	if(digit >= 10)
	{
		term_putc(digit / 10);
		digit %= 10;
	}

	term_putc(digit);
}

/*! \ingroup util_term
 Set terminal to VT52 mode.
 */
#define term_set_vt52_mode() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('?');\
	term_putc('2');\
	term_putc('l');

/*! \ingroup util_term
 Set terminal to VT100 mode.
 */
#define term_set_vt100_mode() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('?');\
	term_putc('2');\
	term_putc('h');

/*! \ingroup util_term
 Set terminal to display cursor.
 */
#define term_show_cursor() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('?');\
	term_putc('2');\
	term_putc('5');\
	term_putc('h');

/*! \ingroup util_term
 Set terminal to hide cursor.
 */
#define term_hide_cursor() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('?');\
	term_putc('2');\
	term_putc('5');\
	term_putc('l');


/*! \ingroup util_term
 Erase line from cursor location to the end of it.
 */
#define term_erase_end_of_line() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('K');

/*! \ingroup util_term
 Erase line from start of it to cursor location.
 */
#define term_erase_start_of_line() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('1'); \
	term_putc('K');

/*! \ingroup util_term
 Erase current line.
 */
#define term_erase_line() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('2'); \
	term_putc('K');

/*! \ingroup util_term
 Erase lines from current one to last one.
 */
#define term_erase_down() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('J');

/*! \ingroup util_term
 Erase lines from first one to current one.
 */
#define term_erase_up() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('1'); \
	term_putc('J');

/*! \ingroup util_term
 Erase all lines on the screen.
 */
#define term_erase_screen() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('2'); \
	term_putc('J');

/*! \ingroup util_term
 Move cursor to upper left position. Same as
 #term_set_cursor_position(1,1).
 */
#define term_set_cursor_home() \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('H');

/*! \ingroup util_term
 Set cursor position to x, y coordinate.
 */
#define term_set_cursor_position( x, y) \
	term_putc('\e'); \
	term_putc('['); \
    term_itoa(x); \
	term_putc(';'); \
	term_itoa(y); \
	term_putc('H');

/*! \ingroup util_term
 Save cursor position.
 */
#define term_save_cursor_position() \
	term_putc('\e' ); \
	term_putc('7' );

/*! \ingroup util_term
 Restore cursor position.
 */
#define term_restore_cursor_position() \
	term_putc('\e'); \
	term_putc('8');

/*! \ingroup util_term
 Set terminal mode. #term_mode_e should be use as argument.
 */
#define term_set_mode(mode) \
	term_putc('\e'); \
	term_putc('['); \
	term_putc(mode); \
	term_putc('m');

/*! \ingroup util_term
 Set terminal mode and foreground colour.
 #term_mode_e and #term_colour_e should be use as argument.
 */
#define term_set_mode_foreground(mode, foregound) \
	term_putc('\e'); \
	term_putc('['); \
	term_putc(mode); \
	term_putc(';'); \
	term_putc('3'); \
	term_putc(foregound); \
	term_putc('m');

/*! \ingroup util_term
 Set terminal mode, foreground and background colour.
 #term_mode_e and #term_colour_e should be use as argument.
 */
#define term_set_mode_foreground_background(mode, foregound, background) \
	term_putc('\e'); \
	term_putc('['); \
	term_putc(mode); \
	term_putc(';'); \
	term_putc('3'); \
	term_putc(foregound); \
	term_putc(';'); \
	term_putc('4'); \
	term_putc(background); \
	term_putc('m');

/*! \ingroup util_term
 Set terminal foreground and background colour.
 #term_mode_e and #term_colour_e should be use as argument.
 */
#define term_set_foreground_background(mode, foregound, background) \
	term_putc('\e'); \
	term_putc('['); \
	term_putc('3'); \
	term_putc(foregound); \
	term_putc(';'); \
	term_putc('4'); \
	term_putc(background); \
	term_putc('m');

#endif /*TERM_H_*/
