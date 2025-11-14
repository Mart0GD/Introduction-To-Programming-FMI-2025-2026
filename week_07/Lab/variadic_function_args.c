#include <stdio.h>

// function forward declaration
int add(int number_of_agrs, ...);

int main(){

    /*
        Variadic function arguments are used to pass an unknow number of parameteres to a function
        ** For people used to C# or Java this is the same as params keyword **
    */

    // An easy example for a function with variable number of arguments is printf
    // printf(<string to be formated>, arg1, arg2, ...);

    /*
        in this case printf starts reading the string:
        1) it sees %d it knows to read one argument from the list of type signed int
        2) it reaches the end,
        3) we pass the only argument in the list which is a function with 5 arguments to sum
    */
    printf("%d\n", add(5 ,1 ,2 ,3 ,4 ,5));
    return 0;
}

// To be able to work with variable number of arguments we'll have to use the stdarg.h header 
#include <stdarg.h>

int add(int number_of_agrs, ... /* the va_arg ... should always be at the end*/){

    // this is a special defined type for storing the arguments
    va_list list_to_extract_argumets;

    /*
        void va_start(va_list ap, paramN)

        ap      --> the va_list to be initialized for later use
        paramN  --> the rightmost param before the ... 
    */
    va_start(list_to_extract_argumets, number_of_agrs);

    /*
        type va_arg(va_list ap, type)

        Extracts the next argument from the argument list provided in the function
        If there are no further arguments or if the next argument is not of the specified type
        we have undefined behavior!
    */
    int sum  = va_arg(list_to_extract_argumets, int);
    for(int i = 2; i <= number_of_agrs; ++i){
        sum += va_arg(list_to_extract_argumets, int);
    }


    /*
        void va_end(va_list ap)

        Prevents the list to be used any further. If not used than we have indefined behaviour. 
    */
    va_end(list_to_extract_argumets);

    return sum;
}


/*
    read more about the topic:

    > https://publications.gbdirect.co.uk/c_book/chapter9/stdarg.html
    > https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1548.pdf (The C11 standart read chapter 9.11)

*/