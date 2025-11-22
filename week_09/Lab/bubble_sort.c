#include <stdio.h>

/*
    Works on a single unsorted array, very simple
    
    *Complexity -->  O(n^2)
*/

int main(){

    int arr[] = {10, 1 , 12 , 3 , 123, 1, 87, 13, 68};
    int len = sizeof(arr) / sizeof(arr[0]);

    int swapped, temp;
    for (int i = 0; i < len; i++)
    {
        swapped = 0;
        for (int j = 0; j < len - i - 1; ++j)
        {
            if(arr[j] <= arr[j + 1]) continue;

            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = 1;
        }
        if(!swapped) break;
    }
    
    return 0;
}