/* memcmp.c
 * Created on Sun Apr 09 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <string.h>

int memcmp(const void* ptr_a, const void* ptr_b, size_t len) {
    const unsigned char* point_a = (const unsigned char*)(ptr_a);
    const unsigned char* point_b = (const unsigned char*)(ptr_b);

    for (size_t ix = 0; ix < len; ix++) {
        if (point_a[ix] < point_b[ix])
            return -1;
        else if (point_b[ix] < point_a[ix])
            return 1;
    }

    return 0;
}