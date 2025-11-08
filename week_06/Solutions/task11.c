#include <stdio.h>

int main(){

    unsigned int num1, num2;
    printf("Insert number1 and number2: ");

    if(scanf("%u %u", &num1, &num2) != 2){
        printf("Invalid input!");
        return -1;
    }

    int hemming_distance = 0;
    for (int i = 0; i < 32; i++)
    {
        int n1th_bit = num1 >> i & 1;
        int n2th_bit = num2 >> i & 1;

        hemming_distance += n1th_bit ^ n2th_bit;
    }

    printf("Hemming distance %d\n", hemming_distance);
    return 0;
}