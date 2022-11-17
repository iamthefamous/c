#include <stdio.h>
#define lim 1000

char line[lim+1];

void getNumber(void);
int htoi(void);
int toDigit(char c);
int hexDigit(char c);
int isDigit(char c);

/*main function*/
int main(int argc, char** argv) {
    extern int ans;
    printf("write hexadecimal Nuber : \n");
    
    getNumber();
    printf("%s\n", line);

    printf("\n\t\tOUT\n\n");
    printf("%d\n", htoi());
}

/*getNumber function : specialized version*/
void getNumber(void) {
    int i;
    char c;
    extern char line[];

    for(i = 0; i < lim && (c=getchar()) != '\n'; ++i) {
        line[i] = c;
    }
    line[i] = '\0';
}

/* htoi function: specialized version
 * converts hexadecimal to gedimal */
int htoi(void) {
    int ans=0;
    extern char line[];
    int i;
    char c;

    for(i = 0; line[i] != '\0'; ++i) {
        ans *= 16;
        if(isDigit(line[i])){
            ans += toDigit(line[i]);
        } else {
            ans += hexDigit(line[i]);
        }
    }
    return ans;
}

/*isDigit function: specialized version
 * checks for digits if char is digit */
int isDigit(char c) {
    if (c >= '0' && c <='9')        
        return 1;
    return 0;
}

/*toDigit funcion: specialized version
 * returns int digit of char */
int toDigit(char c) {
    return ((int) c-'0');
}

/* hexDigit funcion: specialized version
 * returns (a-f) as a hex digits */
int hexDigit(char c) {
    return ((int) c-87);
}
