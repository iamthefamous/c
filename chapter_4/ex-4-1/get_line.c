#include "get_line.h"

void get_line(char out[], char str[], int limit){
    printf("%s",out);

    int i, c;

    for(i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i) {
        str[i] = c;
    }
    str[i] = '\0';
}
