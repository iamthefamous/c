#include <stdio.h>

#define NUL 0
#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    printf("alloc n == %d\n\n", n);
    if (allocp + n <= allocbuf + ALLOCSIZE) {
        allocp += n;
        return (allocp-n) ;
    } else {
        return NUL;
    }
}
void Free(char *p) {
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE) 
        allocp = p;
}

int strLen(char *s) {
    char *p = s;
    while(*p != '\0')
        p++;

    return (p-s);
}

void strCat(s,t)
char *s, *t; {
    int sz = strLen(s);
    
    s = alloc(strLen(s) + strLen(t));
    printf("srtCat s size == %d\n\n", strLen(s));

    s += sz;
    
    while((*(s++) = *(t++)) != '\0')
        ;
}

int main(void){
    char *s = "Hello, ";
    char *t = "WOorld!";

    strCat(s,t);

    printf("size of s == %d\n\n",strLen(s));

    printf("%s\n",s);
    return 0;
}
