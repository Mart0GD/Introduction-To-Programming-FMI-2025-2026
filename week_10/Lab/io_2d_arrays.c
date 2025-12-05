#include <stdio.h>

#define ROWS 2
#define COLS 2


void read_matrix(int matrix[][COLS], unsigned rows, unsigned cols);

// "modern" C99+ matrix function pass
void read_matrix_new(int rows, int cols, int matrix[rows][cols]);
//void read_matrix_new(int rows, int cols, int (*)[cols]); --> rows don't matter

int main(){

    int matrix[ROWS][COLS];

    read_matrix(matrix, ROWS, COLS);

    return 0;
}


void read_matrix(int matrix[][COLS], unsigned rows, unsigned cols){

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            scanf("%d", &matrix[y][x]);

            /*
                The compiler decays matrix[y][x] into:

                *(*(matrix + y) + x)

                But the compiler needs COLS to know how big a row is, so:

                y = y * COLS * sizeof(int) number of bytes

                *(matrix * y * COLS + x) or 
                The colum size is absolutely neccesery to the compiler
            */
        }
        
    }
    
}
