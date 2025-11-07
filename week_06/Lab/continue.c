#include <stdio.h>

int main() {

    /*
        The 'continue' keyword in C:

        -- Skips the remaining part of the current loop iteration
           and jumps directly to the next logical check
           (or incrementation step in for loops).

        !! Important !!
        'continue' can ONLY be used inside loop scopes.
        Using it outside of a loop causes a compilation error.
    */

    // ------------------------------------------------------------------------------------------
    // Example 1: Skipping a step inside a for loop

    for (int i = 0; i < 10; ++i) {
        if (i == 5)
            continue;  // skip when i == 5

        // This code executes for all i except 5
        printf("%d ", i);
    }
    printf("\n");

    // ------------------------------------------------------------------------------------------
    // Example 2: Skipping a step inside a while loop

    int i = 0;
    while (i < 10) {
        ++i; // increment first

        if (i == 5)
            continue;  // skip printing number 5

        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
