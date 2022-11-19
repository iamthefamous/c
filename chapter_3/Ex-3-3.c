#include <stdio.h>
#include <ctype.h>

#define MAXLEN 100000

char str[MAXLEN];
char expanded_str[MAXLEN];

int get_line(void);
void expand(void);

int main(void) {
    extern char expanded_str[];

    get_line();
    expand();

    printf("\t\tOUT\n\n");
    printf("%s",expanded_str);
}

int get_line(void){
    int i=0,c;
    extern char str[];

    while(i < MAXLEN - 1&& (c = getchar()) != EOF ) {
        str[i++] = c;
    }
    str[i] = '\0';

    return i;
}

void expand(void) {
    int i, j = 0;
    extern char str[];
    extern char expanded_str[];

    for(i = 0; i < MAXLEN - 1 && j < MAXLEN - 1 && str[i] != '\0'; ++i) {
        if(isalnum(str[i]) && str[i+1] == '-' && str[i] < str[i + 2]) {
            do {
                int k;
                for (k = 0; k <= (str[i + 2] - str[i]); ++k) {
                    int temp = str[i] + k;
                    expanded_str[j++] = temp;
                }

                i += 2;
            } while (isalnum(str[i]) && str[i] == '-' && str[i] < str[i + 2]);
        } else {
            expanded_str[j++] = str[i];
        }
        //printf("%d\n",isalnum(str[i]));
    }
    expanded_str[j] = '\0'; 
}
