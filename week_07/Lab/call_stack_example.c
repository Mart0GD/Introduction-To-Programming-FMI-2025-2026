#include <stdio.h>

void function_one(void);
void function_two(void);
void function_three(void);

int main(void) {

    /*
        Our programs (and computers) run on a stack-like principle:

        1) We call a function 
        2) It calls another function 
        3) We execute the function
           // if this new function calls another one the cycle continues on
        4) We go back to the previous function
    */

    function_one();
    return 0;
}

void function_one(void) {

    /*
        The processes of main are now stopped until 
        function_one is executed.
    */

    puts("inside function one!");
    function_two();

    // some operations...
}

void function_two(void) {

    /*
        The processes of function_one are now stopped until 
        function_two is executed.
    */

    puts("inside function two!");
    function_three();

    puts("calculating the meaning of life....");
    puts("calculating the meaning of life....");
    puts("calculating the meaning of life....");
    puts("calculating the meaning of life....");

    puts("The meaning of life is: 42");
}

void function_three(void) {

    /*
        This function stops the execution of function_two.
    */

    puts("inside function three!");
}
