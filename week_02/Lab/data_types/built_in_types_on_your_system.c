#include <stdio.h>

#include <limits.h>  // integer limits (e.g., INT_MAX, CHAR_MAX)
#include <float.h>   // floating-point limits (e.g., FLT_DIG, DBL_DIG)


int main(void) {
    // --- Integer max values from <limits.h> ---
    short               _short      = SHRT_MAX; 
    unsigned short      _ushort     = USHRT_MAX;

    int                 _int        = INT_MAX;
    unsigned int        _uint       = UINT_MAX;

    long                _long       = LONG_MAX;
    unsigned long       _ulong      = ULONG_MAX;

    long long           _longlong   = LLONG_MAX;
    unsigned long long  _ulonglong  = ULLONG_MAX;

    char                _char       = CHAR_MAX;
    unsigned char       _uchar      = UCHAR_MAX;

    // ------------------ TYPE SIZES ------------------
    printf("The size of a signed short is:          %u bytes\n", sizeof(short));
    printf("The size of an unsigned short is:       %u bytes\n", sizeof(unsigned short));

    printf("The size of a signed int is:            %u bytes\n", sizeof(int));
    printf("The size of an unsigned int is:         %u bytes\n", sizeof(unsigned int));

    printf("The size of a signed long is:           %u bytes\n", sizeof(long));
    printf("The size of an unsigned long is:        %u bytes\n", sizeof(unsigned long));

    printf("The size of a signed long long is:      %u bytes\n", sizeof(long long));
    printf("The size of an unsigned long long is:   %u bytes\n", sizeof(unsigned long long));

    printf("The size of a signed char is:           %u byte\n", sizeof(char));
    printf("The size of an unsigned char is:        %u byte\n", sizeof(unsigned char));

    printf("The size of a float is:                 %u bytes\n", sizeof(float));
    printf("The size of a double is:                %u bytes\n", sizeof(double));
    printf("The size of a long double is:           %u bytes\n", sizeof(long double));

    printf("\n");

    // ------------------ MAXIMUM VALUES ------------------
    printf("Max signed short:                       %hd\n",   _short);
    printf("Max unsigned short:                     %hu\n",   _ushort);   

    printf("Max signed int:                         %d\n",    _int);
    printf("Max unsigned int:                       %u\n",    _uint);

    printf("Max signed long:                        %ld\n",   _long);
    printf("Max unsigned long:                      %lu\n",   _ulong);   

    printf("Max signed long long:                   %lld\n",  _longlong);
    printf("Max unsigned long long:                 %llu\n",  _ulonglong);

    printf("Max signed char value:                  %c\n",    _char);
    printf("Max unsigned char value:                %c\n",    _uchar);

    putchar('\n');

    // ------------------ FLOATING-POINT PRECISION ------------------
    // FLT_DIG, DBL_DIG, LDBL_DIG → number of reliable decimal digits
    int _float_digits   = FLT_DIG;
    int _double_digits  = DBL_DIG;
    int _ldouble_digits = LDBL_DIG;

    printf("Max reliable decimal digits for float:        %d\n", _float_digits);    
    printf("Max reliable decimal digits for double:       %d\n", _double_digits);   
    printf("Max reliable decimal digits for long double:  %d\n", _ldouble_digits);  

    return 0;
}
