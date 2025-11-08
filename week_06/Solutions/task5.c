#include <stdio.h>

int main(){

    unsigned int a, b;
    printf("insert two numbers: ");

    if(scanf("%u %u", &a, &b) != 2){
        printf("Invalid input!");
        return -1;
    }

    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    
    printf("Greatest common divisor: %u\n", a);
    return 0;
}