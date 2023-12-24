class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0 and s[i]=='1')
            {
                c++;
            }
            if(i%2==1 and s[i]=='0')
            {
                c++;
            }
        }
        return min(c, n-c);
    }
};
