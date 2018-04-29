include mkfiles/cflags.mk

# default

default :
	$(MAKE) core

# rules

# commands

core :
	$(MAKE) -C lib
	$(MAKE) -C kernel

clean :
	$(MAKE) -C lib clean
	$(MAKE) -C kernel clean
