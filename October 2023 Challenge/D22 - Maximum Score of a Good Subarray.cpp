class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = nums[k]; 
        int maxi = nums[k];
        int i = k; 
        int j = k; 
        while(i>0 || j<n-1)
        {
            int left, right;
            if(i>0)
            {
                left = nums[i-1];
            }
            else
            {
                left = 0;
            }
            if(j<n-1)
            {
                right = nums[j+1];
            }
            else
            {
                right = 0;
            }
            if(left>right)
            {
                i--;
                mini = min(mini, left);
            }
            else
            {
                j++;
                mini = min(mini, right);
            }
            maxi = max(maxi, mini*(j-i+1));
        }
        return maxi;
    }
};
