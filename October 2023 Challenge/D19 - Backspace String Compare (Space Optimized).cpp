class Solution {
public:
    bool backspaceCompare(string s, string t) {
        function<int(string, int)> nextValidChar = [&](string s, int index)
        {
            int backspace = 0;
            while(index>=0)
            {
                if(backspace==0 && s[index]!='#')
                {
                    break;
                }
                else if(s[index]=='#')
                {
                    backspace++;
                }
                else
                {
                    backspace--;
                }
                index--;
            }
            return index;
        };

        int index_s = s.length()-1;
        int index_t = t.length()-1;
        while(index_s>=0 || index_t>=0)
        {
            index_s = nextValidChar(s, index_s);
            index_t = nextValidChar(t, index_t);
            if(index_s<0 && index_t<0)
            {
                return true;
            }
            if(index_s<0 || index_t<0)
            {
                return false;
            }
            else if(s[index_s]!=t[index_t])
            {
                return false;
            }
            index_s--;
            index_t--;
        }
        return true;
    }
};
