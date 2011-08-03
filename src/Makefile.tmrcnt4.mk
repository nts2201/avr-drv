# Hey Emacs, this is a -*- makefile -*-

TMRCNT4_DEVICES = atmega128rfa1
TMRCNT4_DEVICES += atmega640
TMRCNT4_DEVICES += atmega1280
TMRCNT4_DEVICES += atmega1281
TMRCNT4_DEVICES += atmega2560
TMRCNT4_DEVICES += atmega2561

TMRCNT4_OBJS=$(TMRCNT4_DEVICES:%=$(OBJDIR)/%/tmrcnt4.o)

TMRCNT4_TARGETS=$(TMRCNT4_DEVICES:%=$(OUTDIR)/%/libtmrcnt4.a)

TMRCNT4_OBJDIRS=$(TMRCNT4_DEVICES:%=$(OBJDIR)/%)
TMRCNT4_OUTDIRS=$(TMRCNT4_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/tmrcnt4.o : tmrcnt4.c tmrcnt4.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/libtmrcnt4.a: $(TMRCNT4_OBJS)
	$(AR) $@ $(OBJDIR)/$*/tmrcnt4.o

# Create object files directory
$(shell mkdir -p $(TMRCNT4_OBJDIRS))
$(shell mkdir -p $(TMRCNT4_OUTDIRS))
