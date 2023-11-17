// Approach 1 - O(nlogn)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int maxi = 0;
        while(i<j)
        {
            maxi = max(nums[i]+nums[j], maxi);
            i++;
            j--;
        }
        return maxi;
    }
};


// Approach 2 - O(n)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        vector<int> frequency(100001, 0);

        for(int num: nums)
        {
            frequency[num]++;
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }

        int low = minNum;
        int high = maxNum;
        while(low<=high)
        {
            if(frequency[low]==0)
            {
                low++;
            }
            else if(frequency[high]==0)
            {
                high--;
            }
            else
            {
                int currentPairSum = low+high;
                maxSum = max(maxSum, currentPairSum);
                frequency[low]--;
                frequency[high]--;
            }
        }
        return maxSum;
    }
};
