/* ekernel.c
 * Created on Sun Apr 02 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

/*
section .rodata
    esos_arch       db  "IA32", 0           ; OS rchitecture Information
    esos_version    db  "0.0.0.0"           ; OS Build Version Numbering
    esos_codename   db  "Esaul"             ; OS Working Title Codename
    esos_debug      db  "master(raine)"     ; Misc. OS Information

; A full version string looks something like this (stolen from microsoft):
; 4.0.2456.2.mips64le(fre).private/mips_speed(skvbl03).20280305-1800
; Major.Minor.Build.Revision.Architecture(Config Suffix).Branch(builduser).YYYYMMDD-HHMM
; this is found in src/crt/sdk/system/osver.h
*/

#include <kernel/panic.h>
#include <kernel/terminal/tty.h>
#include <kernel/debug/kstdio.h>
#include <kernel/debug/klog.h>
#include <sysinfo.h>
#include <kernel/fpu.h>

#include "test.h"

int dowehavefpu = 0;

void _esaul_kernel_entry() {

    terminal_initialize();
    kputs("Welcome to SkylightOS!");
    kputs("Sponsored by clang-15 /s");

    if (detectfpu() == "0") {
        kputs("No FPU detected");
        dowehavefpu = 0;
    } else if (detectfpu() == "1") {
        kputs("FPU detected, good");
        dowehavefpu = 1;
    } else {
        kputs("Inconsistent kernel state!");
        panic();
    }

    sysinfo_display();

    test_logger();

    panic();
}
