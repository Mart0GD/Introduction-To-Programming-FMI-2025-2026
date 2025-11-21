#include <stdio.h>

void foo(int *arr) {
    /*
        Here we get a copy of the pointer to the first element of the array. 
        We still have access to the data and we can modify it, but we cannot
        modify the array *type* itself (size information is lost).
    */

    printf("First element: %d\n", *arr);
}

void foo_direct(int (*arr)[5]) {
    /*
        Here we get a pointer to the entire array (type: int (*)[5]).
        This preserves the array's size information.
    */

    printf("Size of array: %d\n", sizeof(*arr) / sizeof(*(arr[0])));
}

// --------------------------------------------------------------
// K&R (Kernighan & Ritchie) C syntax—obsolete but still supported
// --------------------------------------------------------------
void goo(a, b)
int *a;
int *b;
{
    // old K&R function body
}


int main() {

    // ------------------------------------------------------
    //                       Pointers
    // ------------------------------------------------------

    int a;

    // Correct way to print pointers:
    printf("%p\n", (void*)0); // NULL pointer
    printf("%p\n", (void*)&a); // address of 'a' given by the OS

    // ------------------------------------------------------
    //                 Pointer arithmetic & arrays
    // ------------------------------------------------------

    int arr[5] = {0};
    arr[0] = 6;
    arr[1] = 9;

    int *arr_ptr = arr;         // pointer to first element (int*)
    int (*arr_ptr2)[5] = &arr;  // pointer to whole array (int (*)[5])

    // Both access arr[0]:
    printf("%d\n", *arr);        // prints 6
    printf("%d\n", (*arr_ptr2)[0]); // prints 6

    foo(arr);       // pass pointer to arr[0]
    foo_direct(&arr); // pass pointer to the array

    return 0;
}
