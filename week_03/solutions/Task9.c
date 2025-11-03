#include "stdio.h"

int main(){

    int r, xc, yc;
    printf("Insert radius, x, y: "); scanf("%d %d %d", &r, &xc, &yc);

    int x1, y1, x2, y2;
    printf("Insert two points: "); scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    int closer_to_left_x  = xc <= x1;
    int closer_to_right_x = xc >= x2;
    int inside_x = !closer_to_left_x && !closer_to_right_x;

    int closer_to_bottom_y = yc <= y1;
    int closer_to_top_y = yc >= y2;
    int inside_y = !closer_to_bottom_y && !closer_to_top_y;

    int final_x = closer_to_left_x * x1 + closer_to_right_x * x2 + inside_x * xc;
    int final_y = closer_to_bottom_y * y1 + closer_to_top_y * y2 + inside_y * yc;

    float distance = (final_x - xc)*(final_x - xc) + (final_y - yc)*(final_y - yc);
    int inside = distance <= r*r;

    printf("%d", inside);
}
