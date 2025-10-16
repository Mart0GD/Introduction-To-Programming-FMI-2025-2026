#include "stdio.h"

int main(){
    const double EPSILON = 1.0E-6; // 0.0000001;

    // if we want to compare floating point values for equality we use an epsilon value
    float a = 1.2f;
    float b = 4.3;
    float a_close = 1.200001;

    printf("a == b :        %d\n", b - a        <= EPSILON);
    printf("a == a_close :  %d\n", a_close - a  <= EPSILON);

    return 0;
}