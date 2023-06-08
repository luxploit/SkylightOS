#!/bin/bash

if [ ! -f ./SConstruct ]; then
   echo "You are not running this script from the SkylightOS root directory. Please change to the SkylightOS root directory."
   exit 1
fi

if [ -x "$(command -v grub2-install)" ]; then
   version=$(grub2-install --version)
   prefix="grub2-"
elif [ -x "$(command -v grub-install)" ]; then
   version=$(grub-install --version)
   prefix="grub-"
else
   echo "ERR: unable to find GRUB prefix"
   exit 1
fi

if ! ( [[ $version =~ "2." || $version =~ "1.9" ]] ) then
   echo "GRUB2 is required"
   exit 1
fi

set -e

rm -rf publish/sysroot
rm -f publish/skylight.iso
mkdir -p publish/sysroot/boot/grub
cp publish/intrim/grub.cfg publish/sysroot/boot/grub
cp bin/ia32_$(tools/update_osver.py read)/base/esos/chkernel.elf publish/sysroot/boot
tools/check_mb.sh

${prefix}mkrescue /usr/lib/grub/i386-pc -o publish/skylight.iso publish/sysroot
