#include "my_printf.h"

int my_signed_decimal(int nbr){ //signed decimal | same as %i
    char buffer[32]; //size is 32 as it fits with all bases as well as 32 and 64 bit
    int index = 0;
    int count = 0;

    if(nbr == 0){
        my_putchar('0');
        count = 1;
        return count;
    }
    else if (nbr < 0){
        nbr = -nbr;
        my_putchar('-');
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