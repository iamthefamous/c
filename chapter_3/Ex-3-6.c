#include <stdio.h>
#include <stdlib.h>

#define LEN 1000

int ilen(int a);
int get_int(char out[]);
void int_to_array(int n, char s[], int padding);
void str_reverse(char s[], int left, int right);

int main(void) {
    int number = get_int("Enter your number : ");
    char array[LEN];
    int padding = get_int("Enter padding value : ");

    int_to_array(number, array, padding);

    printf("\t\tOUT\n\n");
    printf("%s\n",array);

}

int get_int(char out[]) {
    int ans = 0;
    int i,c;
    int sign_check = 0;
    
    printf("%s", out);

    for(i = 0; i<9 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if(c == '-') {
            sign_check = 1;
            continue;
        }
        ans *= 10;
        ans += c - 48;
    }
    if (sign_check)
        ans *= -1;

    return ans;
}

int ilen(int number) {
    int i = 0;
    while(number) {
        ++i;
        number /= 10;
    }

    return i;
}

void int_to_array(int number, char array[], int padding){
    int i = 0, sign = number;

    do {
        array[i++] = abs(number % 10) + '0';
    } while (number /= 10);

    if(sign < 0)
        array[i++] = '-';

    int len = ilen(sign);
    while (len < padding) {
        array[i++] = '_';
        --padding;
    }
    
    array[i] = '\0';

    str_reverse(array,0,i-1);
}

void str_reverse(char str[], int left, int right) {
    if(left >= right) 
        return ;

    char temp;
    
    printf("%c == %c\n",str[left],str[right]);

    temp = str[left];
    str[left] = str[right];
    str[right] = temp;


    str_reverse(str, left+1, right-1);
}
