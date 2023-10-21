class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty())
            {
                nums[i] += nums[dq.front()];
            }
            while(!dq.empty() && (i-dq.front()>=k || nums[i]>=nums[dq.back()]))
            {
                if(nums[i]>=nums[dq.back()])
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }

            if(nums[i]>0)
            {
                dq.push_back(i);
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
