#include <stdio.h>

/*
Напишете програма, която прочита букви (команди) докато не прочете буквата 'E' и тогава прекратява действието си. Програмата ще се налага да поддържа следните команди:

P -> изисква допълнителен вход цяло число n и пресмята пермутацията на n.
V -> изисква допълнителен вход 2 цели числа n и k и пресмята тяхната вариация.
C -> изисква допълнителен вход 2 цели числа n и k и пресмята тяхната комбинация 
E -> край на програмата.
Друг вход -> принтира съобщение за невалиден вход и изисква нов вход "Invalid command input!"
*/
#define EXIT_COMMAND        'E'
#define PERMUTATION_COMMAND 'P'
#define VARIATION_COMMAND   'V'
#define COMBINATION_COMMAND 'C'
#define MAX_VALUE 20

char read_char();

unsigned long long calculate_permutation(unsigned int n);
unsigned long long calculate_variation(unsigned int n, unsigned int k);
unsigned long long calculate_combination(unsigned int n, unsigned int k);

int main(){

    char command;
    do
    {
        command = read_char();
        switch (command)
        {
            case PERMUTATION_COMMAND:{
                unsigned int n;
                if(scanf("%u", &n) != 1 || n > MAX_VALUE) {puts("Invalid input!"); break;}

                printf("P(%u) = %llu\n", n, calculate_permutation(n));
            }break;

            case VARIATION_COMMAND:{
                unsigned int n, k;
                if(scanf("%u %u", &n, &k) != 2 || k > n || n > MAX_VALUE || k > MAX_VALUE) {
                    puts("Invalid input!"); break;
                }

                printf("V(%u,%u) = %llu\n", n, k, calculate_variation(n, k));
            }break;

            case COMBINATION_COMMAND:{
                unsigned int n, k;
                if(scanf("%u %u", &n, &k) != 2 || k > n || n > MAX_VALUE || k > MAX_VALUE) {
                    puts("Invalid input!"); break;
                }

                printf("C(%u,%u) = %llu\n", n, k, calculate_combination(n, k));
            }break;

            case EXIT_COMMAND: return 0;
            default:  printf("Invalid command input!\n"); break;
        }

    } while (1);
    
    return 0;
}

char read_char(){

    char c;
    while (scanf(" %c", &c) != 1) { 
        printf("Invalid command input!\n");
        while (getchar() != '\n'); // clear line
    }
    return c;
}


unsigned long long calculate_permutation(unsigned int n){

    unsigned long long perm = 1;
    for (int i = 2; i <= n; i++) { 
        perm *= i;
    }
    
    return perm;
}
unsigned long long calculate_variation(unsigned int n, unsigned int k){

    unsigned long long res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
    }
    
    return res;
}
unsigned long long calculate_combination(unsigned int n, unsigned int k){
    return calculate_variation(n,k) / calculate_permutation(k);
}