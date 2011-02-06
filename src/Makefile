# Hey Emacs, this is a -*- makefile -*-

include Makefile.mk
include Makefile.adc.mk
include Makefile.can.mk
include Makefile.errno.mk
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

all: iopin $(ADC_TARGETS) $(CAN_TARGETS) $(ERRNO_TARGETS) $(EXTINT_TARGETS) $(SPI_TARGETS) $(TMRCNT0_TARGETS) $(TMRCNT1_TARGETS) $(TMRCNT2_TARGETS) $(TMRCNT3_TARGETS) $(TMRCNT4_TARGETS) $(TMRCNT5_TARGETS) $(TWI_TARGETS) $(TWIINT_TARGETS) $(USART_TARGETS) 

adc: $(ADC_TARGETS)

iopin:
	mkdir -p $(OUTDIR)/inc/io_pin
	cp ../io_pin/* $(OUTDIR)/inc/io_pin

clean:
	$(REMOVE) $(ADC_TARGETS)
	$(REMOVE) $(ADC_OBJS)
	$(REMOVE) $(CAN_TARGETS)
	$(REMOVE) $(CAN_OBJS)
	$(REMOVE) $(ERRNO_TARGETS)
	$(REMOVE) $(ERRNO_OBJS)
	$(REMOVE) $(EXTINT_TARGETS)
	$(REMOVE) $(EXTINT_OBJS)
	$(REMOVE) $(SPI_TARGETS)
	$(REMOVE) $(SPI_OBJS)
	$(REMOVE) $(TMRCNT0_TARGETS)
	$(REMOVE) $(TMRCNT0_OBJS)
	$(REMOVE) $(TMRCNT1_TARGETS)
	$(REMOVE) $(TMRCNT1_OBJS)
	$(REMOVE) $(TMRCNT2_TARGETS)
	$(REMOVE) $(TMRCNT2_OBJS)
	$(REMOVE) $(TMRCNT3_TARGETS)
	$(REMOVE) $(TMRCNT3_OBJS)
	$(REMOVE) $(TMRCNT4_TARGETS)
	$(REMOVE) $(TMRCNT4_OBJS)
	$(REMOVE) $(TMRCNT5_TARGETS)
	$(REMOVE) $(TMRCNT5_OBJS)
	$(REMOVE) $(TWI_TARGETS)
	$(REMOVE) $(TWI_OBJS)
	$(REMOVE) $(TWIINT_TARGETS)
	$(REMOVE) $(TWIINT_OBJS)
	$(REMOVE) $(USART_TARGETS)
	$(REMOVE) $(USART_OBJS)


# Listing of phony.
.PHONY : all clean adc iopin
