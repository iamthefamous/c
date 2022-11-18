#include <stdio.h>
#define MAXLEN 100000

char line[MAXLEN];

void getLine(void);

/*main fuction : specialized version*/
int main(int argc, char** argv) {
    extern char line[];

    getLine();

    printf("%s\n",line);
    return 0;
}

/*getLine function: specialized version*/
void getLine(void) {
    extern char line[];
    int i,c;

    for(i = 0; i < MAXLEN-1&& (c=getchar()) != EOF; ++i) {
        switch(c){
            case '\t':
                line[i] = '\\';
                line[++i] = 't';
                break;

            case '\n':
                line[i] = '\\';
                line[++i] = 'n';
                break;
            default :
                line[i] = c;
                break;
        }
    }
    line[i] = '\\';
    line[++i] = '0';
}
