#include <stdio.h>

int main()
{   
    short z1;
    int z2;
    long z3;
    long long z4;

    unsigned short n1;
    unsigned int n2;
    unsigned long n3;
    unsigned long long n4;

    float r1;
    double r2;
    long double r3;

    char c1;

    scanf("%hd %d %ld %lld", &z1, &z2, &z3, &z4);
    scanf("%hu %u %lu %llu", &n1, &n2, &n3, &n4);
    scanf("%f %lf %Lf", &r1, &r2, &r3);
    scanf("%c", &c1);
    
    return 0;
}
