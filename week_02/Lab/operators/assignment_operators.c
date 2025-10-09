#include <stdio.h>

int main(){

    int number_one;
    int number_two;

    printf("Insert number one: ");   scanf("%d", &number_one);
    printf("Insert number two: ");   scanf("%d", &number_two);

    printf("number_one += number_two = %d", number_one += number_two);
    printf("number_one -= number_two = %d", number_one -= number_two);
    printf("number_one *= number_two = %d", number_one *= number_two);
    printf("number_one /= number_two = %d", number_one /= number_two);
    printf("number_one %%= number_two = %d", number_one %= number_two);

    number_one = number_two = 3;
    printf("number_one = %d", number_one);
    printf("number_two = %d", number_two);

    // but this is not allowed (number_oner = number_two) = 3;
    return 0;
}