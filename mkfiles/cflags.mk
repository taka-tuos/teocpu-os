ARMGNU   = arm-linux-gnueabihf
MAKE     = make -r
GCC      = $(ARMGNU)-gcc
LD       = $(ARMGNU)-ldv

CFLAGS = -fno-builtin -Os -mcpu=cortex-a7
CFLAGS += -fno-common -nostdlib -nostdinc -nostartfiles -nodefaultlibs 
CFLAGS += -fno-pie -mfloat-abi=hard -mfpu=neon -ffast-math
CFLAGS += -ffreestanding -fno-stack-protector
