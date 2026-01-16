#include <stdio.h>
#include <stdlib.h>

#define SIDES 4

size_t** allocate_matrix(size_t n, size_t m);
size_t** generate_custom_matrix(size_t rows, size_t cols);


size_t   calculate_weight(size_t** matrix, size_t rows, size_t cols, size_t index, size_t index_col);
void     delete_rows_with_weight(size_t*** matrix, size_t* rows, size_t cols, size_t weight);

int      valid_pos(size_t row, size_t col, size_t rows, size_t cols);


int main(){

    size_t rows, cols;

    printf("Insert dimensions: ");
    if(scanf("%d %d", &rows, &cols) != 2) return -1;

    size_t** matrix = generate_custom_matrix(rows, cols);

    delete_rows_with_weight(&matrix, &rows, cols, 18);

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    return 0;
}

int      valid_pos(size_t row, size_t col, size_t rows, size_t cols){
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void     delete_rows_with_weight(size_t*** matrix, size_t* rows, size_t cols, size_t weight){
    if(!matrix) return;
    
    size_t* to_delete = (size_t*)calloc(*rows, sizeof(size_t));
    if(!to_delete) return;
    
    size_t   r_temp = *rows;
    int      iter   = 0;

    for (int i = 0; i < r_temp; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(calculate_weight(*matrix, r_temp, cols, i, j) == weight){
                to_delete[iter++] = 1;
                break;
            }
        }
        
    }

    if(iter > 0){

        for (int i = 0; i < iter; i++)
        {
            size_t* del = (*matrix)[i];
            for (int j = to_delete[i]; j < r_temp - 1; ++j) (*matrix)[j] = (*matrix)[j + 1];
            
            --(*rows);
            if(i + 1 != iter) --to_delete[i + 1];
        }
        
        size_t** temp = realloc(*matrix, *rows * sizeof(size_t*));
        if(temp) *matrix = temp;
    }
    
    free(to_delete); to_delete = NULL;
}

size_t   calculate_weight(size_t** matrix, size_t rows, size_t cols, size_t index_row, size_t index_col){
    if(!matrix) return 0;

    static const int directions[SIDES][2] =
    {
        {1, 1},
        {-1, 1},
        {1, -1},
        {-1, -1},
    }; 

    size_t weight = 0;

    for (int i = 0; i < SIDES; ++i)
    {
        size_t curr_x = index_col, curr_y = index_row;
        
        if(!valid_pos(curr_y + directions[i][1], curr_x + directions[i][0], rows, cols)) continue;

        do
        {
            weight += matrix[curr_y][curr_x];

            curr_y += directions[i][1];
            curr_x += directions[i][0];
        } while (valid_pos(curr_y, curr_x, rows, cols));
    }
 
    return weight;
}

size_t** generate_custom_matrix(size_t rows, size_t cols){
    
    size_t** matrix = allocate_matrix(rows, cols);
    if(!matrix) return NULL;

    int counter = 1;
    for(int i; i < rows; ++i){
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = counter++;
        }
        
    }

    return matrix;
}

size_t** allocate_matrix(size_t n, size_t m){

    size_t** matrix = (size_t**)malloc(sizeof(size_t*) * n);
    if(!matrix) return NULL;

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (size_t*)malloc(sizeof(size_t) * m);
        if(!matrix[i]){
            for (int k = 0; k < i; k++)  free(matrix[k]);
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}