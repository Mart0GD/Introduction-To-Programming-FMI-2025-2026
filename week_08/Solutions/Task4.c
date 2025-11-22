#include <stdio.h>

void print_histogram(const int arr[], int size){
    const int MAX_HISTOGRAM_SIZE = 256;
    int histogram[MAX_HISTOGRAM_SIZE];
    
    for(int i = 0; i < MAX_HISTOGRAM_SIZE; ++i) histogram[i] = 0;

    for (int i = 0; i < size; i++) ++histogram[arr[i]];

    for (int i = 0; i < MAX_HISTOGRAM_SIZE; ++i) printf("%d --> %d \n", i, histogram[i]);
    
}

int main(){   
    const int MAX_LEN = 512;

    int arr[MAX_LEN];
    int n;

    printf("Insert n: ");
    if(scanf("%d", &n) != 1 || n > MAX_LEN){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    print_histogram(arr, n);
    return 0;
}