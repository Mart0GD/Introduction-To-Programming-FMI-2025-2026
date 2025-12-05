#include <stdio.h>

int main(){

    int matrix[2][4] = {{ 1, 2, 3, 4}, {9, 8, 7, 6}};
    // decays to int (*)[4]; --> the rows don't matter to the compiler

    /*
        Visualization:

        ptr -> 1 2 3 4
        ptr -> 9 8 7 6
    
    */

    // The address of the first array. 
    //
    // Returns the address of [1,2,3,4]
    printf("Address of the the first array: %d\n", matrix);

    // The address of the first element inside the first row. 
    //
    // Returns the address of 1

    printf("First row, first element address: %d\n", *matrix);

    // The value of the first element in the first row. 
    // 
    // Returns 1

    printf("First row, first element value: %d\n", **matrix);


    // The value of the 1-st element in the second array + 3
    //
    // Returns 12
    printf("Second row, first element + 3: %d\n", **(matrix + 1) + 3);

    // The value of the 3-rd element in the first array + 3
    //
    // Returns 6
    printf("First row, third element + 3: %d\n", (*(*matrix) + 2) + 3);

    return 0;
}