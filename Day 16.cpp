// Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n)
            return 0;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        
        for(int i = 1; i <= 2; i++) {
            int maxDiff = INT_MIN;
            for(int j = 1; j < n; j++) {
                maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            }
        }
        
        return dp[2][n - 1];
    }
};