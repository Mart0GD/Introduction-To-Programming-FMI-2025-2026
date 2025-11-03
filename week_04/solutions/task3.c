#include "stdio.h"


int main(){

    unsigned number;
    printf("Insert n: "); scanf("%u", &number);

    printf("2^%u = %lld", number, (long long)(1 << number));
    return 0;
}