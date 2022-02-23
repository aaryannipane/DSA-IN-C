#include <stdio.h>
#include <math.h>

int max(int, int);

int main(){

    printf("%d", max(2, 1));

    return 0;
}

int max(int a, int b){
    return ((a > b) ? a : b);
}