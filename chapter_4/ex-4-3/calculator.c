#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'

char get_operation(char s[]);
void push(double);
double pop();

int main(void) {
    int type ;
    double op2;
    char s[MAXOP];

    while((type = get_operation) != EOF) {
        switch(type) {
        case NUMBER :
            push(atof(s));
            break;
        case '+' :
            push(pop() + pop());
            break;
        
        case '-' :
            op2 = pop();
            push(pop() - op2);
            break;
        
        case '/':
            op2 = pop();
            if(pop != 0.0) {
                push(pop() / op2);
            } else {
                printf("ERROR : zero devisor!\n");
            }
            break;
        
        case '%' :
            op2 = pop();
            if(op2 != 0.0) {
                push(pop() % op2);
            } else {
                printf("ERROR : zero devisor!\n");
            }
            break;
        
        case '\n' :
            printf(out)
        }
        
    }
}
