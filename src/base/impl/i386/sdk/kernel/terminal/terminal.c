// Codename "Esaul" Operating System - Copyright 2023 (c) Laura Raine;
// Licensed under AGPL-3.0 only

#include "../../../../../sdk/kernel/terminal/terminal.h"
#include "../../../../../sdk/libc/string/string.h"
#include <stddef.h>
#include <stdint.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

void terminal_initialize() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }
}

void terminal_setcolor(uint8_t color) {
    terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
    switch (c) {
        case '\n':
            ++terminal_row;
            terminal_column = 0;
            break;
        case '\t':
            terminal_column += 4;
            break;
        default:
            terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
            ++terminal_column;
    }

    if (terminal_column >= VGA_WIDTH) {
        terminal_column = 0;
        ++terminal_row;
    }

    if (terminal_row >= VGA_HEIGHT) {
        size_t ix, jx;
        for (ix = 0; ix < VGA_WIDTH - 1; ix++) {
            for (jx = VGA_HEIGHT - 2; jx > 0; jx--) {
                terminal_buffer[(jx * VGA_WIDTH) + ix] = terminal_buffer[((jx + 1) * VGA_WIDTH) + ix];
            }
        }

        for (ix = 0; ix < VGA_WIDTH - 1; ix++) {
            terminal_putentryat(' ', terminal_color, ix, VGA_HEIGHT - 1);
        }

        terminal_row = VGA_HEIGHT - 1;
    }
}

void terminal_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        terminal_putchar(data[i]);
}

void terminal_writestring(const char* data) {
    terminal_write(data, strlen(data));
}