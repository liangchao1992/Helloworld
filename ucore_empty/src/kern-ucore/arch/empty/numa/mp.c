#include <mp.h>
void *percpu_offsets[NCPU];
DEFINE_PERCPU_NOINIT(struct cpu, cpus);

void mp_set_mm_pagetable(struct mm_struct *mm)
{
}
void mp_tlb_invalidate(pgd_t * pgdir, uintptr_t la)
{
}

void mp_tlb_update(pgd_t * pgdir, uintptr_t la)
{
}
