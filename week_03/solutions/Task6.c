#include "stdio.h"

int main(){
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    printf("Insert coordinates for rectangle 1: "); scanf("%d %d %d %d", &Ax, &Ay, &Cx, &Cy);

    int Ex, Ey, Fx, Fy, Gx, Gy, Hx, Hy;
    printf("Insert coordinates for rectangle 2: "); scanf("%d %d %d %d", &Ex, &Ey, &Gx, &Gy);

    Bx = Cx,    By = Ay;
    Dx = Ax,    Dy = Cy;

    Fx = Gx,    Fy = Ey;
    Hx = Ex,    Hy = Gy;
    
    int inside = 
    Ax > Ex  && Ax < Gx && Ay > Ey && Ay < Gy ||
    Bx > Ex  && Bx < Gx && By > Ey && By < Gy ||
    Cx > Ex  && Cx < Gx && Cy > Ey && Cy < Gy ||
    Dx > Ex  && Dx < Gx && Dy > Ey && Dy < Gy ||
    
    Ex > Ax && Ex < Cx && Ey > Ay && Ey < Cy  || 
    Fx > Ax && Fx < Cx && Fy > Ay && Fy < Cy  || 
    Gx > Ax && Gx < Cx && Gy > Ay && Gy < Cy  || 
    Hx > Ax && Hx < Cx && Hy > Ay && Hy < Cy  ||
    Ax == Ex && Ay == Ey && Cx == Gx && Cy == Gy;

    // another way --> bounding box
    // int inside_two = !(Cx <= Ex || Gx <= Ax || Cy <= Ey || Gy <= Ay);

    printf("Inside: %d\n", inside);
    //printf("Inside: %d\n", inside_two);
    return 0;
}
