#include <stdio.h>
#define MAX_LEN 128
    
void print_longest_growing_subsequence(int arr[], int size){

    int longest[MAX_LEN];
    int temp[MAX_LEN];

    int longest_size = 0;
    int temp_size;

    for (int i = 0; i < size; i++)
    {   
        temp_size = 0;
        temp[temp_size++] = arr[i];
        for (int j = i + 1; j < size; ++j) {
            if(arr[j] >= arr[j - 1]) {
                temp[temp_size++] = arr[j];
            }
        }
        
        if(temp_size > longest_size){
            longest_size = 0;
            for (int j = 0; j < temp_size; j++)
            {
                longest[longest_size++] = temp[j];
            }
        }
    }
    
    for(int i = 0; i < longest_size; ++i) printf("%d ", longest[i]);
    putchar('\n');
}


int main(){

    int arr[MAX_LEN] = {0};

    int n;
    printf("Insert n: ");
    if(scanf("%d", &n) != 1 || n > MAX_LEN){
        printf("Invalid input!");
        return -1;
    }

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    print_longest_growing_subsequence(arr, n);
    return 0;
}