#include <stdio.h>
#include <stdlib.h>

void how_to_use_malloc(){
    const int ROWS_SIZE = 15;
    const int COLS_SIZE = 15;

    /*
        Allocate an array of ROWS_SIZE pointers to int.
        The total memory is ROWS_SIZE * sizeof(int*).
        The contents of these pointers are indeterminate.
    */

    int **matrix = malloc(ROWS_SIZE * sizeof(int *));
    if (matrix == NULL) return;

    for (int i = 0; i < ROWS_SIZE; i++) {

        matrix[i] = malloc(COLS_SIZE * sizeof(int));
        if (matrix[i] == NULL) {

            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }

            // Free the pointer array itself
            free(matrix);

            return;
        }
    }

    // Use matrix...

    // Free rows
    for (int i = 0; i < ROWS_SIZE; i++) {
        free(matrix[i]);
    }

    // Free pointer array
    free(matrix);
}

int main(){

    how_to_use_malloc();
    return 0;
}