int merge(vector<int> &arr, int start, int mid, int end) {
    int n1 = mid - start + 1; 
    int n2 = end - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];
   
    int i = 0, j = 0, k = start;
    int count = 0;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else 
        {
            count += (n1 - i);
            arr[k++] = right[j++];
        }
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
    
    return count;
}

int inversion_helper(vector<int> &arr, int start, int end) {
    // base case
    if(start >= end)
        return 0;
    
    // recursivec  merge sort
    int result = 0, mid = start + (end - start) / 2;
    result += inversion_helper(arr, start, mid);
    result += inversion_helper(arr, mid + 1, end);
    result += merge(arr, start, mid, end);
    
    return result;
}

int Solution::countInversions(vector<int> &A) {
    return inversion_helper(A, 0, A.size() - 1);
}
