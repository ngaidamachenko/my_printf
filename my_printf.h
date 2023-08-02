#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

void reverse_string(char* str);
void my_putchar(char c);
void my_putstr(char* c);
int my_signed_decimal(int nbr);
int my_unsigned_decimal(unsigned int nbr);
int my_unsigned_oct(unsigned int nbr);
int my_unsigned_hex(unsigned long int nbr);
int my_unsigned_hex_ptr(unsigned long int nbr);
int my_printf(char* specification, ...);

#endif // MY_PRINTF_H
