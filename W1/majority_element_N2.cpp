class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0, count = 0;
        
        for(const int &x : nums) {
            if(count == 0) {
                result = x;
                count = 1;
            }
            else if(result == x)
                count++;
            else
                count--;
        }
        return result;
    }
};
