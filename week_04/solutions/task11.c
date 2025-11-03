#include "stdio.h"

size_t get_time(short time);

int main(){

    // we won't be using more than 12 bits
    short binary_time_one, binary_time_two;
    printf("Insert binary times: ");
    if(scanf("%hd %hd", &binary_time_one, &binary_time_two) != 2){
        return -1;
    }

    size_t time_one = get_time(binary_time_one);
    if(time_one == -1) return -1;
    size_t time_two = get_time(binary_time_two);
    if(time_two == -1) return -1;

    size_t diff = time_one - time_two;

    size_t h = diff / 3600;
    size_t m = diff % 60;

    printf("diff: ");
    printf("%02d:%02d\n", h, m);

    return 0;
}

size_t get_time(short time){
    const int AM_PM_MASK_DISTANCE = 12;
    const int HOUR_FIRST_DIGIT_DISTANCE = 6;
    const int HOUR_SECOND_DIGIT_DISTANCE = 10;


    unsigned minute_mask                = 0b0000000111111;
    unsigned hour_second_digit_mask     = 0b0001111000000;
    unsigned hour_first_digit_mask      = 0b0110000000000;
    unsigned am_pm_mask                 = 0b1000000000000; // 0 --> 12 1 --> 24

    int american = !((time & am_pm_mask) >> AM_PM_MASK_DISTANCE);

    size_t minutes = (time & minute_mask); // direct
    
    int hours_d2    = (time & hour_second_digit_mask) >> HOUR_FIRST_DIGIT_DISTANCE;
    int hours_d1    = (time & hour_first_digit_mask) >> HOUR_SECOND_DIGIT_DISTANCE;
    int hours       = 10 * hours_d1 + hours_d2;
    
    if(hours > 12 && american || hours_d2 > 9 || hours > 23 || minutes > 59) {
        printf("invalid format!\n");   
        return -1;
    }

    printf("%02d:%02d\n", hours, minutes);
    return minutes * 60 + hours * 3600;
}
