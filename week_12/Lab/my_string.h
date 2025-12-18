#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t my_strlen(const char *str);
char*  my_strcpy(char *where, const char *what);

// CASE SENSITIVE
int my_strcmp(const char* str1, const char* str2){

    while (*str1 && *str2 && *str1 == *str2) {
        ++str1; ++str2;
    }
    
    return *str1 - *str2;
}

const char* strstr(const char *needle, const char *haystack){

    int len = my_strlen(needle);
    int iter = 0;

    while(*haystack != '\0' && iter < len){
        if(*needle == *haystack){
            ++needle;
            ++iter;
        }
        else{
            needle -= iter;
            iter = 0;
        }

        ++haystack;
    }

    return *needle == '\0' ? haystack : NULL;
}

char* my_strcpy(char *where, const char *what){
    if(what == NULL) return NULL;

    assert(my_strlen(where) == 0); // will leak if this is not empty

    size_t len = my_strlen(what);

    char *temp = (char*)malloc(len); // char size is 1 BYTE, no need to multiply by sizeof 
    if(!temp) return NULL;

    where = temp;
    return where;
}

// Linear looping around the string. Don't call inside LOOPS!!!!
size_t my_strlen(const char *str){
    if(str == NULL) return 0; 

    size_t len = 0;
    while(*str != '\n') ++len;

    return len;
}   

int main(){

    char my_string[] = "Here is some text with length 33";
    char my_other_string[] = "This is my other string";

    char a[]     = "a";
    char a_two[] = "a";


    printf("Length: %d", my_strlen(my_string));
    my_strcmp(a, a_two);

    return 0;
}