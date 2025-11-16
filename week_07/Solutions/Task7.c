#include <stdio.h>
#include <math.h>

int is_prime(unsigned int number);

int main(){

    unsigned number;
    printf("Insert number: ");
    if(scanf("%u", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    printf("Is prime: %s", is_prime(number) ? "yes\n" : "no\n");
    return 0;
}

int is_prime(unsigned int number){
    if(number == 1 || number == 0) return 0; // edge cases

    int top = sqrt(number);
    for (int i = 2; i <= top; ++i) {
        if(number % i == 0) return 0;
    }
    
    return 1;
}