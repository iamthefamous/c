#include "atof.h"

/* reversing number */
int reverse(int number) {
    int ans = 0;
    
    while(number > 0) {
        ans = ans * 10 + (number % 10);
        number/= 10;
    }

    return ans;
}

/* returning size of floating point */
int floating_size(char str[]) {
    int answer = 0;
    int i = 0;
    int point_check = 0;

    while(str[i] != '\0') {
        if(point_check)
            ++answer;
        
        if(str[i] == '.')
            point_check = 1;
        
        ++i;    
    }

    return answer;
}

/* converting floating-point to e or E and optional signed exponent */
void atof(char str[]) {
    int size = floating_size(str);
    if(size < 8)
        return ;

    int i = 0;
    while(str[i] != '.')
        ++i;
    
    i += 3;
    str[i++] = 'e';
    str[i++] = '-';
    
    size = reverse(size-2);
    while(size > 0) {
        str[i++] = (size%10) + '0';
        size /= 10;
    }

    str[i] = '\0';
}
