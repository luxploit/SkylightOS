/* vga.c
 * Created on Sun Apr 02 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/terminal/vga.h>

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}