#include <board.h>
#include <types.h>
#include <stdio.h>
#include <kio.h>
#include <kdebug.h>
#include <string.h>
#include <console.h>
#include <picirq.h>
#include <trap.h>
#include <clock.h>
#include <intr.h>
#include <pmm.h>
#include <vmm.h>
#include <ide.h>
#include <swap.h>
#include <proc.h>
#include <assert.h>
#include <atomic.h>
#include <mp.h>
#include <sched.h>
#include <fs.h>
#include <sync.h>
#include <ramdisk.h>
#include <kgdb-stub.h>
#include <module.h>
#include <dde_kit/dde_kit.h>

#ifdef UCONFIG_HAVE_YAFFS2
#include <yaffs2_direct/yaffsfs.h>
#endif

#ifdef printf
#undef printf
#endif

#ifdef DEBUG
#define _PROBE_() kprintf("PROBE %s: %d\n", __FILE__, __LINE__);
#else
#define _PROBE_()
#endif

// Very important:
// At the boot, exceptions handlers have not been defined
// Copy the address of exceptions handlers (defined in vectors.S) to 0x24 
// (or Ox20 if we decide to change reset handler)
// XXX it works only when 0x0 is a sram/sdram
extern char __vector_table, __vector_table_end;
static inline void exception_vector_init(void)
{
	memcpy((void *)SDRAM0_START, (void *)&__vector_table,
	       &__vector_table_end - &__vector_table);
}

int kern_init(void) __attribute__ ((noreturn));


int kern_init(void)
{
	board_init();
}
