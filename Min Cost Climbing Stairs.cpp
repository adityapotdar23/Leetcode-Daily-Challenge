class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp_n = n+1;
        int dp[dp_n];
        dp[dp_n-1] = 0;
        dp[dp_n-2] = cost[n-1];
        int i = dp_n-3;
        while(i>=0)
        {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
            i--;
        }
        return min(dp[0], dp[1]);
    }
};
