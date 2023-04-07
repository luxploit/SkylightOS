/* bootstrap entry point for bootloaders */
ENTRY(_start)

/* define various sections of obj files for final image */
SECTIONS {
    . = 1M;                             /* begin sections at 1 mib */

    .text BLOCK(4K) : ALIGN(4K) {       /* code sections */
        *(.multiboot)
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K) {     /* read only data sections */
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K) {       /* read write data sections (initialized) */
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K) {        /* read write data sections (uninitialized) */
        *(COMMON)
        *(.bss)
    }

    /* add additional segments as needed */
}

