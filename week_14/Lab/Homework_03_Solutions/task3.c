#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

/*
    Disclaimer --> will save the first word it sees as a sample, I could have made it to save words 
    all to lower case but, too lazy
*/

char   to_lower (const char c);
int    is_letter(const char c);
int    is_word  (const char c);

int    stricmp(const char* l, const char* r);
char*  compress(const char* str, char*** words_list, size_t* words_list_size);
char*  decompress(const char* compressed, char** words_list, const size_t words_list_size);
char** generate_words_list(const char* str, size_t* words_list_size);

void   free_matrix(char** matrix, size_t size);
int    find_word(char** words, const char* word, size_t words_cnt);

int    extract_number(const char** text);
char*  extract_word(const char** text);
char*  num_to_string(int num);

void   sort(char** words, size_t* count_map, size_t cnt);

int main(){

    char str[] = "The quick brown fox jumped over the brown dog on the chair.";

    char** words_list = NULL;
    size_t word_list_size = 0;

    char* compressed  = compress(str, &words_list, &word_list_size);
    printf("Compressed text: %s\n", compressed);

    char* decompressed = decompress(compressed, words_list, word_list_size);
    printf("Decompressed text: %s\n", decompressed);

    printf("Are they equal: %s\n", stricmp(str, decompressed) == 0 ? "Yes" : "No");

    free_matrix(words_list, word_list_size);
    free(compressed); compressed = NULL;
    free(decompressed); decompressed = NULL;
    return 0;
}

char* compress(const char* str, char*** words_list, size_t* words_list_size){
    if(!str) return NULL;

    *words_list = generate_words_list(str, words_list_size);

    char *compressed = (char*)malloc(strlen(str) + 1);
    if(!compressed) return NULL;

    const char *itt = str;
    int compressed_size = 0;
    while (*itt != '\0')
    {
        if(!is_word(*itt)) {
            compressed[compressed_size++] = *(itt++);
            continue;
        }
        else{
            char* word = extract_word(&itt);
            int  index = find_word(*words_list, word, *words_list_size);

            char* to_str = num_to_string(index);

            strcpy(compressed + compressed_size, to_str);
            compressed_size += strlen(to_str);

            free(to_str); to_str = NULL;
            free(word);   word   = NULL;
        }

    }

    return compressed;
}

char*   decompress(const char* compressed, char** words_list, const size_t words_list_size){
    if(!compressed || !words_list) return NULL;

    size_t size = strlen(compressed) * 2;
    char* decompressed = (char*)malloc(size + 1);
    if(!decompressed) return NULL;

    int iter = 0;
    while (*compressed != '\0')
    {
        if(!is_word(*compressed)){
            decompressed[iter++] = *compressed;
            ++compressed;
        }
        else{
            int num = extract_number(&compressed);

            size_t word_len = strlen(words_list[num]);
            if(word_len + iter >= size){
                char* temp = realloc(decompressed, word_len + iter + 1);
                if(!temp){
                    free(decompressed);
                    return NULL;
                } 
                decompressed = temp;
                size = word_len + iter + 1;
            }

            strcpy(decompressed + iter, words_list[num]);
            iter += word_len;
        }
    }
    
    return decompressed;
}

int  is_word  (const char c){
    return is_letter(c) || c >= '0' && c <= '9' || c == '-';
}

char to_lower(char c){
    if(!is_letter(c)) return c;

    const int diff = 32;
    return c >= 'a' ? c : c + diff;
}

