#include <stdio.h>
#include <stdlib.h>

// linear search or sequential search
/*
    searching technique is done in sequential manner
    TC = O(n)

    seqSearch(A, i, x, n)
    where, 
        A is array 
        i is index number
        x is element to search
        n is length of array
*/

int linearSearch(int array[], int n, int x){
    for(int i=0; i<n; i++)
        if(x == array[i])
            return 1;
        
    return -1;
}

int main(){

    int ARRAY[5] = {1, 3, 5, 12, 60};
    int x = 120;
    // length of array 
    int n = sizeof(ARRAY) / sizeof(ARRAY[0]);

    int result = linearSearch(ARRAY, n, x);

    (result == 1)? printf("Element Found"):printf("Element Not Found");

    return 0;
}