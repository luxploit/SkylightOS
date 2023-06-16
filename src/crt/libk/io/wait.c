/* wait.c
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/io/wait.h>
#include <kernel/io/outx.h>

void io_wait() {
    outb(0x80, 0);
}