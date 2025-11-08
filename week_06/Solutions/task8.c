#include <stdio.h>

int main(){

    int number;
    printf("Insert number: ");

    if(scanf("%d", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    int cnt = 0;
    for (int i = 0; i < 32; i++)
        if((number >> i) & 1) ++cnt;
    
    printf("Number of ones : %d\n", cnt);
    return 0;
}