#include "stdio.h"
#include "math.h"

int main(){

    double px,py;
    scanf("%lf %lf", &px, &py);

    // vectors
    const double 
    abx = 3     , aby = 6,
    acx = -3    , acy = 4,
    apx = px + 2, apy = py + 1;

    // corss product
    double cross_ab_ap = abx * apy - aby * apx;
    double cross_ap_ac = apx * acy - apy * acx;

    double cross_ab_ac = abx * acy - aby * acx;

    // check sign
    int is_between = cross_ab_ac >= 0 && cross_ab_ap >= 0 && cross_ap_ac >= 0 ||
                     cross_ab_ac <= 0 && cross_ab_ap <= 0 && cross_ap_ac <= 0;
    
    const double 
    circle_x = -1, circle_y = 4,
    circle_radius = 1;

    int is_outside_circle = (px - circle_x) * (px - circle_x) + (py - circle_y) * (py - circle_y) > circle_radius;

    const double ax = -2, ay = -1;
    const double outer_radius = sqrt(36 + 9); // pythagorean theorem

    int is_in_range = (px - ax) * (px - ax) + (py - ay) * (py - ay) < outer_radius * outer_radius;

    printf("Inside: %d\n", is_in_range && is_outside_circle && is_between);
    return 0;
}