#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LEN 1024

char* read_text();
void  censor(const char* text);

int   is_number(char symb);

int main(){

    char* text = read_text();
    censor(text);

    free(text);
    return 0;
}


void censor(const char* text){
    if(!text) return;

    const char censore_text[] = "***";

    size_t size = strlen(text) * 2;
    char* censored = (char*)malloc(size + 1);
    if(!censored) return;


    int iter = 0;
    while (*text)
    {
        if(iter + 3 == size){
            char* temp = realloc(censored, size * 2 + 1);
            if(!temp) {
                free(censored); censored = NULL;
                return;
            }
            censored = temp;
            size *= 2;
        }

        if(!is_number(*text)) 
        {
            censored[iter++] = *text;
            ++text;
        }
        else{

            while(is_number(*text)) ++text;

            strcpy(censored + iter, censore_text);
            iter += sizeof(censore_text) - 1;
        }
    }
    
    char* temp = (char*)realloc(censored, iter + 1);
    if(temp) censored = temp;
    censored[iter] = '\0';

    printf("Censored text: %s\n", censored);
    free(censored); censored = NULL;
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

int is_number(char c){
    return c >= '0' && c <= '9';
}