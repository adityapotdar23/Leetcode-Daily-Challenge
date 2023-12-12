// Approach 1 - O(nlogn)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};


// Approach 2 - O(n) 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;

        for(int num: nums)
        {
            if(num>=maxi1)
            {
                maxi2 = maxi1;
                maxi1 = num;
            }
            else if(num>maxi2)
            {
                maxi2 = num;
            }
        }

        return (maxi1-1)*(maxi2-1);
    }
};
