/* inx.c
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/io/inx.h>

uint8_t inb(uint16_t port) {
    uint8_t _return;
    asm volatile("inb %1, %0" : "=a"(_return) : "Nd"(port));
    return _return;
}