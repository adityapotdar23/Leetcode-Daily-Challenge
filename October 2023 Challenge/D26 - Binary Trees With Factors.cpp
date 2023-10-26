class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        unordered_map<long, long> sc;

        for(long root: arr) 
        {
            sc[root] = 1;
            for(long factor: arr)
            {
                if(factor>=root)
                {
                    break;
                }
                if(root%factor==0 && sc.find(root/factor)!=sc.end())
                {
                    sc[root] += sc[factor]*sc[root/factor];
                }
            }
        }
        long t = 0;
        for(const auto& i: sc)
        {
            t += i.second;
        }
        return t%static_cast<int>(pow(10, 9)+7);
    }
};
