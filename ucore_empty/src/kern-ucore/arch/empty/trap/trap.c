#include <types.h>
#include <mmu.h>
#include <memlayout.h>
#include <clock.h>
#include <trap.h>
#include <arm.h>
#include <stdio.h>
#include <assert.h>
#include <console.h>
#include <vmm.h>
#include <proc.h>
#include <sched.h>
#include <unistd.h>
#include <kio.h>
#include <picirq.h>
#include <syscall.h>
#include <error.h>
#include <signal.h>
#include <kgdb-stub.h>

#define TICK_NUM 5

//handle hw irq, should be implemented in mach_xxx
void irq_handler(void);
static int __irq_level = 0;

static const char *trapname(int trapno)
{
	static const char *const excnames[] = {
		"Reset",
		"Undefined instruction",
		"Software interrupt",
		"Prefetch abort",
		"Data abort",
		"Reserved",
		"Interrupt request",
		"Fast interrupt request"
	};

	if (trapno < sizeof(excnames) / sizeof(const char *const)) {
		return excnames[trapno];
	}
	if (trapno == T_SYSCALL) {
		return "System call";
	}
	if (trapno >= IRQ_OFFSET && trapno <= IRQ_OFFSET + IRQ_MAX_RANGE) {
		return "Hardware Interrupt";
	}
	return "(unknown trap)";
}

static const char *const modenames[] = {
	"User",
	"FIQ",
	"IRQ",
	"Supervisor",
	"", "", "",
	"Abort",
	"", "", "",
	"Undefined",
	"", "", "",
	"System"
};

/* trap_in_kernel - test if trap happened in kernel */
bool trap_in_kernel(struct trapframe *tf)
{
	return 0;
}

void print_trapframe(struct trapframe *tf)
{
}

void print_regs(struct pushregs *regs)
{
}

static inline void print_pgfault(struct trapframe *tf)
{
}

static int pgfault_handler(struct trapframe *tf)
{
	return 0;
}

static void killed_by_kernel()
{
}

static int udef_handler(struct trapframe *tf)
{
	return 0;
}

/* trap_dispatch - dispatch based on what type of trap occurred */
static void trap_dispatch(struct trapframe *tf)
{
}

static int __is_irq(struct trapframe *tf)
{
	return (tf->tf_trapno == T_IRQ);
}

/* *
 * trap - handles or dispatches an exception/interrupt. if and when trap() returns,
 * the code in kern/trap/trapentry.S will restore the state before the exception.
 * */
void trap(struct trapframe *tf)
{
}

/* eabi compiler */
void raise(void)
{
	return;
}

int ucore_in_interrupt()
{
	return __irq_level;
}
