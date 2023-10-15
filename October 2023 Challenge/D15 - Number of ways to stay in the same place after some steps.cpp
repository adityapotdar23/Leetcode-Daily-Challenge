class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        
        vector<vector<long long>> memo(steps+1, vector<long long>(min(arrLen, steps)+1, -1));

        return dp(steps, 0, arrLen, MOD, memo);
    }

    long long dp(int stepsLeft, int index , int arrLen, const int MOD, vector<vector<long long>>& memo)
    {
        if(stepsLeft==0)
        {
            if(index==0)
            {
                return 1;
            }
            return 0;
        }

        if(stepsLeft<0 || index<0 || index>=arrLen || stepsLeft<index)
        {
            return 0;
        }

        if(memo[stepsLeft][index]!=-1)
        {
            return memo[stepsLeft][index];
        }
        long long total = dp(stepsLeft-1, index-1, arrLen, MOD, memo);
        total += dp(stepsLeft-1, index+1, arrLen, MOD, memo);
        total += dp(stepsLeft-1, index, arrLen, MOD, memo);

        memo[stepsLeft][index] = total % MOD;
        return total%MOD;
    }
};
