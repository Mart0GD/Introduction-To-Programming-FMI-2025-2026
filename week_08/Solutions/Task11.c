#include<stdio.h>
#define MAX_LEN 128

int find_unique_num(const int arr[MAX_LEN], int arrLength) {

	int uniqueNumber = 0;
	for (int i = 0; i < arrLength; ++i) {
		uniqueNumber ^= arr[i];
	}

	return uniqueNumber;
}

int main() {
	int n;
	int arr[MAX_LEN];

	if(scanf("%d", &n) != 1 || n > MAX_LEN){
        printf("Invalid input!");
        return -1;
    }

	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

	int uniqueNumber = find_unique_num(arr, n);
	printf("Unique number -> %d\n", uniqueNumber);
	return 0;
}