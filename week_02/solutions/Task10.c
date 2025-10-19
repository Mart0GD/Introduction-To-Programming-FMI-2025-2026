#include <stdio.h>

int main()
{
    int x, y;
    printf("Enter two integers:\n");
    scanf("%d %d", &x, &y);
    
    int sum = x + y; // use a new variable for ease
    int diff = x - y;
    int res = sum*sum*sum*sum - diff*diff; // sum^4 - diff^2

    printf("Result = %d", res);
    
    return 0;
}
