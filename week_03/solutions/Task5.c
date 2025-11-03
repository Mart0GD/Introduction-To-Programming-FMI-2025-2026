#include "stdio.h"

int main(){

    int A,B,C,D;
    printf("Insert A,B,C,D: "); scanf("%d %d %d %d", &A, &B, &C, &D);

    int A_C_check = A < C;
    int bottom = C * A_C_check + A * !A_C_check;

    int B_D_check = B < D;
    int top = B * B_D_check + D * !B_D_check;

    int sum = (bottom + top) * (bottom <= top);

    int bottom_equals_top = bottom == top;
    sum = sum * !bottom_equals_top + bottom * bottom_equals_top;

    printf("Sum: %d\n", sum);
    return 0;
}
