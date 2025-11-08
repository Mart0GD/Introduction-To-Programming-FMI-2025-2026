#include <stdio.h>

int main(){

    int n;
    printf("Insert n: ");

    if(scanf("%d", &n) != 1){
        printf("Invalid data!");
        return -1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < i; ++j) printf("   ");

        for(int j = i; j <= n; ++j) printf("%3d", j);
        
        for(int j = n; j >= i; --j) printf("%3d", j);

        putchar('\n');
    }
   
    for (int i = n - 1; i >= 1; --i)
    {
        for(int j = 0; j < i; ++j) printf("   ");

        for(int j = i; j <= n; ++j) printf("%3d", j);
        
        for(int j = n; j >= i; --j) printf("%3d", j);

        putchar('\n');
    }
    

    return 0;
}