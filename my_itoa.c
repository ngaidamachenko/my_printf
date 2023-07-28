#include "my_printf.h"

void my_putnbr(int nbr){ //signed decimal
    char buffer[32]; //size is 32 as it fits with all bases as well as 32 and 64 bit
    if(nbr == 0){
        my_putchar("0");
        return;
        }
    else if (nbr < 0){
        nbr = -nbr;
        my_putchar(nbr);
        return;
    }
    else if (nbr >= 10){
        nbr = nbr % 10;
    }
    else if (nbr < 10 && nbr != 0){
        nbr = nbr+48;
        
    }
    my_putchar(nbr);
}

void my_unsgined_decimal(unsigned int nbr){ //unsigned decimal
    char buffer[32];
    int index = 0;

    if(nbr == 0){
        my_putchar("0"); 
        return;
    }
    while(nbr>0){
        buffer[index++] = '0' + (nbr % 10); //decimal base uses 10 as its represenation | [i++] becasue we iterate each index within the buffer
        nbr /= 10; //nbr equals to assigned number divided by the decimal base
    }
    buffer[index] = '\0';//to account for null character
    reverse_string(buffer);
    my_putstr(buffer);
}


void my_putunsoct(int nbr){ //unsigned octal

}


void my_putunshex(int nbr){ //unsigned hexadecimal

}


void my_putbin(int nbr){ //binary 

}

