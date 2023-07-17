class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> results;
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        for(int &x : nums) {
            if(x == num1)
                count1++;
            else if(x == num2)
                count2++;
            else if(count1 == 0) {
                num1 = x;
                count1 = 1;
            }
            else if(count2 == 0) {
                num2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        int n = nums.size();
        for(int &x : nums) {
            if(x == num1)
                count1++;
            else if(x == num2)
                count2++;
        }
        if(count1 > n / 3)
            results.push_back(num1);
        if(count2 > n / 3)
            results.push_back(num2);
        
        return results;
    }
};
