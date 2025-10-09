#include <stdio.h>

int main(){

    int number_one;
    int number_two;

    printf("Insert number one: ");   scanf("%d", &number_one);
    printf("Insert number two: ");   scanf("%d", &number_two);

    printf("number_one < number_two  = %d", number_one < number_two);   // Less than
    printf("number_one <= number_two = %d", number_one <= number_two);  // Less than or equal

    printf("number_one > number_two  = %d", number_one > number_two);   // More than
    printf("number_one >= number_two = %d", number_one >= number_two);  // More than or equal

    printf("number_one == number_two = %d", number_one == number_two);  // Equal
    printf("number_one != number_two = %d", number_one != number_two);  // Different 
    
    return 0;
}