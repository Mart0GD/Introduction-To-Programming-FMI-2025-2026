#include <stdio.h>

int main()
{
    int x, y, z;
    printf("Enter three integers\n");
    scanf("%d %d %d", &x, &y, &z);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    int temp = x;
    x = y;
    y = z;
    z = temp;
    
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    
    return 0;
}
