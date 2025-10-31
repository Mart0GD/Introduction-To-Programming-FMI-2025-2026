#include <stdio.h>

int main()
{
    /*
        The ternary operator is a conditional operator with three arguments.

        ******************************************
        <condition> ? <operation1> : <operation2>;
        ******************************************

        <condition> --> conditional statement
        Example: (a > 0)

        <operation1> --> evaluated if <condition> == 1  
        It must return a value.  
        Example: (a > 0) ? 1

        <operation2> --> evaluated if <condition> == 0  
        It must also return a value.  
        Example: (a > 0) ? 1 : 0;

        !! Very important !!
        --> <operation1> and <operation2> must return values of the same data type.
        --> Only one of the operations will be evaluated.
    */

    int a = 1;
    int b = 0;

    // using the ternary operator to assign a value
    int ternary_example = (a > b) ? 1 : 0;

    /*
        we can also do this.
        printf() returns an int, but we just ignore the return value
    */
    (a > b) ? printf("%d\n", a) : printf("%d\n", b);

    /*
        we can use the ternary operator just like an if/else statement 
    */
    (a > b)
        ? (
            {
                printf("a is bigger than b\n");
            }
        )
        : (
            {
                printf("b is bigger than a\n");
            }
        );

    return 0;
}
