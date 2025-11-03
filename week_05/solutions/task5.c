#include <stdio.h>

int main(){

    int x1, y1, x2, y2;
    printf("Insert coordinates: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int perp = (x1 * x2 + y1 * y2) == 0;

    if(perp)    puts("Perpendicular");
    else        puts("Not perpendicular");

    return 0;
}