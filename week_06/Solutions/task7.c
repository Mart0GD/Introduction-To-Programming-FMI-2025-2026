#include <stdio.h>

int main(){

    unsigned int number;
    printf("Insert number: ");
    
    if(scanf("%u", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    int delimiter = 2;
    int first = 1;
    while (number != 1)
    {
        if(number % delimiter == 0){
            if(first)   printf("%d ",    delimiter);
            else        printf("* %d ",  delimiter);

            first = 0;
            number /= delimiter;
        }
        else ++delimiter;
    }

    return 0;
}