#include "stdio.h"

int min(int a, int b);
int max(int a, int b);

int main(){
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    printf("Insert coordinates for rectangle 1: "); scanf("%d %d %d %d", &Ax, &Ay, &Cx, &Cy);

    int Ex, Ey, Fx, Fy, Gx, Gy, Hx, Hy;
    printf("Insert coordinates for rectangle 2: "); scanf("%d %d %d %d", &Ex, &Ey, &Gx, &Gy);

    Bx = Cx,    By = Ay;
    Dx = Ax,    Dy = Cy;

    Fx = Gx,    Fy = Ey;
    Hx = Ex,    Hy = Gy;

    int new_x1 = max(Ax,Ex);
    int new_y1 = max(Ay,Ey);

    int new_x2 = min(Cx,Gx);
    int new_y2 = min(Cy,Gy);

    int width  = max(0, new_x2 - new_x1);
    int height = max(0, new_y2 - new_y1);

    int common_area = width * height;
    
    printf("Area: %d", common_area);
    return 0;
}

int min(int a, int b){
    int check = a < b;
    return check * a + !check * b;
}

int max(int a, int b){
    int check = a > b;
    return check * a + !check * b;
}
