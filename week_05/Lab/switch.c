#include <stdio.h>

int main()
{
    /*
        Structure of a switch statement

        **************************
        switch(<expression>) {
        
            case <expression1>:
                <operators>
                break;
            
            case <expression2>:
                <operators>
                break;

            (...)

            default:
                <operators>
                break;
        }
        **************************

        <expression>                    --> must evaluate to an integer type (int, char)
        <expression1>....<expressionK>  --> must be distinct constant values
        default                         --> executes when no other case matches
        break                           --> exits the switch statement
    */

    int number = 1;

    switch (number)
    {
        case 1:     printf("1\n");
        case 2:     printf("2\n");
        default:    printf("%d\n", number);
    }

    /*
        Explanation:
        ------------
        In this example, we have not used 'break' statements.
        Once a case matches, all statements below it will execute 
        until the switch block ends or a 'break' is reached.
        This behavior is known as "fall-through".
    */


    // ======= Fall-through Example =======
    int value = 3;
    int counter = 1;

    switch (value)
    {
        case 1:     ++counter;
        case 3:     counter += 1;
        case 2:     counter += 10;
        default:    counter = 0;
    }

    printf("counter: %d\n", counter);  // Output: 0


    // ======= Example Using 'break' =======
    counter = 1;

    switch (value)
    {
        case 1:     ++counter;      break;
        case 3:     counter += 1;   break;
        case 2:     counter += 10;  break;
        default:    counter = 0;    break;
    }

    printf("counter: %d\n", counter);  // Output: 2

    /*
        !! Very Important !!

        Variable declaration inside a switch statement
        -----------------------------------------------

        The following code is INVALID:

            value = 2;
            switch (value)
            {
                case 1:
                    int a = 2;
                    printf("%d", a);
                    break;

                case 2:
                    int a = 2;     // ERROR: redeclaration of 'a' in the same block
                    printf("%d", a);
                    break;

                default: break;
            }

        Both 'case' labels belong to the same switch block.
        Declaring variables with the same name inside these cases
        will cause a compilation error.

        To fix this, wrap each 'case' block in its own pair of braces { }:
    */

    // ======= Correct Version =======
    value = 2;
    switch (value)
    {
        case 1:
        {
            int a = 2;
            printf("%d\n", a);
        }
        break;

        case 2:
        {
            int a = 2;
            printf("%d\n", a);
        }
        break;

        default:
            break;
    }

    /*
        Notes:
        ------
        → Each 'case' label represents a possible value of <expression>.
        → The 'default' label is optional but recommended for handling unexpected input.
        → 'break' prevents fall-through; omitting it can cause multiple cases to execute.
        → The switch expression can only be of type int, char, or an enum.
        → Strings or floating-point values (float, double) are NOT allowed.
    */

    return 0;
}
