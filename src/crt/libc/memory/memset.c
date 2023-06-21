/* memset.c
 * Created on Sun Apr 09 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <string.h>

void* memset(void* buffer, int value, size_t len) {
    unsigned char* uc_buffer = (unsigned char*)(buffer);

    for (size_t ix = 0; ix < len; ix++) {
        uc_buffer[ix] = (unsigned char)(value);
    }

    return buffer;
}