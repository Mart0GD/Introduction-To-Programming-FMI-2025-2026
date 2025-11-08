#include <stdio.h>
#include <math.h>
/*
Напишете програма, която по подадено число n в 10-тична бройна ситема извежда на конзолата представянето му в двоична бройна система.
Направете и обратното. По подадено n в двоична, го принтирайте в 10-тична.
*/

void bin_to_decimal();
void dec_to_bin();

int main(){

    bin_to_decimal();
    dec_to_bin();

    return 0;
}

void bin_to_decimal() {
    unsigned long long bin;
    printf("Insert 16-bit binary number: ");

    if (scanf("%llu", &bin) != 1) {
        printf("Invalid input!");
        return;
    }

    int negative = 0;

    int value = 0;
    int base = 1;
    for (int i = 0; i < 15; i++) {
        unsigned d = bin % 10;
        bin /= 10;
        if (d > 1) {
            printf("Not a binary number!\n");
            return;
        }
        value += d * base;
        base <<= 1;
    }

    unsigned sign = bin % 10;bin /= 10;
    if (sign > 1 || bin > 0) { 
        printf("Not a binary number!\n");
        return;
    }

    if (sign == 1) {  // negative number in 2’s complement
        value -= 1 << 15;
    }

    printf("Decimal: %d\n", value);
} 
void dec_to_bin(){
    short number;
    printf("Insert decimal number: ");
    if(scanf("%hd", &number) != 1){
        printf("Invalid input!");
        return;
    }

    const int MAX_BIT = 15;
    
    for (int i = MAX_BIT; i >= 0; --i)
    {
        printf("%d", (number >> i) & 1);
    }
    
    puts("");
}
