/* kprintf.c
 * Created on Tue Apr 11 2023 by Laura Raine (lnkexploit)
 * Codename "Esaul" Operating System
 * Copyright (c) 2023 - SkylightOS Project
*/

#include <kernel/debug/kstdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>

bool print(const char* data, size_t len) {
    const unsigned char* bytes = (const unsigned char*)(data);

    for (size_t ix = 0; ix < len; ix++) {
        if (kputchar(bytes[ix]) == EOF)
            return false;
    }

    return true;
}

int kprintf(const char* format, ...) {
    va_list params;
    va_start(params, format);

    int chars_written = 0;

    while (*format != '\0') {
        size_t maxrem = INT_MAX - chars_written;

        if (format[0] != '%' || format[1] == '%') {
            size_t amount = 1;
            
            if (format[0] == '%')
                format++;
            
            while (format[amount] && format[amount] != '%')
                amount++;
            
            if (maxrem < amount) {
                // TODO: Implement set errno to EOVERFLOW
                return -1;
            }

            if (!print(format, amount))
                return -1;

            format += amount;
            chars_written += amount;
            continue;
        }

        const char* format_begun_at = format++;

        if (*format == 'c') {
            format++;
            char _char = (char)(va_arg(params, int)); /*promote char to int*/

            if (!maxrem) {
                // TODO: Implement set errno to EOVERFLOW
                return -1;
            }

            if (!print(&_char, sizeof(_char)))
                return -1;

            chars_written++;
        } else if (*format == 's') {
            format++;
            const char* str = va_arg(params, const char*); /*promote char to const char(*)*/
            size_t len = strlen(str);

            if (maxrem < len) {
                // TODO: Implement set errno to EOVERFLOW
                return -1;
            }

            if (!print(str, len))
                return -1;

            chars_written += len;
        } else {
            format = format_begun_at;
            size_t len = strlen(format);

            if (maxrem < len) {
                 // TODO: Implement set errno to EOVERFLOW
                return -1;
            }

             if (!print(format, len))
                return -1;

            chars_written += len;
            format += len;
        }
    }

    va_end(params);
    return chars_written;
}