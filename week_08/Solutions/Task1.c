#include <stdio.h>
#define MAX_SIZE 128 

/*
Напишете функция transform, която получава аргумент масив и преобразува всички негови елементи по следната схема:

по-малките от 0 се заменят с квадрата си
по-големите от 0 с половината си
всяка нулата се заменя с единица
*/

int main(){

    int arr[MAX_SIZE];

    int n;
    printf("Insert n: ");
    if(scanf("%d", &n) != 1 || n > MAX_SIZE){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
    {
        if(arr[i] < 0)          arr[i] = arr[i] * arr[i];
        else if(arr[i] > 0)     arr[i] = arr[i] / 2;
        else                    arr[i] = 1;
    }

    for (int i = 0; i < n; i++)  printf("%d ", arr[i]);

    return 0;
}
