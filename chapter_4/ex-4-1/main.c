#include <stdio.h>
#include "strindex.h"
#include "get_line.h"

#define LIMIT 10000

int main(void) {
    char str1[LIMIT];
    char str2[LIMIT];
    
    get_line("Enter your string : ", str1, LIMIT);
    get_line("Enter your string : ", str2, LIMIT);
    
    int index = strindex(str2,str1);

    printf("\t\tOUT\n\n");
    if(index == -1)
        printf("string \"%s\" does not contain string \"%s\"\n",str1,str2);
    else
        printf("string \"%s\" contain string \"%s\" in index %d\n",str1,str2,index);
    
    return 0;
}
