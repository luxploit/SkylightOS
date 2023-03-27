Project Structure
```
.
├── Makefile
├── README.md
├── src
│   └── base
│       ├── esos
│       │   └── ekernel.c
│       ├── impl
│       │   └── i386
│       │       ├── boot
│       │       │   └── multiboot.asm
│       │       └── sdk
│       │           ├── string
│       │           │   └── string.c
│       │           └── terminal
│       │               └── terminal.c
│       └── sdk
│           ├── string
│           │   └── string.h
│           └── terminal
│               └── terminal.h
├── target
│   ├── build
│   │   ├── ekernel.o
│   │   ├── memory_ops.o
│   │   ├── multiboot.o
│   │   ├── string.o
│   │   └── terminal.o
│   ├── config
│   │   └── i386_linker.ld
│   ├── image
│   │   └── boot
│   │       ├── esaul.bin
│   │       └── grub
│   │           └── grub.cfg
│   ├── publish
│   │   └── esaul.iso
│   └── test
│       └── esaul.bin
└── tools
    ├── check_mb2
    ├── compile
    ├── iso
    └── vm
```