#include <stdio.h>
#include <limits.h>

int main(){

    unsigned int number;
    if(scanf("%u", &number) != 1 || number > 9999) {
        printf("Invalid number!");
        return -1;
    }

    short digit_one     =  number / 1000;
    short digit_two     = (number / 100  )  % 10;
    short digit_three   = (number / 10   )  % 10;
    short digit_four    = (number        )  % 10;

    // let's by default set it to the last digit
    short biggest_digit = digit_four;
    short smallest_digit = digit_four;

    if      (number >= 10     && digit_three > biggest_digit)            biggest_digit = digit_three;
    else if (number >= 10     && digit_three < smallest_digit)           smallest_digit = digit_three;
    
    if      (number >= 100    && digit_two > biggest_digit)              biggest_digit = digit_two;
    else if (number >= 100    && digit_two < smallest_digit)             smallest_digit = digit_two;
    
    if      (number >= 1000   && digit_one > biggest_digit)              biggest_digit = digit_one;
    else if (number >= 1000   && digit_one < smallest_digit)             smallest_digit = digit_one;

    printf("Biggest difference: %d - %d = %d\n", 
        biggest_digit, smallest_digit, biggest_digit - smallest_digit);

    return 0;
}