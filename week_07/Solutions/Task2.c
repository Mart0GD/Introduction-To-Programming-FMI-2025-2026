#include <stdio.h>

int is_suffix(unsigned n, unsigned k);

int main(void){

    unsigned int n, k;
    printf("Insert n,k: ");

    if(scanf("%u %u", &n, &k) != 2){
        printf("Invalid values!");
        return -1;
    }

    printf(is_suffix(n,k) ? "yes" : "no");
    return 0;
}

int is_suffix(unsigned n, unsigned k){

    while(k){
        if(n % 10 != k % 10) return 0;
        n /= 10;
        k /= 10;
    }

    return 1;
}