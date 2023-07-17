class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int result = 0;
        for(int i = 0; i < n; i++)
            result ^= arr[i];
        for(int i = 1; i <= n; i++)
            result ^= i;
        
        int rsb_mask = result & -result;
        int missing = 0, repeating = 0;
        for(int i = 0; i < n; i++) {
            if(rsb_mask & arr[i])
                repeating ^= arr[i];
            else
                missing ^= arr[i];
        }
        for(int i = 1; i <= n; i++) {
            if(rsb_mask & i)
                repeating ^= i;
            else
                missing ^= i;
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] == missing) {
                swap(missing, repeating);
                break;
            }
        }
        int *ans = new int[2];
        ans[0] = repeating;
        ans[1] = missing;
        
        return ans;
        
    }
};
