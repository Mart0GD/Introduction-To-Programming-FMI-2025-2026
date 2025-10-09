#include <stdio.h>

int main(){

    int number_one;
    int number_two;

    printf("Insert number one: ");   scanf("%d", &number_one);
    printf("Insert number two: ");   scanf("%d", &number_two);

    // Binary
    printf("number_one && number_two = %d\n", number_one && number_two);
    printf("number_one || number_two = %d\n", number_one || number_two);

    // Unary
    printf("!number_one = %d\n", !number_one);
    printf("!number_two = %d\n", !number_two);

    /*
        The "," operator is a special one
        (<expression>, <expression>, ...) --> n number of expressions
        The value of the operator is the last expression1
    */
    printf("1+2 = %d\n", (0 + 1, 16 + 12, 1 + 2));

    return 0;
}