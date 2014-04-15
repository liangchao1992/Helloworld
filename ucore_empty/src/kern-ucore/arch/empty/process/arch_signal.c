/*
 * =====================================================================================
 *
 *       Filename:  arch_signal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2012 06:51:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Yuheng (Chen Yuheng), chyh1990@163.com
 *   Organization:  Tsinghua Unv.
 *
 * =====================================================================================
 */

#include <arch.h>
#include <mp.h>
#include <vmm.h>
#include <proc.h>
#include <slab.h>
#include <error.h>
#include "arch_signal.h"

// set user stack for signal handler, also set eip to handler
int __sig_setup_frame(int sign, struct sigaction *act, sigset_t oldset,
		      struct trapframe *tf)
{
	return 0;
}

// do syscall sigreturn, reset the user stack and eip
int do_sigreturn()
{
	return 0;
}
