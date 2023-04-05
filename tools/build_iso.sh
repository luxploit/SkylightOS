rm -r publish/sysroot
rm publish/skylight.iso
mkdir -p publish/sysroot/boot/grub
cp publish/intrim/grub.cfg publish/sysroot/boot/grub
cp build/ia32_chk/base/esos/chkernel.elf publish/sysroot/boot
grub2-mkrescue /usr/share/grub2/i386-pc -o publish/skylight.iso publish/sysroot