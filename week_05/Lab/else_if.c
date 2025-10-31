#include <stdio.h>

int main()
{
    /*
        We can chain multiple conditional checks by placing
        an if statement as the <operator> of the else operator.

        This is known as the "else-if ladder".

        It allows us to check several conditions in sequence, 
        where only the first TRUE condition will be executed.

        Example
        ---------
        if (<condition1>) <operator1>
        else if (<condition2>) <operator2>
        else if (<condition3>) <operator3>
        ...
        else <operatorN>
    */

    double grade = 5.45;   // student's grade

    if      (grade >= 5.5 && grade <= 6)    printf("Excellent!\n");
    else if (grade >= 4.5)                  printf("Very good!\n");
    else if (grade >= 3.5)                  printf("Good!\n");
    else if (grade >= 3.0)                  printf("Satisfactory!\n");
    else if (grade >= 2.0)                  printf("Bad!\n");
    else                                    printf("Invalid grade!\n");

    /*
        How it works:
        -------------
        • The program checks each condition from top to bottom.
        • As soon as one condition is TRUE, its statement executes.
        • The rest of the conditions are skipped.
        • If none of the conditions are true, the final 'else' block runs.

        Notes:
        ------
        → Use 'else if' when you want only one branch to run.
        → If multiple conditions can be true but you want all of them to run,
          you should use separate 'if' statements instead.
        → The order of conditions matters — the first one that matches will stop the chain.
    */

    return 0;
}
