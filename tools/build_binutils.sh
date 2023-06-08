#!/bin/bash
set -e

if [ ! -f ./tooldir.stamp ]; then
  echo "You are not running this script from the SkylightOS tools directory. Please change to the SkylightOS tools directory."
  exit 1
fi

# wget check
echo "Performing required tools check..."
# TODO: implement curl support (even tho i never use it personally)
if ! [ -x "$(command -v wget)" ]; then
  echo 'Error: wget is not installed.' >&2
  exit 1
fi
echo "Required tools check passed."

# random variables
BINUTILS_VERSION="2.40"
TARGET="i686-elf"
TOOLCHAIN_PWD=${PWD}/../toolchain

# work starts here
rm -rf $TOOLCHAIN_PWD
mkdir $TOOLCHAIN_PWD
cd $TOOLCHAIN_PWD

# actual compile
echo "Compiling binutils for ${TARGET} version ${BINUTILS_VERSION}..."

rm -f binutils-${BINUTILS_VERSION}.tar.gz
wget https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.gz
tar -xvf binutils-${BINUTILS_VERSION}.tar.gz
mkdir binutils-compile
cd binutils-compile
$TOOLCHAIN_PWD/binutils-${BINUTILS_VERSION}/configure --target=${TARGET} --prefix="$TOOLCHAIN_PWD/toolchain-binaries" --with-sysroot --disable-nls --disable-werror
make -j$(nproc)
make -j$(nproc) install
echo "Compiling successful."
