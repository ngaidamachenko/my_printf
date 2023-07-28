#include "my_printf.h"

char* my_strcpy(char* dest, char* source){
    int i = 0;
    while (source[i]){ //while source[i] exists
        dest[i]=source[i]; //destination equals to the source
        i++; //iterate through the source to transfer the information to the destination
    }
    dest[i]='\0'; //add null character at the end 
    return dest; //return iterated destination with source info in it
}