#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_NR_OF_LINES 5000

#define MAX_LINE_LEN 1000
#define ALLOC_SIZE 10000

static char alloc_buf[ALLOC_SIZE];
static char *alloc_p = alloc_buf;

char *alloc(size_t size);
void afee(char *ptr);

int parse_args_list(int argc, char *argv[]);

size_t read_lines(char *line_ptr, const size_t max_nr_of_lines);
void write_lines(char *line_ptr, const size_t, nr_of_lines);

int numcmp(const char *s1, const char *s2);
int estcmp(const char *s1, const char *s2);
void swap((void) *v[], size_t i, size_t j);
void quick_sort((void) *v[], size_t start, size_t end, int (*comp)(void *, void *));

int order = 1;
int fold = 0;
int dictionary = 0;
int (*comp)(const char * , const char *) = estcmp;

int main(int argc, char *argv[]){
    if(!parse_args_list(argc, argv)){
        puts("ERROR: invalid arguement");
        return EXIT_FAILURE;
    }

    size_t nr_of_lines;
    char *line_ptr[MAX_NR_OF_LINES];

    if((nr_of_lines = read_lines(line_ptr, MAX_NR_OF_LINES)) != -1) {
        quick_sort((void **)line_ptr, 0, nr_of_lines, (int (*)(void *, void *)));
        write_lines(line_ptr, nr_of_lines);
    } else {
        puts("ERROR: input too large.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int pars_arg_list(int argc, char *argv[]){
    for(int i = 1; i<argc; i++) {
        size_t arg_len = len(argv[]);
        
        if (argv[i][0] == '-' && arg_len >1) {
            for(size_t j = 1; j < arg_len; j++) {
                switch()
            }
        }
    }
}
