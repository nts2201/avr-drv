# Hey Emacs, this is a -*- makefile -*-

ADC_DEVICES = at90can32
ADC_DEVICES += at90can64
ADC_DEVICES += at90can128
ADC_DEVICES += at90pwm1
ADC_DEVICES += at90pwm2
ADC_DEVICES += at90pwm2b
ADC_DEVICES += at90pwm3
ADC_DEVICES += at90pwm3b
ADC_DEVICES += at90pwm81
ADC_DEVICES += at90pwm216
ADC_DEVICES += at90pwm316
ADC_DEVICES += at90usb646
ADC_DEVICES += at90usb647
ADC_DEVICES += at90usb1286
ADC_DEVICES += at90usb1287
ADC_DEVICES += atmega8
ADC_DEVICES += atmega16
ADC_DEVICES += atmega16a
ADC_DEVICES += atmega16m1
ADC_DEVICES += atmega16u4
ADC_DEVICES += atmega32
ADC_DEVICES += atmega32c1
ADC_DEVICES += atmega32m1
ADC_DEVICES += atmega32u4
ADC_DEVICES += atmega32u6
ADC_DEVICES += atmega48
ADC_DEVICES += atmega48a
ADC_DEVICES += atmega48p
ADC_DEVICES += atmega64
ADC_DEVICES += atmega64c1
ADC_DEVICES += atmega64m1
ADC_DEVICES += atmega88
ADC_DEVICES += atmega88a
ADC_DEVICES += atmega88p
ADC_DEVICES += atmega88pa
ADC_DEVICES += atmega103
ADC_DEVICES += atmega128
ADC_DEVICES += atmega128rfa1
ADC_DEVICES += atmega164p
ADC_DEVICES += atmega164a
ADC_DEVICES += atmega165
ADC_DEVICES += atmega165p
ADC_DEVICES += atmega168
ADC_DEVICES += atmega168a
ADC_DEVICES += atmega168p
ADC_DEVICES += atmega169
ADC_DEVICES += atmega169a
ADC_DEVICES += atmega169p
ADC_DEVICES += atmega169pa
ADC_DEVICES += atmega324p
ADC_DEVICES += atmega324a
ADC_DEVICES += atmega324pa
ADC_DEVICES += atmega325
ADC_DEVICES += atmega325p
ADC_DEVICES += atmega328p
ADC_DEVICES += atmega328
ADC_DEVICES += atmega329
ADC_DEVICES += atmega329p
ADC_DEVICES += atmega329pa
ADC_DEVICES += atmega640
ADC_DEVICES += atmega644
ADC_DEVICES += atmega644a
ADC_DEVICES += atmega644p
ADC_DEVICES += atmega644pa
ADC_DEVICES += atmega645
ADC_DEVICES += atmega645a
ADC_DEVICES += atmega645p
ADC_DEVICES += atmega649
ADC_DEVICES += atmega649a
ADC_DEVICES += atmega649p
ADC_DEVICES += atmega1280
ADC_DEVICES += atmega1281
ADC_DEVICES += atmega1284p
ADC_DEVICES += atmega2560
ADC_DEVICES += atmega2561
ADC_DEVICES += atmega3250
ADC_DEVICES += atmega3250p
ADC_DEVICES += atmega3290
ADC_DEVICES += atmega3290p
ADC_DEVICES += atmega6450
ADC_DEVICES += atmega6450a
ADC_DEVICES += atmega6450p
ADC_DEVICES += atmega6490
ADC_DEVICES += atmega6490a
ADC_DEVICES += atmega6490p
ADC_DEVICES += atmega8535
ADC_DEVICES += attiny13
ADC_DEVICES += attiny13a
ADC_DEVICES += attiny24
ADC_DEVICES += attiny24a
ADC_DEVICES += attiny25
ADC_DEVICES += attiny43u
ADC_DEVICES += attiny44
ADC_DEVICES += attiny44a
ADC_DEVICES += attiny45
ADC_DEVICES += attiny48
ADC_DEVICES += attiny84
ADC_DEVICES += attiny85
ADC_DEVICES += attiny88
ADC_DEVICES += attiny87
ADC_DEVICES += attiny167
ADC_DEVICES += attiny261
ADC_DEVICES += attiny261a
ADC_DEVICES += attiny461
ADC_DEVICES += attiny861
ADC_DEVICES += attiny861a

#Broken device
#ADC_DEVICES += attiny26
#ADC_DEVICES += atmega323
#ADC_DEVICES += atmega163

ADC_OBJS=$(ADC_DEVICES:%=$(OBJDIR)/%/adcCommun.o)
ADC_OBJS+=$(ADC_DEVICES:%=$(OBJDIR)/%/adcDigitalInput.o)
ADC_OBJS+=$(ADC_DEVICES:%=$(OBJDIR)/%/adcMux.o)
ADC_OBJS+=$(ADC_DEVICES:%=$(OBJDIR)/%/adcTriggerSelect.o)

ADC_TARGETS=$(ADC_DEVICES:%=$(OUTDIR_LIB)/%/libadc.a)

ADC_OBJDIRS=$(ADC_DEVICES:%=$(OBJDIR)/%)
ADC_OUTDIRS=$(ADC_DEVICES:%=$(OUTDIR_LIB)/%)

ADC_HEADER = $(OUTDIR_HEADER)/adc.h
ADC_HEADER += $(OUTDIR_HEADER)/adcDef.h

$(OBJDIR)/%/adcCommun.o : adcCommun.c adcDef.h adc.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@ 

$(OBJDIR)/%/adcDigitalInput.o : adcDigitalInput.c adcDef.h adc.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OBJDIR)/%/adcMux.o : adcMux.c adcDef.h adc.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OBJDIR)/%/adcTriggerSelect.o : adcTriggerSelect.c adcDef.h adc.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR_LIB)/%/libadc.a: $(ADC_OBJS)
	$(AR) $@ $(OBJDIR)/$*/adcCommun.o $(OBJDIR)/$*/adcDigitalInput.o $(OBJDIR)/$*/adcMux.o $(OBJDIR)/$*/adcTriggerSelect.o

# Create object files directory
$(shell mkdir -p $(ADC_OBJDIRS))
$(shell mkdir -p $(ADC_OUTDIRS))
