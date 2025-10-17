#include <stdio.h>

int main()
{
    // format specifiers [flags][width][.precision][lenght]modificator
    
    // 1. [flags]
    int x = 25;
    // My variable x = 25   , cool right? left-justification
    printf("My variable x = %-5d, cool right?\n", x); // using '-'
    
    // My variable x =    25, cool right? Right-justification is performed by default
    printf("My variable x = %5d, cool right?\n", x); // default justification
    
    // My variable x = 00025, cool right?
    printf("My variable x = %05d, cool right?\n", x); // using '0'
    
    
    // 2. [width]
    // My variable x = 25             , cool right?
    printf("My variable x = %-15d, cool right?\n", x); // using width + left justification
    
    // My variable x =              25, cool right?
    printf("My variable x = %*d, cool right?\n", 15, x);  // The width is not specified in the format string,
                                                         //but as an additional integer value argument
                                                        //preceding the argument that has to be formatted.
    
    // 3. [precision]
    // for integers precisions specifies the minimum number of digits to be written
    // if the value is shorter than this number, the result gets padded with leading zeros
    
    // My variable x = 00025, cool right?
    printf("My variable x = %.5d, cool right?\n", x);
    
    // My variable x = 00025, cool right?
    printf("My variable x = %.*d, cool right?\n", 5, x);
    
    
    // 4. [length]
    // The length sub-specifier modifies the length of the data type
    
    // h, l, ll
    return 0;
}
