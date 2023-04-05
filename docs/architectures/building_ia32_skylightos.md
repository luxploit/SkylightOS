# Building SkylightOS for IA32

Before building SkylightOS for IA32, first set the following tools/config.py options:
```py
config='chk/fre'                    # Build Configuration: chk = debug, fre = release
arch='ia32'                         # Build Architecture: ia32 = x86
image='bin'                         # Currently Unused, can be ignored
toolchain='/usr/local/bin/cross'    # Path to GCC target toolchain, see docs/building_gcc.md
```

Then to run the build, execute:
```bash
scons
```
or if you have scons installed via pip --user
```bash
~/.local/bin/scons
```

This will create chkernel.elf for checked (chk) or ekernel.elf for retail (fre) builds. This can be run directly in QEMU however it is recommended to package it inside of an ISO file with GRUB2 as the bootloader.

To Create an ISO with GRUB2 pre-loaded, run the following command:
```bash
tools/build_iso.sh
```
**If you see "kernel failed multiboot test!", this means the compiled kernel is linked incorrectly and will not work**

To boot the kernel directly, run:
```bash
qemu-system-i386 -kernel publish/sysroot/boot/chkernel.elf  # debug kernel
```
or
```bash
qemu-system-i386 -kernel publish/sysroot/boot/ekernel.elf   # retail kernel
```

To boot the kernel via grub from the ISO, run:
```bash
qemu-system-i386 -cdrom publish/skylight.iso                # debug build
```
*there are no retail iso builds as of now*

Congrats, you've successfully built SkylightOS for IA32 Hardware