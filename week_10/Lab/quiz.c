#include <stdio.h>

// Any mistakes here and if yes what are they
int* copy(int arr[], int size){

    int c[size];
    for (int i = 0; i < size; i++)
    {
        c[i] = arr[i];   
    }
    
    return c;
}


int main(){
    int arr[] = {1, 2, 3 ,4};
    int len   = sizeof(arr) / sizeof(arr[0]);

    // Question 1
    int* p = copy(arr, len);

    // Question 2
    int arr1[] = {1, 2, 3 ,4};
    int arr2[4];

    // Will this compile
    // arr1 = arr2;
}