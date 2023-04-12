/* memcpy.c
 * Created on Sun Apr 09 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <string.h>

void* memcpy(void* dst, const void* src, size_t len) {
    unsigned char* uc_dst       = (unsigned char*)      (dst);
    const unsigned char* uc_src = (const unsigned char*)(src);

    for (size_t ix = 0; ix < len; ix++) {
        uc_dst[ix] = uc_src[ix];
    }

    return dst;
}