#include <stdio.h>

int is_infix(unsigned n, unsigned k);
int is_suffix(unsigned n, unsigned k);

int main(){

    unsigned n,k;
    printf("Insert n,k: ");
    if(scanf("%u %u", &n, &k) != 2){
        printf("Invalid input!");
        return -1;
    }

    printf(is_infix(n,k) ? "yes" : "no");
    return 0;
}

int is_infix(unsigned n, unsigned k){
    
    while (n) {
        if(is_suffix(n,k)) return 1;
        n /= 10;
    }
    
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