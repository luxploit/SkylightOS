ASM=nasm
CC=/usr/local/bin/cross/bin/i686-elf-gcc

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LFLAGS=-ffreestanding -O2 -nostdlib -lgcc

SRC_DIR=src
TOOLS_DIR=tools
TARGET_DIR=target
BUILD_DIR=target/build

.PHONY: all kernel deploy

all: deploy

deploy: $(TARGET_DIR)/publish/esaul.iso

$(TARGET_DIR)/publish/esaul.iso: kernel
	rm $(TARGET_DIR)/image/boot/esaul.bin
	cp $(TARGET_DIR)/test/esaul.bin $(TARGET_DIR)/image/boot/esaul.bin
	grub2-mkrescue -o $(TARGET_DIR)/publish/esaul.iso $(TARGET_DIR)/image/
	$(TOOLS_DIR)/check_mb2

kernel:
	$(ASM) -felf32 $(SRC_DIR)/base/impl/i386/boot/multiboot.asm -o $(TARGET_DIR)/build/multiboot.o
	$(CC) -c $(SRC_DIR)/base/impl/i386/sdk/libc/string/string.c -o $(TARGET_DIR)/build/string.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/base/impl/i386/sdk/kernel/terminal/terminal.c -o $(TARGET_DIR)/build/terminal.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/base/esos/ekernel.c -o $(TARGET_DIR)/build/ekernel.o $(CFLAGS)
	$(CC) -T $(TARGET_DIR)/config/i386_linker.ld -o $(TARGET_DIR)/test/esaul.bin $(BUILD_DIR)/multiboot.o $(BUILD_DIR)/string.o $(BUILD_DIR)/terminal.o $(BUILD_DIR)/ekernel.o $(LFLAGS)