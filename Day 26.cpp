// Minimum Cost For Tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n);
        dp[0] = min(costs[0], min(costs[1], costs[2]));
        
        int last7, last30;
        last7 = last30 = 0;
        
        for(int i = 1; i < n; i++) {
            while(last7 < i && (days[last7] + 7 <= days[i])) {
                last7++;
            }
            while(last30 < i && (days[last30] + 30 <= days[i])) {
                last30++;
            }
            int one = dp[i - 1] + costs[0];
            int seven = last7 ? dp[last7 - 1] + costs[1] : costs[1];
            int thirty = last30 ? dp[last30 - 1] + costs[2] : costs[2];
            dp[i] = min(one, min(seven, thirty));
        }
        
        return dp[n - 1];
    }
};