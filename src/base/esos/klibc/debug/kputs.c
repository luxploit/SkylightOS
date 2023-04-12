/* kputs.c
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/debug/kstdio.h>
#include <kernel/terminal/tty.h>

int kputchar(int integer_char) {
    char _char = (char)(integer_char);
    terminal_write(&_char, sizeof(_char));

    return integer_char;
}

int kputs(const char* str) {
    return kprintf("%s\n", str);
}