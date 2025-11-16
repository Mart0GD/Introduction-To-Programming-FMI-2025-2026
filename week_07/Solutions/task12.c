#include <stdio.h>

int get_longest_growing_subset_len(unsigned long long number);

int main(){

    unsigned long long number;
    printf("Insert number: ");

    if(scanf("%llu", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    int longest_growing_subset_len = get_longest_growing_subset_len(number);
    printf("Longest growing subset length: %d\n", longest_growing_subset_len);

    return 0;
}

// the function will be misleading because we'll do it backwards
int get_longest_growing_subset_len(unsigned long long number){

    int max_len = 1, current_len = 1, prev = number % 10, current;
    while (number /= 10)
    {
        current = number % 10;
        if(current <= prev) ++current_len;
        else current_len = 1;

        if(current_len > max_len) max_len = current_len;

        prev = current;
    }
 
    return max_len;
}