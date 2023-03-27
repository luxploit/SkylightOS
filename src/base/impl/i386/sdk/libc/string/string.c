// Codename "Esaul" Operating System - Copyright 2023 (c) Laura Raine;
// Licensed under AGPL-3.0 only

#include "../../../../../sdk/libc/string/string.h"

size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}