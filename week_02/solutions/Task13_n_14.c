#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int a, b, c; // for this task you can paste the following in the top of the file: #include <math.h>
                          // now you can use "sqrt()"
    printf("Enter sides of a triangle:\n");
    scanf("%u %u %u", &a, &b, &c);

    float perimeter = -1;
    float area = -1;
    
    unsigned int isValid = (a + b > c) && (a + c > b) && (b + c > a);
    perimeter += isValid * (1 + a + b + c); // if isValid = 0, then perimeter will be -1
   
    float sP = perimeter / 2; // semi-perimeter

    // using Heron's formula for area of a triangle
    area += isValid * (1 + sqrt(sP*(sP - a)*(sP - b)*(sP - c)));
    printf("Perimeter = %d, Area = %.2f", perimeter, area);
    
    return 0;
}
