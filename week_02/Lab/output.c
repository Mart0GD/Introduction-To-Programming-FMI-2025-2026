#include <stdio.h>

int main(void) {
    // --- Integer types ---
    short               _short      = -1; 
    unsigned short      _ushort     = 1;

    int                 _int        = -2;
    unsigned int        _uint       = 2;

    long                _long       = -3;
    unsigned long       _ulong      = 3;

    long long           _longlong   = -4;
    unsigned long long  _ulonglong  = 4;

    // --- Character types ---
    char                _char       = 'a';
    unsigned char       _uchar      = 'a';

    // --- Floating-point types ---
    float               _float      = 1.2f;
    double              _double     = 1.2;
    long double         _ldouble    = 1.2L;

    // ------------------ INTEGER FORMATS ------------------

    printf("Signed short:        %hd\n",   _short);
    printf("Signed short:        %hi\n",   _short);

    printf("Signed int:          %d\n",    _int);
    printf("Signed int:          %i\n",    _int);
    
    printf("Signed long:         %ld\n",   _long);
    printf("Signed long:         %li\n",   _long);

    printf("Signed long long:    %lld\n",  _longlong);
    printf("Signed long long:    %lli\n",  _longlong);

    printf("Unsigned short:      %hu\n",   _ushort);   
    printf("Unsigned int:        %u\n",    _uint);
    printf("Unsigned long:       %lu\n",   _ulong);   
    printf("Unsigned long long:  %llu\n",  _ulonglong);

    // Character and string
    printf("Char:                %c\n",    _char);
    printf("Unsigned char:       %c\n",    _uchar);
    printf("C-string:            %s\n",    "This is a c-string");

    // ------------------ FLOATING POINT FORMATS ------------------

    // float
    printf("Float (%%f):          %f\n",    _float);    
    printf("Float (%%F):          %F\n",    _float);  
    printf("Float (%%g):          %g\n",    _float);    
    printf("Float (%%G):          %G\n",    _float);    

    // double
    printf("Double (%%lf):        %lf\n",   _double);   
    printf("Double (%%lF):        %lF\n",   _double);  
    printf("Double (%%lg):        %lg\n",   _double);   
    printf("Double (%%lG):        %lG\n",   _double);  

    // long double
    printf("Long double (%%Lf):   %Lf\n",   _ldouble);  
    printf("Long double (%%LF):   %LF\n",   _ldouble);  
    printf("Long double (%%Lg):   %Lg\n",   _ldouble);  
    printf("Long double (%%LG):   %LG\n",   _ldouble); 

    // Scientific notation (base-10 exponents)
    printf("Scientific float (%%e):         %e\n", 2.320166666666001); 
    printf("Scientific float (%%E):         %E\n", 2.320166666666001); 
    printf("Scientific double (%%le):       %le\n", 2.320166666666001); 
    printf("Scientific double (%%lE):       %lE\n", 2.320166666666001); 
    printf("Scientific long double (%%Le):  %Le\n", 2.320166666666001L); 
    printf("Scientific long double (%%LE):  %LE\n", 2.320166666666001L); 

    // ------------------ OCTAL / HEX FORMATS ------------------

    // Octal (8-base)
    printf("Octal short:         %ho\n",   5);     
    printf("Octal int:           %o\n",    6);      
    printf("Octal long:          %lo\n",   7L);     
    printf("Octal long long:     %llo\n",  8LL);    

    // Hexadecimal integers (16-base)
    printf("Hex short (%%hx):       %hx\n",   13);       
    printf("Hex short (%%hX):       %hX\n",   13);       
    printf("Hex int (%%x):          %x\n",    14);      
    printf("Hex int (%%X):          %X\n",    14);      
    printf("Hex long (%%lx):        %lx\n",   15L);      
    printf("Hex long (%%lX):        %lX\n",   15L);      
    printf("Hex long long (%%llx):  %llx\n", 16LL); 
    printf("Hex long long (%%llX):  %llX\n", 16LL); 

    // Hexadecimal floating-point
    printf("Hex float (%%a):        %a\n",    14.1f);   
    printf("Hex float (%%A):        %A\n",    14.1f);   
    printf("Hex double (%%la):      %la\n",   15.1);     
    printf("Hex double (%%lA):      %lA\n",   15.1);       
    printf("Hex long double (%%La): %La\n", 16.1L);    
    printf("Hex long double (%%LA): %LA\n", 16.1L);    

    return 0;
}
