#include <stdio.h>
#define LEN 100000

int get_int(char out[]);
int atob(int n, char s[], int base);

int main(void) {
    int number;
    int base;
    char converted[LEN];

    number = get_int("Please enter your number : ");
    base = get_int("Please enter convertion base : ");
    
    printf("\nNUMBER : %d\n",number);
    printf("BASE : %d\n\n", base);

    atob(number, converted, base);

    printf("\t\tOUT\n\n");
    printf("%s\n",converted);
}

int get_int (char out[]) {
    printf("%s",out);
    
    int c,i=0;
    int result = 0;
    int negative_check = 0;

    while (i < 9 && (c = getchar()) != EOF && c != '\n') {
        if(c == '-') {
            negative_check = 1;
            continue;
        } 

        result *= 10;
        result += c - '0';
        ++i;
    }
    if (negative_check)
        result *= -1;

    return result;
}

int atob(int n, char s[], int base) {
    int size = 0;
    int negative_check = 0;
    if(n < 0) {
        negative_check = 1;
        n *= -1;
    }

    while (n > 0) {
        int temp = n % base;
        if(temp < 10) {
            s[size] = temp + '0';
        } else {
            s[size] = ('a' + temp%10);
        }
        n /= base;
        ++size;
    }
    for(int i = 0; i < size/2; ++i) {
        char temp = s[i];
        s[i] = s[size-1-i];
        s[size-1-i] = temp;
    }
    if(negative_check) {
        for(int i = size ; i >= 0 ; --i)
            s[size] = s[size-1];
        s[0] = '-';
        size++;
    }
    s[size] = '\0';
    return size;
}
