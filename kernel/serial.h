#ifndef __H3_SERIAL_H__
#define __H3_SERIAL_H__

#define UART0_BASE	0x01C28000
#define UART_BASE	((struct h3_uart *) UART0_BASE)

#define BAUD_115200    (0xD) /* 24 * 1000 * 1000 / 16 / 115200 = 13 */

#define NO_PARITY      (0)
#define ONE_STOP_BIT   (0)
#define DAT_LEN_8_BITS (3)
#define LC_8_N_1       (NO_PARITY << 3 | ONE_STOP_BIT << 2 | DAT_LEN_8_BITS)

void uart_init ( void );
void uart_putc ( char c );
void uart_puts ( char *s );
void uart_puts_with_len ( char *s, int len );

#endif
