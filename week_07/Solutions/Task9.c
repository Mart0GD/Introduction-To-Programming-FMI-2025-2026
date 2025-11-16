#include <stdio.h>
#include <math.h>

int is_prime(unsigned int number);
int count_distinct_prime_divisors(unsigned int number);

int main(){

    unsigned number;
    printf("Insert number: ");
    if(scanf("%u", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    printf("Number of distinct prime divisors: %d\n", count_distinct_prime_divisors(number));
    return 0;
}

int count_distinct_prime_divisors(unsigned int number){
    if(number == 0 || number == 1) return 0;

    int cnt = is_prime(number) ? 1 : 0;
    int top = sqrt(number);
    for (int i = 2; i <= top; i++)
    {
        if(number % i == 0){
            cnt += is_prime(i) ? 1 : 0;
            unsigned int pair = number / i;
            cnt += is_prime(pair) && pair != i ? 1 : 0; // != i for perfect sqaure like 49
        }
    }
    
    return cnt;
}

int is_prime(unsigned int number){
    if(number == 1 || number == 0) return 0; // edge cases

    int top = sqrt(number);
    for (int i = 2; i <= top; ++i) {
        if(number % i == 0) return 0;
    }
    
    return 1;
}