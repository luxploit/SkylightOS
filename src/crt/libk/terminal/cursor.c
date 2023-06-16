/* cursor.c
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/terminal/cursor.h>
#include <kernel/io/inx.h>
#include <kernel/io/outx.h>

void cursor_enable(uint8_t start, uint8_t end) {
    outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | end);
}

void cursor_disable() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void cursor_update(size_t width, int x, int y) {
    uint16_t pos = y * width + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

uint16_t cursor_get_position() {
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
}