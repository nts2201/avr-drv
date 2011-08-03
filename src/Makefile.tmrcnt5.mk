# Hey Emacs, this is a -*- makefile -*-

TMRCNT5_DEVICES = atmega128rfa1
TMRCNT5_DEVICES += atmega640
TMRCNT5_DEVICES += atmega1280
TMRCNT5_DEVICES += atmega1281
TMRCNT5_DEVICES += atmega2560
TMRCNT5_DEVICES += atmega2561

TMRCNT5_OBJS=$(TMRCNT5_DEVICES:%=$(OBJDIR)/%/tmrcnt5.o)

TMRCNT5_TARGETS=$(TMRCNT5_DEVICES:%=$(OUTDIR)/%/libtmrcnt5.a)

TMRCNT5_OBJDIRS=$(TMRCNT5_DEVICES:%=$(OBJDIR)/%)
TMRCNT5_OUTDIRS=$(TMRCNT5_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/tmrcnt5.o : tmrcnt5.c tmrcnt5.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/libtmrcnt5.a: $(TMRCNT5_OBJS)
	$(AR) $@ $(OBJDIR)/$*/tmrcnt5.o

# Create object files directory
$(shell mkdir -p $(TMRCNT5_OBJDIRS))
$(shell mkdir -p $(TMRCNT5_OUTDIRS))
