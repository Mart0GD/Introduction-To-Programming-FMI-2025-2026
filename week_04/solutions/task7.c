#include "stdio.h" 

int main(){

    unsigned number, i, j, k;
    printf("Insert number, i,j,k: "); scanf("%u %u %u %u", &number, &i, &j, &k);

    // bit off
    number = number & ~(1 << i);

    // bit on 
    number = number | (1 << j);

    // bit flip
    number = number ^ (1 << k);

    printf("number = %u", number);
}