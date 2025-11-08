#include <stdio.h>

int main(){

    int n; 
    printf("Insert n: ");

    if(scanf("%d", &n) != 1){
        printf("Invalid data!");
        return -1;
    }

    putchar('\n');
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d ", j);
        }
        putchar('\n');
    }
    
    return 0;
}