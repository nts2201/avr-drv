# Hey Emacs, this is a -*- makefile -*-

TWI_DEVICES = at90can32
TWI_DEVICES += at90can64
TWI_DEVICES += at90can128
TWI_DEVICES += at90usb646
TWI_DEVICES += at90usb647
TWI_DEVICES += at90usb1286
TWI_DEVICES += at90usb1287
TWI_DEVICES += atmega16
TWI_DEVICES += atmega16a
TWI_DEVICES += atmega32
TWI_DEVICES += atmega32u4
TWI_DEVICES += atmega32u6
TWI_DEVICES += atmega48
TWI_DEVICES += atmega48a
TWI_DEVICES += atmega48p
TWI_DEVICES += atmega64
TWI_DEVICES += atmega88
TWI_DEVICES += atmega88a
TWI_DEVICES += atmega88p
TWI_DEVICES += atmega88pa
TWI_DEVICES += atmega128
TWI_DEVICES += atmega128rfa1
TWI_DEVICES += atmega164p
TWI_DEVICES += atmega164a
TWI_DEVICES += atmega168
TWI_DEVICES += atmega168a
TWI_DEVICES += atmega168p
TWI_DEVICES += atmega324p
TWI_DEVICES += atmega324a
TWI_DEVICES += atmega324pa
TWI_DEVICES += atmega328
TWI_DEVICES += atmega328p
TWI_DEVICES += atmega640
TWI_DEVICES += atmega644
TWI_DEVICES += atmega644a
TWI_DEVICES += atmega644p
TWI_DEVICES += atmega644pa
TWI_DEVICES += atmega1280
TWI_DEVICES += atmega1281
TWI_DEVICES += atmega1284p
TWI_DEVICES += atmega2560
TWI_DEVICES += atmega2561
TWI_DEVICES += attiny48
TWI_DEVICES += attiny88

#broken
#TWI_DEVICES += atmega8
#TWI_DEVICES += atmega16hvb
#TWI_DEVICES += atmega32hvb
#TWI_DEVICES += atmega163
#TWI_DEVICES += atmega323
#TWI_DEVICES += atmega406

TWI_OBJS=$(TWI_DEVICES:%=$(OBJDIR)/%/twi.o)

TWI_TARGETS=$(TWI_DEVICES:%=$(OUTDIR_LIB)/%/libtwi.a)

TWI_OBJDIRS=$(TWI_DEVICES:%=$(OBJDIR)/%)
TWI_OUTDIRS=$(TWI_DEVICES:%=$(OUTDIR_LIB)/%)

TWI_HEADER = $(OUTDIR_HEADER)/twi.h

$(OBJDIR)/%/twi.o : twi.c twi.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR_LIB)/%/libtwi.a: $(TWI_OBJS)
	$(AR) $@ $(OBJDIR)/$*/twi.o

# Create object files directory
$(shell mkdir -p $(TWI_OBJDIRS))
$(shell mkdir -p $(TWI_OUTDIRS))
