class Solution {
public:
    bool check(vector<int> arr)
    {
        int min_element = INT_MAX;
        int max_element = INT_MIN;
        unordered_set<int> arrSet; 

        for(int num: arr)
        {
            min_element = min(num, min_element);
            max_element = max(num, max_element);
            arrSet.insert(num);
        }

        if((max_element-min_element)%(arr.size()-1)!=0)
        {
            return false;
        }

        int diff = (max_element-min_element)/(arr.size()-1);
        int curr = min_element + diff;

        while(curr<max_element)
        {
            if(arrSet.find(curr)==arrSet.end())
            {
                return false;
            }
            curr += diff;
        }

        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;

        for(int i=0;i<l.size();i++)
        {
            vector<int> arr(begin(nums)+l[i], begin(nums)+r[i]+1);
            res.push_back(check(arr));
        }
        return res;
    }
};
