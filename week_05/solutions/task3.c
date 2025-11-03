#include <stdio.h>

int main(){

    int num1,num2,num3;
    printf("Insert numbers!\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    int temp;

    // get first one in place
    if(num1 > num2){
        temp = num2;
        num2 = num1;
        num1 = temp;
    }
    if(num1 > num3){
        temp = num3;
        num3 = num1;
        num1 = temp;
    }

    // get second one in place
    if(num2 > num3){
        temp = num3;
        num3 = num2;
        num2 = temp;
    }

    printf("Sorted: %d %d %d", num1, num2, num3);
    return 0;
}