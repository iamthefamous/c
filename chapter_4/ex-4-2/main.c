#include <stdio.h>
#include "atof.h"
#include "get_line.h"

#define LIMIT 10000

int main(void) {
    char number[LIMIT];

    get_line("Enter your number : ", number, LIMIT);
    atof(number);

    printf("\n\t\tOUT\n\n");
    printf("%s\n",number);

    return 0;
}
