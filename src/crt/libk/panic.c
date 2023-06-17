/* abort.c
 * Created on Sun Apr 09 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/debug/kstdio.h>
#include <kernel/debug/klog.h>
#include <kernel/panic.h>

__attribute__((__noreturn__)) void panic() {
    kputs("");
    klog_fatal("kernel", "panic()");
    asm volatile("hlt");

    __builtin_unreachable();
}