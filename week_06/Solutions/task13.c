#include <stdio.h>

int main(){

    int n;
    printf("Insert n: ");
    if(scanf("%d", &n) != 1){
        printf("Invalid data!");
        return -1;
    }

    unsigned long long subsets = 1 << n; // 2 ^ n

    /*
        We use the natual way binary numbers increment to represent a 
        Combinatorix configuration with order and no repetition
    */
    for (unsigned long long bitset = 0; bitset < subsets; ++bitset)
    {
        printf("{ ");
        for (int i = 0; i < n; i++) {
            if(bitset & (1 << i)) printf("%d ", i + 1);
        }
        puts("}");
    }
    
    return 0;
}