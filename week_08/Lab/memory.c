// ===============================
// Zero-initialized memory in C
// ===============================

// Global and static variables have *static storage duration*.
// According to the C standard, if you do NOT initialize them explicitly,
// they are automatically initialized to zero (or NULL for pointers).
// This happens *before main() starts*, usually during the program's startup phase.

// WHY? Because:
// 1. They are placed in the .bss section of the program.
// 2. The loader or runtime initialization code zeroes out .bss for efficiency.
// 3. This allows large uninitialized variables to take no space in the binary.

// Example: global const variable (still static storage duration!)
const int some_size;   // Zero-initialized to 0 because it is global.

// Static arrays without explicit initialization also go to .bss
// EXCEPT if you initialize them — then they go to .data.
int arr[50];           // All 50 elements are automatically set to 0.

// --------------------------------------------------------------
// Not valid!!!!
// int arr[some_size]
// --------------------------------------------------------------
// This is invalid because "some_size" is NOT a compile-time constant.
// Even though it is 'const', global const variables in C have storage,
// so they cannot be used as array bounds for static arrays.

// Only true compile-time constants such as:
//   #define SIZE 10
//   integer literals can be used for global array sizes.


// ===============================
// Automatic (stack) memory in C
// ===============================
int main(){

    // Local (automatic) variables do NOT get zeroed.
    int some_size;  // Contains garbage — NOT zero-initialized!

    // Automatic arrays also start with garbage unless initialized explicitly:
    // int a[10];  // <- filled with random stack contents

    // Why? Because:
    // 1. Zeroing stack variables every time would slow execution.
    // 2. The C language was designed for performance, not safety.

    return 0;
}
