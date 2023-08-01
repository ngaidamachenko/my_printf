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

int my_signed_decimal(int nbr){ //signed decimal | same as %i
    char buffer[32]; //size is 32 as it fits with all bases as well as 32 and 64 bit
    int index = 0;
    int count = 0;

    if(nbr == 0){
        my_putchar('0');
        count = 1;
    }
    else if (nbr < 0){
        nbr = -nbr;
        buffer[index++] = '-';
        count++;
    }
    while (nbr > 0){
        buffer[index++] = '0' + (nbr % 10);
        nbr /= 10;
        count++;
    }
    reverse_string(buffer);
    my_putstr(buffer);
    return count;
}

int my_unsigned_decimal(unsigned int nbr){ //unsigned decimal
    char buffer[32];
    int index = 0;
    int count  = 0;

    if(nbr == 0){
        my_putchar('0'); 
        count = 1;
    }
    while(nbr > 0){
        buffer[index++] = '0' + (nbr % 10); //decimal base uses 10 as its represenation | [i++] because we iterate each index within the buffer
        nbr /= 10; //nbr equals to assigned number divided by the decimal base
        count ++;
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
    return count; 
}


int my_unsigned_oct(unsigned int nbr){ //unsigned octal
    char buffer[32];
    int index = 0;
    int count = 0;

    if(nbr == 0){
        my_putchar('0'); 
        count = 1;
    }
    while(nbr>0){
        buffer[index++] = '0' + (nbr % 8); //octal base uses 8 as its represenation | [i++] because we iterate each index within the buffer
        nbr /= 8; //nbr equals to assigned number divided by the decimal base
        count++;
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
    return count;
}


int my_unsigned_hex(unsigned long int nbr){ //unsigned hexadecimal
    char buffer[32];
    size_t index = 0;
    int count = 0;

    if(nbr == 0){
        my_putchar('0'); 
        count = 1;
    }
    while(nbr>0){
        int digit = nbr % 16; //extracting a single hex digit from the nbr 
        count++;
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
    return count;
}

int my_unsigned_hex_ptr(unsigned long int nbr){ //unsigned hexadecimal
    char buffer[32];
    size_t index = 0;
    int count = 0;

    if (nbr == 0) {
        my_putchar('0');
        count = 1;
        return count;
    }
    
    while (nbr > 0) {
        int digit = nbr % 16;
        count++;
        if (digit < 10) {
            buffer[index++] = '0' + digit;
        } else {
            buffer[index++] = 'a' + digit - 10;
        }
        nbr /= 16;
    }

    buffer[index++] = 'x';
    buffer[index++] = '0';
    buffer[index] = '\0';
    reverse_string(buffer);
    my_putstr(buffer);
    return count + 2; // +2 for the "0x" prefix
}


/*void my_signed_bin(unsigned int nbr){ //binary 
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
}*/

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
                    //my_putstr("0x"); // to indicate that it's a hex representation of a pointer
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
