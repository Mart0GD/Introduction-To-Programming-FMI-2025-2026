#include <stdio.h>
#include <math.h>   // Needed for sqrt() and pow()
#include <stdlib.h> // Needed for abs()

int main(void) {
    int a = -15;
    double x = 25.0;
    double base = 2.0, exponent = 3.0;

    // abs() - returns the absolute value of an integer
    // Useful when you want to ignore the sign of a number.
    int absValue = abs(a);
    printf("abs(%d) = %d\n", a, absValue);

    // sqrt() - returns the square root of a floating point number
    // Commonly used in geometry, physics, statistics, etc.
    double root = sqrt(x);
    printf("sqrt(%.2f) = %.2f\n", x, root);

    // pow() - returns base raised to the power of exponent
    // Useful for floating point powers. Slower than repeated multiplication.
    double power = pow(base, exponent);
    printf("pow(%.2f, %.2f) = %.2f\n", base, exponent, power);

    // A faster alternative for small integer powers:
    double fastPower = base * base * base;  // 2^3
    printf("Fast 2^3 using multiplication = %.2f\n", fastPower);

    return 0;
}
