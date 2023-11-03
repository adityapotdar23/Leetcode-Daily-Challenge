class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> res;
        vector<string> ops;
        int target_size = target.size();
        for(int i=1;i<=n;i++)
        {
            res.push_back(i);
            ops.push_back("Push");
            if(res[res.size()-1]!=target[res.size()-1])
            {
                res.pop_back();
                ops.push_back("Pop");
            }
            if(res==target)
            {
                break;
            }
        }
        return ops;
    }
};
