#include <types.h>
#include <kio.h>
#include <mmu.h>
#include <string.h>
#include <pmm.h>


/* Page Tables */
/* VADDRESS, PTADDRESS, MASTERPTADDRESS, PTTYPE, DOM */
//static Pagetable masterPT = {0x30700000, 0x30700000, 0x30700000, MASTER, 0};
/* Regions */
/* vAddress, pageSize, numPages, AP, CB, pAddress, PT */
// note: for now, no cached, otherwise the interrupt doesn't finish
//static Region masterRegion = {0x00000000, SECTIONPAGE, 4096, PTE_RWNA, PTE_cb, 0x00000000, &masterPT};

/* mmuInitPT
 * Initialize a page table by filling it with fault PTE */
int mmu_init_pdt(Pagetable * pt)
{
	return -1;
}

void mmu_init(void)
{
}
