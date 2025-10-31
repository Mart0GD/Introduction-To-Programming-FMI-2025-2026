#include <stdio.h>

// what will happen is these sitauitons
int main(){

    // =========== Question 1 ===========
    int x = 6;

    if(x >= 0)
        if(x <= 5) printf("x is in in [0,5]\n");
    else 
        printf("x is negative!\n");

    // =========== Question 2 ===========
    x = -6;

    if(x >= 0)
        if(x <= 5) printf("x is in in [0,5]\n");
    else 
        printf("x is negative!\n");
    
    // =========== Question 3 ===========

     x = 6;

    if(x >= 0)
    {
        if(x <= 5) printf("x is in in [0,5]\n");
    }
    else 
        printf("x is negative!\n");

    // =========== Question 4 ===========

    unsigned days = 0;
    unsigned month = 2;

    switch (month)
    {
        default: days += 1;
        case 4:
        case 6:
        case 9:
        case 11: days += 2;
        case 2: days += 28;
    }

    printf("days in month 2: %d", days);
}