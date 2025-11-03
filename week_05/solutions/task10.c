#include <stdio.h>
#include <math.h>
/*
По въведени координати на центровете и радиусите на две окръжности намерете и изведете взаимното 
им положение (дали се пресичат, допират (вътрешно/външно), съдържат се една в друга или не се пресичат)
*/

int main(){

    int 
    c1x, c1y,
    c2x, c2y;
    
    unsigned r1, r2;

    printf("Insert radius center 1 and 2: ");
    if(scanf("%d %d %d %d", &c1x, &c1y, &c2x, &c2y) != 4){
        printf("Invalid input!");
        return -1;
    }

    printf("Insert radius 1 and radius 2: ");
    if(scanf("%d %d", &r1, &r2) != 2){
        printf("Invalid input!");
        return -1;
    }

    // we will use squared distance for simplicity's sake
    float distance = sqrt((c2x - c1x) * (c2x - c1x) +
                          (c2y - c1y) * (c2y - c1y));

    unsigned diff = (r1 > r2) ? (r1 - r2) : (r2 - r1);

    const double EPS = 1e-6;

    int external_tangent_check 
    = distance - (r1 + r2) >= 0 ? distance - (r1 + r2) : -(distance - (r1 + r2));

    int internal_tangent_check
    = distance - diff >= 0 ? distance - diff : -(distance - diff);

    if      (distance <= EPS && r1 == r2)               printf("Same circle!");
    else if (distance > r1 + r2)                        printf("No intersection!");
    else if (external_tangent_check < EPS)              printf("External tangent!");
    else if (internal_tangent_check < EPS)              printf("Internal tangent!");
    else if (distance < r1 + r2 && distance > diff)     printf("Two intersection points!");
    else if (distance < diff)                           printf("One circle inside the other!");
    
    return 0;
}