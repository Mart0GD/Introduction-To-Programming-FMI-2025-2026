#include <stdio.h>
#include <math.h>

/*
    'inline' in C

    The 'inline' keyword tells the compiler:

        "If possible, replace this function call with the function code
         directly at the call site."

    This can remove the overhead of:
        - pushing arguments on the stack
        - jumping to another function
        - returning afterward

    HOWEVER:
    > The compiler can ignore 'inline' completely
    > Most compilers already inline small functions automatically (when optimized)
    > It does NOT guarantee performance improvement
       (in fact, too much inlining can make the program slower due to code bloat)
*/
inline double distance(int x1, int y1, int x2, int y2);


int main(void) {

    printf("%f\n", distance(0, 0, 20, 20));
    return 0;
}


inline double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) +
                (y1 - y2) * (y1 - y2));
}
