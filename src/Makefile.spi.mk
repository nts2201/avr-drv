# Hey Emacs, this is a -*- makefile -*-

SPI_DEVICES = at90can32
SPI_DEVICES += at90can64
SPI_DEVICES += at90can128
SPI_DEVICES += at90pwm1
SPI_DEVICES += at90pwm2
SPI_DEVICES += at90pwm2b
SPI_DEVICES += at90pwm3
SPI_DEVICES += at90pwm3b
SPI_DEVICES += at90pwm216
SPI_DEVICES += at90pwm316
SPI_DEVICES += at90usb82
SPI_DEVICES += at90usb162
SPI_DEVICES += at90usb646
SPI_DEVICES += at90usb647
SPI_DEVICES += at90usb1286
SPI_DEVICES += at90usb1287
SPI_DEVICES += atmega8
SPI_DEVICES += atmega8u2
SPI_DEVICES += atmega16
SPI_DEVICES += atmega16a
SPI_DEVICES += atmega16m1
SPI_DEVICES += atmega16u4
SPI_DEVICES += atmega32
SPI_DEVICES += atmega32c1
SPI_DEVICES += atmega32m1
SPI_DEVICES += atmega32u2
SPI_DEVICES += atmega32u4
SPI_DEVICES += atmega32u6
SPI_DEVICES += atmega48
SPI_DEVICES += atmega48a
SPI_DEVICES += atmega48p
SPI_DEVICES += atmega64
SPI_DEVICES += atmega64c1
SPI_DEVICES += atmega64m1
SPI_DEVICES += atmega88
SPI_DEVICES += atmega88a
SPI_DEVICES += atmega88p
SPI_DEVICES += atmega88pa
SPI_DEVICES += atmega128
SPI_DEVICES += atmega128rfa1
SPI_DEVICES += atmega161
SPI_DEVICES += atmega162
SPI_DEVICES += atmega163
SPI_DEVICES += atmega164p
SPI_DEVICES += atmega164a
SPI_DEVICES += atmega165
SPI_DEVICES += atmega165p
SPI_DEVICES += atmega168
SPI_DEVICES += atmega168a
SPI_DEVICES += atmega168p
SPI_DEVICES += atmega169
SPI_DEVICES += atmega169p
SPI_DEVICES += atmega169pa
SPI_DEVICES += atmega323
SPI_DEVICES += atmega324p
SPI_DEVICES += atmega324a
SPI_DEVICES += atmega324pa
SPI_DEVICES += atmega325
SPI_DEVICES += atmega325p
SPI_DEVICES += atmega328
SPI_DEVICES += atmega328p
SPI_DEVICES += atmega329
SPI_DEVICES += atmega329p
SPI_DEVICES += atmega329pa
SPI_DEVICES += atmega640
SPI_DEVICES += atmega644
SPI_DEVICES += atmega644a
SPI_DEVICES += atmega644p
SPI_DEVICES += atmega644pa
SPI_DEVICES += atmega645
SPI_DEVICES += atmega649
SPI_DEVICES += atmega649p
SPI_DEVICES += atmega1280
SPI_DEVICES += atmega1281
SPI_DEVICES += atmega1284p
SPI_DEVICES += atmega2560
SPI_DEVICES += atmega2561
SPI_DEVICES += atmega3250
SPI_DEVICES += atmega3250p
SPI_DEVICES += atmega3290
SPI_DEVICES += atmega3290p
SPI_DEVICES += atmega6450
SPI_DEVICES += atmega6490
SPI_DEVICES += atmega8535
SPI_DEVICES += attiny48
SPI_DEVICES += attiny88

SPI_OBJS=$(SPI_DEVICES:%=$(OBJDIR)/%/spi.o)

SPI_TARGETS=$(SPI_DEVICES:%=$(OUTDIR)/%/libspi.a)

SPI_OBJDIRS=$(SPI_DEVICES:%=$(OBJDIR)/%)
SPI_OUTDIRS=$(SPI_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/spi.o : spi.c spi.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/libspi.a: $(SPI_OBJS)
	$(AR) $@ $(OBJDIR)/$*/spi.o

# Create object files directory
$(shell mkdir -p $(SPI_OBJDIRS))
$(shell mkdir -p $(SPI_OUTDIRS))
