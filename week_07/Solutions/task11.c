#include <stdio.h>

int get_trailing_zeros(int number);

int main(){

    unsigned number;
    printf("Insert number: ");
    if(scanf("%u", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    printf("Number of zeros: %d", get_trailing_zeros(number));
    return 0;
}

/*
    if we want to get the leading zeros, we'll just do:
    
    ---------
    32 - (int)(log2(number) + 1); number > 0
    ---------
*/
int get_trailing_zeros(int number){
    if(number % 2) return 0; // every odd number starts with 1

    int top =  sizeof(unsigned) * 8;
    int cnt = 0;
    for (int i = 0; i < top; ++i)
    {
        if((number >> i & 1) != 0) return cnt;
        ++cnt;
    }

    return cnt;
}