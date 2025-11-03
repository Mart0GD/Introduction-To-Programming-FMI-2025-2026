#include <stdio.h>
#include <math.h>

int main(){

    double a,b,c;
    printf("Inert parameters: ax^2 + bx + c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double det = b*b - 4*a*c;

    if(a != 0 && det >=0){
        double sqrt_det = sqrt(det);

        double root_1 = (-b + sqrt_det) / 2*a;
        double root_2 = (-b - sqrt_det) / 2*a;

        printf("Root 1 is: %lf\n", root_1);
        printf("Root 2 is: %lf\n", root_2);
    }
    else printf("no real roots!");

    return 0;
}