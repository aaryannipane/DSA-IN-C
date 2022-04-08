#include<stdio.h>
#include<stdlib.h>

// BUBBLE SORT
/*
    - in bubble sorting technique, each pair of adjacent is compared and elements are swapped if they are not in order
    - worst case time complexity is  O(n^2)
*/

void bubbleSort(int array[], int n){

    // loop till length-1(last index) of array 
    for(int step=0; step < n-1; step++){
        int flag = 0;
        // loop to compare array elements 
        for(int i = 0; i < n-1-step; i++){

            // use '>' when to sort in acending order
            // use '<' when to sort in decending order
            if(array[i] > array[i+1]){
                // swapping
                int a = array[i];
                array[i] = array[i+1];
                array[i+1] = a;

                flag = 1;
            }
        }

        if(flag == 0){
            break;
        }
    }

    // print array
    for(int j=0; j<n; j++){
        printf("%d ", array[j]);
    }
}

int main(){
    int ARRAY[] = {-2, 45, 0, 11, -9};
    int n = sizeof(ARRAY) / sizeof(ARRAY[0]);  // length of array

    bubbleSort(ARRAY, n);

    return 0;
}