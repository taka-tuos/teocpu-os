#ifndef __H3_GPIO_H__
#define __H3_GPIO_H__

#define GPIO_A    0
#define GPIO_B    1
#define GPIO_C    2
#define GPIO_D    3
#define GPIO_E    4
#define GPIO_F    5
#define GPIO_G    6
#define GPIO_H    7
#define GPIO_I    8
#define GPIO_L    9	/* R_PIO */

/* Only A, G, and R can interrupt */

/* GPIO pin function config (0-7) */
#define GPIO_INPUT        (0)
#define GPIO_OUTPUT       (1)
#define H3_GPA_UART0      (2)
#define H5_GPA_UART0      (2)
#define GPIO_DISABLE      (7)

/* GPIO pin pull-up/down config (0-3)*/
#define GPIO_PULL_DISABLE	(0)
#define GPIO_PULL_UP		(1)
#define GPIO_PULL_DOWN		(2)
#define GPIO_PULL_RESERVED	(3)

void gpio_config ( int gpio, int pin, int val );
void gpio_pull ( int gpio, int pin, int val );
void gpio_output ( int gpio, int pin, int val );
int gpio_input ( int gpio, int pin );
void uart_gpio_init ( void );
void led_init ( void );
void led_on ( void );
void led_off ( void );
void status_on ( void );
void status_off ( void );
void uart_clock_init ( void );

#endif
