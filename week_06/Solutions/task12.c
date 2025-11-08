#include <stdio.h>
#include <math.h>

int main(){

    int number;
    printf("Insert number: ");

    if(scanf("%d", &number) != 1 || number < 0){
        printf("Invalid input!");
        return -1;
    }

    int max_1_digit = (int)log2(number);

    int pallindrome = 1;
    for (int i = 0; i <= max_1_digit / 2; i++)
    {
        int bit_one = number >> i & 1;
        int bit_two = (number >> (max_1_digit - i)) & 1;

        if(bit_one ^ bit_two) {
            pallindrome = 0;
            break;
        }
    }

    printf("is number binary pallindrome: %s\n", pallindrome ? "yes" : "no");
    return 0;
}