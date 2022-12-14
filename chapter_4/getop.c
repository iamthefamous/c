#include <stdio.h>

#define NUMBER '0'
#define TOOBIG '1'
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int f) {
    if(bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = f;
}

int getop(s, lim)
char s[];
int lim;
{
    int i, c;

    while((c = getch()) == ' ' || c == '\t' || c == '\n') ;

    if(c != '.' && (c < '0' || c > '9')) {
        return (c);
    }

    for(i = 1; (c = getch()) >= '0' && c <='9'; i++) {
        if(i < lim)
            s[i] = c;
    }
    
    if(c == '.') {
        if(i < lim)
            s[i] = c;
        for(i++ ; (c = getch()) >= '0' && c <= '9'; i++) 
            if(i < lim)
                s[i] = c;
    }
    
    if(i < lim) {
        ungetch(c);
        s[i] = '\0';
        return (NUMBER);
    } else {
        while(c != '\n' && c != EOF)
            c = getchar();
        s[lim - 1] = '\0';
        return (TOOBIG);
    }

}
