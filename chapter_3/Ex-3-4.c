#include <stdio.h>
#define LEN 9

int get_line(char line[]);
int atoi(char line[]);

int main(void) {
    int converted_int;
    char line[LEN];

    get_line(line);
    converted_int = atoi(line);

    printf("\t\tOUT\n\n");
    printf("%d\n", converted_int);
}

int get_line(char line[]) {
    int i,c;

    for(i = 0; i<LEN && (c=getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    line[i] = '\0';
    
    return i;
}

int atoi(char line[]) {
    int ans = 0;
    int check_for_minus = 0;
    int i = 0;

    if(line[i] == '-') {
        check_for_minus = 1;
        ++i;
    }

    while((i < LEN && line[i] != '0') && (line[i] >= '0' && line[i] <= '9')) {
        int temp = line[i]-'0';
        ans = ans * 10 + temp;
        ++i ;
    }
    if(check_for_minus) {
        ans *= -1;
    }

    return ans;
}
