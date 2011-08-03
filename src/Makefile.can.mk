# Hey Emacs, this is a -*- makefile -*-

CAN_DEVICES = at90can32
CAN_DEVICES += at90can64
CAN_DEVICES += at90can128
CAN_DEVICES += atmega32c1
CAN_DEVICES += atmega64c1
CAN_DEVICES += atmega16m1
CAN_DEVICES += atmega32m1
CAN_DEVICES += atmega64m1

CAN_OBJS=$(CAN_DEVICES:%=$(OBJDIR)/%/can.o)

CAN_TARGETS=$(CAN_DEVICES:%=$(OUTDIR)/%/libcan.a)

CAN_OBJDIRS=$(CAN_DEVICES:%=$(OBJDIR)/%)
CAN_OUTDIRS=$(CAN_DEVICES:%=$(OUTDIR)/%)

$(OBJDIR)/%/can.o : can.c can.h
	$(CC) -c -mmcu=$* $(ALL_CFLAGS) $< -o $@

$(OUTDIR)/%/libcan.a: $(CAN_OBJS)
	$(AR) $@ $(OBJDIR)/$*/can.o

# Create object files directory
$(shell mkdir -p $(CAN_OBJDIRS))
$(shell mkdir -p $(CAN_OUTDIRS))
