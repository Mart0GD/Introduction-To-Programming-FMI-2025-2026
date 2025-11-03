#include <stdio.h>
#include <math.h>

int main()
{
    unsigned parent_two = 0;
    unsigned parent_one = 0;
    unsigned cross_point = 0;
    
    printf("Enter two numbers and a cross_point index\n");
    scanf("%u %u %u", &parent_one, &parent_two, &cross_point);

    cross_point %= 32; // ensure the index is valid (advanced) 
    
    unsigned mask = pow(2, cross_point) - 1;
    
    // save the first #cross_point bits
    unsigned buffer = parent_one & mask;
    
    // turn off first #cross_point bits
    parent_one &= ~mask;
    
    // apply crossing to parent_one
    parent_one |= parent_two & mask;
    
    // turn off first #cross_point bits
    parent_two &= ~mask;
    
    // apply crossing to parent_two
    parent_two |= buffer;
    
    printf("Parent one: %#x\n Parent two: %#x\n", parent_one, parent_two);
    return 0;
}
