#include <stdio.h>

int binary_search(int arr[], int size, int desired);

/*
    One of the most important algorithms of all time
    Works on a sorted linear data structure. Finds the index of an element inside an array
    
    *Complexity --> O(lon2(n)) 
*/

int main(){

    int arr[] = {1, 2, 7, 11, 23, 43, 23, 87, 112, 132};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", binary_search(arr, len, 11));
    return 0;
}

int binary_search(int arr[], int size, int desired){

    int l = 0;
    int r = size - 1;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] > desired)        r = m;
        else if(arr[m] < desired)    l = m + 1;
        else return m;
    }
    
    return -1;
}