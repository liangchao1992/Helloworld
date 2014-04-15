OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
  FLASH        (rx) : ORIGIN = 0x00000000, LENGTH = 0x80000   /* 512K   --<>256k  (2^2)*(2^4)^4=2^18/2^10=2^8=256k Bytes */
  RAM_VECTOR  (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00400   /*   1k */
  RAM_BSSDATA (rwx) : ORIGIN = 0x20000400, LENGTH = 0x01c00   /*   7k */
  RAM_SYSTEM  (rwx) : ORIGIN = 0x20002000, LENGTH = 0x05000   /*  20k */
  RAM_USER    (rwx) : ORIGIN = 0x20007000, LENGTH = 0x01000   /*   4k */
  RAM_STACK   (rwx) : ORIGIN = 0x20008000, LENGTH = 0x00000   /*   0k */
                                                          /*sum:  32k */
}

ENTRY(reset_handler)

SECTIONS {
	. = 0x00000000;
	.text : 
	{
		*(.vector)
		PROVIDE(__kernel_text_start = .);
		*(.text)
		PROVIDE(__kernel_text_end = .);
		*(.rodata)
       		PROVIDE(__percpu_start = .);
        	*(.percpu)
        	PROVIDE(__percpu_end = .);

		PROVIDE(__start___param = .);
       		*(__param)
       	 	PROVIDE(__stop___param = .);
        	PROVIDE(__start___ksymtab = .);
        	PROVIDE(__stop___ksymtab = .);
        	PROVIDE(__start___ksymtab_gpl = .);
        	PROVIDE(__stop___ksymtab_gpl = .);
		*(__ksymtab)
        	*(__ksymtab_strings)
		*(.ARM.extab)
	} > FLASH
	
    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > FLASH
    __exidx_end = .;
    		
	__data_org = .;
	.data : AT(__data_org) 
	{
		__data_start = .;
		*(.data)
		__data_end = .;
	} > RAM_SYSTEM
	.bss : 
	{
		__bss_start = .;
		*(.bss)
		__bss_end = .;
		__end = .;
	} > RAM_SYSTEM		/*unsafe*/
	
    __stack_top = ORIGIN(RAM_STACK);
    PROVIDE(etext = .); /* Define the 'etext' symbol to this value */
    PROVIDE(end = .); /* Define the 'end' symbol to this value */
    PROVIDE(edata = .); /* Define the 'edata' symbol to this value */
    PROVIDE(__STAB_BEGIN__ = .);
    PROVIDE(__STAB_END__ = .);
    PROVIDE(__STABSTR_BEGIN__ = .);
    PROVIDE(__STABSTR_END__ = .);
 
   /DISCARD/ :
    {
        *(.eh_*)
    }
}
