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


#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>


void reverse_string(char* str){
    int i, j; //variables from both ends iterating through the string
    char temp; //stores temporary data
    for(i = 0, j=strlen(str)-1;i<j;i++,j--){ //iterating changes from both ends until they meet in the middle thus i<j
        temp = str[i]; //iterated first part 
        str[i] = str[j]; //iterated first part goes to the end 
        str[j] = temp; //iterated second part goes to the front
    }
    //return str; //returning reversed string
}

void my_putchar(char c) {
  write(STDOUT_FILENO, &c, 1); //(1 - output on screen, variable - what to write, how many symbols will be displayed)
}

void my_putstr(char* c) {
    write(1,c,strlen(c));
}

void my_signed_decimal(int nbr){ //signed decimal | same as %i
    char buffer[32]; //size is 32 as it fits with all bases as well as 32 and 64 bit
    int index = 0;
    if(nbr == 0){
        my_putchar('0');
        return;
        }
    else if (nbr < 0){
        nbr = -nbr;
        buffer[index++] = '-';
    }
    while (nbr > 0){
        buffer[index++] = '0' + (nbr % 10);
        nbr /= 10;
    }
    reverse_string(buffer);
    my_putstr(buffer);
}

void my_unsigned_decimal(unsigned int nbr){ //unsigned decimal
    char buffer[32];
    int index = 0;

    if(nbr == 0){
        my_putchar('0'); 
        return;
    }
    while(nbr > 0){
        buffer[index++] = '0' + (nbr % 10); //decimal base uses 10 as its represenation | [i++] because we iterate each index within the buffer
        nbr /= 10; //nbr equals to assigned number divided by the decimal base
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
}


void my_unsigned_oct(unsigned int nbr){ //unsigned octal
    char buffer[32];
    int index = 0;

    if(nbr == 0){
        my_putchar('0'); 
        return;
    }
    while(nbr>0){
        buffer[index++] = '0' + (nbr % 8); //octal base uses 8 as its represenation | [i++] because we iterate each index within the buffer
        nbr /= 8; //nbr equals to assigned number divided by the decimal base
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
}


void my_unsigned_hex(unsigned int nbr){ //unsigned hexadecimal
    char buffer[32];
    int index = 0;

    if(nbr == 0){
        my_putchar('0'); 
        return;
    }
    while(nbr>0){
        int digit = nbr % 16; //extracting a single hex digit from the nbr 
        if (digit < 10){
            buffer[index++] = '0' + digit; //hexadecimal base uses number 0-9 for its represenation in numbers and A-F for its representation in letters| [i++] because we iterate each index within the buffer
        }
        else{
            buffer[index++] = 'A' + digit - 10; //'A' represents 10 in ASCII table. We subract 10 to adjust for the calculated ASCII value 
        }
        
        nbr /= 16; //nbr equals to assigned number divided by the decimal base
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
}


void my_signed_bin(unsigned int nbr){ //binary 
    char buffer[32];
    int index = 0;

    if(nbr == 0){
        my_putchar('0'); 
        return;
    }
    while(nbr>0){
        buffer[index++] = '0' + (nbr % 2); //binary base uses 2 as its represenation | [i++] because we iterate each index within the buffer
        nbr /= 2; //nbr equals to assigned number divided by the decimal base
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
}

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
                    my_signed_decimal(argument);
                    total_chars ++;
                    break;
                }
                case 'o': {
                    unsigned int argument = va_arg(args, unsigned int);
                    my_unsigned_oct(argument);
                    total_chars ++;
                    break;
                }
                case 'u': {
                    unsigned int argument = va_arg(args, unsigned int);
                    my_unsigned_decimal(argument);
                    total_chars ++;
                    break;
                }
                case 'x': {
                    unsigned int argument = va_arg(args, unsigned int);
                    my_unsigned_hex(argument);
                    total_chars ++;
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
                    my_putstr(argument);
                    total_chars += strlen(argument);
                    break;
                }
                case 'p': {
                    void* argument = va_arg(args, void*);
                    my_putstr("0x"); // to indicate that it's a hex representation of a pointer
                    my_unsigned_hex((unsigned long int)argument);
                    total_chars += strlen(argument);
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
