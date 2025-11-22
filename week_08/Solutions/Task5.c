#include <stdio.h>
#include <limits.h>
#define MAX_LEN     128
#define BUCKET_CAP  1024


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

void counting_sort(int arr[MAX_LEN], int len){
    int bucket[BUCKET_CAP] = { [0 ... 1023] = 0};
    // {0} will do just the same

    for (int i = 0; i < len; ++i) ++bucket[arr[i]];

    int index = 0;
    for (int i = 0; i < BUCKET_CAP; ++i) {
        for (int j = 0; j < bucket[i]; ++j) {
            arr[index++] = i;
        }
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

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    linear_sort(arr, n);
    counting_sort(arr, n);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}