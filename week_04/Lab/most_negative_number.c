#include "stdio.h"
/*
Operation	    Typical cost	
+, -, &,|,^	    ~1 cycle
<<, >>	        ~1–3 cycles	
*	            ~3 cycles	
/, %	        10–40 cycles
*/
int main(){

    short most_negative_number = 0b1000000000000000;

    /*
        x  = 1000 0000 0000 0000
        -x = invert + 1 = 0111 1111 1111 1111 + 1 = 1000 0000 0000 0000
    */

    printf("One's component 45: %d\n", ~45);
    printf("Two's component 45: %d\n", ~(45) + 1);

    printf("Most negative number(short) flip: %hd\n", ~most_negative_number + 1);
    return 0;
}