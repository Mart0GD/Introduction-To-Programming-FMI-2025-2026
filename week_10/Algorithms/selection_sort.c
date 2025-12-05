#include <stdio.h>

// Complexity --> O(n^2)
// Stable     --> No
void selection_sort(int arr[], int size){

    int smallest_index;
    int temp;

    // 1. Iterate over the array
    for(int i = 0; i < size; ++i){
        smallest_index = i;

        // 2. Find the smallest element 
        for (int j = i + 1; j < size; ++j) {
            if(arr[j] < arr[smallest_index]){
                smallest_index = j;
            }
        }

        // 3. Swap the smallest element and the element on current index
        temp = arr[i];
        arr[i] = arr[smallest_index];
        arr[smallest_index] = temp;
    }
}

int main(){
    int arr[] = {7, 2 , 11, 5, 3 , 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, len);

    for(int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }
}