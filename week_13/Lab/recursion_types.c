#include <stdio.h>

void head_recurion(int num);
void tail_recurion(int num);

void combined_recursion(int num);

int main(){

    head_recurion(5);
    tail_recurion(5);

    combined_recursion(5);
}

void head_recurion(int num){
    if(num > 0) head_recurion(num - 1);

    printf("%d\n", num);
}

void tail_recurion(int num){
    printf("%d\n", num);
    
    if(num > 0) head_recurion(num - 1);
}

void combined_recursion(int num){
    printf("%d\n", num + 1);
    
    if(num > 0) combined_recursion(num - 1);

    printf("%d\n", num - 1);
}