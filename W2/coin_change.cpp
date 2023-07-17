int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    int n = coins.size();
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for(int i = 1; i <= amount; i++) {
        for(const int &c : coins) {
            if(c <= i) {
                int result = dp[i - c];
                if(result != INT_MAX)
                   dp[i] = min(dp[i], result + 1);  
            }
            else 
                break;
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
