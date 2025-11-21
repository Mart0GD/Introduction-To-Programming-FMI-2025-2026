#include <stdio.h>

void increment_by_value(int a);
void increment_by_address(int *a);

int main(void) {

    int a = 0;

    printf("Initial a = %d\n", a);

    // Pass by value (a copy is passed)
    increment_by_value(a);
    printf("After increment_by_value, a = %d\n", a);

    // Pass by address (allows modifying the original variable)
    increment_by_address(&a);
    printf("After increment_by_address, a = %d\n", a);

    return 0;
}

/*
    Passing a variable by value:

    The function receives a COPY of the variable.
    Modifying it does NOT change the original.
*/
void increment_by_value(int a) {
    ++a; 
}

/*
    Passing a variable by address:

    The function receives a copy of the ADDRESS of 'a'.
    Using the dereference operator (*) we can access and modify
    the original variable's stored value.
*/
void increment_by_address(int *a) {
    ++(*a);
}
