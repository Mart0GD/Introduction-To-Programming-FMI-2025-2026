#include <stdio.h>

/*
Дадено е цяло положително число a. Разглеждаме редицата a1, a2, a3, ..., където a1 = a и за i>1, ai е 
равно на сумата от квадратите на цифрите на ai−1.

а) Напишете функция sequence, която за дадени цяли положителни числа a, k и n, пресмята колко пъти 
k се среща измежду първите n члена на разглежданата редица.

б) За дадено a казваме, че редицата е k-балансирана, ако сумата на първите ѝ k елемента е по-малка от 
дадено число A, а сумата на първите (k + 1) елемента е по-голяма или равна на A. Напишете програма, 
която прочита от стандартния вход стойност за a, след което прочита последователно стойности за A, 
до прочитането на отрицателно число, и за всяка прочетена стойност, извежда за кое k редицата е k-балансирана. 
Ако няма такава стойност на k по-малка или равна на 1000 да се изведе текста "MAX". Помислете 
как да реализирате програмата си максимално ефективна.

Пример:

Вход за a = 12 следващите елементи на редицата са 5, 25, 29, 85, 89, …

При:
A = 5,   k = 0 (тук имаше грешка май, защото това не е правилен отговор)
А = 20, k = 2, защото сумата на първите два члена е 17, а на първите три е 42.
*/

#define MAX_ITERATION 1000

size_t sequence(size_t a, size_t k, size_t n);

int    get_balance(size_t a, int A);

int main(){

    // printf("Get number of 145's: %zu\n", sequence(5, 145, 5));

    size_t a;
    printf("Select a: ");
    if(scanf("%zu", &a) != 1) return -1;

    int A;
    do
    {
        printf("Select A: ");
        if(scanf("%d", &A) != 1) return -1;

        int k = get_balance(a, A);
        k > MAX_ITERATION  && puts("MAX");
        k <= MAX_ITERATION && printf("The seqence is k balanced for: %d\n", k);
    } while (a >= 0);
    
    return 0;
}


size_t sequence(size_t a, size_t k, size_t n){

    size_t to_calculate = a;
    size_t counter = 0;

    for (int i = 0; i < n; i++)
    {
        size_t curr = 0;
        do
        {
            size_t digit = to_calculate % 10;

            curr += digit * digit;
        } while (to_calculate /= 10);


        if(curr == k)   ++counter;
        to_calculate = curr;
    }
    
    return counter;
}

int get_balance(size_t a, int A){

    size_t to_calculate = a;
    size_t sum = a;

    for (int i = 1; i <= MAX_ITERATION; i++)
    {
        
        size_t curr = 0;
        do
        {
            size_t digit = to_calculate % 10;
            curr += digit * digit;
        } while (to_calculate /= 10);
        
        if(sum < A && sum + curr >= A) return i;

        sum += curr;
        to_calculate = curr;
    }
    
    return MAX_ITERATION;
}
