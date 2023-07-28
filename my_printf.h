#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

void reverse_string(char* str); // we don't need to return it
void my_putchar(char c);
void my_putstr(char* str);
void my_signed_decimal(int nbr);
void my_unsigned_decimal(unsigned int nbr);
void my_unsigned_oct(unsigned int nbr);
void my_unsigned_hex(unsigned int nbr);
void my_signed_bin(unsigned int nbr);
void my_printf(char* specification, ...);

#endif /* MY_PRINTF_H */
