#include <stdio.h>

int main(){

    unsigned x, y;
    if(scanf("%u %u", &x, &y) != 2) {
        printf("Inavlid input!");
        return -1;
    }

    for (int i = 0; x != 0; ++i)
    {
        int current = x % 10;
        if(current == y) {
            printf("Digit is %d\n", i + 1);
            return 0;
        }
        x /= 10;
    }

    printf("Y not found in number x!\n");
    return 0;
}