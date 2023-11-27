class Solution {
public:
    int knightDialer(int n) {
        if(n==1)
        {
            return 10;
        }

        int mod = 1e9+7;

        vector<vector<int>> jumps = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        vector<int> dp(10, 1);

        for(int i=0;i<n-1;i++)
        {
            vector<int> next_dp(10, 0);
            for(int j=0;j<10;j++)
            {
                for(int k=0;k<jumps[j].size();k++)
                {
                    next_dp[jumps[j][k]] = (next_dp[jumps[j][k]] + dp[j])%mod;
                }
            }

            dp = next_dp; 
        }
        int res = 0;
        for(int i=0;i<10;i++)
        {
            res = (res + dp[i])%mod;
        }
        return res;
    }
};
