/* cursor.h
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Adding During Codename Phase: "Esaul"
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <stdint.h>
#include <stddef.h>

void cursor_enable(uint8_t start, uint8_t end);
void cursor_disable();
void cursor_update(size_t width, int x, int y);
uint16_t cursor_get_position();