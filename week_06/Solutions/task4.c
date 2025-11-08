#include <stdio.h>


int main(){

    unsigned int number;
    unsigned int digit_one, digit_two;
    printf("insert numbers: ");
    
    if(scanf("%u %u %u", &number, &digit_one, &digit_two) != 3){
        printf("Invalid input!");
        return -1;
    }

    unsigned new_number = 0;
    int digit_present = 0;
    while (number != 0) {
        int current_digit = number % 10;
        if(current_digit == digit_one) {
            current_digit = digit_two;
            digit_present = 1;
        }
        
        new_number = new_number * 10 + current_digit;
        number /= 10;
    }
    
    if(!digit_present){
        printf("Digit is not present in number!\n");
        return -1;
    }

    // reverse back the number
    while (new_number != 0) {
        number = (number * 10) + (new_number % 10);
        new_number /= 10;
    }
    

    printf("new number: %u\n", number);
    return 0;
}