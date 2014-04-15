#include <types.h>
#include <kio.h>
#include <stdio.h>
#include <string.h>
#include <mmu.h>
#include <memlayout.h>
#include <proc.h>
#include <pmm.h>
#include <buddy_pmm.h>
#include <sync.h>
#include <slab.h>
#include <swap.h>
#include <error.h>
#include <ide.h>
#include <trap.h>
#include <mp.h>
#include <ramdisk.h>

uint32_t do_set_tls(struct user_tls_desc *tlsp)
{
	return 0;
}


static Pagetable masterPT = { 0, 0, 0, MASTER, 0 };

static struct memmap masterMemmap = { 1,
	{
	 {SDRAM0_START, SDRAM0_SIZE, MEMMAP_MEMORY}
	 }
};

// virtual address of physicall page array
struct Page *pages;
// amount of physical memory (in pages)
size_t npage = 0;
unsigned long max_pfn;

static DEFINE_PERCPU_NOINIT(size_t, used_pages);
DEFINE_PERCPU_NOINIT(list_entry_t, page_struct_free_list);

// virtual address of boot-time page directory
pde_t *boot_pgdir = NULL;
// physical address of boot-time page directory
uintptr_t boot_pgdir_pa;

// physical memory management
const struct pmm_manager *pmm_manager;

size_t nr_used_pages(void)
{
	return 0;
}

void pmm_init_ap(void)
{
}

//alloc_pages - call pmm->alloc_pages to allocate a continuous n*PAGESIZE memory 
struct Page *alloc_pages(size_t n)
{
	return NULL;
}

//free_pages - call pmm->free_pages to free a continuous n*PAGESIZE memory 
void free_pages(struct Page *base, size_t n)
{
	return;
}

//nr_free_pages - call pmm->nr_free_pages to get the size (nr*PAGESIZE) 
//of current free memory
size_t nr_free_pages(void)
{
	return 0;
}



void __boot_map_iomem(uintptr_t la, size_t size, uintptr_t pa)
{
	return;
}


void pmm_init(void)
{
}

void tlb_invalidate(pde_t * pgdir, uintptr_t la)
{
}

void tlb_update(pgd_t * pgdir, uintptr_t la)
{
}

void tlb_invalidate_all()
{
}

void load_rsp0(uintptr_t esp0)
{
}

/**
 * set_pgdir - save the physical address of the current pgdir
 */
void set_pgdir(struct proc_struct *proc, pde_t * pgdir)
{
}
void map_pgdir(pde_t * pgdir)
{
}

//print_pgdir - print the PDT&PT
void print_pgdir(int (*printf) (const char *fmt, ...))
{
	printf("---------------------NO PAGE DIR ---------------------\n");
}

static uint32_t __current_ioremap_base = UCORE_IOREMAP_BASE;

void *__ucore_ioremap(unsigned long phys_addr, size_t size, unsigned int mtype)
{
	return;
}
