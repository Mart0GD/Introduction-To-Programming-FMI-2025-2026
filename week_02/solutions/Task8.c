#include <stdio.h>

int main()
{
    unsigned int x, y;
    printf("Enter two unsigned integers:\n");
    scanf("%d %d", &x, &y);
    
    // using a temporary variable
    printf("x = %d, y = %d\n", x, y);
    // reverse them once
    unsigned temp = x;
    x = y;
    y = temp;
    printf("x = %d, y = %d\n", x, y);

    // reverse them twice by using arithmetics
    x = x + y;
    y = x - y;
    x = x - y;
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}
