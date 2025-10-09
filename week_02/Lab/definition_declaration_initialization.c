#include <stdio.h>

int main() {
    // Declaration vs Definition vs Initialization
    // Syntax: <type> <variable_name> = <value>;

    // Declaration + Definition (without initialization)
    int myInt; // memory contains an indeterminate value (often called "garbage")
    printf("Uninitialized value --> %d\n", myInt);

    // Assignment (assigning a value after declaration)
    myInt = 42;
    printf("New value in memory --> %d\n", myInt);

    // Declaration + Definition with initialization
    int myOtherInt = 100;
    printf("myOtherInt value in memory --> %d\n", myOtherInt);

    /*
        Declaration: gives the type and name; (for the compiler)
        Definition: allocates storage; (for the linker)
        Initialization: assigns an initial value at definition time;
    */

    // Const values must be initialized upon Declaration and cannot be changed
    const int   FINGERS_ON_MY_HAND  = 10;
    const float PI                  = 3.141592;

    // this will result in an error
    // PI = 2;
}