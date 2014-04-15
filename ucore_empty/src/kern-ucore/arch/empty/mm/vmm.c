#include <vmm.h>
#include <string.h>
#include <mmu.h>
#include <stdio.h>
#include <kio.h>

bool
copy_from_user(struct mm_struct *mm, void *dst, const void *src, size_t len,
	       bool writable)
{
	return 0;

}

bool copy_to_user(struct mm_struct * mm, void *dst, const void *src, size_t len)
{
	return 0;
}

bool copy_string(struct mm_struct * mm, char *dst, const char *src, size_t maxn)
{
	return 0;
}
