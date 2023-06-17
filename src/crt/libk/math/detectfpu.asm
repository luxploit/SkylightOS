; detectfpu.asm
; Created on Fri Jun 16 2023 by Seal Sealy (seal331)
; Codename "Esaul" Operating System
; Copyright (c) 2023 - SkylightOS Project

global detectfpu:function (detectfpu.end - detectfpu)

detectfpu:
    MOV EDX, CR0                            ; Start probe, get CR0
    AND EDX, (-1) - (0x00000008 + 0x00000004)       ; clear TS and EM to force fpu access
    MOV CR0, EDX                            ; store control word
    FNINIT                                  ; load defaults to FPU
    FNSTSW [.testword]                      ; store status word
    CMP word [.testword], 0                 ; compare the written status with the expected FPU state
    JNE .nofpu                              ; jump if the FPU hasn't written anything (i.e. it's not there)
    JMP .hasfpu

.nofpu:
    extern _esaul_nofpu
    call _esaul_nofpu
    ret

.hasfpu:
    extern _esaul_hasfpu
    call _esaul_hasfpu
    ret

.testword: DW 0x55AA                    ; store garbage to be able to detect a change
.end:
