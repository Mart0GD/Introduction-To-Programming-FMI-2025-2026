#include <stdio.h>
#include <math.h>

int main(){

    unsigned int n, k;
    printf("Insert n and k: ");

    if(scanf("%u %u", &n, &k) != 2){
        printf("Inavlid input!");
        return -1;
    }

    int temp = k;

    int max_bit_n = log2(n);
    int max_bit_k = log2(k);

    int infix = 0;
    int counter = 0;
    for (int i = 0; i < max_bit_n; ++i)
    {
        int kth_bit = (k >> counter) & 1;
        int nth_bit = (n >> i) & 1;

        if((nth_bit ^ kth_bit) == 0) ++counter;
        else counter = 0;
        
        if(counter == max_bit_k + 1) {
            infix = 1;
            break;
        }
    }

    printf("is k an infix of n: %s\n", infix ? "yes" : "no");
    return 0;
}