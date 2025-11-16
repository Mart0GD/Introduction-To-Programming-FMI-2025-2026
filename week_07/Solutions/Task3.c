#include <stdio.h>

unsigned reverse(unsigned number);
int is_suffix(unsigned n, unsigned k);

int main(void){

    unsigned int n, k;
    printf("Insert n,k: ");

    if(scanf("%u %u", &n, &k) != 2){
        printf("Invalid values!");
        return -1;
    }

    // we are lazy
    unsigned n_rev = reverse(n);
    unsigned k_rev = reverse(k);

    printf(is_suffix(n_rev, k_rev) ? "yes" : "no");
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

unsigned reverse(unsigned number){

    unsigned rev = 0;
    while (number)
    {
        rev *= 10;
        rev += number % 10;
        number /= 10;
    }

    return rev;
}