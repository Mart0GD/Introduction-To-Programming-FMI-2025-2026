#include <stdio.h>

int main()
{
    int year; // [0,2025] first 11 bits
    int month; // [1, 12] next 4 bits
    int day; // [1,31] next 5 bits
    
    // masks
    int year_mask = 2047;
    int month_mask = 15;
    int day_mask = 31;
    
    // required bit-shifts
    const int month_shift = 11;
    const int day_shift = 15;
    
    scanf("%d %d %d", &year, & month, &day);
    
    int encoded_date = 0;
    encoded_date |= (year & year_mask) |
                    (month & month_mask) << month_shift |
                    (day & day_mask) << day_shift;
                    
    int output_year = encoded_date & year_mask;
    int output_month = (encoded_date >> month_shift) & month_mask; 
    int output_day = (encoded_date >> day_shift) & day_mask;
    
    printf("Year: %d\n Month: %d\n Day: %d\n", output_year, output_month, output_day);

    return 0;
}
