#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end) 
{
    int n1 = mid - start + 1; 
    int n2 = end - mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for(int i = 0; i < n1; i++)
        right[i] = arr[mid + i + 1];
    
    int i = 0, j = 0, k = start;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) 
            arr[k++] = left[i++];
        else    
            arr[k++] = right[j++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int *arr, int start, int end) 
{
    if(start >= end)
        return;
    
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
