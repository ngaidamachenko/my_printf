#include "my_printf.h"

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