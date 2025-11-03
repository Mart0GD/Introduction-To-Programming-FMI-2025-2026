#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int main(){

    unsigned int mask = UINT_MAX;

    srand(time(NULL));
    unsigned int chromosome_one, chromosome_two;
    printf("Insert chromosomes: "); scanf("%u %u", &chromosome_one, &chromosome_two);

    int msb_chr_one = log2(chromosome_one);
    int msb_chr_two = log2(chromosome_two);

    int min_index = msb_chr_one < msb_chr_two ? msb_chr_one : msb_chr_two;
    int index = rand() % (min_index + 1); // inclusive

    // bit mask
    unsigned int temp_chromo_one = chromosome_one & (mask >> (sizeof(unsigned) * 8 - index));
    unsigned int temp_chromo_two = chromosome_two & (mask >> (sizeof(unsigned) * 8 - index));

    // bit off
    chromosome_one &= ~(mask >> (sizeof(unsigned) * 8 - index));
    chromosome_two &= ~(mask >> (sizeof(unsigned) * 8 - index));

    // bit on
    chromosome_one |= temp_chromo_two;
    chromosome_two |= temp_chromo_one;

    // print in hexadecimal
    printf("Chromosome one --> %x", chromosome_one);
    printf("Chromosome two --> %x", chromosome_two);
    return 0;
}
