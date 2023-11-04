class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l_size = left.size(), r_size = right.size();
        if(l_size==0)
        {
            return n - *min_element(right.begin(), right.end());
        }
        if(r_size==0) 
        {
            return *max_element(left.begin(), left.end());
        }
        int l_maxi = *max_element(left.begin(), left.end());
        int r_mini = *min_element(right.begin(), right.end());
        int r_maxi = n - r_mini;
        return max(l_maxi, r_maxi);
    }
};
