#include <stdio.h>
#define MAX_LEN     128

void sort(int arr[], int size);
void rem(int arr[], int size, int index);
int contains(int arr[], int size, int elem);

void unite(const int arr1[MAX_LEN], const int arr2[MAX_LEN], int size_arr1, int size_arr2);
void intersect(int arr1[MAX_LEN], int arr2[MAX_LEN], int size_arr1, int size_arr2);
void diff (int arr1[MAX_LEN], int arr2[MAX_LEN], int size_arr1, int size_arr2);

int main(){

    int arr1[MAX_LEN] = {0};
    int arr2[MAX_LEN] = {0};

    int n, m;
    printf("Insert n, m: ");
    if(scanf("%d %d", &n, &m) != 2 || n + m > MAX_LEN){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    printf("\nUnite: ");
    unite(arr1, arr2, n, m);

    printf("\nIntersect: ");
    intersect(arr1, arr2, n, m);
    
    printf("\nDiff: ");
    diff (arr1, arr2, n, m);

    return 0;
}


void unite(const int arr1[MAX_LEN], const int arr2[MAX_LEN], int size_arr1, int size_arr2){
    int bucket[MAX_LEN] = {0};
    int index = 0;

    for(int i = 0; i < size_arr1; ++i) bucket[index++] = arr1[i];
    for(int i = 0; i < size_arr2; ++i) bucket[index++] = arr2[i];

    sort(bucket, index);

    for(int i = 0; i < index - 1; ++i){
        if(bucket[i] == bucket[i + 1]) {
            rem(bucket, index, i);
            --index; --i;
        }
    }

    for(int i = 0; i < index; ++i) printf("%d ", bucket[i]);
    putchar('\n');
}
void intersect(int arr1[MAX_LEN], int arr2[MAX_LEN], int size_arr1, int size_arr2){
    int bucket[MAX_LEN] = {0};
    int index = 0;

    for(int i = 0; i < size_arr1; ++i) bucket[index++] = arr1[i];
    for(int i = 0; i < size_arr2; ++i) bucket[index++] = arr2[i];

    sort(bucket, index);

    for(int i = 0; i < index; ++i){
        if(bucket[i] != bucket[(i + 1) % index]) {
            rem(bucket, index, i);
            --index; --i;
        }
    }

    for(int i = 0; i < index - 1; ++i){
        if(bucket[i] == bucket[i + 1]) {
            rem(bucket, index, i);
            --index; --i;
        }
    }

    for(int i = 0; i < index; ++i) printf("%d ", bucket[i]);
    putchar('\n');
}
void diff (int arr1[MAX_LEN], int arr2[MAX_LEN], int size_arr1, int size_arr2){
    int bucket[MAX_LEN] = {0};
    int index = 0;

    for(int i = 0; i < size_arr1; ++i) bucket[index++] = arr1[i];

    for (int i = 0; i < size_arr2; i++)
    {
        int found = contains(bucket, index, arr2[i]);
        if(found != -1){
            rem(bucket, index, found);
            --index; --i;
        }
    }
    
    for(int i = 0; i < index; ++i) printf("%d ", bucket[i]);
    putchar('\n');
}


int contains(int arr[], int size, int elem){
    for (int i = 0; i < size; ++i)
        if(arr[i] == elem) return i;

    return -1;
}
void rem(int arr[], int size, int index){
    for (int i = index; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
}
void sort(int arr[], int size){
    int swapped, temp;
    for (int i = 0; i < size; i++)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] <= arr[j + 1]) continue;

            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = 1;
        }
        if(!swapped) break;
    }
}