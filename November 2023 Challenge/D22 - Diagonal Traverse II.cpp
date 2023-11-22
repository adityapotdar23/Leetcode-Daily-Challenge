class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(); 
        int maxSum = 0, size = 0, index = 0;
        vector<vector<int>> map(100001);

        for(int i=0;i<n;i++)
        {
            size += nums[i].size();
            for(int j=0;j<nums[i].size();j++)
            {
                int sum = i+j;
                map[sum].push_back(nums[i][j]);
                maxSum = max(sum, maxSum);
            }
        }

        vector<int> res(size);
        for(int i=0;i<=maxSum;i++)
        {
            vector<int>& cur = map[i];
            for(int j=cur.size()-1;j>=0;j--)
            {
                res[index++] = cur[j];
            }
        }

        return res;
    }
};
