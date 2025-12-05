#include <stdio.h>

int main(){

    // Three ways to define a two-dimensional array
    
    // Method 1 --> literals
    int arr1[2][3]; 

    // Method 2 --> const variables
    const int rows = 2;
    const int cols = 3;

    int arr2[rows][cols];

    // Method 3 --> macros
    #define ROWS 2
    #define COLS 3

    int arr3[ROWS][COLS];


    // How to initialize a two dimensional array
    int matrix1[2][3] = { {1,2,3}, {4,5,6} };

    int matrix2[2][3] = { 1, 2, 3, 4, 5, 6 };

    int matrix3[ ][4] = { 1, 2, 3, 4, 5, 6 };

    // Will not compile. The second dimension is mandatory
    // int matrix_wrong[2][] = {1, 2, 3, 4, 5, 6};

    // this is a pointer to an array of two elements. That's why we can initialize 
    // a matrix with it directly
    int array_as_matrix[1][2] = {{1, 2}};
    int (*matrix_as_pointer)[2] = array_as_matrix;

    // this is a normal array, we have to pass it's address to be able to initialize
    // the matrix
    int array[4] = {1,2,3,4};
    int (*matrix)[4] = &array;    

    return 0;
}


