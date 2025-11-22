#include <stdio.h>
#define MAX_SIZE 128

int main(){

    int arr[MAX_SIZE] = {0};
    int n;
    if(scanf("%d", n) != 1) return -1;


    for(int i = 0; i < n; ++i){
        if(scanf("%d", &arr[i])){
            return -1;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    
    return 0;
}