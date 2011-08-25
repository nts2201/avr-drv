# Hey Emacs, this is a -*- makefile -*-

include Makefile.mk
include Makefile.adc.mk
include Makefile.can.mk
include Makefile.extint.mk
include Makefile.spi.mk
include Makefile.tmrcnt0.mk
include Makefile.tmrcnt1.mk
include Makefile.tmrcnt2.mk
include Makefile.tmrcnt3.mk
include Makefile.tmrcnt4.mk
include Makefile.tmrcnt5.mk
include Makefile.twi.mk
include Makefile.twiInt.mk
include Makefile.usart.mk

all: iopin adc can errno extint spi tmrcnt0 tmrcnt1 tmrcnt2 tmrcnt3 tmrcnt4 tmrcnt5 twi twiInt usart 

adc: $(ADC_TARGETS) $(ADC_HEADER)

can: $(CAN_TARGETS) $(CAN_HEADER)

iopin:
	mkdir -p $(OUTDIR)/include/io_pin
	$(COPY) ./io_pin/* $(OUTDIR)/include/io_pin
	mkdir -p $(OUTDIR)/example
	$(RSYNC) -r --exclude=.svn ./example/ $(OUTDIR)/example
	mkdir -p $(OUTDIR)/include/util
	$(RSYNC) -r --exclude=.svn ./util/ $(OUTDIR)/include/util

errno: $(ERRNO_HEADER)

extint: $(EXTINT_TARGETS) $(EXTINT_HEADER)

spi: $(SPI_TARGETS) $(SPI_HEADER)

tmrcnt0: iopin $(TMRCNT0_TARGETS) $(TMRCNT0_HEADER)

tmrcnt1: iopin $(TMRCNT1_TARGETS) $(TMRCNT1_HEADER)

tmrcnt2: iopin $(TMRCNT2_TARGETS) $(TMRCNT2_HEADER)

tmrcnt3: iopin $(TMRCNT3_TARGETS) $(TMRCNT3_HEADER)

tmrcnt4: iopin $(TMRCNT4_TARGETS) $(TMRCNT4_HEADER)

tmrcnt5: iopin $(TMRCNT5_TARGETS) $(TMRCNT5_HEADER)

twi: iopin $(TWI_TARGETS) $(TWI_HEADER)

twiInt: $(TWIINT_TARGETS) $(TWIINT_HEADER)

usart: $(USART_TARGETS) $(USART_HEADER)

clean:
	$(REMOVEDIR) $(OUTDIR)
	$(REMOVEDIR) $(OBJDIR)

# Create object files directory
$(shell mkdir -p $(OUTDIR))
$(shell mkdir -p $(OUTDIR_HEADER))

# Listing of phony.
.PHONY : all clean adc can errno extint spi iopin tmrcnt0 tmrcnt1 tmrcnt2 tmrcnt3 tmrcnt4 tmrcnt5 twi twiInt usart
