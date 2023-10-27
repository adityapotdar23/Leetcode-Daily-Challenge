class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int resLen = 0;

        for(int i=0;i<s.length();i++)
        {
            int l = i, r = i;
            while(l>=0 && r<s.length() && s[l]==s[r])
            {
                if(r-l+1>resLen)
                {
                    ans = s.substr(l, r-l+1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i+1;
            while(l>=0 && r<s.length() && s[l]==s[r])
            {
                if(r-l+1>resLen)
                {
                    ans = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};
