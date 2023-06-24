/* bootstrap entry point for bootloaders */
ENTRY(_start)

/* define various sections of obj files for final image */
SECTIONS {
    . = 1M;                             /* begin sections at 1 mib */

    .text ALIGN(4K) : {       /* code sections */
        *(.multiboot .multiboot.*)
        *(.text .text.*)
    }

    .rodata ALIGN(4K) : {     /* read only data sections */
        *(.rodata .rodata.*)
    }

    .data ALIGN(4K) : {       /* read write data sections (initialized) */
        *(.data .data.*)
    }

    .bss ALIGN(4K) : {        /* read write data sections (uninitialized) */
        *(COMMON)
        *(.bss .bss.*)
    }

    /* add additional segments as needed */
}

