#include "stdio.h"

int main(){

    unsigned char byte ;//= 0b10100101;
    printf("Insert char: "); scanf("%d", &byte);

    int bit_1, bit_2, bit_3, bit_4, bit_5, bit_6, bit_7, bit_8;

    bit_1 = byte & 1;
    bit_2 = (byte & (1 << 1)) >> 1;
    bit_3 = (byte & (1 << 2)) >> 2;
    bit_4 = (byte & (1 << 3)) >> 3;
    bit_5 = (byte & (1 << 4)) >> 4;
    bit_6 = (byte & (1 << 5)) >> 5;
    bit_7 = (byte & (1 << 6)) >> 6;
    bit_8 = (byte & (1 << 7)) >> 7;

    printf("Is palindrome: %d\n", bit_1 == bit_8 && bit_2 == bit_7 && bit_3 == bit_6 && bit_4 == bit_5);

}