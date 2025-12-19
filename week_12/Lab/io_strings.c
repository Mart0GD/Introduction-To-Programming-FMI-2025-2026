#include <stdio.h>
#include <stdlib.h>

char* read_manually();

int main(){

    char c;
    char str[1024];

    // reads until whitespace (not buffer overflow safe)
    scanf("%s", str);

    /*
        Safe method to read input

        Reads until '\n' or until the buffer is exceeded
    */
    fgets(str, sizeof(str), stdin);
    if(str == EOF){
        /*
            What is EOF?

            EOF is a macro with value -1 used to indicate that a stream(file reading input)
            has been broken or the file has reached it's end.
        */
    }

    char* text = read_manually();
    free(text); text = NULL;

    /*
        fgetc vs getc

        getc  --> usually implemented as a macro, faster but not safe for specific cases
        fgetc --> a function, can be slower but for modern compilers it doens't matter

        Use whichever you want
    */

    // Read an int, some values exceed normal chars
    int symb; 

    symb = fgetc(stdin);
    symb = getc(stdin);
}


char* read_manually(){
    int buffer = 1024;

    char* text = (char*)malloc(buffer);
    if(!text) return text;

    int iter = 0, c;
    while ((c = fgetc(stdin)) != EOF && c != '\n')
    {
        // we have exhausted or memory 
        if(iter + 1 >= buffer){
            char* temp = realloc(text, buffer * 2 * sizeof(char));
            if(!temp){
                free(text);
                return NULL;
            }
            text = temp;
            buffer *= 2;
        }
        text[iter++] = c;
    }
    text[iter] = '\0';
    
    return text;
}