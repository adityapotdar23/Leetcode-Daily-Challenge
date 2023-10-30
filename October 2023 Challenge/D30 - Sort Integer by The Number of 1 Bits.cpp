// Method 1 
class Solution {
public:
    static bool compare(int a, int b) 
    {
        int bitCountA = __builtin_popcount(a);
        int bitCountB = __builtin_popcount(b);

        if(bitCountA==bitCountB)
        {
            return a<b;
        }
        return bitCountA<bitCountB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};


// Method 2 
class Solution {
public:
    static int countSetBits(int n)
    {
        int count = 0;
        while(n>0) 
        {
            count += n&1;
            n = n>>1;
        }
        return count;
    }
    static bool compare(int a, int b) 
    {
        int bitCountA = countSetBits(a);
        int bitCountB = countSetBits(b);

        if(bitCountA==bitCountB)
        {
            return a<b;
        }
        return bitCountA<bitCountB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
