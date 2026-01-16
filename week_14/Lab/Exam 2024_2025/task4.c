#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Дадена е таблица с 𝑛 реда и 𝑚 стълба, в която са записани символи. 
Две клетки в таблицата ще наричаме съседни, ако имат обща стена, т.е. всяка клетка има най-много четири съседа.

а) Да се напише функция, която проверява дали от дадена позиция в 
таблицата може да се премине през съседни клетки и така да се прочете дадена дума. Празният низ може да бъде прочетен винаги.

б) Да се напише функция, която получава като аргументи такава таблица и масив с думи. 
Да се премахнат от масива думите, които не могат да се прочетат в матрицата с начало някоя клетка.

в) Да се демонстрира извикването на горната функция в кратка програма, която прочита от стандартния 
вход таблицата и масива с думи и извежда на екрана думите, които могат да се прочетат в таблицата. 
Въведете броя на думите и самите думи, като можете да приемете, че всяка дума е с по-малко от 128 символа.
*/

#define MAX_TEXT_LEN 128

int         can_read_word(size_t rows, size_t cols, const char** matrix, const char* word, size_t start_y, size_t start_x);

char*       read_text();
char**      allocate_matrix(size_t n, size_t m);

void        remove_non_findable_words(char*** words, size_t* rows, size_t cols, const char** table, size_t rows_t, size_t cols_t, size_t start_x, size_t start_y);

int         find_word(
size_t rows, 
size_t cols, 
const char** matrix, 
int x, 
int y, 
size_t pos,
const char* word, 
int* used
);

static const char* table[4] =
{
    "qko ",
    "m te",
    " k o",
    "mnog"
};

int main(){

    size_t words_cnt;
    printf("Insert words count: ");
    if(scanf("%zu", &words_cnt) != 1) return -1;

    int c;
    while(c = getchar() != '\n');

    char** words = allocate_matrix(words_cnt, MAX_TEXT_LEN);
    if(!words) return -1;

    for (int i = 0; i < words_cnt; i++)
    {

        char* word = read_text();
        if(!words){
            for(int j = 0; j < words_cnt; ++j) free(words[j]);
            free(words); 
            return -1;
        }

        words[i] = word;
    }
    
    remove_non_findable_words(&words, &words_cnt, MAX_TEXT_LEN, table, 4, 4, 0, 0);


    for(int j = 0; j < words_cnt; ++j) free(words[j]);
    free(words); 
    return -1;
}

char* read_text(){

    size_t buffer = MAX_TEXT_LEN;

    char* arr = (char*)malloc(buffer + 1); 
    if(!arr) return NULL;

    int iter = 0;
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if(iter + 1 == buffer){
            puts("Invalid input - 1024 symbols max");
            free(arr); arr = NULL;
            return arr;
        }

        arr[iter++] = c;
    }

    arr[iter] = '\0';
    return arr;
    
}


void remove_non_findable_words(char*** words, size_t* rows, size_t cols, const char** table, size_t rows_t, size_t cols_t, size_t start_x, size_t start_y){
    if(!table || !words) return;

    for (int i = 0; i < *rows; i++)
    {
        if(!can_read_word(rows_t, cols_t, table, (*words)[i], start_y, start_x)){
            char* to_delete = (*words)[i];
            for (int j = i; j < *rows - 1; j++) (*words)[j] = (*words)[j + 1];
            
            --(*rows);
            --i;
            free(to_delete); to_delete = NULL;
        }
    }
    
    char** temp = realloc(*words, *rows * sizeof(char*));
    if(temp) *words = temp;
}

char** allocate_matrix(size_t n, size_t m){

    char** matrix = (char**)malloc(sizeof(char*) * n + 1);
    if(!matrix) return NULL;

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (char*)malloc(sizeof(char) * m);
        if(!matrix[i]){
            for (int k = 0; k < i; k++)  free(matrix[k]);
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}

int     can_read_word(size_t rows, size_t cols, const char** matrix, const char* word, size_t start_y, size_t start_x){

    int*  used_cells = (int*)calloc(rows * cols, sizeof(int));
    if(!used_cells){
        free(used_cells); used_cells = NULL;
        return 0;
    }

    int res = find_word(rows, cols, matrix, start_y, start_x, 0, word, used_cells);

    free(used_cells);   used_cells = NULL;
    return res;
}


int     find_word(
size_t rows, 
size_t cols, 
const char** matrix, 
int x, 
int y, 
size_t pos,
const char* word, 
int* used
)
{
    if(word[pos] == '\0') return 1;
    if(!matrix || y < 0 || x < 0 || x >= cols || y >= rows || used[y * cols + x]) return 0;

    if(matrix[y][x] == word[pos]) ++pos;
    else return 0;
    
    used[y * cols + x] = 1;
    if(
        find_word(rows, cols, matrix, x + 1, y, pos, word, used) ||
        find_word(rows, cols, matrix, x - 1, y, pos, word, used) ||
        find_word(rows, cols, matrix, x, y + 1, pos, word, used) ||
        find_word(rows, cols, matrix, x, y - 1, pos, word, used)
    )
    {
        return 1;
    }

    used[y * cols + x] = 0;
    return 0;
}
