#include <stdio.h>

int main() {

    /*
        Structure of a do-while loop in C

        Overview:
        -- This loop guarantees that the body will execute at least once.

        Order of execution:
            Execute <body>
            Evaluate <logical condition>
            If true → repeat from step 1
            If false → stop loop

        Syntax:

        do {
            <body>
        } while (<logical condition>);
              ↑
              Note the semicolon here — required by the syntax!
    */

    // ------------------------------------------------------------------------------------------
    // Example: Ensuring valid integer input from the user

    int i;
    int successful;

    do {
        successful = 1;

        if (scanf("%d", &i) != 1) successful = 0;

        // Clear the input buffer (consuming leftover characters)
        while (getchar() != '\n');

    } while (!successful);  // repeat if input was invalid

    /*
        Use cases of do-while:
        > Getting user input and re-prompting on failure
        > Operations that must happen at least once
        > Retry logic (e.g., network, I/O operations)
    */

    return 0;
}
