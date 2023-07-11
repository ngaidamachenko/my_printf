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
*/
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#include "my_printf.h"

void my_putchar(char c) {
    write(1, &c, 1);
}


void my_printf(char* specification, ...){
    va_list args;
    va_start(args, specification);
    while(*specification != '\0'){
        if(*specification == '%'){
            specification++;
            switch(*specification){
                case 'd':{
                    int argument = va_copy(args, int);
                    write(STDOUT_FILENO, argument, 1);
                    break;
                }
                case 'o':{
                    unsigned char argument = va_copy(args, unsigned char);
                    break;
                }
                case 'u':{
                    int argument = va_copy(args, int);
                    break;
                }
                case 'x':{
                    int argument = va_copy(args, int);
                    break;
                }
                case 'c':{
                    char argument = (char)va_copy(args, int);
                    write(STDOUT_FILENO, &argument, 1);
                    break;
                }
                case 's':{
                    char* argument = va_copy(args, char*);
                    write(STDOUT_FILENO, argument, strlen(argument));
                    break;
                }
                case 'p':{
                    void argument = va_copy(args, void);
                    write(int __fd, argument, size_t __n);
                    break;
                }
            }
            my_putchar(*specification);
        }
        specification++;
    }
    va_end(args);
}
