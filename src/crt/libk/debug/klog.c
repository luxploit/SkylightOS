/* klog.c
 * Created on Wed Apr 12 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/debug/klog.h>
#include <kernel/debug/kstdio.h>

#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>

#include <kernel/terminal/tty.h>
#include <kernel/terminal/vga.h>

void k_internal_print(enum vga_color color, const char* module, const char* message, __attribute__((unused))va_list args) {   
    kprintf("[ ");
    terminal_setcolor(vga_entry_color(color, VGA_COLOR_BLACK));
    kprintf("%s", module);
    terminal_setcolor(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK));
    kprintf(" ] %s\n", message);
    //TODO: Implement sprintf to handle va_list
}

void klog_info(const char* module, const char* message, ...) {
    va_list args;
    va_start(args, message);
    k_internal_print(VGA_COLOR_LIGHT_GREY, module, message, args);
    va_end(args);
}

void klog_warning(const char* module, const char* message, ...) {
    va_list args;
    va_start(args, message);
    k_internal_print(VGA_COLOR_LIGHT_RED | VGA_COLOR_LIGHT_GREEN, module, message, args);
    va_end(args);
}

void klog_error(const char* module, const char* message, ...) {
    va_list args;
    va_start(args, message);
    k_internal_print(VGA_COLOR_LIGHT_RED, module, message, args);
    va_end(args);
}

void klog_debug(const char* module, const char* message, ...) {
    va_list args;
    va_start(args, message);
    k_internal_print(VGA_COLOR_CYAN, module, message, args);
    va_end(args);
}

void klog_fatal(const char* module, const char* message, ...) {
    va_list args;
    va_start(args, message);
    k_internal_print(VGA_COLOR_RED, module, message, args);
    va_end(args);
}
