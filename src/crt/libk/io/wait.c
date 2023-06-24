/* wait.c
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/io/wait.h>
#include <kernel/io/outx.h>

void io_wait() {
    outb(0x80, 0);
}