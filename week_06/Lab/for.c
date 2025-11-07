#include <stdio.h>

int main() {

    /*
        Structure of a for loop in C:

        for (<initialization>; <logical condition>; <increment/decrement>)
            <loop body>

        Explanation:

        <initialization>
        -- Variable or iterator initialization (declaration/assignment).
           A variable declared here is visible only inside the loop's scope.

        <logical condition>
        -- A boolean expression checked before each iteration.
           If it evaluates to false, the loop stops.

        <increment/decrement>
        -- Expression executed after each iteration.
           Usually used to update the loop's controlling variable.

        !!Very Important!!
        Each of these three components is OPTIONAL.
    */

    for (
        int i = 0;    // initialization --> 'i' exists only inside this loop
        i < 10;       // condition: loop continues while i < 10
        ++i           // increment: executed after each iteration
    ) {
        printf("%d\n", i);
    }

    // ------------------------------------------------------------------------------------------
    // A for loop without braces (valid if only one statement is inside)

    for (int i = 0; i < 10; ++i)
        printf("%d\n", i);

    // ------------------------------------------------------------------------------------------
    // A for loop without initialization (if iterator is declared outside)

    int i = 0;
    for (/* empty */; i < 10; ++i)
        printf("%d\n", i);

    // ------------------------------------------------------------------------------------------
    // A for loop without a condition → infinite loop (equivalent to while(1))

    /*
    WARNING: Endless loop! Uncomment at your own risk.
    for (int i = 0; /* empty */ /*; ++i)
        printf("Endless!\n");
    */

    // ------------------------------------------------------------------------------------------
    // A for loop without increment (useful if incrementing happens inside)

    for (int year = 2011; (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; /* empty */) 
    {
        // year = get_next_year();  // hypothetical update
        break;  // prevent endless loop here
    }

    // ------------------------------------------------------------------------------------------
    // Completely empty for loop → infinite loop

    /*
    for (;;)
        ; // infinite empty loop
    */

    return 0;
}


/*
    The for loop is the most flexible loop structure in C —
    anything possible with a while loop can also be done with a for loop.
*/
