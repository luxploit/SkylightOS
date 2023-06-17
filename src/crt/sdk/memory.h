/* memory.h
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <stddef.h>

int memcmp(const void* ptr_a, const void* ptr_b, size_t len);
void* memcpy(void* dst, const void* src, size_t len);
void* memmove(void* dst, const void* src, size_t len);
void* memset(void* buffer, int value, size_t len);