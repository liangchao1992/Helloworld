/*
 * =====================================================================================
 *
 *       Filename:  versatilepd_uart.c
 *
 *    Description:  PL011 driver
 *
 *        Version:  1.0
 *        Created:  03/17/2012 02:43:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Yuheng (Chen Yuheng), chyh1990@163.com
 *   Organization:  Tsinghua Unv.
 *
 * =====================================================================================
 */

#include <types.h>
#include <arm.h>
#include <stdio.h>
#include <kio.h>
#include <string.h>
#include <sync.h>
#include <board.h>
#include <picirq.h>

static bool serial_exists = 0;
static uint32_t uart_base = GOLDFISH_UART0;
/* from qemu-android */
enum {
	TTY_PUT_CHAR = 0x00,
	TTY_BYTES_READY = 0x04,
	TTY_CMD = 0x08,

	TTY_DATA_PTR = 0x10,
	TTY_DATA_LEN = 0x14,

	TTY_CMD_INT_DISABLE = 0,
	TTY_CMD_INT_ENABLE = 1,
	TTY_CMD_WRITE_BUFFER = 2,
	TTY_CMD_READ_BUFFER = 3,
};

static uint8_t tty_buffer[4];

static int serial_int_handler(int irq, void *data)
{
	return 0;
}

void serial_init_early()
{
}

void uart_init(void);
uint8_t uart_recvchar(void);
void uart_sendchar(uint8_t c);


void serial_init(uint32_t base, uint32_t irq)
{
	uart_init();//reuse the one from mb9bf506r.
}

static void serial_putc_sub(int c)
{
	
}

/* serial_putc - print character to serial port */
void serial_putc(int c)
{
	uart_sendchar(c);//resue the one form mb9bf506r
}

/* serial_proc_data - get data from serial port */
int serial_proc_data(void)
{
	return 0;
}

int serial_check()
{
	return 0;
}

void serial_clear()
{
}
