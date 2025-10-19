#include <stdio.h>

int main()
{   
    int x, y;
    float fX, fY;
    printf("Enter two integer numbers: ");
    scanf("%d %d", &x, &y);
    
    printf("Sum = %d, Difference = %d, Product = %d, Division = %d, Division with remainder = %d ", x+y, x-y, x*y, x/y, x%y);
    
    printf("Enter two float numbers: ");
    scanf("%f %f", &fX, &fY);
    // hint: you can't perform division with a remainder on float numbers
    printf("Sum = %.2f, Difference = %.2f, Product = %.2f, Division = %.2f", fX+fY, fX-fY, fX*fY, fX/fY);
    
    return 0;
}

// no input of y will be 0!!
