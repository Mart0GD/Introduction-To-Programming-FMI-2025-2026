#include "stdlib.h"
#include "stdio.h"

// Fibonacci Sequence (Recursive)
size_t fibonacci_wrapper(int number, int fast);

size_t fibonacci(int number);
size_t fibonacci_fast(int number, size_t* memo);

int main(){

    printf("%zu\n", fibonacci_wrapper(48, 1));
}


size_t fibonacci_wrapper(int number, int fast){
    
    if(!fast)   return fibonacci(number);
    else {
        
        size_t* memo = (size_t*) calloc(number, sizeof(size_t));
        if(!memo) return 0;

        size_t res = fibonacci_fast(number, memo);
        free(memo); memo = NULL;
        
        return res;
    }
}

// Time  complexity --> O(2^n)
// Space complexity --> O(n) 
size_t fibonacci(int number){
    if(number <= 1) return number;

    return fibonacci(number - 1) + fibonacci(number - 2);
}

// Time  complexity --> O(n)
// Space complecity --> O(n)
size_t fibonacci_fast(int number, size_t* memo){
    if(number <= 1) return number;

    if(memo[number] != 0) return memo[number];

    memo[number] = fibonacci_fast(number - 1, memo) + fibonacci_fast(number - 2, memo);
    return memo[number];
}