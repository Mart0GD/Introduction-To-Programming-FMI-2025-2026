#include <stdio.h>

int main()
{
    /*
        Structure of an if/else statement

        **************************
        if(<condition>) <operator1>
        else            <operator2>
        **************************

        If <condition> is true , then <operator1> is evaluated
        If <condition> is false, then <operator2> is evaluated
    */

    if (2 + 2 == 5)  printf("2 + 2 = 5!\n");
    else             printf("2 + 2 = 4!\n");

    /*
        we can even put the operator on the next line 
        still valid
    */
    if (2 + 2 == 5)
        printf("It is true!\n");
    else 
        printf("But the party says it's true!!\n");

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
    else
    {   // start of block

        printf("this can't be true!!\n");

    }   // end of block

    return 0;
}
