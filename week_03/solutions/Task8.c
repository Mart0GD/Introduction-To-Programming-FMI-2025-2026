#include "stdio.h"

int main(){
    const double EPSILON = 0.0000001;
    
    int r;
    printf("Insert circle radius: "); scanf("%d", &r);

    double px, py;
    printf("Insert point: "); scanf("%lf %lf", &px, &py);

    int on_border = px * px + py * py <= EPSILON;
    int inside = px * px + py * py < r * r && !on_border;
    int outside = !inside && !on_border;
    
    printf("Inside:     %d\n",    inside);
    printf("On border:  %d\n", on_border);
    printf("outside:    %d\n",   outside);

    return 0;
}