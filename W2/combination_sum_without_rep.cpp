class Solution {
    int prev_candidate;
public:
    Solution() {
        prev_candidate = 60;
    }
    void find_combinations(vector<int> &candidates, int target, int idx, vector<int> &path, vector<vector<int>> &results) {
        if(idx == candidates.size()) {
            if(target == 0)
                results.push_back(path);
            return;
        }    
        if(candidates[idx] <= target && prev_candidate != candidates[idx]) {
            path.push_back(candidates[idx]);
            find_combinations(candidates, target - candidates[idx], idx + 1, path, results);
            prev_candidate = candidates[idx];
            path.pop_back();
        }
        find_combinations(candidates, target, idx + 1, path, results);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        find_combinations(candidates, target, 0, path, results);
        return results;
    }
};
