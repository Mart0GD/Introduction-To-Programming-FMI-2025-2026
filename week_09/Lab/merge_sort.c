#include <stdio.h>
#define MAX_SIZE 128

void merge_sort(int res[], const int arr1[], const int arr2[], int size1, int size2);

/*
    Takes two sorted arrays and merges them into one

    *Complexity --> O(nlog(n)) 
*/

int main(){

    int arr1[] = { 1, 2, 3 , 4, 11, 43, 54};
    int arr2[] = { 11, 11, 14 , 22, 111, 433, 524};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    int res[MAX_SIZE] = {0};
    merge_sort(res, arr1, arr2, len1, len2);
    return 0;
}

void merge_sort(int res[], const int arr1[], const int arr2[], int size1, int size2){

    int res_iter = 0, iter1 = 0, iter2 = 0;
    while (iter1 < size1 && iter2 < size2)
    {
        if(arr1[iter1] < arr2[iter2]) res[res_iter++] = arr1[iter1++];
        else                          res[res_iter++] = arr2[iter2++];
    }

    while(iter1 < size1) res[res_iter++] = arr1[iter1++];
    while(iter2 < size2) res[res_iter++] = arr2[iter2++];
}