# Introduction #

The headers found in _io\_pin_ directory are similar to the _io_ headers provided by _avr-libc_. Simply include the _io\_pin.h_ header to use it.

These headers map function pins to their respective ports. This way, it is easier to create portable code across devices.

# Warning #

Headers are script generated from _Atmel's_ _XML_ which are known to contains errors. Open an issue if you find anything wrong in _io\_pin_ headers. The project keeps track of changes made to _Atmel's_ _XML_ in order to provide the most accurate information. _Atmel_ has been informed for most error found in their _XML_ and they are slow to react(_XML_ are taken from _AVR_ _Studio_ releases, which is not that often), if they react at all.

# Usage #

The example bellow allows to enable the pull-up on the _TWI_ pins.

```
#include "io_pin/io_pin.h"

void twi_enable_pullup(void)
{
    SDA_PORT |= _BV(SDA_BIT);
    SCL_PORT |= _BV(SCL_BIT);
}

```