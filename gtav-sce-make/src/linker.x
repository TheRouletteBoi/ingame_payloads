OUTPUT_FORMAT("elf64-powerpc")
OUTPUT_ARCH(powerpc:common64)

__base = 0xABC00000;

ENTRY(_start)

PHDRS {
    stage1		PT_LOAD FLAGS(7);
}

SECTIONS {
    . = __base;
    __self_start = .;

    .start : { *(.start) } :stage1 = 0

    . = ALIGN(8);
    .text : {
        *(.text)
        *(.text.*)
    }
    .rodata : {
        *(.rodata)
        *(.rodata.*)
    }

    __reloc_start = 0x88ED42CD01541111;

    .data : {
        *(.data)
        *(.data.*)
        *(.sdata)
        *(.sdata.*)
    }
    
    .bss : {
        *(.sbss)
        *(.sbss.*)
        *(COMMON)
        *(.bss)
        *(.bss.*)
        LONG(0)
    }
    
    . = ALIGN(8);
    __toc_start = .;
    __toc = . + 0x8000;
    .toc : {
        *(.toc)
        *(.toc.*)
    }
    __toc_end = .;		
    __opd_start = .;
    .opd : {
        *(.opd)
        *(.opd.*)
    }
    __opd_end = .;
    __reloc_end = 0xAADEFFEE97123654;

    __self_end = .;	
}



