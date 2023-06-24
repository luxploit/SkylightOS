/* tty.c
 * Created on Sun Apr 02 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/terminal/tty.h>
#include <kernel/terminal/vga.h>
#include <kernel/terminal/cursor.h>
#include <memory.h>

static const size_t terminal_vga_width = 80;
static const size_t terminal_vga_height = 25;
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize() {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < terminal_vga_height; y++) {
		for (size_t x = 0; x < terminal_vga_width; x++) {
			const size_t index = y * terminal_vga_width + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}

	cursor_enable(10, 12);
}
 
void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * terminal_vga_width + x;

	if (index >= terminal_vga_width * terminal_vga_height)
		return;

	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_scroll() {
	// scroll up
	size_t buffer_len = (terminal_vga_height - 1)* terminal_vga_width;
	memmove(terminal_buffer, terminal_buffer + terminal_vga_width, buffer_len * 2);

	// clear last
	size_t last_row = terminal_vga_height - 1;
	for (size_t ix = 0; ix < terminal_vga_width; ix++) {
		terminal_putentryat(' ', terminal_color, ix, last_row);
	}
}

void terminal_putchar(char c) {
	if (c == '\n') {
		if (terminal_row + 1 == terminal_vga_height) {
			terminal_scroll();
			terminal_color = 0;
		}
		else {
			terminal_row++;
			terminal_column = 0;
		}
		return;
	}

	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	cursor_update(terminal_vga_width, terminal_column + 1, terminal_row);
	if (++terminal_column == terminal_vga_width) {
		terminal_column = 0;
		if (++terminal_row == terminal_vga_height)
			terminal_scroll();
	}
}
 
void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}