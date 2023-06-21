/* strlen.c
 * Created on Fri Apr 07 2023 by Laura Raine (lnkexploit)
 * Added for Codename: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <string.h>

size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
 