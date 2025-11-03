#include "stdio.h"
#include "stdlib.h"

int main(){

    int 
    x1,y1,
    x2,y2;
    
    printf("Insert two points (x,y): "); scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int distance_x = (x2 - x1) * (x2 - x1);
    int distance_y = (y2 - y1) * (y2 - y1);

    // horse
    int horse = distance_x + distance_y  == 5;

    // king 
    int king = (distance_x + distance_y <= 2)        && distance_x + distance_y != 0;

    // tower
    int tower = (distance_x == 0 || distance_y == 0)  && distance_x + distance_y != 0;

    // bishop
    int bishop = (distance_x == distance_y)           && distance_x + distance_y != 0;

    // queen
    int queen = bishop || tower;



    printf( "Horse:  %d\n"
            "King:   %d\n" 
            "Tower:  %d\n"
            "Bishop: %d\n"
            "Queen:  %d\n", horse, king, tower, bishop, queen);
    return 0;
}