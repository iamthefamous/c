#include <stdio.h>
#include <string.h>

#define MAXSTORE 10000
#define MAXLINES 5000

char *line_ptr[MAXLINES];

size_t get_line(char line[], size_t max_line_len);

int readLines(char *line_ptr[], int max_nr_of_lines, char *stored_lines);
void writeLines(char *line_ptr[], int nr_of_lines);

void swap(char *v[], int i, int j);
void quick_sort(char *line_prt[], int left, int right);

int main(void) {
    int nr_of_lines;
    char stored_lines[MAXSTORE];
    
    if((nr_of_lines = readLines(line_ptr, MAXLINES, stored_lines)) >= 0) {
        quick_sort(line_ptr, 0, nr_of_lines);
        printf("\t\tOUT\n\n");
        writeLines(line_ptr, nr_of_lines);
    } else {
        printf("ERROR: input too big to sort.\n");
    }
}

#define MAXLEN 1000

int readLines(char *lines_ptr[], int max_nr_of_lines, char *stored_lines) {
    int len;
    int nr_of_lines;

    char *p = stored_lines + strlen(stored_lines);
    char line[MAXLEN];

    nr_of_lines = 0;
    while((len = get_line(line, MAXLEN)) > 0) {
        if(nr_of_lines >= max_nr_of_lines || (strlen(stored_lines) + len) > MAXSTORE){
            return -1;
        }
        
        line[len-1] = '\0';
        strcpy(p, line);
        lines_ptr[nr_of_lines++] = p;
        p += len;
    }

    return nr_of_lines;
}

void writeLines(char *lines_ptr[], int nr_of_lines) {
    while(nr_of_lines--) {
        printf("%s\n",*lines_ptr++);
    }
}

size_t get_line(char line[], size_t max_line_len) {
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

void quick_sort(char *v[], int left, int right) {
    int i;
    int last;

    if(left >= right){
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left; i < right; i++){
        if(strcmp(v[i],v[left]) < 0) {
            swap(v, ++left, i);
        }
    }

    swap(v, left, last);
    quick_sort(v, left, last - 1);
    quick_sort(v, last + 1, right);
}

void swap(char *v[],int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
