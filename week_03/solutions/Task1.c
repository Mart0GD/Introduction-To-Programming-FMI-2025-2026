#include <stdio.h>
#include <math.h>

int inside_square(float x, float y);
int inside_little_square(float x, float y);
int inside_circle(float x, float y);
int inside_shape(float x, float y);

int main(){

    float x, y;
    printf("Insert point (x,y): "); scanf("%f %f", &x, &y);

    int res1 = inside_square(x, y);
    int res2 = inside_little_square(x, y);
    int res3 = inside_circle(x,y);
    int res4 = inside_shape(x, y);

    printf("Inside square:          %d\n", res1);
    printf("Inside little square:   %d\n", res2);
    printf("Inside circle:          %d\n", res3);
    printf("Inside shape:           %d\n", res4);
    return 0;
}

int inside_square(float x, float y){
    return x <= 1 && x >= -1 && y <= 1 && y >= -1;
    /*
        алтернативно
        return fabs(x) <= 1 && fabs(y) <= 1;
    */
}

int inside_little_square(float x, float y){
    return x >= 1 && x <= 2 && y >= 1 && y <= 2;
}

int inside_circle(float x, float y){
    const float radius = 1.0f;
    float r_x = 1, r_y = 1;
    
    float distance_between = (x - r_x) * (x - r_x) + (y - r_y) * (y - r_y);
    return distance_between <= radius * radius; // radius is 1 no pow needed
}

int inside_shape(float x, float y){
    int check_one =  x*x + y*y <= 4.0f && y >= 0;
    int check_two = (x + 1) * (x + 1) + y*y <= 1;
    int check_three = (x - 1) * (x - 1) + y*y < 1;

    return (check_one || check_two) && !check_three;
}