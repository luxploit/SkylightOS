; crtn.asm
; Created on Tue Apr 04 2023 by Laura Raine (lnkexploit)
; Adding During Codename Phase: "Esaul"
; Copyright (c) 2023 - SkylightOS Project

section .init
global _init
_init:
	push ebp
	mov ebp, esp
	; crtbegin.o .init placed here by gcc

section .fini
global _fini
_fini:
	push ebp
	mov ebp, esp
	; crtbegin.o .fini placed here by gcc