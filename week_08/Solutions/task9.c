#include <stdio.h>
#define MAX_LEN 128

void linear_sort(int arr[MAX_LEN], int len){

    int min, index = 0, temp;
    for (int i = 0; i < len; ++i)
    {
        min = arr[i]; index = i;
        for (int j = i; j < len; ++j)
        {
            if(min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    
}

int main(){

    int arr[MAX_LEN] = {0};

    int n;
    printf("Insert n: ");
    if(scanf("%d", &n) != 1 || n > MAX_LEN){
        printf("Invalid input!");
        return -1;
    }

    if(n == 0){
        puts("Numbr of unique numbers: 0");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    linear_sort(arr, n);

    int unique_cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i] != arr[i - 1]) ++unique_cnt;
    }
    
    printf("Numbr of unique numbers: %d\n", unique_cnt);
    return 0;
}