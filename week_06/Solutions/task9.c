#include <stdio.h>

int main(){

    int number;
    printf("Insert number: ");

    if(scanf("%d", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < 32; i++)
    {
        if(((number >> i) & 1) != 0) {
            number ^= (1 << i);
            break;
        }
    }

    printf("Number with flipped most right one: %d\n", number);
    return 0;
}