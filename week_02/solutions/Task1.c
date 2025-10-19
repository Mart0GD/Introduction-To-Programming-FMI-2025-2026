#include <stdio.h>

int main()
{
    // Task1
    printf("%d ", 0 / 0); // throws an exception (Division by zero)
    
    printf("%g ", 0.0 / 0.0); // -nan (value of a broken floating point number)    
    printf("%G ", 0.0 / -0.0); // -NAN
  
    printf("%g ", 1.0 / 0/0); // inf
     printf("%G ", 1.0 / 0/0); // INF
  
    float res = 0.1 + 0.1;
    printf("%.20f ", res); // printf 20 digits after the floating point, however float maintains
                               // precision up to 6 digits after the '.', so the remaining digits make up a funky result
    
    unsigned int a = 0;
    printf("%u ", a - 1); // defaults to the largest number an unsigned int can hold = 2^32 - 1
  
    int x = 4;
    int y = 2 * x++ * 10 / x; // y = 16 = 2*4*10 / 5
    
    int x = 1;
    int res = 2 * (x++, x--) - (10 * --x); // res = 4
      
    return 0;
}
