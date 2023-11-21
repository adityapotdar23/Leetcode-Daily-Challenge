class Solution {
public:
    int rev(int n)
    {
        int reversed_number = 0; 
        while(n!=0)
        {
            int remainder = n%10; 
            reversed_number = reversed_number*10 + remainder;
            n = n/10;
        }
        return reversed_number;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
        {
            int temp = nums[i] - rev(nums[i]);
            if(mp.find(temp)!=mp.end())
            {
                mp[temp]++;
            }
            else
            {
                mp[temp] = 1;
            }
        }
        long result = 0;
        int mod = 1000000007;
        for(const auto& entry: mp)
        {
            result = (result%mod + ((long)entry.second*((long)entry.second-1)/2))%mod;
        }
        return static_cast<int>(result);
    }
};
