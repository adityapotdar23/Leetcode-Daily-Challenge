class Solution {
public:
    string largestGoodInteger(string num) {
        int result = -1;
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i]==num[i+1] && num[i]==num[i+2])
            {
                result = max(result, num[i]-'0');
            }
        }

        if(result==-1)
        {
            return "";
        }
        return string(3, '0'+result);
    }
};
