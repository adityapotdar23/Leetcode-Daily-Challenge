class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_n = s.length();
        int t_n = t.length();

        stack<char> s1, s2; 

        for(char x: s)
        {
            if(x!='#')
            {
                s1.push(x);
            }
            else if(s1.size()!=0)
            {
                s1.pop();
            }
        }
        for(char x: t)
        {
            if(x!='#')
            {
                s2.push(x);
            }
            else if(s2.size()!=0)
            {
                s2.pop();
            }
        }
        string str1 = "", str2 = "";
        while(!s1.empty())
        {
            char temp = s1.top();
            str1 = str1 + temp;
            s1.pop();
        }
        while(!s2.empty())
        {
            char temp = s2.top();
            str2 = str2 + temp;
            s2.pop();
        }
        if(str1==str2)
        {
            return true;
        }
        return false;
    }
};
