#include "my_printf.h"

int my_printf(char* specification, ...){
    va_list args;
    va_start(args, specification);
    int total_chars = 0;
    while(*specification != '\0'){
        if(*specification == '%'){
            specification++;
            switch(*specification){
                case 'd': {
                    int argument = va_arg(args, int); // need to convert doux from int into a string
                    total_chars += my_signed_decimal(argument);
                    break;
                }
                case 'o': {
                    unsigned int argument = va_arg(args, unsigned int);
                    total_chars += my_unsigned_oct(argument);
                    break;
                }
                case 'u': {
                    unsigned int argument = va_arg(args, unsigned int);
                    total_chars += my_unsigned_decimal(argument);
                    break;
                }
                case 'x': {
                    unsigned int argument = va_arg(args, unsigned int);
                    total_chars += my_unsigned_hex(argument);
                    break;
                }
                case 'c': {
                    char argument = (char)va_arg(args, int);
                    my_putchar(argument);
                    total_chars++;
                    break;
                }
                case 's': {
                    char* argument = va_arg(args, char*);
                    if(argument != NULL){
                        my_putstr(argument);
                        total_chars += strlen(argument);}
                    else{
                        my_putstr("(null)");
                        total_chars += 6;
                    }
                    break;
                }
                case 'p': {
                    void* argument = va_arg(args, void*);
                    total_chars += my_unsigned_hex_ptr((unsigned long int)(uintptr_t)argument);
                    break;
                }
                default:{
                    my_putchar(*specification);
                    total_chars++;
                    break;
                }
            }
        }
        else{
            my_putchar(*specification);
            total_chars++;
        }
        specification++;
    }
    va_end(args);
    return total_chars;
}
