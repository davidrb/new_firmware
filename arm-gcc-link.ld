OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
ENTRY(reset_handler)
MEMORY
{
	rom (rx)  : ORIGIN = 0x8000000, LENGTH = 256K
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 32K
}
SECTIONS {
    /* text section */
    .text : { 
        __vectors = .;
        KEEP(*(vectors)); 
        *(.text); 
        *(.text*); 
    }>rom

    .ARM.extab : {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > rom 

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
        __etext = .;
    } > rom 

    /* read only data section */
    .rodata : {
        *(.rodata);
        *(.rodata*);

        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP(*(SORT(.preinit_array.*)));
        KEEP(*(.preinit_array));
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP(*(SORT(.init_array.*)));
        KEEP(*(.init_array));
        __init_array_end = .;
    }>rom

    __rom_data_start = .;

    /* data section */
    .data : AT(__rom_data_start) {
        __ram_data_start = .;
        *(.data);
        *(.data*);

        __ram_data_end = .;
        __data_size = __ram_data_end - __ram_data_start;
    }>ram

    /* bss section */
    .bss : {
        __bss_start = .;
        KEEP(*(.bss*));
        __bss_end = .;
    }>ram


    . = ALIGN(4);
    __heap_start = .;
}
