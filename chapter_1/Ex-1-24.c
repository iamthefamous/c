#include <stdio.h>
#define MAXSIZE 1000000

char input[MAXSIZE];

void getInput(void);
void errorChecker(void);

/*exercise 1-24 : main function */
int main(int argc, char** argv) {
    getInput();
    errorChecker();

    printf("\t\tDONE\n\n");
    return 0;
}

/*getIput funcion: specialized version*/
void getInput(void) {
    int i,c;
    extern char input[];

    for(i = 0; i < MAXSIZE && (c=getchar()) != EOF; ++i) {
        input[i] = c;
    }

    input[i] = '\0';
}

/*errorChecker function: specialized version*/
void errorChecker(void) {
    int i,c;
    int brace=0;
    int bracket = 0;
    int singleQuotes = 0, doubleQuotes = 0;
    int paranthes = 0;
    int line=0;

    for(i = 0; input[i] != '\0'; ++i) {
        if(input[i] == '\n') {
            if(doubleQuotes)
                printf("ERROR::MISSING::(\")::IN LINE %d\n",line);
            if(singleQuotes)
                printf("ERROR::MISSING::(\')::IN LINE %d\n", line);

            doubleQuotes = singleQuotes = 0;
            line++;
            continue;
        }
        if(input[i] == '"')
            doubleQuotes = (doubleQuotes+1) % 2;
        if(doubleQuotes)
            continue;
        if(singleQuotes) {
            if(input[i-1] == '\'')
                continue;
            else if(input[i-2] == '\'') {
                singleQuotes = 0;
                continue;
            }
            else {
                printf("ERROR::MISSING::(\')::IN LINE %d\n", line);
                singleQuotes = 0;
            }
        }
        if(input[i] == '\'')
            singleQuotes = 1;
        
        if(i == '{')
            ++brace;
        if(input[i] == '}')
            --brace;
        if(input[i] == '(')
            ++paranthes;
        if(input[i] == ')')
            --paranthes;
        if(input[i] == '[')
            ++bracket;
        if(input[i] == ']')
            --bracket;

        if(paranthes == -1){
            printf("ERROR::EXTRA::( ) )::IN LINE %d\n", line);
            paranthes = 0;
        }
        if(brace == -1){
            printf("ERROR::EXTRA::( } )::IN LINE %d\n", line);
            brace = 0;
        }
        if(bracket == -1){
            printf("ERROR::EXTRA::( ] )::IN LINE %d\n", line);
            bracket = 0;
        }
    }

    while( --paranthes ) {
        printf("ERROR::MISSING::( ) )\n");
    }
    while( --brace ) {
        printf("ERROR::MISSING::( } ) \n");
    }
    while( --bracket ) {
        printf("ERROR::MISSING::( ]  )\n");
    }
}
