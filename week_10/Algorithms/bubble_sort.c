#include <stdio.h>

// Complexity --> O(n^2)
// Stable     --> Yes
void bubble_sort_wrong(int arr[], int size){

    int temp;
    int swapped;

    // 1. iterate the array. On each iteration the largest element will bubble up
    for (int i = 0; i < size; i++)
    {
        swapped = 0;

        // 2. iterate over 
    // 1. iterate the array. On each iteration the largest element will bubble upthe elements up until the last element that went to the back
        for (int j = 0; j < size - i - 1; ++j)
        {
            // 3. if the element after us is bigger, don't do anything
            if(arr[j] < arr[j + 1]) continue;

            // 4. swap the elements
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp; 

            swapped = 1;
        }
        if(!swapped) break; // 5. no swaps --> it's sorted
    }
    
}

void bubble_sort(int arr[], int size){

    int temp;
    int swapped;

    /*
        Same algorithm but the smallest element bubbles up to the start
        A correct theoretical implementation of "bubble sort"
    */

    for (int i = size - 1; i > 0; --i)
    {
        swapped = 0;

        for (int j = size - 1; j > size -1 - i; --j)
        {
            if(arr[j] > arr[j - 1]) continue;

            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp; 

            swapped = 1;
        }
        if(!swapped) break; 
    }
    
}

int main(){
    int arr[] = {7, 2 , 11, 5, 3 , 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, len);

    for(int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }
}