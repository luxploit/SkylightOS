# Compiling SkylightOS

To acquire the required dependencies, run:
```bash
tools/resolve_deps.sh
```

List of available platforms for SkylightOS:
| Architecture | Configuration Name | QEMU Executable  | Status           |
|--------------|--------------------|------------------|------------------|
| x86 (32-bit) | ia32               | qemu-system-i386 | Work in Progress |

Before building SkylightOS, first set the following config options in tools/build/config.py:
```py
config=     # Build Configuration: chk = debug, fre = retail
arch=       # Build Architecture: see above for list of architectures.
```

Then to run the build, in the root directory, execute:
```bash
scons
```
or if you have scons installed via pip --user
```bash
~/.local/bin/scons
```

This will create `ekernel.elf`. This can be run directly in QEMU however it is recommended to package it inside of an ISO file with GRUB2 as the bootloader (for now).

To Create an ISO with GRUB2 pre-loaded, run the following command:
```bash
tools/build_iso.sh
```
**If you see "kernel failed multiboot test!", this means the compiled kernel is linked incorrectly and will not work**

To boot the kernel directly, run:
```bash
(qemu for your architecture) -kernel publish/sysroot/boot/ekernel.elf     
```

To boot the kernel via grub from the ISO, run:
```bash
(qemu for your architecture) -cdrom publish/skylight.iso                    
```

Congrats, you've successfully built SkylightOS.
