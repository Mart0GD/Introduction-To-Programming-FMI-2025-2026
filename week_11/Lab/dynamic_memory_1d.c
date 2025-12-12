#include <stdio.h>

// To allocate memory we need to include the standart library
#include <stdlib.h>

void how_to_use_malloc(){
    const int some_size = 15;

    // Proccess of allocating memory

    // 1) Allocating an array with 15 int elements

    /*
        What does malloc do?

        This operation gets 15 * 4 = 60 bytes from: 
        
        > From the already freed memory.
        > The OS. When no freed memory chunk satisfies our needs.

        If the operation was a success than the memory is returned as void pointer (void*).
        Otherwise a NULL address is returned. 

        The values of each element is random!!!
    */

    int *arr = (int*)malloc(some_size * sizeof(int));

    // 2) Check if memory has been allocated (we can run out of memory!)
    if(arr == NULL) return;

    // Use array...

    // 3) Free array
    free(arr);

    /*
        After using free arr still points to the exact same address but the address is no longer valid
        Trying to access it is undefined behaviour, that's why it's good practice to set it to NULL
    */
    arr = NULL; // set arr to NULL
}

void how_to_use_calloc(){
    const int some_size = 15;

    // 1) Allocating an array

    /*
        What does calloc do?
        Takes two arguments <number of elements> <size of each element>

        This operation gets 15 * 4 = 60 bytes from: 
        
        > From the already freed memory.
        > The OS. When no freed memory chunk satisfies our needs.

        If the operation was a success than the memory is returned as void pointer (void*).
        Otherwise a NULL address is returned. 

        The value of each element is zero!!
    */

    int *arr = (int*)calloc(some_size, sizeof(int));

    // 2) Check for success
    if(!arr) return;

    // Use array...

    // 3) Free array
    free(arr);
    arr = NULL;
}

int main(){
    
    how_to_use_calloc();
    how_to_use_malloc();

    return 0;
}