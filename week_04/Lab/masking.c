#include <stdio.h>

int main(void) {
    unsigned char number = 0b10001111; // 143 (binary: 10001111)
    unsigned int mask = 1;

    // --- Get first (least significant) bit ---
    int first_bit = number & mask;
    printf("First bit: %d\n", first_bit);

    // --- Get bit at position k (here: 3) ---
    int k = 3;
    int bit_at_k = (number & (mask << k)) >> k;
    printf("Bit at position %d: %d\n", k, bit_at_k);

    // --- Get last (most significant) bit ---
    int last_position = sizeof(unsigned char) * 8 - 1;
    int last_bit = (number & (mask << last_position)) >> last_position;
    printf("Last bit: %d\n", last_bit);

    return 0;
}
