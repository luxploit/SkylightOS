#!/bin/bash

if [ ! -f ./SConstruct ]; then
  echo "You are not running this script from the SkylightOS root directory. Please change to the SkylightOS root directory."
  exit 1
fi

qemu-system-i386 -cdrom publish/skylight.iso
