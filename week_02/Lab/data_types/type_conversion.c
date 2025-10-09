#include <stdio.h>

int main(){

    float real = 2.334;
    
    // Implicit type conversion with loss
    int result_with_loss = real;                // 2

    // Implicit type conversion without loss
    double result_without_loss = real;          // 2.334

    // Explicit type conversion
    int     cast_with_loss      = (int)real;    // 2
    double  cast_without_loss   = (double)real; // 2.334

    /*   Type promotion
           char / short
                ↓
               int
                ↓
            unsigned int
                ↓
              long
                ↓
           unsigned long
                ↓
            long long
                ↓
        unsigned long long
                ↓
              float
                ↓
              double
                ↓
           long double

        !! Important !!
    */
    return 0;
}