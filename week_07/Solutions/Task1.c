#include "stdio.h"

int check_date(unsigned day, unsigned month, unsigned year);

int main(void){

    unsigned int day, month, year;
    printf("Insert date: ");

    if(scanf("%u.%u.%u", &day, &month, &year) != 3){
        printf("Invalid input!");
        return -1;
    }

    printf(check_date(day, month, year) ? "Correct\n" : "Incorrect\n");

    return 0;
}


int check_date(unsigned day, unsigned month, unsigned year){
    if(day > 31 || month > 12) return 0;

    int leap = (year % 4 == 0 && year % 100) || (year % 400 == 0);

    int max_days = 0;
    switch (month)
    {
        default: max_days += 1;
        case 4:
        case 6:
        case 9:
        case 11: max_days += 2;
        case 2 : max_days += 28;
    }
    max_days += leap ? 1 : 0;

    /*
        Another way

         int max_days;
        switch (month) {
            case 4: case 6: case 9: case 11:
                max_days = 30;
                break;
            case 2:
                max_days = leap ? 29 : 28;
                break;
            default:
                max_days = 31;
                break;
    }
    */

    return day <= max_days;
}