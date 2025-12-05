#include <stdio.h>

// Complexity  --> O(n^2)
// Stable      --> yes
void insertion_sort(int arr[], int size){

    int pos;
    int temp;

    // 1. iterate the array
    for (int i = 0; i < size; i++)
    {   
        pos = i;

        // 2. swap elements until we either:
        // > reach the start 
        // > find a smaller element before us
        while (pos > 0 && arr[pos] < arr[pos - 1])
        {
            temp         = arr[pos];
            arr[pos]     = arr[pos - 1];
            arr[pos - 1] = temp;
            --pos;
        }
        
    }
    
}

int main(){
    int arr[] = {7, 2 , 11, 5, 3 , 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, len);

    for(int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }
}
