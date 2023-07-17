void allSubseq(int *arr, int n) {
    int size = pow(2, n);
    for(int i = 1; i < size; i++) {
        int temp = i;
        int j = 0;

        while(temp) {
            if(temp & 1)
                cout << arr[j] << " ";
            j++;
            temp >>= 1;
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "All non-empty subsequences: " << endl;
    allSubseq(arr, n);
}