int  is_letter(const char c){
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

int stricmp(const char* l, const char* r){
    
    while(*l != '\0'){
        if(*r == '\0') return 1;

        char to_lower_l = to_lower(*l);
        char to_lower_r = to_lower(*r);

        if(to_lower_r > to_lower_l)         return -1;
        else if(to_lower_l > to_lower_r)    return 1;
        else                                ++r; ++l;
    }

    if(*r != '\0') return -1;
    return 0;
}

char** generate_words_list(const char* str, size_t* words_list_size){
    if(!str) return NULL;
    size_t buffer = 16;

    size_t* count_map = (size_t*)calloc(sizeof(size_t), buffer);
    if(!count_map) return NULL;

    char** words     = (char**)malloc(sizeof(char*) * buffer);
    if(!words){
        free(count_map);
        return NULL;
    }
    for(int i = 0; i < buffer; ++i){ 
        words[i] = NULL; // null out memory, so we don't access trash memory! 
    }

    *words_list_size = 0;
    while(*str != '\0'){

        if(!is_word(*str)) {++str; continue;}

        char* word = extract_word(&str);
        if(!word){
            free_matrix(words, buffer);
            free(count_map); count_map = NULL;
            return NULL;
        }

        int word_index = find_word(words, word, *words_list_size);
        if(word_index == -1){
            
            if(*words_list_size == buffer){
                char**  temp  = realloc(words, buffer * 2);
                size_t* temp2 = realloc(count_map, buffer * 2);
                if(!temp || !temp2){
                    free(temp);
                    free(temp2);
                    free(count_map);
                    free_matrix(words, buffer);
                    return NULL;
                }
                words = temp;
                count_map = temp2;
                buffer *= 2;
            }

            words[*words_list_size] = word;
            count_map[*words_list_size] = 1;
            ++(*words_list_size);
        }
        else {
            ++count_map[word_index];
            free(word);
        }

    }   

    char** temp = realloc(words, (*words_list_size + 1) * sizeof(char*));
    if(temp) words = temp;

    sort(words, count_map, *words_list_size);
    free(count_map); count_map = NULL;
    return words;
}

void   sort(char** words, size_t* count_map, size_t cnt){
    if(!words) return;

    int     swapped;
    char*   word_temp;
    size_t  count_temp;

    for (int i = 0; i < cnt; i++)
    {
        swapped = 0;
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if(count_map[j] > count_map[j + 1]) continue;
            if(count_map[j] == count_map[j + 1] && stricmp(words[j], words[j + 1]) < 0) continue;
            
            word_temp = words[j];
            words[j] = words[j + 1];
            words[j + 1] = word_temp;

            count_temp = count_map[j];
            count_map[j] = count_map[j + 1];
            count_map[j + 1] = count_temp;

            swapped = 1;
        }
        if(!swapped) break;
    }
}

char*  extract_word(const char** text){
    if(!text) return NULL;

    size_t buffer = 128;
    char* word    = (char*)malloc(buffer);

    size_t iter = 0;
    while (*(*text) != '\0' && is_word(*(*text)))
    {
        if(iter == buffer - 1){
            char* temp = realloc(word, buffer * 2 + 1);
            if(!temp){
                free(word); word = NULL;
                return NULL;
            }
            word = temp;
            buffer *= 2;
        }

        word[iter++] = *(*text);
        ++(*text);
    }
    
    word[iter] = '\0';
    return word;
}

int    extract_number(const char** text){
    if(!text) return 0;

    int num = 0;
    while(*(*text) != '\0' && *(*text) >= '0' && *(*text) <= '9'){
        num *= 10;
        num += *(*text) - '0';

        ++(*text);
    }

    return num;
}

char*  num_to_string(int num){

    int digits = 1;
    int temp = num;
    while(temp /= 10){
        ++digits;
    }

    char* text = (char*)malloc(digits + 1);
    if(!text) return NULL;

    for (int i = digits - 1; i >= 0; --i)
    {
        text[i] = num % 10 + '0';
        num /= 10;
    }
    text[digits] = '\0';
    
    return text;
}

int    find_word(char** words, const char* word, size_t words_cnt){
    if(!word || !words) return -1;

    for (int i = 0; i < words_cnt; i++)
        if(stricmp(words[i], word) == 0) return i;

    return -1;
}

void   free_matrix(char** matrix, size_t size){
    if(!matrix) return;

    for (int i = 0; i < size; i++) {
        free(matrix[i]); matrix[i] = NULL;
    }
    
    free(matrix); matrix = NULL;
}