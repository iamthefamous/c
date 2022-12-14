#include <stdio.h>
#include <string.h>

void strCat(char *s, char *t);
void strPy(char *s, char *t);
int strIndex(char *s, char *t);
void strReverse(char *s);
size_t strLen(char *s);

int main(void) {
    char s[100] = "Hello, ";
    char *t = "World!!!";
    size_t n = 5;

    strCat(s, t);
    puts(s);

    int index = strIndex(s, t);
    if(index >= 0) {
        printf("string %s occurs in string %s in postion %d\n", t, s, index);
    } else {
        printf("string %s does not contain string %s\n", s ,t);
    }

    strPy(s, t);
    puts(s);

    strReverse(s);
    puts(s);

    return 0;
}

/* strCat function: copies string 't' to the end of string 's' */
void strCat(char *s, char *t) {
    // Find the end of s
    size_t s_size = strLen(s);
    
    //Move the pointer to the end of the 's' string
    s += s_size;

    //copy t to the end of s
    while((*s++ = *t++) != '\0')
        ;
}

/* strPy function: copies string 't' to stirn 's' */
void strPy(char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}

/* strReverse function: reverses string 's' */
void strReverse(char *s) {
    char *t = s + (strLen(s) - 1);
    char temp  = 0;

    if(*s == '\0')
        return;

    while(s < t){
        temp = *t;
        *t -- = *s;
        *s++ = temp;
    }
}

/* strIndex function: returns position of string 't' int string s */
int strIndex(char *s, char *t) {
    char *first;
    char *second;
    int pos = 0;

    while(*s != '\0') {
        if(*s == *t) {
            first = s;
            second = t;

            while(*first++ == *second++) {
                if (*second == '\0') {
                    return pos;
                
                 }
             }
        }
        pos ++;
        s++;
    }

    return -1;
}

/* strLen function: returns size of string() */
size_t strLen(char *s){
    size_t count = 0;

    while(*(s++) != '\0')
        count ++;
    
    //printf("%d\n", count);
    return (count);
}
