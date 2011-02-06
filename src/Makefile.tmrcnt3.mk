# Hey Emacs, this is a -*- makefile -*-

TMRCNT3_DEVICES = at90can32
TMRCNT3_DEVICES += at90can64
TMRCNT3_DEVICES += at90can128
TMRCNT3_DEVICES += at90usb646
TMRCNT3_DEVICES += at90usb647
TMRCNT3_DEVICES += at90usb1286
TMRCNT3_DEVICES += at90usb1287
TMRCNT3_DEVICES += atmega128rfa1
TMRCNT3_DEVICES += atmega640
TMRCNT3_DEVICES += atmega1280
TMRCNT3_DEVICES += atmega1281
TMRCNT3_DEVICES += atmega2560
TMRCNT3_DEVICES += atmega2561

TMRCNT3_OBJS=$(TMRCNT3_DEVICES:%=$(OBJDIR)/%/tmrcnt3.o)

TMRCNT3_TARGETS=$(TMRCNT3_DEVICES:%=$(OUTDIR)/%/tmrcnt3.a)

TMRCNT3_OBJDIRS=$(TMRCNT3_DEVICES:%=$(OBJDIR)/%)
TMRCNT3_OUTDIRS=$(TMRCNT3_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/tmrcnt3.o : tmrcnt3.c tmrcnt3.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/tmrcnt3.a: $(TMRCNT3_OBJS)
	$(AR) $@ $(OBJDIR)/$*/tmrcnt3.o

# Create object files directory
$(shell mkdir -p $(TMRCNT3_OBJDIRS))
$(shell mkdir -p $(TMRCNT3_OUTDIRS))
