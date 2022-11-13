#include <stdio.h>
#define MAXSIZE 1000

char line[MAXSIZE];
char outLine[MAXSIZE];

int getLine(void);
void copy(void);

//detab main fanction
int main() {
    int len;
    extern char outLine[];

    while((len = getLine()) > 0){
        copy();
        printf("%d == %s",len, outLine);
    }

    printf(" DONE!!!\n");
    return 0;
}

//inputing chars;
int getLine(void) {
    int c, i=0;

    extern char line[];

    for(i=0 ; i<MAXSIZE -1 
            && (c=getchar()) != EOF && c != '\n'; ++i) {
        if( c == '\t' ) {
            for(int j=0; j<8-i%8; ++j) {
                line[i+j] = ' ';
            }
            i += (8-i%8)-1;
        } else {
            line[i] = c;
        }
    }
    if(c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

//copying from line to outLine
void copy(void) {
    int i=0;
    extern char line[];
    extern char outLine[];

    while((outLine[i] = line[i]) != '\0')
        ++i;
}
