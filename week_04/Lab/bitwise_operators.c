#include <stdio.h>

// !!! Very important: Bitwise operators can be used only on WHOLE numbers !!!
int main(void) {
    // ─────────────────────────────────────────────
    // Binary initialization of an int
    unsigned int binary_a = 0b11;   // 3
    unsigned int binary_b = 0b1;    // 1

    // Hexadecimal initialization of an int
    unsigned int hex_a    = 0x3;    // 3
    unsigned int hex_b    = 0x1;    // 1
    unsigned int hex_16   = 0x10;   // 16

    // Decimal initialization of an int
    unsigned int a        = 3;      // 11 (binary)
    unsigned int b        = 1;      // 01 (binary)

    printf("binary_a == a : %d\n", binary_a == a);
    printf("binary_b == b : %d\n", binary_b == b);

    putchar('\n');

    /*
        Truth table
        -----------------------------------
        | a | b | a&b | a^b | a|b |  ~a  |
        |---|---|-----|-----|-----|------|
        | 1 | 1 |  1  |  0  |  1  |  0   |
        | 1 | 0 |  0  |  1  |  1  |  0   |
        | 0 | 1 |  0  |  1  |  1  |  1   |
        | 0 | 0 |  0  |  0  |  0  |  1   |
        -----------------------------------
    */

    /*
        ** Operator priority **
        << >>
        &      (bitwise AND)
        ^      (bitwise XOR)
        |      (bitwise OR)
    */

    /*
        ── AND --> & ──
        > Binary operator
        > Performs a & b on each bit (a and b don't need to be the same size)
    */
    printf("(a & b) = %d\n", a & b);  // prints 1

    /*
        ── OR --> | ──
        > Binary operator
        > Performs a | b on each bit
    */
    printf("(a | b) = %d\n", a | b);  // prints 3

    /*
        ── XOR --> ^ ──
        > Binary operator
        > Performs a ^ b on each bit
    */
    printf("(a ^ b) = %d\n", a ^ b);  // prints 2

    /*
        ── Negation --> ~ ──
        > Unary operator
        > Inverts all bits
        > Be careful with signed vs unsigned types
    */
    printf("~a       = %d\n", ~a);    // prints ...1110

    /*
        ── Left shift --> << ──
        > Binary operator
        > Avoid using with NEGATIVE numbers
        > Shifts the bits of "number" by n places to the left
    */
    printf("b << 2  = %d\n", b <<= 2); // 1 (00001) → 4 (00100)

    /*
        ── Right shift --> >> ──
        > Binary operator
        > Avoid using with NEGATIVE numbers
        > Shifts the bits of "number" by n places to the right
    */
    printf("b >> 2  = %d\n", b >>= 2); // 4 (00100) → 1 (00001)

    putchar('\n');
    return 0;
}
