#include <stdio.h>

int main(){
    unsigned number;
    printf("Insert number: "); scanf("%u", &number);

    unsigned mask = (1 << 4) -1;

    unsigned msb_half_byte = (number >> 28) & (mask);
    unsigned lsb_half_byte = (number & (mask));

    int same = msb_half_byte == lsb_half_byte;

    printf("Half bytes the same: %d\n", same);
    return 0;
}  