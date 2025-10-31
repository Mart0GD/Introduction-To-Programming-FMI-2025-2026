#include <stdio.h>

int main()
{
    /*
        Structure of an if statement

        **************************
        if(<condition>) <operator>
        **************************

        If <condition> is true, then the operator is evaluated
    */

    if (2 + 2 == 5) printf("George Orwell was right!\n");

    /*
        we can even put the operator on the next line 
        still valid
    */

    if (2 + 2 == 5)
        printf("George Orwell was right!\n");


    /*
        If we want to define variables or evaluate multiple operations, 
        we must place a block after the if statement
    */
    if (2 + 2 == 4)
    {   // start of block

        // define variables 
        int a = 2;
        int b = 3;
        int res = a + b;

        // call a function
        printf("!!! 2 + 2 == %d !!!\n", res);

        // we have reached the end --> the variables will be deleted now
    }   // end of block

    return 0;
}
