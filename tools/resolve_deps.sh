#!/bin/bash

# resolve_deps.sh
# Created on Sun Jun 25 2023 by Laura Raine (lnkexploit)
# Added for Codename: "Esaul"
# Copyright (c) 2023 - SkylightOS Project

echo "resolving dependencies via package manager"

if [ -x "$(command -v zypper)" ]; then
    sudo zypper -n in nasm clang binutils lld python311 python311-pip xorriso qemu grub2
elif [ -x "$(command -v emerge)" ]; then
    sudo emerge dev-lang/nasm sys-devel/clang sys-devel/binutils sys-devel/lld dev-lang/python dev-python/pip sys-boot/grub dev-libs/libisoburn app-emulation/qemu
elif [ -x "$(command -v apt)" ]; then
    sudo apt install -y nasm clang-15 lld-15 binutils python3 python3-pip qemu qemu-kvm grub2 xorriso
elif [ -x "$(command -v dnf)" ]; then
    sudo dnf install nasm clang binutils lld python3 python3-pip xorriso qemu grub2
elif [ -x "$(command -v pacman)" ]; then
    sudo pacman -Sy --noconfirm nasm clang python python-pip lld binutils libisoburn grub qemu-full
elif [ -x "$(command -v xbps)" ]; then
    sudo xbps-install -Sy nasm clang lld binuitls python3 python3-pip xorriso grub qemu
else
    echo "[Error]: Unable to resolve dependencies. Please install the following: nasm, clang, lld, binutils, python3 (3.10 minimum), python3-pip, qemu, xorriso, grub2"
    exit 1
fi    

echo "installing scons via pip"
sudo pip install scons