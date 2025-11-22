#include <stdio.h>
#define MAX_LEN 128

int main(){

    int arr[MAX_LEN];

    int n;
    printf("Insert n: ");
    if(scanf("%d", &n) != 1 || n > MAX_LEN){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n - 1; i++)
    {
        if(arr[i] == arr[i + 1]) {
            printf("Has equal elements --> %d == %d\n", arr[i], arr[i + 1]); 
            return 0;
        }
    }
    
    printf("Does not have equal elements!");
    return 0;
}