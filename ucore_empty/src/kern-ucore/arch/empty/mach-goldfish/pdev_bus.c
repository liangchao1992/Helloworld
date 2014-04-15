/*
 * =====================================================================================
 *
 *       Filename:  pdev_bus.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/2012 02:45:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Yuheng (Chen Yuheng), chyh1990@163.com
 *   Organization:  Tsinghua Unv.
 *
 * =====================================================================================
 */

#include <board.h>
#include <arm.h>
#include <stdio.h>
#include <pdev_bus.h>
#include <serial.h>
#include <clock.h>
#include <string.h>

struct pdev_device {
	uint32_t id, base, size, irq, irq_count, name_len;
	uint32_t state;
	char name[64];
};

static int pdev_device_init(struct pdev_device *dev)
{
}

void pdev_bus_init()
{

}
