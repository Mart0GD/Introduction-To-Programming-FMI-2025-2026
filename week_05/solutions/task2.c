#include <stdio.h>

int main(){

    unsigned int year, month;
    printf("Insert year and month: "); scanf("%u %u", &year, &month);

    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    unsigned days = 0;
    switch (month)
    {
        default: days += 1;
        case 4:
        case 6:
        case 9:
        case 11: days += 2;
        case 2: days += leap && month == 2 ? 29 : 28;
    }

    printf("Days: %d", days);

    return 0;
}