#include "my_printf.h"

void my_putchar(char c) {
  write(STDOUT_FILENO, &c, 1); //(1 - output on screen, variable - what to write, how many symbols will be displayed)
}

void my_putstr(char* c) {
    write(STDOUT_FILENO,c,strlen(c));
}