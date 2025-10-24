#include <stdio.h>

int main() {
    // Very important: difference between && and &
    int some_value_1 = 1;
    int some_value_2 = 0;
    int boolean;

    /*
        ++some_value_1 WON'T be executed.
        (some_value_1 && some_value_2) is false → short-circuit.
    */
    boolean = (some_value_1 && some_value_2) && (++some_value_1);
    printf("some_value_1 after && = %d\n", some_value_1);

    /*
        ++some_value_1 WILL be executed.
        some_value_1 & some_value_2 returns 0,
        then 0 & 2 is evaluated next (no short-circuit).
    */
    boolean = (some_value_1 & some_value_2) & ++some_value_1;
    printf("some_value_1 after &  = %d\n", some_value_1);

    // !!! Conclusion: & and && are NOT interchangeable !!!

    // Very important: bit loss when shifting (<< >>)
    int a = 1;

    a >>= 1;
    printf("a = %d\n", a);  // will be 0

    a <<= 1;
    printf("a = %d\n", a);  // will still be 0

    // !!! Conclusion: if a bit goes beyond range it is lost !!!
    return 0;
}
