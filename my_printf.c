/* what am i supposed to do ?! :(
1. Push function output to stdout
2. Function to specify how subsequent arguments are converted for output 
- Google variable-length argument facilities of stdarg(3))
- What's a format string?
3. my_cpy to copy characters unchanged directly to the output
4. Conversion specification (PERCENTAGE):
    doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
    c The int argument is converted to an unsigned char, and the resulting character is written.
    s The char * argument is expected to be a pointer to an array of character type (pointer to a string). 
      Characters from the array are written up to (but not including) a terminating NUL character.
    p The void * pointer argument is printed in hexadecimal.
5. Malloc

Try using itoa to convert intergers into a string
*/

#include "my_printf.h"

void my_printf(char* specification, ...){
    va_list args;
    va_start(args, specification);
    while(*specification != '\0'){
        if(*specification == '%'){
            specification++;
            switch(*specification){
                case 'd': {
                    int argument = va_arg(args, int); // need to convert doux from int into a string
                    my_signed_decimal(argument);
                    break;
                }
                case 'o': {
                    unsigned int argument = va_arg(args, unsigned int);
                    my_unsigned_oct(argument);
                    break;
                }
                case 'u': {
                    unsigned int argument = va_arg(args, unsigned int);
                    my_unsigned_decimal(argument);
                    break;
                }
                case 'x': {
                    unsigned int argument = va_arg(args, unsigned int);
                    my_unsigned_hex(argument);
                    break;
                }
                case 'c': {
                    char argument = (char)va_arg(args, int);
                    my_putchar(argument);
                    break;
                }
                case 's': {
                    char* argument = va_arg(args, char*);
                    my_putstr(argument);
                    break;
                }
                case 'p': {
                    void* argument = va_arg(args, void*);
                    my_putstr("0x"); // to indicate that it's a hex representation of a pointer
                    my_unsigned_hex((unsigned long int)argument);
                    break;
                }
                default:{
                    my_putchar(*specification);
                }
            }
        }
        else{
            my_putchar(*specification);
        }
        specification++;
    }
    va_end(args);
}

int main() {
    int nbr = 65;
    unsigned int unnbr = 0;
    unsigned int unnbr_1 = 15;
    unsigned int unnbr_2 = 48;
    char c = 'A';
    char* str = "Hello World\n";
    void* ptr = &nbr;

    my_printf("Signed Integer: %d\n", nbr);
    my_printf("Unsigned octal: %o\n", unnbr);
    my_printf("Unsigned octal: %o\n", unnbr_2);
    my_printf("Unsigned decimal: %u\n", unnbr);
    my_printf("Unsigned hex: %x\n", unnbr_1);
    my_printf("Unsigned hex: %x\n", unnbr_2);
    my_printf("Char: %c\n", c);
    my_printf("String: %s\n", str);
    my_printf("The Holy Pointer: %p\n", ptr);
}