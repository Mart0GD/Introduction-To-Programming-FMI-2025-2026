#include <stdio.h>

int main(){

    int number1, number2;
    printf("Insert number1 and number2 for addition: ");
    if( scanf("%d %d", &number1, &number2) != 2){
        printf("Invalid input!");
        return -1;
    }

    int 
    carry = 0, 
    res = 0;

    do
    {
        
        res     = number1 ^ number2;
        carry   = number1 & number2;
        
        number1 = res;
        number2 = carry;
        number2 <<= 1;
    } while (carry != 0);
    
    printf("num1 + num2 = %d\n", res);

    printf("Insert number1 and number2 for subtraction: ");
    if( scanf("%d %d", &number1, &number2) != 2){
        printf("Invalid input!");
        return -1;
    }

    number2 = ~number2 + 1;
    do
    {
        
        res     = number1 ^ number2;
        carry   = number1 & number2;
        
        number1 = res;
        number2 = carry;
        number2 <<= 1;
    } while (carry != 0);

    printf("num1 - num2 = %d\n", res);
    return 0;
}