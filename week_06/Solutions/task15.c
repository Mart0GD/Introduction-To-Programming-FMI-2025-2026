#include <stdio.h>

int main(){

    unsigned short n;
    printf("Insert n: ");
    if(scanf("%hu", &n) != 1 || n > 63){
        printf("Invalid data!");
        return -1;
    }

    unsigned long long bitset = 0;
    int number = 0; 
    do
    {
        if(scanf("%d", &number) != 1){
            printf("Invalid input!\n");
            return -1;
        }

        if(number > n || number < -1){
            printf("Invalid value. Element was not added to bitset!\n");
            continue;
        }

        if(number >= 0)bitset |= (1ULL << number);
    } while (number != -1);
    
    for (int i = 0; i < n; i++) {
        int bit = (bitset >> i) & 1;

        if(bit) printf("%d ", i);
    }
    
    return 0;
}