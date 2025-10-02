#include <stdio.h>

/*
*   Част от типовете в езика C: (зависи от системата 32bit/64bit)


*   ------------- 1 byte
*   signed char
*   unsigned char
*   -------------- 2 bytes
*   short/ short int / signed short / signed short int 
*   unsigned short / unsigned short int
*   -------------- 4 bytes
*   int / signed / signed int
*   unsigned / unsigned int
*   -------------- 4 bytes
*   long / long int / signed long / signed long int 
*   unsigned long / unsigned long int 
*   -------------- 8 bytes
*   long long / long long int / signed long long / signed long long int 
*   unsigned long long / unsigned long long int 
*   -------------- 
*   float --> 4 bytes
*   double --> 8 bytes
*   long double --> 16 bytes
*   --------------
*/


int main() {
    // Integer types
    char symbol = 'v';                          
    short short_integer = 10;               
    signed integer = 10000;                 
    long long_integer = -100000;            
    long long very_long_integer = 10000000; 

    // Unsigned Integer types (same sizes as the signed one, the difference is in the range)
    unsigned char u_symbol;
    unsigned int u_integer;
    unsigned short u_short_integer;
    unsigned long u_long_integer;
    unsigned long long u_very_long_integer;

    // Floating Point 
    float single_precision_real = 3.14;
    double double_precision_real = 3.141592;
    long double long_double_precision_real = 3.1415926535;

    // no boolean type like other languages
    int false = 0;  // false
    int true  = 1;  // everything apart 0 

    return 0;
}