#include "stdio.h"

int main(){

    unsigned number, n;
    printf("Insert number and n: "); scanf("%u %u", &number, &n);

    printf("Most signifficant bit: %d\n", (number & (1 << sizeof(unsigned))) >> sizeof(unsigned));
    printf("Least signifficant bit: %d\n", number & 1);
    printf("Nth bit: %d\n", (number & (1 << n)) >> n); // counting from 0

    return 0;
}