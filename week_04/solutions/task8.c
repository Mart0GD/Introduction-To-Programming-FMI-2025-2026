#include "stdio.h"

int main(){

    unsigned int number;
    int i,j;
    printf ("Insert number, i, j: "); scanf("%u %d %d", &number, &i, &j);

    // bit get
    int bit_i = (number & (1 << i)) >> i;
    int bit_j = (number & (1 << j)) >> j;

    // bit off
    number = number & ~(1 << i);
    number = number & ~(1 << j);

    // bit on
    number = number | (bit_i << j);
    number = number | (bit_j << i);

    printf("Number = %d", number);
    return 0;
}