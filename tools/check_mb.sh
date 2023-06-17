#!/bin/bash

# update_osver.py
# Created on Mon March 27 2023 by Laura Raine (lnkexploit)
# Codename "Esaul" Operating System
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

if ! ( [[ $version =~ "2." || $version =~ "1.9" ]] ) then
   echo "ERR: GRUB2 is required"
   exit 1
fi

set -e

if ${prefix}file --is-x86-multiboot publish/sysroot/boot/chkernel.elf; then
	echo kernel is multiboot confirmed
else
	echo kernel failed multiboot test!
	exit 1
fi
