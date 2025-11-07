#include <stdio.h>

int main() {

    /*
        Structure of a while loop in C:

            while (<logical condition>)
                <operation / loop body>

        <logical condition>
        -- A boolean expression that is checked before each iteration.
           If it evaluates to false, the loop stops.

        This loop is particularly useful when we don’t know in advance
        how many iterations we need to perform.

        !! Very important !!
        -- The logical condition is NOT optional (unlike in for loops).
        -- The loop body executes ONLY if the condition is true.
    */

    // ------------------------------------------------------------------------------------------
    // While loop example
    int day_of_the_week = 1;
    while (day_of_the_week != 3) {
        // day_of_the_week = get_random_day();
        break; // break to prevent an infinite loop in this example
    }

    // ------------------------------------------------------------------------------------------
    // Endless loop example
    // while (1) printf("Endless!\n");

    // ------------------------------------------------------------------------------------------
    // While loop with an empty body
    // Useful in rare cases (e.g., fast index iteration without work inside)
    int index = 0;
    while (index++ <= 10);  // do nothing

    // After this loop → index = 12

    // ------------------------------------------------------------------------------------------
    // Be very careful with continue inside while loops — it can break your logic

    int number = 0;
    while (number <= 10) {
        if (number == 5)
            continue; // Endless loop — number stops being incremented here!

        ++number; // This line will never be reached if number == 5
    }

    return 0;
}

/*
    Key note:
    We use while loops when we do not know the exact number of iterations needed.
*/
