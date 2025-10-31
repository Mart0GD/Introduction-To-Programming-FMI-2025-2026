#include <stdio.h>

/*
    This is the main function. Its block is defined by the two curly braces.
    All variables defined in main live in main, with exceptions you will learn soon.
*/
int main()
{   // start of block

    // When we define a variable inside a block, it lives until the end of that block.
    int a = 8;

    // We can define our own block
    {
        int a = 5;  // This 'a' won't be visible outside of this block.

        // We can define another nested block of code
        {
            int a = 6;  // This 'a' exists only in this inner-most block.

            // We have reached the end → this double-nested 'a' will be deleted now.
        }

        // We have reached the end → this nested 'a' will be deleted now.
    }

    // We have reached the end → 'a' will be deleted now.
}   // end of block

/*
    Very important --> two variables with the same name !CANNOT! be defined inside the same block
*/