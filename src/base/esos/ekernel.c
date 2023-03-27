// Codename "Esaul" Operating System - Copyright 2023 (c) Laura Raine;
// Licensed under AGPL-3.0 only

#include "../sdk/kernel/terminal/terminal.h"

void _esaul_kernel_entry() {
    terminal_initialize();
    terminal_writestring("Codename \"Esaul\" v0.0.1 (i386)\n");

}