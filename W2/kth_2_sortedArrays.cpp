int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0;
            while((arr1[n-1-i]>arr2[i])&&i<m&&i<n){
                swap(arr1[n-1-i],arr2[i]);
                i++;
            }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        if(k<=n)
        return arr1[k-1];
        else
        return arr2[k-n-1];
    }

