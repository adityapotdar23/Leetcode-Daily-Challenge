class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n==1)
        {
            return 1;
        }
        if(arr[0]!=1)
        {
            arr[0] = 1;
        }
        int maxi = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==1)
            {
                continue;
            }
            if(abs(arr[i]-arr[i-1])<=1)
            {
                maxi = arr[i];
            }
            else
            {
                arr[i] = arr[i-1] + 1;
                maxi = arr[i];
            }
        }
        return maxi;
    }
};
