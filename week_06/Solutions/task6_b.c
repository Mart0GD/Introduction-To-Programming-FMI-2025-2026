#include <stdio.h>

int main(){

    int n;
    printf("Insert n: ");

    if(scanf("%d", &n) != 1){
        printf("Invalid data!");
        return -1;
    }

    putchar('\n');
    for (int i = n; i >= 1; --i){

        for(int k = 0; k < n - i; ++k) printf("   ");

        for (int j = i; j >= 1; --j) {
            printf("%3d", j);
        }
        putchar('\n');
    }
    

    return 0;
}