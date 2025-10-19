#include <stdio.h>

int main()
{
    int x, y, z;
    const unsigned int inputsCount = 3;
    printf("Enter three integers\n");
    scanf("%d %d %d", &x, &y, &z);
    unsigned int posCount = (x > 0) + (y > 0) + (z > 0);
    unsigned int negCount = (x < 0) + (y < 0) + (z < 0); // or negCount = 3 - posCount
    
    printf("Positive numbers = %d\n Negative numbers = %d\n", posCount, negCount);
    
    return 0;
}
