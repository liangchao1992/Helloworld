/*
 * =====================================================================================
 *
 *       Filename:  picirq.c
 *
 *    Description:  Vectored Interrupt Controller (VIC) PL190 support
 *
 *        Version:  1.0
 *        Created:  03/25/2012 08:40:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Yuheng (Chen Yuheng), chyh1990@163.com
 *   Organization:  Tsinghua Unv.
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <types.h>
#include <arm.h>
#include <picirq.h>
#include <clock.h>
#include <serial.h>
#include <intr.h>
#include <kio.h>
#include <assert.h>
#include <memlayout.h>

enum {
	INTERRUPT_STATUS = 0x00,	// number of pending interrupts
	INTERRUPT_NUMBER = 0x04,
	INTERRUPT_DISABLE_ALL = 0x08,
	INTERRUPT_DISABLE = 0x0c,
	INTERRUPT_ENABLE = 0x10
};

static bool did_init = 0;
#define VIC_VBASE __io_address(GOLDFISH_VIC_BASE)

void pic_disable(unsigned int irq)
{
}

void pic_enable(unsigned int irq)
{
}

struct irq_action {
	ucore_irq_handler_t handler;
	void *opaque;
};

struct irq_action actions[32];

void register_irq(int irq, ucore_irq_handler_t handler, void *opaque)
{
}

/* pic_init
 * initialize the interrupt, but doesn't enable them */
void pic_init(void)
{

}

void irq_handler()
{
}

/* irq_clear
 * 	Clear a pending interrupt request
 *  necessary when handling an irq */
void irq_clear(unsigned int source)
{
}
