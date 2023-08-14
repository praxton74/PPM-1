vector<int> Solution::prevSmaller(vector<int> &arr) {
    stack<int> s;
    int n = (int)arr.size();
    vector<int> results(n);
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        results[i] = s.empty() ? -1 : arr[s.top()];
        s.push(i);
    }
    return results;
}
