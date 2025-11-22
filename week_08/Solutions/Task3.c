#include <stdio.h>

int is_prime(int number);

int main(){
    const int max_len = 128;

    int arr[max_len];

    int n;
    printf("Insert n: ");
    if(scanf("%d", &n) != 1 || n > max_len){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    for (int i = 0; i < n; ++i)
    {
        if(is_prime(arr[i])){
            for (size_t j = i; j < n - 1; ++j)
            {
                arr[j] = arr[j + 1];
            }
            --n; --i;
        }
    }
    
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    return 0;
}

int is_prime(int number){
    if(number == 1 || number == 0) return 0;
    
    for (int i = 2; i * i <= number; ++i)
        if(number % i == 0) return 0;

    return 1;
}