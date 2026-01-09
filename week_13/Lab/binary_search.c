#include <stdio.h>

int binary_search_wrapper(int number, int* arr, int size);

int binary_search(int number, int* arr, int l, int r);

int main(){

    int arr[] = {1};

    printf("%d\n", binary_search_wrapper(1, arr, 1));
    return 0;
}

int binary_search_wrapper(int number, int* arr, int size){
    return binary_search(number, arr, 0, size);
}

// Question: Is this tail or head recursion?
int binary_search(int number, int* arr, int l, int r){
    if(l >= r) return -1;

    int mid = l + (r - l) / 2;

    if(number < arr[mid])       return binary_search(number, arr, l, mid);
    else if(number > arr[mid])  return binary_search(number, arr, mid + 1, r);
    else                        return mid;
}