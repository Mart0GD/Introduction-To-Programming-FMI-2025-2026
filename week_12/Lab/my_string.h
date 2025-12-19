#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

<<<<<<< HEAD
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
=======
size_t my_strlen(const char *str);
char*  my_strcpy(char *where, const char *what);

// CASE SENSITIVE
int my_strcmp(const char* str1, const char* str2){
>>>>>>> 9e157dd73b4dd13fadd636ff8a1649c2f809c53e

    while (*str1 && *str2 && *str1 == *str2) {
        ++str1; ++str2;
    }
    
    return *str1 - *str2;
}

<<<<<<< HEAD
char* my_strcpy(char *where, const char *what){
    if(what == NULL || where == NULL) return NULL;

    char* temp = where;
    while((*(temp++) = *(what++)))   ;

=======
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
>>>>>>> 9e157dd73b4dd13fadd636ff8a1649c2f809c53e
    return where;
}

// Linear looping around the string. Don't call inside LOOPS!!!!
size_t my_strlen(const char *str){
<<<<<<< HEAD
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

=======
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
>>>>>>> 9e157dd73b4dd13fadd636ff8a1649c2f809c53e
}