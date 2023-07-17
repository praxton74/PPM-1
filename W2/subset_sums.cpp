void subsets_helper(vector<int> &arr, int idx, int sum, int n, vector<int> &results) {
    if(idx == n) {
        results.push_back(sum);
        return;
    }
    subsets_helper(arr, idx + 1, sum + arr[idx], n, results);
    subsets_helper(arr, idx + 1, sum, n, results);
    
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> results;
    subsets_helper(arr, 0, 0, n, results);
    sort(results.begin(), results.end());
    return results;
}
