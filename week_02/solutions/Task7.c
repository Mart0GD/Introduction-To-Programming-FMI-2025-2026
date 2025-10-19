#include <stdio.h>

int main()
{ 
    unsigned int x;
    printf("Enter a five digit unsigned integer: ");
    scanf("%d", &x);
    unsigned int dig5 = x % 10; // extract last digit
    unsigned int dig4 = (x / 10) % 10; // remove the last digit by dividing by 10, then extract 4th digit
    unsigned int dig3 = (x / 100) % 10;
    unsigned int dig2 = (x / 1000) % 10;
    unsigned int dig1 = (x / 10000);
    printf("In order:\n");
    printf("%d %d %d %d %d\n", dig1, dig2, dig3, dig4, dig5);

    printf("Reversed order:\n");
    printf("%d %d %d %d %d\n", dig5, dig4, dig3, dig2, dig1);
    
    unsigned int sum = dig1 + dig2 + dig3 + dig4;
    printf("Sum of digits = %u\n", sum);
    
    return 0;
}
