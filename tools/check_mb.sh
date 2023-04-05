if grub2-file --is-x86-multiboot publish/sysroot/boot/chkernel.elf; then
	echo kernel is multiboot confirmed
else
	echo kernel failed multiboot test!
fi
