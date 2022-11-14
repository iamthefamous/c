#include <stdio.h>
#define MAXSIZE 1000000

char inLine[MAXSIZE];
char outLine[MAXSIZE];

void getLine(void);
void fold_copy(void);

/*fold long lines program: specialized version */
int main(int argv, char** argc) {
    /*char i = '\n';
    printf("%c test case",i);*/
    extern char outLine[];

    getLine();
    fold_copy();

    printf("%s", outLine);
}

/*getLine function: specialized version*/
void getLine(void) {
    int c, i;
    extern char inLine[];

    for(i = 0; i < MAXSIZE-1 && (c=getchar()) != EOF; ++i) {
        inLine[i] = c;
    }
    inLine[i] = '\0';
}

/*fold_copy function : specialized version*/
void fold_copy(void) {
    int i=0,j=0;
    int lastBlank=0;
    extern char inLine[];
    extern char outLine[];

    while((outLine[j] = inLine[i]) != '\0'){
        if(inLine[i] == ' '|| inLine[i] == '\n')
            lastBlank = j;
        if(j % 39 == 0 ){
            if(lastBlank%39 > 20)
                outLine[lastBlank] = '\n';
            else {
                outLine[j] = '\n';
                --i;
            }
            lastBlank = 0;
        }
        ++i;
        ++j;
    }
}
