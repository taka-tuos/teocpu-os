include ../mkfiles/cflags.mk

OBJS = crt0.o main.o serial.o gpio.o timer.o libc_wrap.o memory.o

CFLAGS += -I. -I../include/

all : uImage

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.lst
	rm -f *.map
	rm -f uImage
	
%.o : %.c Makefile
	$(ARMGNU)-gcc -c $(CFLAGS) -o $*.o $*.c

%.o : %.s Makefile
	$(ARMGNU)-gcc -c $(CFLAGS) -o $*.o $*.s

uImage : memmap $(OBJS)
	$(ARMGNU)-ld $(OBJS) -L../lib/  -T memmap -Map uImage.map -lc -o uImage.elf
	$(ARMGNU)-objdump -D uImage.elf > uImage.lst
	$(ARMGNU)-objcopy uImage.elf -O binary uImage.bin 
	mkimage -A arm -O linux -C none  -T kernel -a 0x48000000 -e 0x48000000 -n 'teocpu-os' -d uImage.bin uImage






