#include <stdio.h>
#define MAX_LEN 128

int are_equal (int arr1[MAX_LEN], int arr2[MAX_LEN], int size_arr1, int size_arr2);
int contains(int arr[], int size, int elem);

int main(){

    int arr1[MAX_LEN] = {0};
    int arr2[MAX_LEN] = {0};

    unsigned n, m;
    if( scanf("%u %u", &n, &m) != 2 || n > MAX_LEN || m > MAX_LEN){
        puts("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    int res = are_equal(arr1, arr2, n, m);

    res && puts("Sequences are equal!");
    !res && puts("Sequences are not equal!");

    return 0;
}

int are_equal (int arr1[MAX_LEN], int arr2[MAX_LEN], int size_arr1, int size_arr2){
    int bucket[MAX_LEN] = {0};
    int index = 0;

    int res = 1;
    for (int i = 0; i < size_arr1; i++)
    {
        if(contains(arr2, size_arr2, arr1[i]) == -1) {
            res = 0;
            break;
        }
    }

    if(res){
        for (int i = 0; i < size_arr2; i++)
        {
            if(contains(arr1, size_arr1, arr2[i]) == -1) {
                res = 0;
                break;
            }
        }
    }
    
    return res ;
}

int contains(int arr[], int size, int elem){
    for (int i = 0; i < size; ++i)
        if(arr[i] == elem) return i;

    return -1;
}