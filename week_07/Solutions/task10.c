#include <stdio.h>

void print_all_neighbour_digit_numbers(int start, int end);
int is_valid(int number);

int main(){

    int start, end;
    printf("Insert start and end: ");
    if(scanf("%d %d", &start, &end) != 2){
        printf("Invalid input!");
        return -1;
    }

    print_all_neighbour_digit_numbers(start,end);
    
    return 0;
}

void print_all_neighbour_digit_numbers(int start, int end){

    for (int i = start; i <= end; ++i) {
        if(is_valid(i)) printf("%d\n", i);
    }
}

int is_valid(int number)
{
    int prev, current;
    prev = number % 10;
    while (number /= 10)
    {
        current = number % 10;
        if (current == prev) return 1;
        prev = current;
    }
    
    return 0;
}
