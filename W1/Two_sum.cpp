class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m {{nums[0], 0}}; 
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            int rem = target - nums[i];
            if(m.find(rem) != m.end()) {
                return {m[rem], i};
            }
            m.insert({nums[i], i});
        }
        return {};
    }
};
