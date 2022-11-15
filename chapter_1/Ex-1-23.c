#include <stdio.h>
#define MAXSIZE 10000

int sizeOfFile;
char inLine[MAXSIZE];
char outLine[MAXSIZE];

void getLine(void);
void copy(void);
int setBool(int b);

/*remove c comments: specialized version*/
int main(int argc, char** argv) {
    extern char outLine[];

    getLine();
    copy();

    printf("\n\t\tOUT\n\n%s", outLine);
}

/*getLine function: specialized version*/
void getLine(void) {
    int c,i;
    extern int sizeOfFile;
    extern char inLine[];

    for(i = 0; i<MAXSIZE-1 && (c=getchar()) != EOF ; ++i)
        inLine[i] = c;

    inLine[i] = '\0';
    sizeOfFile = i+1;
}

/*copy function: specialized version*/
void copy(void) {
    extern int sizeOfFile;
    extern char inLine[];
    extern char outLine[];
    int i,j=0;
    int quoteCheck = 0;
    int commentCheck =0;

    for(i=0 ; i < sizeOfFile && inLine[i] != '\0'; ++i) {
        if(inLine[i] == '"'){
            outLine[j] = inLine[i];
            ++i;
            ++j;
                while(inLine[i] != '"') {
                    outLine[j] = inLine[i];
                    ++i;
                    ++j;
                }
        }
        if(i < sizeOfFile-1 && inLine[i] == '/' && inLine[i+1] == '*') {
            i+=3;
            while(++i) 
                if (inLine[i-1] == '*' && inLine[i] == '/')
                    break;
            ++i;
        } else{
            outLine[j] = inLine[i];
            ++j;
        }
    }
}
        

/*setBool function: specialized version*/
int setBool(int b) {
    if(b)
        return 0;
    return 1;
}
