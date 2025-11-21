#include <stdio.h>

/*
    ===========================================================
    compile-time size checking using "static" in function params
    ===========================================================

    The keyword "static" inside function parameter declarations
    (a C99 feature) tells the compiler:

        "The caller must pass an array with AT LEAST this many elements."

    It is NOT a runtime check.
    It does NOT allocate anything.

    If the caller passes a smaller array → Undefined Behavior,
    but many compilers may warn about it with high warning levels.
*/

// compile-time *guarantee* (not enforcement) about minimum array length
void foo(int arr[static 100]);


/*
    ===========================================================
    IMPORTANT: this does NOT create or expect a 1024-element array
    ===========================================================

    In function parameters, arrays ALWAYS decay to pointers.
    So:

        void foo2(int arr[1024]);

    is EXACTLY the same as:

        void foo2(int *arr);

    The "1024" is treated purely as documentation and is ignored
    by the compiler for type purposes.
*/
void foo2(int arr[1024]) {

    /*
        ===========================================================
        sizeof(arr) when 'arr' is a function parameter
        ===========================================================

        Inside the function, 'arr' is a pointer. Always.
        So:

            sizeof(arr)       -> sizeof(int*)   (8 bytes on 64-bit)
            sizeof(arr[0])    -> sizeof(int)    (4 bytes)

        Therefore the computed "length" becomes:

            8 / 4 = 2

        which is WRONG because the array size information is lost.
    */
    int len = sizeof(arr) / sizeof(arr[0]); // ALWAYS 2 on 64-bit
}


int main() {

    const int a = 10;   // local const → valid VLA size (C99+)
    int var = 10;       // runtime value → also valid VLA size (C99+)

    #define SIZE 10     // macro → compile-time constant

    // ---------------------------
    // Array declarations
    // ---------------------------

    int arr1[a];        // VLA — runtime-sized array
    int arr2[SIZE];     // compile-time sized array
    int arr3[10];       // compile-time sized array
    int arr4[var];      // VLA — NOT allowed in C90
    
    /*
        ===========================================================
        Zero-initialized arrays
        ===========================================================

        Explicitly providing an initializer causes the array to be
        zero-initialized.

        These are identical:
    */
    int zero_init1[SIZE] = {0};                     // all elements = 0
    int zero_init2[SIZE] = {[0 ... SIZE - 1] = 0};  // GCC extension: all = 0

    /*
        ===========================================================
        "Trash" (uninitialized) arrays
        ===========================================================

        These contain indeterminate (garbage) values.
        Local automatic storage is NOT zeroed by the compiler.
    */
    int trash1[SIZE] = {};   // NOT zero-initialized in C — GCC extension → uninitialized
    int trash2[SIZE];        // uninitialized → garbage values

    /*
        ===========================================================
        sizeof() ONLY works for arrays IN THEIR OWN SCOPE
        ===========================================================

        Here, arr1 is a REAL array and it's in scope so we have access to all the data
    */
    int len = sizeof(arr1) / sizeof(arr1[0]);  // correct length

    /*
        ===========================================================
        REMEMBER:
        -----------------------------------------------------------
        If you pass arr1 to a function:
        
            foo2(arr1);

        inside foo2(), sizeof() NO LONGER WORKS because the array 
        decays to a pointer and the size information is lost.
        ===========================================================
    */

    return 0;
}
