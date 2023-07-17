int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int count = 1; 
    int max_count = 1;
    int i = 1, j = 0;
    
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            count++;
            i++;
        }
        else {
            count--;
            j++;
        }
        if(count > max_count)
            max_count = count;
    }
    return max_count;
}
