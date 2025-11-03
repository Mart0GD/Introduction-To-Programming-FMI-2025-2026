#include "stdio.h"
#include "math.h"

int main(){

    double px,py; // point to check
    scanf("%lf %lf", &px, &py);


    // first we lay out our vectors
    const double
    abx = -1    , aby = 6,
    acx = 6     , acy = 1,
    apx = px + 4, apy = py + 1;

    /*
        Point P lays between AB and AC <=> the cross product axc and cxb have the same sign as axb
        AB x AP =   | ABx   ABy | = ABx * APy - ABy * APx;
                    | APx   APy |
    */
    double cross_ab_ap = abx * apy - aby * apx;
    double cross_ap_ac = apx * acy - apy * acx;

    double cross_ab_ac = abx * acy - aby * acx;

    // check for the same sign (orientation)
    int is_between = cross_ab_ac > 0 && cross_ab_ap > 0 && cross_ap_ac > 0 ||
                     cross_ab_ac < 0 && cross_ab_ap < 0 && cross_ap_ac < 0;
    
    const double circle_x = -3, circle_y = -5;
    const double radius = 1;

    int is_out_of_circle = (px - circle_x) * (px - circle_x) + (py - circle_y) * (py - circle_y) > radius * radius;

    const double outer_circle_x = -4, outer_circle_y = -1;
    const double o_radius = 6;

    int is_inside_outer_circle = (px - outer_circle_x) * (px - outer_circle_x) + 
                                 (py - outer_circle_y) * (py - outer_circle_y) < o_radius * o_radius; 
    
    printf("Inside: %d\n", is_inside_outer_circle && is_out_of_circle && !is_between); // final condition
    return 0;
}


/*
    Resources that might help --> https://math.stackexchange.com/questions/169998/figure-out-if-a-fourth-point-resides-within-an-angle-created-by-three-other-poin

    -------------
    How do we get a vector from A(x1,y1) to B(x2,y2)?
    Like this: AB(Bx - Ax, By - Ay) --> AB(x2 - x1, y2 - y1)
*/
