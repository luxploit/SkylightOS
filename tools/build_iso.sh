rm -r publish/sysroot
rm publish/skylight.iso
mkdir -p publish/sysroot/boot/grub
cp publish/intrim/grub.cfg publish/sysroot/boot/grub
cp build/ia32_chk/base/esos/chkernel.elf publish/sysroot/boot
tools/check_mb.sh
grub2-mkrescue /usr/lib/grub/i386-pc -o publish/skylight.iso publish/sysroot