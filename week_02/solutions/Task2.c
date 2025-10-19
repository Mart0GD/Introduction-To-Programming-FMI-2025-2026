#include <stdio.h>

int main(){
    short _short = 1; signed int _int = 1000 ; signed long _long = 1000000; signed long long _llong = 100000000;
    unsigned short _ushort = 2; unsigned int _uint = 2000; unsigned long _ulong = 2000000; unsigned long long _ullong = 200000000;
    float _float = 3.14; double _double = 3.14444444; long double _ldouble = 3.1444444444444;
    char _char = 'c';

    printf("Printing: \n"
            "%hd %d %ld %lld\n"
            "%hu %u %lu %llu\n"
            "%f %lf %Lf\n"
            "%c\n", _short, _int, _long, _llong, _ushort, _uint, _ulong, _ullong, _float, _double, _ldouble, _char);

    _short = 2; _int = 2000 ; _long = 2000000; _llong = 200000000;
    _ushort = 3;  _uint = 3000; _ulong = 3000000; _ullong = 300000000;
    _float = 4.14;_double = 4.14444444; _ldouble = 4.1444444444444;
    _char = 'h';

    printf("Printing: \n"
            "%hd %d %ld %lld\n"
            "%hu %u %lu %llu\n"
            "%f %lf %Lf\n"
            "%c\n", _short, _int, _long, _llong, _ushort, _uint, _ulong, _ullong, _float, _double, _ldouble, _char);

    return 0;
}