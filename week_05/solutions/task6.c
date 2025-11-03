#include <stdio.h>

int main(){

    unsigned int number;
    scanf("%u", &number);

    if(number >= 40 && number < 50){
        printf("XL");
        number -= 40;
    }
    else if(number >= 50){
        printf("L");
        number -= 50;
    }

    // fall through
    switch(number / 10){
        case 3: printf("X"); 
        case 2: printf("X"); 
        case 1: printf("X"); 
    }

    switch (number % 10)
    {
        case 9: printf("IX");   break;
        case 8: printf("VIII"); break;
        case 7: printf("VII");  break;
        case 6: printf("VI");   break;
        case 5: printf("V");    break;
        case 4: printf("IV");   break;
        case 3: printf("III");  break;
        case 2: printf("II");   break;
        case 1: printf("I");    break;
    }
    return 0;
}