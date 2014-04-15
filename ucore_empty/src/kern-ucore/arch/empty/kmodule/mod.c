#include <elf.h>
#include <mod.h>

int
apply_relocate(struct secthdr *sechdrs, const char *strtab,
	       unsigned int symindex, unsigned int relindex,
	       struct module *module)
{
	return 0;
}

int
apply_relocate_add(struct secthdr *sechdrs, const char *strtab,
		   unsigned int symindex, unsigned int relsec,
		   struct module *module)
{
	return -1;
}
