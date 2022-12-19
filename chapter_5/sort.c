#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAXSTORE 10000
#define MAXLINES 5000
#define ALLOC_SIZE 10000

static char alloc_buf[ALLOC_SIZE];
static char *alloc_p = alloc_buf;

char *line_ptr[MAXLINES];

char *alloc(size_t size);
void afree(char *ptr);

int parse_argv_list(int argc, char *argv[]);

size_t get_line(char line[], size_t max_line_len);

int readLines(char *line_ptr[], int max_nr_of_lines, char *stored_lines);
void writeLines(char *line_ptr[], int nr_of_lines);

int numcmp(const char *s1, const char *s2);
int etccmp(const char *s1, const char *s2);
void swap(void *v[], int i, int j);
void quick_sort(void *v[], size_t start, size_t end, int (*comp)(void *, void *));

int order = 1;
int dictionary = 0;
int fold = 0;
int (*comp)(const char *s1, const char *s2) = etccmp;

int main(int argc, char *argv[]) {
    if(!parse_argv_list(argc, argv)){
        puts("ERROR: invalid arguments");
        return EXIT_FAILURE;
    }

    int nr_of_lines;
    char stored_lines[MAXSTORE];
    
    if((nr_of_lines = readLines(line_ptr, MAXLINES, stored_lines)) >= 0) {
        quick_sort((void **)line_ptr, 0, nr_of_lines-1, (int (*)(void *, void *))comp);
        printf("\t\tOUT\n\n");
        writeLines(line_ptr, nr_of_lines);
    } else {
        printf("ERROR: input too big to sort.\n");
    }

    return EXIT_SUCCESS;
}

int parse_argv_list(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        size_t arg_len = strlen(argv[i]);
        if(arg_len > 0 && argv[1][0] == '-') {
            for(size_t j = 1; j < arg_len; ++j) {
                switch (argv[i][j]) {
                    case 'n':
                        comp = numcmp;
                        break;

                    case 'r':
                        order = -1;
                        break;

                    case 'f':
                        fold = 1;
                        break;

                    case 'd':
                        dictionary = 1;
                        break;

                    default:
                        return 0;
                        break;
                }
            }
        } else {
            return 0;
        }
    } 

    return 1;
}


#define MAXLEN 1000

int readLines(char *lines_ptr[], int max_nr_of_lines, char *stored_lines) {
    int len;
    int nr_of_lines;

    char *current_line = alloc(MAXLEN);
    char *current_line_copy = NULL;

    nr_of_lines = 0;
    while((len = get_line(current_line, MAXLEN)) > 0) {
        if(nr_of_lines >= max_nr_of_lines || (current_line_copy = alloc(len)) == NULL){
            return -1;
        }
        
        current_line[len-1] = '\0';
        strcpy(current_line_copy, current_line);
        lines_ptr[nr_of_lines++] = current_line_copy;
    }

    afree(current_line);

    return nr_of_lines;
}

void writeLines(char *lines_ptr[], int nr_of_lines) {
    for(int i = 0; i < nr_of_lines; i++) {
        puts(lines_ptr[i]);
        afree(lines_ptr[i]);
    }
}

size_t get_line(char *line, size_t max_line_len) {
    int c;
    size_t i;

    for(i = 0; i < max_line_len - 1 && (c = getc(stdin)) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void quick_sort(void *v[], size_t start, size_t end, int (*comp)(void *, void *)) {

    if((long)start >= (long)end){
        return;
    }

    swap(v, start, (start + end) / 2);
    
    size_t last = start;
    for (size_t i = start; i <= end; ++i){
        if((*comp)(v[i],v[start]) < 0) {
            swap(v, ++last, i);
        }
    }

    swap(v, start, last);
    quick_sort(v, start, last - 1, comp);
    quick_sort(v, last + 1, end, comp);
}

void swap(void *v[],int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(const char *s1, const char *s2){
    double num1 = atof(s1);
    double num2 = atof(s2);

    if(num1 < num2) {
        return order * -1;
    }
    if(num1 > num2) {
        return order * 1;
    }

    return 0;
}

int etccmp(const char *s1, const char *s2) {
    while(*s1 != '\0' && *s2 != '\0') {
        if (dictionary) {
            while (*(s1) != '\0' && !isalnum(*s1) && !isspace(*s1)) {
                ++s1;
            }
            while (*(s2) != '\0' && !isalnum(*s2) && !isspace(*s2)) {
                ++s2;
            }

        }
        
        int result = (fold) ? tolower(*s1) - tolower(*s2) : *s1 - *s2;
        if (!result) {
            ++s1;
            ++s2;
        }
        else {
            return (order * result);
        }
    }

    return 0;
}

char *alloc(size_t size) {
    if (alloc_buf + ALLOC_SIZE - alloc_p >= size) {
        alloc_p += size;
        return (alloc_p - size);
    } else {
        return NULL;
    }
}

void afree(char *ptr) {
    if(ptr >= alloc_buf && ptr < alloc_buf + ALLOC_SIZE) {
        alloc_p = ptr;
    }
}
