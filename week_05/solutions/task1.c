#include <stdio.h>

int main(){

    unsigned int age;
    printf("Enter age: "); scanf("%u", &age);
    
    if(age >= 18 && age <= 120){
        printf("You are an adult!");
    }
    else if(age < 18){
        printf("You are a minor!");
    }
    else printf("Invalid age!");

    return 0;
}