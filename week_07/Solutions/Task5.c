#include <stdio.h>

unsigned reverse(unsigned number);
int get_common_suffix_len(unsigned num1, unsigned num2);

int main(){

    unsigned num1, num2;
    printf("Insert two numbers: ");

    if(scanf("%u %u", &num1, &num2) != 2){
        printf("Invalid input!");
        return -1;
    }

    unsigned num1_rev = reverse(num1);
    unsigned num2_rev = reverse(num2);

    int longest_common_prefix = get_common_suffix_len(num1_rev, num2_rev);
    int longest_common_suffix = get_common_suffix_len(num1, num2);

    printf("Longest prefix: %d\n", longest_common_prefix);
    printf("Longest suffix: %d\n", longest_common_suffix);

    return 0;
}

int get_common_suffix_len(unsigned num1, unsigned num2){

    int cnt = 0;
    while(num1 && num2 && num1 % 10 == num2 % 10) {
        num1 /= 10;
        num2 /= 10;
        ++cnt;
    }

    return cnt;
}

unsigned reverse(unsigned number){

    unsigned rev = 0;
    while (number) {
        rev *= 10;
        rev += number % 10;
        number /= 10;
    }

    return rev;
}