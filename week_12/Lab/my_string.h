#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFFER 1024

size_t      my_strlen(const char *str);
char*       my_strcpy(char *where, const char *what);
int         is_prefix(const char* where, const char* what);
const char* my_strstr(const char *needle, const char *haystack);
int         my_strcmp(const char* str1, const char* str2);

int main(){

    // automatic terminating zero placed by the compiler
    char my_string[] = "Here is some text";

    // mind the manual terminating zero
    char my_other_string[] = 
    {'t','h','i','s',' ','i','s',' ','a','n','o','t','h','e','r', /*!!!!*/'\0'/*!!!!*/};

    
    // allocate c_string with 1024 bytes
    char *dynamic_string = (char*)malloc(BUFFER); 

    // !! DON'T DO THIS !!
    // dynamic_string = "this is an absolute MEMORY LEAK"

    printf("Length: %d", my_strlen(my_string));

    // don't forget
    free(dynamic_string);
    dynamic_string = NULL;
    return 0;
}


int is_prefix(const char* where, const char* what){
    if(!what || !where) return 0;

    while (*what && *where && *what == *where)
    {
        ++what;
        ++where;
    }
    
    return *what == '\0';
}

// CASE SENSITIVE
int my_strcmp(const char* str1, const char* str2){
    assert(str1 && str2);

    while (*str1 && *str2 && *str1 == *str2) {
        ++str1; ++str2;
    }
    
    return *str1 - *str2;
}

char* my_strcpy(char *where, const char *what){
    if(what == NULL || where == NULL) return NULL;

    char* temp = where;
    while((*(temp++) = *(what++)))   ;

    return where;
}

// Linear looping around the string. Don't call inside LOOPS!!!!
size_t my_strlen(const char *str){
    if(str == NULL) return 0;

    size_t len = 0;
    while(*str++) ++len;

    return len;
}  

const char* my_strstr(const char *needle, const char *haystack){
    if(!needle || !haystack) return NULL;
    if(*needle == '\0') return haystack;

	const char* haystack_end = haystack + my_strlen(haystack);
	unsigned needle_len = my_strlen(needle);

	while (haystack + needle_len <= haystack_end)
	{
		if (is_prefix(haystack, needle))
			return haystack;

		++haystack;
	}

	return NULL;

}