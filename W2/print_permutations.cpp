void permute_helper(vector<vector<int>> &results, vector<int> &nums, int idx) {
    if(idx == (int)nums.size() - 1) {
        results.push_back(nums);
        return;
    }
    for(int i = idx; i < (int)nums.size(); i++) {
        swap(nums[i], nums[idx]);
        permute_helper(results, nums, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> results;
    permute_helper(results, nums, 0);

    return results;
}