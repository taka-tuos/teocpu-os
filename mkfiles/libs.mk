include ../../mkfiles/cflags.mk

CFLAGS += -I. -I../../include

# default

default :
	$(MAKE) $(TARGET).a

# rules

$(TARGET).a : $(OBJS) Makefile
	ar rcs $(TARGET).a $(OBJS)
	cp $(TARGET).a ../

# normal rules

%.o : %.c Makefile
	$(GCC) $(CFLAGS) -I. -c -o $*.o $*.c

%.o : %.s Makefile
	$(GCC) -I. -c -o $*.o $*.s

# commands

clean :
	rm -f *.o
	rm -f $(TARGET).a
	rm -f ../$(TARGET).a
