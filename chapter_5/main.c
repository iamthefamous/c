#include <stdio.h>
#include "alloc.c"

int main(void){
    char *message = "hello, ";
    char *messageEnd = "World!!";
    strCat(message, messageEnd);
    
    printf("%s",*messageEnd);
    return 0;
}
