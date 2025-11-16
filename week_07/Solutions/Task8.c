#include <stdio.h>
#include <math.h>

int is_prime(unsigned number);
int get_digits(unsigned number);
void print_prime_infixes(unsigned number);
unsigned my_pow(unsigned num, unsigned power);

int main(){

    unsigned number;
    printf("Insert number: ");

    if(scanf("%u", &number) != 1){
        printf("Invalid input!");
        return -1;
    }

    print_prime_infixes(number);
    return 0;
}

void print_prime_infixes(unsigned number){
    if(number < 2) return;

    int digits = get_digits(number);

    unsigned current_digit;
    for (int i = 1; i <= digits; i++)
    {
        current_digit = (number / my_pow(10, digits - i)) % 10;
        if(is_prime(current_digit)) printf("%u ", current_digit);

        for (int j = i + 1; j <= digits; j++)
        {
            current_digit *= 10;
            current_digit += (number / my_pow(10,digits - (j))) % 10;
            
            if(is_prime(current_digit)) printf("%u ", current_digit);
        }
    }
    
}

int is_prime(unsigned number){
    if(number == 0 || number == 1) return 0;

    int top_limit = sqrt(number);
    for(int i = 2; i <= top_limit; ++i)
    {
        if(number % i == 0) return 0;
    }
    

    return 1;
}

int get_digits(unsigned number){

    int cnt = 0;
    while(number){
        number /= 10;
        ++cnt;
    }

    return cnt;
}

unsigned my_pow(unsigned num, unsigned power){

    unsigned res = 1;
    for (int i = 0; i < power; i++) res *= num;
    
    return res;
}