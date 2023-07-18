#!/bin/bash

# build_iso.sh
# Created on Thu May 4 2023 by Laura Raine (lnkexploit)
# Added for Codename: "Esaul"
# Copyright (c) 2023 - SkylightOS Project

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

if [ -x "$(command -v zypper)" ]; then # dirty hack for grub path
   mkpath="/usr/share/grub2/i386-pc"
else
   mkpath="/usr/lib/grub/i386-pc"
fi

if ! ( [[ $version =~ "2." || $version =~ "1.9" ]] ) then
   echo "ERR: GRUB2 is required"
   exit 1
fi

set -e

rm -rf publish/sysroot
rm -f publish/skylight.iso
mkdir -p publish/sysroot/boot/grub
cp publish/intrim/grub.cfg publish/sysroot/boot/grub
cp bin/$(tools/build/new_osver.py read_arch)_$(tools/build/new_osver.py read_config)/base/esos/ekernel.elf publish/sysroot/boot
tools/check_mb.sh

${prefix}mkrescue ${mkpath} -o publish/skylight.iso publish/sysroot
