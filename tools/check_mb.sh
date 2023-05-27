#!/bin/bash

if [ ! -f ./SConstruct ]; then
  echo "You are not running this script from the SkylightOS root directory. Please change to the SkylightOS root directory."
  exit 1
fi

echo "Checking grub version..."
dowehavegrub2=0
echo "Attempting to use grub2- prefix..."
output=$(grub2-install --version 2>/dev/null)
if [[ $output =~ "2." ]]; then
   echo "grub2 found"
   dowehavegrub2=1
   prefix="grub2-"
fi
# i have no idea why but grub 1.9x is also grub2
if [[ $output =~ "1.9" ]]; then
   echo "grub2 found"
   dowehavegrub2=1
   prefix="grub2-"
fi
if [ -z "$output" ]; then
echo "Attempting to use grub- prefix..."
output=$(grub-install --version 2>/dev/null)
if [[ $output =~ "2." ]]; then
   echo "grub2 found"
   dowehavegrub2=1
   prefix="grub-"
fi
# i have no idea why but grub 1.9x is also grub2
if [[ $output =~ "1.9" ]]; then
   echo "grub2 found"
   dowehavegrub2=1
   prefix="grub-"
fi
fi

if [ "$dowehavegrub2" -eq "0" ]; then
   echo "ERR: unable to find grub2";
   exit 1;
fi

set -e

if ${prefix}file --is-x86-multiboot publish/sysroot/boot/chkernel.elf; then
	echo kernel is multiboot confirmed
else
	echo kernel failed multiboot test!
	exit 1
fi
