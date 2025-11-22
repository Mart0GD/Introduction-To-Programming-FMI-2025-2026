#include <stdio.h>
#define MAX_LEN 128

int main(){

    int arr[MAX_LEN] = {0};
    unsigned n;
    if(scanf("%u", &n) != 1 || n > MAX_LEN){
        puts("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int drops = 0;
    for (int i = 1; i < n - 1; ++i) {
        if(arr[i] > arr[i + 1]){
            ++drops;
            if(drops > 1) break; 
        }
    }

    if(arr[n - 1] > arr[0]) ++drops;
    
    drops <= 1 && printf("The array it bitonic sorted!");
    drops > 1  && printf("The array it not bitonic sorted!");
    return 0;
}