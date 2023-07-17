bool isPossible(int maxPages, int A[], int M, int N){
        int children = 1;
        int pages = 0;
        for(int i=0; i<N; i++){
            if(pages + A[i] > maxPages){
                children++;
                pages = A[i];
            }
            else{
                pages += A[i];
            }
        }
        if(children <= M){
            return true;
        }
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M > N){
            return -1;
        }
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0; i<N; i++){
            sum += A[i];
            maxi = max(maxi, A[i]);
        }
        int i = maxi;
        int j = sum;
        int ans = -1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(isPossible(mid, A, M, N)){
                ans = mid;
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
