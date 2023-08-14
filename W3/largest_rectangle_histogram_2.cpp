
class Solution {
    public:
    long long getMaxArea(long long arr[], int n) {
        // Your code here
        stack<long long> s;
        long long max_area = 0, cur_area = 0;
        
        
        for(int i = 0; i <= n; i++) {
            while(!s.empty() && (i == n || arr[i] <= arr[s.top()])) {
                long long tp = s.top();
                s.pop();
                cur_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if(cur_area > max_area)
                    max_area = cur_area;
            }
            s.push(i);
        }
        return max_area;
    }
};
