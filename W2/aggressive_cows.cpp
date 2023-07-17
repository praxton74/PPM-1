bool possible(int mid, vector<int> &stalls, int k){
        int i, temp=stalls[0], count=1;
        for(i=1; i<stalls.size(); i++){
            if(stalls[i]-temp>=mid){
                temp=stalls[i];
                count++;
            }
            if(count==k)
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int low=1, high=stalls[n-1]-stalls[0];
        int ans=1;
        while(low<=high){
            int mid= low + (high-low)/2;
            
            if(possible(mid, stalls, k)){
                low=mid+1;
                ans=max(ans, mid);
            }
            else
                high=mid-1;
        }
        return ans;
    }
