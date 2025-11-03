#include "stdio.h"

int main(){

    unsigned number;
    printf("Insert number: "); scanf("%u", &number);

    printf("Is power of 2: %d\n", (number & (number - 1)) == 0 && number != 0);
    return 0;
}