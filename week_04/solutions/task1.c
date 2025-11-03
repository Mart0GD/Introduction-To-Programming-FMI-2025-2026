#include "stdio.h"

int main(){

    unsigned int a, b;
    printf("Insert numbers: "); scanf("%u %u", &a, &b);

    printf("a & b = %u", a & b);
    printf("a | b = %u", a | b);
    printf("a ^ b = %u", a ^ b);
    printf("~a = %u", ~a);
    
    return 0;
}