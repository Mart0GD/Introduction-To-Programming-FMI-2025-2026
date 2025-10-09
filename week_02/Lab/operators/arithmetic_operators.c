#include <stdio.h>

/*
    In this example you will see all the diffrent arithmetic operators in the C language
*/

int main(){

    int number_one;
    int number_two;

    printf("Insert number one: ");   scanf("%d", &number_one);
    printf("Insert number two: ");   scanf("%d", &number_two);

    printf("Printing all Arithmetic operators: \n");

    // ------------------ BINARY OPERATORS ------------------
    printf("%d + %d = %d\n", number_one, number_two, number_one + number_two);    // Addition
    printf("%d - %d = %d\n", number_one, number_two, number_one - number_two);    // Subtraction
    printf("%d * %d = %d\n", number_one, number_two, number_one * number_two);    // Multiplication
    printf("%d / %d = %d\n", number_one, number_two, number_one / number_two);    // Division
    printf("%d %% %d = %d\n", number_one, number_two, number_one % number_two);   // Modulo

    // ------------------ Unary OPERATORS ------------------
    printf("+ number_one:   %d\n", +number_one);    // Unary plus
    printf("- number_one:  %d\n", -number_one);     // Unary minus

    printf("++ number_one:  %d\n", ++number_one);   // Prefix increment
    printf("++ number_two:  %d\n", ++number_two);   // Prefix increment

    printf("-- number_one:  %d\n", --number_one);   // Prefix decrement
    printf("-- number_two:  %d\n", --number_two);   // Prefix decrement

    printf("number_one ++:  %d\n", number_one++);   // Postfix increment
    printf("number_two ++:  %d\n", number_two++);   // Postfix increment

    printf("number_one on the next line: %d\n", number_one);
    printf("number_two on the next line: %d\n", number_two);

    printf("number_one --:  %d\n", number_one--);   // Postfix decrement
    printf("number_two --:  %d\n", number_two--);   // Postfix decrement

    printf("number_one on the next line: %d\n", number_one);
    printf("number_two on the next line: %d\n", number_two);

    printf("Final result:\n");
    printf("Number one:     %d\n", number_one);
    printf("Number two:     %d\n", number_two);

   
    
   return 0;
}

/*
*   !!Disclaimer!!
*   You cannot do ++number_one++ because the order of the two operations conflicts 
*   with one another
*/