#include <stdio.h>

int main() {

    /*
        The 'break' keyword in C:

        -- Terminates the nearest enclosing loop (for, while, do-while)
        -- Also used in switch-case to stop fallthrough

        !!Important!!
        'break' DOES NOT exit an entire function — only the current loop or switch block.
    */

    // ------------------------------------------------------------------------------------------
    // Example 1: Breaking out of a for loop early

    int i = 0;

    for (; i < 100; ++i) {
        if (i == 5) break;   // loop stops when i reaches 5
    }

    // Here i == 5

    // ------------------------------------------------------------------------------------------
    // Example 2: Breaking inside a while loop

    while (i < 100) {
        // Break loop if i is even → exits immediately (i == 5 → not even)
        if (i % 2 == 0)
            break;

        ++i; // Now i becomes 6 → condition becomes true → break next iteration
    }

    // After this code, i == 6

    return 0;
}
