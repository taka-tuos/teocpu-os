#include "timer.h"
#include "gpio.h"
#include "serial.h"
#include "memory.h"

#include <stdio.h>

int __entry(unsigned int sp)
{
	struct MEMMAN *memman = (struct MEMMAN *) MEMMAN_ADDR;
	memman_init(memman);
	memman_free(memman, 0x50000000, (2UL * 1024UL * 1024UL * 1024UL) - 0x10000000);
	
	uart_init();
	
	puts("hello,world\r");
	
	led_init();
	
	while(1) {
		puts("ON1\r");
		status_on();
		ms_delay(200);
		puts("OFF1\r");
		status_off();
		ms_delay(200);
		puts("ON2\r");
		status_on();
		ms_delay(200);
		puts("OFF2\r");
		status_off();
		ms_delay(1000);
	}
	
	return 0;
}
