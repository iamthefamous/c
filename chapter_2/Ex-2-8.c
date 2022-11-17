#include <stdio.h>

int rightrot(int x, int y);
int invert(int x, int p, int n);
/*main function: specialized version*/
int main(int argc, char** argv) {
    int x, n;
    int p, y;
    scanf("%d",&x);
    scanf("%d",&p);
    scanf("%d",&n);

    printf("rightrot function == %d\n",rightrot(x,n));
    printf("invert funcion == %d\n",invert(x,p,n))
}

/*rightrot function: specialized version*/
int rightrot(int n, int x){
    return n>>x;
}

/*invert function: specialized version */
int invert(int x, int p, int n) {
    ++p; // First position is 0

    unsigned int mask1 = ~(~0 << n) << p;
    unsigned int mask2 = ~mask1 & x;
    
    return mask2 | ~x;
}
