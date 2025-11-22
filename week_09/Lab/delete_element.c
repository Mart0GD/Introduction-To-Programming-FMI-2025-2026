#include <stdio.h>

int main(){

    int arr[] = { 1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    // we want to delete 3
    int index = 2;

    for (int i = index; i < len - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --len;
    
    // another way to do it but with loss of order, we will delete 2
    arr[1] = arr[len - 1];
    --len;
    
    return 0;
}