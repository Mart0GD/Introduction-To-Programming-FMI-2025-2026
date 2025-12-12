#include <stdio.h>
#include <stdlib.h>

/*
    IMPORTANT!!!
    We should not free an array after reallocating --> free(ptr); 

    Realloc has these major cases:

    1) The size of the realloc is smaller than the original:

    > The address is kept and the function just throws off the old data after the new size;

    2) The size of the realloc is larger than the original:

    > The old data is copied to a new location the new allocated elements are filled with trash values
      the old data is freed;

    3) The new size is 0

    > The data is freed (implementation specific)

    4) The pointer is NULL, than realloc acts as malloc
    
    > int *arr = realloc(NULL, sizeof(int) * 10); --> allocates an array with 10 elements
*/

int main(void)
{
    int length1 = 4;
    int length2 = 10;

    int *ptr = (int*)malloc(sizeof(int) * length1);
    if(ptr == NULL)
    {
        printf("The object could not be allocated!\n");
        return 1;
    }  
    *ptr = 0;

    printf("value (not address) of ptr1 before realloc(): %p\n", (void *)ptr);

    int *temp = NULL;
    temp = (int*)realloc(ptr,length2 * sizeof(int));

    if(temp == NULL)
    {
        printf("No new object allocated. Old object remains!\n");
        free(ptr);
        return 1;
    }
    ptr = temp;

    printf("value (not address) of ptr1 after realloc(): %p\n", (void *)ptr);

    free(ptr);
    return 0;
}
