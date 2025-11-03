#include <stdio.h>
#include <math.h>

int main(){
    const double EPS = 0.0000001;
    unsigned int number;
    scanf("%u", &number);

    // one way
    float res = sqrt(number);
    int is_square = res - (int)res <= EPS;
    
    if(is_square) puts("prefect square!");
    else puts("not perfect square!");

    // second way
    res = (int)sqrt(number);

    if(res * res == number) puts("prefect square!");
    else                    puts("not perfect square!");

    return 0;
}