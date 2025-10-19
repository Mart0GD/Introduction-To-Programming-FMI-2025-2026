#include <stdio.h>

int main()
{   
    int x, y ,z;
    printf("Enter three 2-digit integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Product = %d, The remainder of product divided by 6 = %d", x*y*z, x*y*z%6);
    
    return 0;
}
