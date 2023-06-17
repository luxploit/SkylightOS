/* memmove.c
 * Created on Sun Apr 09 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <string.h>

void* memmove(void* dst, const void* src, size_t len) {
    unsigned char* uc_dst       = (unsigned char*)      (dst);
    const unsigned char* uc_src = (const unsigned char*)(src);

    if (uc_dst < uc_src) {
        for (size_t ix = 0; ix < len; ix++) {
            uc_dst[ix] = uc_src[ix];
        }
    }
    else {
        for (size_t jx = len; jx != 0; jx--) {
            uc_dst[jx - 1] = uc_src[jx - 1];
        }
    }

    return dst;
}