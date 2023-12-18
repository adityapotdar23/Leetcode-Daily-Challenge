// Approach 1 - O(nlogn)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1]*nums[n-2] - nums[0]*nums[1];
    }
};


// Approach 2 - O(n) 
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = 0, secondLargest = 0;
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for(int n: nums)
        {
            if(n<smallest)
            {
                secondSmallest = smallest;
                smallest = n;
            }
            else if(n<secondSmallest)
            {
                secondSmallest = n;
            }

            if(n>largest)
            {
                secondLargest = largest;
                largest = n;
            }
            else if(n>secondLargest)
            {
                secondLargest = n;
            }
        }
        return (largest*secondLargest)-(smallest*secondSmallest);
    }
};
