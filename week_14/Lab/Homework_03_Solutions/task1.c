#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 15

char** allocate_matrix(unsigned rows, unsigned cols);
void   free_matrix(unsigned rows, char** matrix);

char*  read_word();
char*  read_sentence();
char*  read_word_from_sentence(char** sentence);
char*  read_whitespace_from_sentence(char** sentence);

int    is_delim(int c);

int main(){

    unsigned words;
    if(scanf("%u", &words) != 1){
        puts("Invalid input!");
        return -1;
    }
    getchar(); // eat newline

    words *= 2;
    char** dictionary = (char**)malloc(sizeof(char*) * words);
    for(int i = 0; i < words; ++i) dictionary[i] = NULL;

    for (int i = 0; i < words;)
    {
        char* bulgarian = read_word();
        if(!bulgarian){
            puts("Invalid word!");
            free_matrix(words, dictionary);
            return -1;
        }

        dictionary[i++] = bulgarian;

        char* english = read_word();
        if(!english){
            puts("Invalid word!");
            free_matrix(words, dictionary);
            return -1;
        }

        dictionary[i++] = english;
    }   

    char* sentence  = read_sentence();
    if(!sentence){
        free_matrix(words, dictionary);
        return -1;
    }

    char* translation       = NULL;
    size_t translation_size = 0;

    char* s_itt = sentence;
    while (*s_itt != '\0')
    {
        char* word;

        if(is_delim(*s_itt)) {
            word = read_whitespace_from_sentence(&s_itt);
            if(!word){
                free_matrix(words, dictionary);
                free(sentence);
                free(translation);
                return -1;
            }
        }
        else{
            word = read_word_from_sentence(&s_itt);
            if(!word){
                free_matrix(words, dictionary);
                free(sentence);
                free(translation);
                return -1;
            }   

            for (int i = 0; i < words; i += 2)
            {
                if(strcmp(word, dictionary[i]) == 0){
                    word = strcpy(word, dictionary[i + 1]); 
                    break;
                }

            }
        }

        size_t word_len = strlen(word);
        size_t new_len  = translation_size + word_len + 1;
        char* temp = realloc(translation, new_len);
        if(!temp){
            free_matrix(words, dictionary);
            free(sentence);
            free(translation);
            free(word);
            return -1;
        }
        translation = temp;
        translation[translation_size] = '\0';
        
        strcpy(translation + translation_size, word);
        translation_size += word_len;

        free(word);
    }
    
    putchar('\n');
    printf("The translation of the sentence is: %s\n", translation);
    
    free_matrix(words, dictionary);
    free(sentence);
    free(translation);
    return 0;
}


char** allocate_matrix(unsigned rows, unsigned cols){

    char** matrix = (char**)malloc(sizeof(char*) * rows);
    if(!matrix) return matrix;

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (char*)malloc(cols);
        if(!matrix[i]){
            free_matrix(rows, matrix);
            return NULL;
        }
    }
    
    return matrix;
}

void   free_matrix(unsigned rows, char** matrix){
    
    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
        matrix[i] = NULL;
    }
    
    free(matrix);
    matrix = NULL;
}

char*  read_word(){
    size_t buffer = MAX_WORD_SIZE + 1; 

    char* arr = (char*)malloc(buffer);
    if(!arr) return arr;

    int c;
    size_t iter = 0;
    do
    {   
        c = getchar();
        if(is_delim(c) || c == '\n') break;     // reached end point
        else if(c == EOF || iter == buffer - 1){    // error parsing or larger than allowed word
            free(arr); arr = NULL;
            return NULL;
        }
    
        arr[iter++] = c;
    } while (1);
    
    arr[iter] = '\0';
    return arr;
}

int    is_delim(int c){
    static const char delimiters[] = {' ', ',', '.'};
    const int size = 3;

    for (int i = 0; i < size; ++i)
        if(c == delimiters[i]) return 1;
    
    return 0;
}

char*  read_sentence(){
    size_t buffer = 1024;

    char* arr = (char*)malloc(buffer);
    if(!arr) return NULL;

    int c;
    size_t iter = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if(iter == buffer){
            char* temp = realloc(arr, buffer * 2 + 1);
            if(!temp){
                free(arr); arr = NULL;
                return NULL;
            }
            arr = temp;
            buffer *= 2;
        }
        arr[iter++] = (char)c;
    }

    char* temp = realloc(arr, iter + 1);
    if(!temp) return arr;
    
    arr[iter] = '\0';
    return arr;
}

char*  read_word_from_sentence(char** sentence){
    if(!sentence) return NULL;

    size_t  buffer = MAX_WORD_SIZE;
    int     iter   = 0;
    char*   arr    = (char*)malloc(buffer + 1); 

    while(*(*sentence) != '\0' && !is_delim(*(*sentence))){

        if(iter == buffer){                
            char* resize = realloc(arr, buffer * 2 + 1);
            if(!resize){
                free(arr); arr = NULL;
                return NULL;
            } 
            arr = resize;
            buffer *= 2;
        }

        arr[iter++] = *(*sentence);
        ++(*sentence);
    }

    char* temp = realloc(arr, iter + 1);
    if(temp) arr = temp;

    arr[iter] = '\0';
    return arr;
}

char*  read_whitespace_from_sentence(char** sentence){
    if(!sentence) return NULL;
    size_t buffer = 24;

    char* arr = (char*)malloc(buffer);
    if(!arr) return NULL;
    
    size_t iter = 0;
    while(*(*sentence) != '\0' && is_delim(*(*sentence))){

        if(iter == buffer){
            char* temp = realloc(arr, buffer * 2 + 1);
            if(!temp){
                free(arr);
                return NULL;
            }
            arr = temp;
            buffer *= 2;
        }

        arr[iter++] = *(*sentence);
        ++(*sentence);
    }

    char* temp = realloc(arr, iter + 1);
    if(temp) arr = temp;
    
    arr[iter] = '\0';
    return arr;
}
