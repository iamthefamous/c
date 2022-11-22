#include "strindex.h"

/* returning the size of string */
int str_size(char str[]){
    int i=0 ;

    while(str[i] != '\0')
        ++i;

    return i;
}

/* finding index of str1 in srt2 if excist
 * else -1 */
int strindex(char str1[], char str2[]){
    int i = 0, j = 0;
    int str1_size = str_size(str1);
    int str2_size = str_size(str2);

    printf("%d == %d\n",str1_size, str2_size);

    if( str1_size > str2_size ) {
        return -1;
    }
    
    while(str2[j] != '\0') {
        i = 0;
        if( str1_size > str2_size-j )
            return -1;

        if(str1[i] == str2[j] ) {
            int j2 = j;
            while(str1[i] == str2[j2] && j2 < str2_size){
                ++i;
                ++j2;
            }
            printf("%d\n",i);
            if (i == str1_size){
                return j;
            }
        }
        ++j;
    }
    return -1;
}
