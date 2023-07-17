class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0, min_val = prices[0];
        int n = prices.size(); 
        for(int i = 1; i < n; i++) {
            if(prices[i] < min_val)
                min_val = prices[i];
            else
                max_profit = max(max_profit, prices[i] - min_val); 
        }
        return max_profit;
    };
}
