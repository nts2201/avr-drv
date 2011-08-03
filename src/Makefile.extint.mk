# Hey Emacs, this is a -*- makefile -*-

EXTINT_DEVICES = at90can32
EXTINT_DEVICES += at90can64
EXTINT_DEVICES += at90can128
EXTINT_DEVICES += at90pwm1
EXTINT_DEVICES += at90pwm2
EXTINT_DEVICES += at90pwm2b
EXTINT_DEVICES += at90pwm3
EXTINT_DEVICES += at90pwm3b
EXTINT_DEVICES += at90pwm216
EXTINT_DEVICES += at90pwm316
EXTINT_DEVICES += at90usb82
EXTINT_DEVICES += at90usb162
EXTINT_DEVICES += at90usb646
EXTINT_DEVICES += at90usb647
EXTINT_DEVICES += at90usb1286
EXTINT_DEVICES += at90usb1287
EXTINT_DEVICES += atmega8u2
EXTINT_DEVICES += atmega16hva2
EXTINT_DEVICES += atmega16hvb
EXTINT_DEVICES += atmega16m1
EXTINT_DEVICES += atmega16u4
EXTINT_DEVICES += atmega32c1
EXTINT_DEVICES += atmega32hvb
EXTINT_DEVICES += atmega32m1
EXTINT_DEVICES += atmega32u2
EXTINT_DEVICES += atmega32u4
EXTINT_DEVICES += atmega32u6
EXTINT_DEVICES += atmega48
EXTINT_DEVICES += atmega48a
EXTINT_DEVICES += atmega48p
EXTINT_DEVICES += atmega64
EXTINT_DEVICES += atmega64c1
EXTINT_DEVICES += atmega64hve
EXTINT_DEVICES += atmega64m1
EXTINT_DEVICES += atmega88
EXTINT_DEVICES += atmega88a
EXTINT_DEVICES += atmega88p
EXTINT_DEVICES += atmega88pa
EXTINT_DEVICES += atmega128
EXTINT_DEVICES += atmega128rfa1
EXTINT_DEVICES += atmega164p
EXTINT_DEVICES += atmega164a
EXTINT_DEVICES += atmega165
EXTINT_DEVICES += atmega165p
EXTINT_DEVICES += atmega168
EXTINT_DEVICES += atmega168a
EXTINT_DEVICES += atmega168p
EXTINT_DEVICES += atmega169
EXTINT_DEVICES += atmega169a
EXTINT_DEVICES += atmega169p
EXTINT_DEVICES += atmega169pa
EXTINT_DEVICES += atmega324p
EXTINT_DEVICES += atmega324a
EXTINT_DEVICES += atmega324pa
EXTINT_DEVICES += atmega325
EXTINT_DEVICES += atmega325p
EXTINT_DEVICES += atmega328
EXTINT_DEVICES += atmega328p
EXTINT_DEVICES += atmega329
EXTINT_DEVICES += atmega329p
EXTINT_DEVICES += atmega329pa
EXTINT_DEVICES += atmega406
EXTINT_DEVICES += atmega640
EXTINT_DEVICES += atmega644
EXTINT_DEVICES += atmega644a
EXTINT_DEVICES += atmega644p
EXTINT_DEVICES += atmega644pa
EXTINT_DEVICES += atmega645
EXTINT_DEVICES += atmega645a
EXTINT_DEVICES += atmega645p
EXTINT_DEVICES += atmega649
EXTINT_DEVICES += atmega649a
EXTINT_DEVICES += atmega649p
EXTINT_DEVICES += atmega1280
EXTINT_DEVICES += atmega1281
EXTINT_DEVICES += atmega1284p
EXTINT_DEVICES += atmega2560
EXTINT_DEVICES += atmega2561
EXTINT_DEVICES += atmega3250
EXTINT_DEVICES += atmega3250p
EXTINT_DEVICES += atmega3290
EXTINT_DEVICES += atmega3290p
EXTINT_DEVICES += atmega6450
EXTINT_DEVICES += atmega6450a
EXTINT_DEVICES += atmega6450p
EXTINT_DEVICES += atmega6490
EXTINT_DEVICES += atmega6490a
EXTINT_DEVICES += atmega6490p
EXTINT_DEVICES += attiny48
EXTINT_DEVICES += attiny88
EXTINT_DEVICES += attiny87
EXTINT_DEVICES += attiny167

EXTINT_OBJS=$(EXTINT_DEVICES:%=$(OBJDIR)/%/extint.o)

EXTINT_TARGETS=$(EXTINT_DEVICES:%=$(OUTDIR)/%/libextint.a)

EXTINT_OBJDIRS=$(EXTINT_DEVICES:%=$(OBJDIR)/%)
EXTINT_OUTDIRS=$(EXTINT_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/extint.o : extint.c extint.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/libextint.a: $(EXTINT_OBJS)
	$(AR) $@ $(OBJDIR)/$*/extint.o

# Create object files directory
$(shell mkdir -p $(EXTINT_OBJDIRS))
$(shell mkdir -p $(EXTINT_OUTDIRS))

# Listing of phony EXTINT_TARGETS.
.PHONY : all clean
