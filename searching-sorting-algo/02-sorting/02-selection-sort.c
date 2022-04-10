#include <stdio.h>
#include <stdlib.h>

// SELECTION SORT
/* 
    Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.
    TC = O(N^2)
*/

int selectionSort(int array[], int size){

    for(int i=0; i<size-1;i++){
        for(int j=i+1; j<size;j++){

            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // dsiplay array
    for(int i=0; i<size;i++){
        printf("%d ", array[i]);
    }

}


int main(){

    int ARRAY[] = {5, 124, 29, 45, 3};
    int n = sizeof(ARRAY) / sizeof(ARRAY[0]);

    selectionSort(ARRAY, n);

    return 0;
}