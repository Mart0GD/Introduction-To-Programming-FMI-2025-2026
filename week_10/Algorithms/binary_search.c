
// Complexity --> O(log2(n))
int binary_search(const int arr[], int size, int desired){
    
    int l = 0;
    int r = size - 1;
    int mid;

    while (l <= r)
    {
        mid = (r - l) / 2 + l;

        if(arr[mid] > desired)          r = mid;
        else if (arr[mid] < desired)    l = mid + 1;
        else return                     mid;
    }
    
    return -1;
}
