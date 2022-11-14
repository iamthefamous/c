#include <stdio.h>
#define MAXSIZE 1000

char line[MAXSIZE];
char outLine[MAXSIZE];

int getLine(void);
void copy(void);

//entab program's main function
int main() {
    extern char outLine[];

    while( getLine() > 0 ) {
        copy();
        printf("%s",outLine);
    }
    printf("DONE!!!\n");
    
    return 0;
}

//getLine: specialized version
int getLine(void) {
    int c,i;
    extern char line[];

    for(i = 0; i < MAXSIZE - 1  && (c=getchar()) != EOF && c != '\n'; ++i ) {
        line[i] = c;
    }
    if(c == '\n') {
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
    return i;
}

//copy: specialized version
void copy(void) {
    extern char line[];
    extern char outLine[];
    int i=0,j=0;
    int spaceCounter=0;

    while((outLine[j] = line[i]) !='\0') {
        if(line[i] == ' ')
           ++spaceCounter;
        else 
            spaceCounter = 0;if(i % 8 != 7 || spaceCounter == 0) {
            outLine[j] = line[i];
        } else {
            j -= spaceCounter-1;
            outLine[j] = '\t';
            spaceCounter = 0;
            
        }
        ++i;
        ++j;

    }
}
