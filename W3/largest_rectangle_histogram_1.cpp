
int Solution::largestRectangleArea(vector<int> &arr) {
    int max_area = 0;
    int n = (int)arr.size();
    
    int pse[n]; // previous smaller element on the left
    int nse[n]; // next smaller element on the right
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        pse[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        nse[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    
    int cur_area;
    for(int i = 0; i < n; i++) {
        cur_area = arr[i] * (nse[i] - pse[i] - 1);
        if(cur_area > max_area)
            max_area = cur_area;
    }
    return max_area;
}
