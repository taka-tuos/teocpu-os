#include "gpio.h"
#include "serial.h"

struct h3_uart {
	volatile unsigned int data;	/* 00 */
	volatile unsigned int ier;	/* 04 */
	volatile unsigned int iir;	/* 08 */
	volatile unsigned int lcr;	/* 0c */
	int _pad;
	volatile unsigned int lsr;	/* 04 */
};

#define dlh	ier
#define dll	data

#define TX_READY	0x40

void
uart_init ( void )
{
	struct h3_uart *up = UART_BASE;

	uart_gpio_init();
	uart_clock_init();

	up->lcr = 0x80;		/* select dll dlh */

	up->dlh = 0;
	up->dll = BAUD_115200;

	up->lcr = LC_8_N_1;
}

void
uart_putc ( char c )
{
	struct h3_uart *up = UART_BASE;

	while ( !(up->lsr & TX_READY) )
	    ;
	up->data = c;
}

void
uart_puts ( char *s )
{
	while ( *s ) {
	    if (*s == '\n')
		uart_putc('\r');
	    uart_putc(*s++);
	}
}

void
uart_puts_with_len ( char *s, int len )
{
	while ( len ) {
	    if (*s == '\n')
		uart_putc('\r');
	    uart_putc(*s++);
	    len--;
	}
}
/* THE END */
