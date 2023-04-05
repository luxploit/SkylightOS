; entry.asm
; Created on Sun Apr 02 2023 by Laura Raine (lnkexploit)
; Codename "Esaul" Operating System
; Copyright (c) 2023 - SkylightOS Project

; Declare multiboot header constants
MBALIGN  equ 1 << 0                         ; align loaded modules on page boundaries
MEMINFO  equ 1 << 1                         ; provide memory map
MBFLAGS  equ MBALIGN | MEMINFO              ; multiboot flag field
MAGICNUM equ 0x1badb002                     ; 1 Bad Boot - Multiboot Magic Number
CHECKSUM equ -(MAGICNUM + MBFLAGS)          ; checksum for magic number + flags inverted, proves multiboot

; Declare aligned multiboot header
section .multiboot
align 4
    dd MAGICNUM
    dd MBFLAGS
    dd CHECKSUM

; Declare Stack
section .bss
align 16
    stack_bottom:
        resb 16384                          ; reserve 16kb for the stack
    stack_top:

; Boostrap entry point
section .text
global _start:function (_start.end - _start)
_start:
    mov esp, stack_top                      ; position stack pointer at the top of the stack
    extern _esaul_kernel_entry              ; define kernel main entry point
    call _esaul_kernel_entry                ; call kernel entrypoint

    cli                                     ; clear interrupts
.hang:
    hlt                                     ; halt execution
    jmp .hang                               ; incase it ever escapes the halt, halt it again.
.end: