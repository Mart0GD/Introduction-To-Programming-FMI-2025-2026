#include <stdio.h>

/*
    Function declarations (prototypes)
    They tell the compiler what functions exist before main().

    A function can be declared many times but only defined !!ONCE!!
*/

void foo_void(void);   // function returning nothing
int  foo_int(void);    // function returning an integer

int main(void) {

    /*
        What is a function?

        A function is a named block of code with a defined scope and, optionally,
        parameters. Its purpose is to:
        - organize logic into smaller reusable pieces
        - improve readability
        - avoid code duplication
        - do a single task!!
    */

    /*
        Function declaration syntax:

        <return type> <function_name>(<parameters>);

        ───────────────────────────────────────────────────────────────
        Function definition syntax:

        <return_type> <function_name>(<parameters>) <optional-specifiers>
        {
            // function body (scope)
        }

        ───────────────────────────────────────────────────────────────

        > Return type:

            void foo() {}    → a function that does not return a value
            int  foo() {}    → a function that returns an integer value
            double foo() {}  → a function that returns a double value

        If a function returns a type other than void, it must use `return`.

        ───────────────────────────────────────────────────────────────

        > Function name (identifier):

            Naming conventions vary but **recommended**:
            - snake_case → my_function()
            - PascalCase → MyFunction()

            Avoid camelCase for function names in C (more common in C++/Java).

        ───────────────────────────────────────────────────────────────

        > Function parameters:

            void foo(void)
            void foo()        → same meaning in C: takes no parameters

            type name(type param1, type param2, ...)

            Example:
                void print_sum(int a, int b);

            Each parameter has:
                - a type
                - a name

        ───────────────────────────────────────────────────────────────

        > Keyword specifiers:

            Examples include:
                static
                extern
                inline
                const

            They change how a function behaves or is visible across files.
            We will explore these later.
    */

    foo_void();          // calling function that returns nothing
    int a = foo_int();   // calling function that returns an int

    return 0;
}


/*
    Function definitions
*/

void foo_void(void) {
    puts("foo_void() was called! It returns nothing.");
    return;      // We do not have to return. We can omit it
}

int foo_int(void) {
    puts("foo_int() was called! It returns an int.");
    return 42;   // We must return a value because return type is int
}
