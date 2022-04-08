#include<stdio.h>
#include<stdlib.h>

/* 
    ->> binary search
    - it is fast searching algorithm with time complexity O(log n)
    - it is based on divide and conquer
    - data item should be in sorted manner
*/

int binarySearch(int array[], int key, int low, int high){
    while(low <= high){
        int mid = (low + high) / 2;

        if(array[mid] == key)
            return 1;
        
        // go to right side
        if(array[mid] < key)
            low = mid + 1;
        // go to left side
        else
            high = mid - 1;
        
    }

    return -1;
}


int main(){

    // sorted array
    int ARRAY[] = {10, 20, 30, 40, 50};
    // length of array 
    int n = sizeof(ARRAY) / sizeof(ARRAY[0]);
    // element to search
    int x = 40;

    int low = 0;
    int high = n-1;

    int result = binarySearch(ARRAY, x, low, high);

    (result == 1)? printf("Element Found"): printf("Element Not Found");

    return 0;
}