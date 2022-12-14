#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define VARNUM 26
#define VARSET 'A'

enum boolean {
    false,
    true
};

int getop(char s[]);
void push(double f);
double pop(void);
int is_empty();
void print(void);
void dublicate(void);
void swap(void);
void clear(void);


/*reverse Polish Calculator*/
int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            
            case '+':
                push(pop() + pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '*':
                push(pop() * pop());
                break;
                
            case '/':
                op2 = pop();
                if(op2 != 0.0) {
                     push(pop() / op2);
                } else {
                    printf("ERROR: zero devizor\n");
                }
                break;

            case '%':
                op2 = pop();
                if(op2 != 0.0) {
                    push((int)pop() % (int)op2);
                } else {
                    printf("ERROR: zero devizor\n");
                }
                break;

            case 'p':
                print();
                break;

            case 'd':
                dublicate();
                break;

            case 's':
                swap();
                break;

            case 'c':
                clear();
                break;

            case '~':
                push(sin(pop()));
                break;

            case 'e':
                push(exp(pop()));
                break;

            case '^':
                op2 = pop();
                push(pow(pop(),op2));
                break;

            case VARSET:
                push

            case '\n':
                if (!is_empty()) {
                    printf("\t%.8g\n", pop());
                } else {
                    printf("ERROR: value STACK is empty!!\n");
                }
                break;

            default:
                printf("ERROR: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double stack[MAXVAL];

/*push: push number onto stack*/
void push(double f) {
    if(sp < MAXVAL) {
        stack[sp++] = f;
    } else {
        printf("ERROR: stack full, can't push %g\n", f);
    }
}

/*pop: pop and return top value from stack*/
double pop(void) {
    if(sp > 0) {
        return stack[--sp];
    } else {
        printf("ERROR: stack empty\n");
    }
    return 0.0;
}

/* is_empty: checks stack is empty or not */
int is_empty(void) {
    if(sp)
        return true;
    return false;
}

/*print: prints without pop */
void print(void) {
    if (sp > 0) {
        printf("%.8g", stack[sp-1]);
    } else {
        printf("ERROR: stack empty\n");
    }
}

/*dublicate: dublicates top element*/
void dublicate(void) {
    double op2 = pop();
    push(op2);
    push(op2);
}

/* swap: swaps two top elements */
void swap() {
    double op1 = pop();
    double op2 = pop();

    push(op1);
    push(op2);
}

/* clear: clears stack */
void clear(void) {
    while(--sp)
        stack[sp] = 0;
    
    stack[0] = '\0';
}

int getch(void);
void ungetch(int);

/*getop: get next character or numeric oparand*/
int getop(char s[]) {
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t') ;

    s[1] = '\0';
    
    if(isalpha(c) && isupper(c)) {
        return VARSET;
    }

    if(!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    i = 0;
    if (c == '-') {
        int next = getch();
        if(!isdigit(next)) {
            return c;
        }
        s[++i] = c = next;
        ungetch(next);
    }
    else {
        c = getch();
    }

    if(isdigit(c)) {
        while(isdigit(s[++i] = c = getch()));
    }

    if(c == '.') {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) 
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buffer[BUFSIZsE];
int bufp = 0;

/* get a (posibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

/* push characger back on input */
void ungetch(int c) {
    if(bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buffer[bufp++] = c;
    }
}
